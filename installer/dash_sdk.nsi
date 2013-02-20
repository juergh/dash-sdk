;
; <AMD 3BSD notice header>
;
; Copyright (c) 2006, 2007, 2008 Advanced Micro Devices, Inc.
;
; All rights reserved.
;
; This file is subject to the license found in the LICENSE.AMD file which
; states the following in part:
;
; Redistribution and use in any form of this material and any product
; thereof including software in source or binary forms, along with any
; related documentation, with or without modification ("this material"),
; is permitted provided that the following conditions are met:
;
;   * Redistributions of source code of any software must retain the above
;     copyright notice and all terms of this license as part of the code.
;
;   * Redistributions in binary form of any software must reproduce the
;     above copyright notice and all terms of this license in any related
;     documentation and/or other materials. 
;
;   * Neither the names nor trademarks of Advanced Micro Devices, Inc.
;     or any copyright holders or contributors may be used to endorse or
;     promote products derived from this material without specific prior
;     written permission.
;

;--------------------------------

  SetCompressor /SOLID LZMA
  SetDatablockOptimize on ; (can be off)
  CRCCheck on ; (can be off)

  !ifndef Config
    !define Config Dualmode
  !endif
  !ifndef Path
    !define Path ..
  !endif

;--------------------------------
;General

  ;Name and file
  !define NAME "Dash Software Development Kit"
  !define _NAME "Dash_Software_Development_Kit"
  !ifdef InstVersion
    !define NAMEVERSION "${NAME} v${InstVersion}"
  !else
    !define NAMEVERSION "${NAME}"
  !endif
  Name "${NAMEVERSION}"
  !define InstVersion "1.1.8.0078"

  !ifndef InstFile
    !if ${CONFIG} == "Debug"
      !ifdef FileVersion
        OutFile "libdashsdk-setup-${FileVersion}-debug.exe"
      !else
        OutFile "libdashsdk-setup-debug.exe"
      !endif
    !else
      !ifdef FileVersion
        OutFile "libdashsdk-setup-${FileVersion}.exe"
      !else
        OutFile "libdashsdk-setup.exe"
      !endif
    !endif
  !else
    OutFile ${InstFile}
  !endif

  !ifndef Path
    !define Path ".."
  !endif

  !define INST_REG_ROOT "SHELL_CONTEXT"
  !define INST_REG_KEY  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${_NAME}"
  !define UNINST_FILENAME  "uninstall.exe"
  !define UNINST_EXE       "$INSTDIR\${UNINST_FILENAME}"

  ;Default installation folder may be changed by the Multi User Page
  InstallDir "$PROGRAMFILES\${NAME}"

  ;default directory for start menu
  !define MUI_STARTMENUPAGE_DEFAULTFOLDER "${NAME}"
  
  ;modern user interface settings: icon
  !define MUI_ICON "dashsdk.ico"

;--------------------------------
;MultiUser Settings

  !define MULTIUSER_EXECUTIONLEVEL Highest
  !define MULTIUSER_INSTALLMODE_INSTDIR "${NAME}"
  !define MULTIUSER_INSTALLMODE_DEFAULT_REGISTRY_KEY "${INST_REG_KEY}"
  !define MULTIUSER_INSTALLMODE_DEFAULT_REGISTRY_VALUENAME "InstallDir"
  !define MULTIUSER_INSTALLMODE_INSTDIR_REGISTRY_KEY "${INST_REG_KEY}"
  !define MULTIUSER_INSTALLMODE_INSTDIR_REGISTRY_VALUENAME "InstallDir"
  !define MULTIUSER_MUI
  !define MULTIUSER_INSTALLMODE_COMMANDLINE
  !define MULTIUSER_INSTALLMODEPAGE_TEXT_TOP ""

;--------------------------------
;Includes

  !include "MUI2.nsh"
  !include "Putty.nsh"
  !include LogicLib.nsh
  !include Sections.nsh
  !include MultiUser.nsh
  !include Common.nsh

;--------------------------------
;Variables

  Var StartMenuFolder

;--------------------------------
;Interface Settings

  !define MUI_ABORTWARNING

;--------------------------------
;Pages

  !define MUI_PAGE_CUSTOMFUNCTION_LEAVE leaveLicensePage
  !insertmacro MUI_PAGE_LICENSE "License.txt"

  !define MUI_PAGE_CUSTOMFUNCTION_LEAVE leaveMultiUserPage
  !insertmacro MULTIUSER_PAGE_INSTALLMODE
  
  !define MUI_PAGE_CUSTOMFUNCTION_PRE enterComponentsPage
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  
  ;Start Menu Folder Page Configuration
  !define MUI_STARTMENUPAGE_REGISTRY_ROOT ${INST_REG_ROOT}
  !define MUI_STARTMENUPAGE_REGISTRY_KEY ${INST_REG_KEY}
  !define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "Start Menu Folder"
  !insertmacro MUI_PAGE_STARTMENU Application $StartMenuFolder

  !insertmacro MUI_PAGE_INSTFILES
  
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_INSTFILES

;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English"

;--------------------------------

  InstType "Full" 

;--------------------------------
;Installer Sections

Section "SDK" SecSDK
  SectionIn RO

  SetOutPath "$INSTDIR"

  ;Store installation folder
  ${if} $MultiUser.InstallMode != "AllUsers"
    WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "DisplayName" "${NAMEVERSION} - Current User (Remove Only)"
  ${else}
    WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "DisplayName" "${NAMEVERSION} - All Users (Remove Only)"
  ${endif}
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "UninstallString" "${UNINST_EXE}"
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "NoRepair" 1
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "NoModify" 1
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "InstallLocation" $INSTDIR
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "Publisher" "AMD"
  WriteRegStr ${INST_REG_ROOT} "${INST_REG_KEY}" "DisplayVersion" "${InstVersion}"
  
  
  ; include for some of the windows messages defines
  ; HKLM (all users) vs HKCU (current user) defines
  !define env_hklm 'HKLM "SYSTEM\CurrentControlSet\Control\Session Manager\Environment"'
  !define env_hkcu 'HKCU "Environment"'
  ; set variable
  WriteRegExpandStr ${env_hklm} MONGOOSE_CONF "$INSTDIR\mongoose.conf"
  ; make sure windows knows about the change
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000


  ;Create uninstaller
  WriteUninstaller "${UNINST_EXE}"
  
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    
    ;Create shortcuts
    CreateDirectory "$SMPROGRAMS\$StartMenuFolder"
    CreateShortCut "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk" "${UNINST_EXE}"
  !include sdk_startmenu_install.nsh  
  !insertmacro MUI_STARTMENU_WRITE_END

!if ${CONFIG} == "Dualmode"
  SetOutPath "$INSTDIR\source\release"
!endif
!if ${CONFIG} != "Debug"
  File "$%VCINSTALLDIR%\redist\x86\Microsoft.VC90.CRT\Microsoft.VC90.CRT.manifest"
  File "$%VCINSTALLDIR%\redist\x86\Microsoft.VC90.CRT\msvcp90.dll"
  File "$%VCINSTALLDIR%\redist\x86\Microsoft.VC90.CRT\msvcr90.dll"
  File "${Path}\install_root\Release\libeay32MD.dll"
  File "${Path}\install_root\Release\ssleay32MD.dll"
!endif
!if ${CONFIG} == "Dualmode"
  SetOutPath "$INSTDIR\source\debug"
!endif
!if ${CONFIG} != "Release"
  File "$%VCINSTALLDIR%\redist\Debug_NonRedist\x86\Microsoft.VC90.DebugCRT\Microsoft.VC90.DebugCRT.manifest"
  File "$%VCINSTALLDIR%\redist\Debug_NonRedist\x86\Microsoft.VC90.DebugCRT\msvcp90d.dll"
  File "$%VCINSTALLDIR%\redist\Debug_NonRedist\x86\Microsoft.VC90.DebugCRT\msvcr90d.dll"
  File "${Path}\install_root\Debug\libeay32MDd.dll"
  File "${Path}\install_root\Debug\ssleay32MDd.dll"
!endif
  !include sdk_install.nsh

  !insertmacro Putty "putty.exe" "http://the.earth.li/~sgtatham/putty/latest/x86/putty.exe" "copy $TEMP\putty.exe $\"$INSTDIR\..\PuTTY\$\"" "$INSTDIR\..\PuTTY" "yes"

SectionEnd

;--------------------------------
;Descriptions

  ;Language strings
  LangString DESC_SecSDK ${LANG_ENGLISH} "Dash SDK"

  ;Assign language strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecSDK} $(DESC_SecSDK)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END

;--------------------------------
;Uninstaller Section

Section "Uninstall"

  Delete "$INSTDIR\source\release\Microsoft.VC90.CRT.manifest"
  Delete "$INSTDIR\source\debug\Microsoft.VC90.DebugCRT.manifest"
  Delete "$INSTDIR\source\release\msvcp90.dll"
  Delete "$INSTDIR\source\release\msvcr90.dll"
  Delete "$INSTDIR\source\debug\msvcp90d.dll"
  Delete "$INSTDIR\source\debug\msvcr90d.dll"
  Delete "$INSTDIR\source\debug\libeay32MDd.dll"
  Delete "$INSTDIR\source\debug\ssleay32MDd.dll"
  Delete "$INSTDIR\source\release\libeay32MD.dll"
  Delete "$INSTDIR\source\release\ssleay32MD.dll"
  Delete "$INSTDIR\Microsoft.VC90.CRT.manifest"
  Delete "$INSTDIR\Microsoft.VC90.DebugCRT.manifest"
  Delete "$INSTDIR\msvcp90.dll"
  Delete "$INSTDIR\msvcr90.dll"
  Delete "$INSTDIR\msvcp90d.dll"
  Delete "$INSTDIR\msvcr90d.dll"
  Delete "$INSTDIR\libeay32MDd.dll"
  Delete "$INSTDIR\ssleay32MDd.dll"
  Delete "$INSTDIR\libeay32MD.dll"
  Delete "$INSTDIR\ssleay32MD.dll"
  Delete "$INSTDIR\ssl_client_log.txt"

  !include sdk_uninstall.nsh

  Delete "${UNINST_EXE}"
  
  RMDir "$INSTDIR\source\release"
  RMDir "$INSTDIR\source\debug"
  RMDir "$INSTDIR\source\"
  RMDir "$INSTDIR"
  
  ExecWait 'sc stop DashWebServer'  
  ExecWait 'sc delete DashWebServer' 

  !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuFolder

  Delete "$SMPROGRAMS\$StartMenuFolder\Uninstall.lnk"
  !include sdk_startmenu_uninstall.nsh
  
  ; delete variable
  DeleteRegValue ${env_hklm} MONGOOSE_CONF
  ; make sure windows knows about the change
  SendMessage ${HWND_BROADCAST} ${WM_WININICHANGE} 0 "STR:Environment" /TIMEOUT=5000
   
  RMDir "$SMPROGRAMS\$StartMenuFolder"
  DeleteRegKey ${INST_REG_ROOT} "${INST_REG_KEY}"
SectionEnd

;--------------------------------
;Functions

Function leaveLicensePage
  ; Initialize $8 -> stores whether the admin privileges hint was already displayed  
  IntOp $8 $8 & 0
  ; Initialize $7 -> stores whether the multiuser page was displayed (page is not displayed if called without admin privileges)
  IntOp $7 $7 & 0
FunctionEnd

Function leaveMultiUserPage
  IntOp $7 $7 | 1
  call alreadyInstalledCheck
FunctionEnd

Function enterComponentsPage
  ; do the checks in case the multiuser page wasn't displayed and therefore the callbacks not called
  IntCmp $7 0 0 Done Done
    call alreadyInstalledCheck
Done:
FunctionEnd

Function .onInit
  !insertmacro MULTIUSER_INIT
FunctionEnd

Function un.onInit
  !insertmacro MULTIUSER_UNINIT
FunctionEnd