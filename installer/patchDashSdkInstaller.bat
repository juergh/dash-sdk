REM
REM <AMD 3BSD notice header>
REM
REM Copyright (c) 2006, 2007, 2008 Advanced Micro Devices, Inc.
REM
REM All rights reserved.
REM
REM This file is subject to the license found in the LICENSE.AMD file which
REM states the following in part:
REM
REM Redistribution and use in any form of this material and any product
REM thereof including software in source or binary forms, along with any
REM related documentation, with or without modification ("this material"),
REM is permitted provided that the following conditions are met:
REM
REM   * Redistributions of source code of any software must retain the above
REM     copyright notice and all terms of this license as part of the code.
REM
REM   * Redistributions in binary form of any software must reproduce the
REM     above copyright notice and all terms of this license in any related
REM     documentation and/or other materials. 
REM
REM   * Neither the names nor trademarks of Advanced Micro Devices, Inc.
REM     or any copyright holders or contributors may be used to endorse or
REM     promote products derived from this material without specific prior
REM     written permission.
REM

REM @echo off
IF "%1" == ""       GOTO outer

set d=%2
set dual=no
IF "%2" == ""       set d=debug
IF "%2" == ""       set dual=yes
set p=%1\..

echo Creating SDK installer files: %p%
echo
REM IF NOT EXIST %p%\dashsdk GOTO dashsdkdirnotfound
IF NOT EXIST %p%\windows\win32pkg\%d% GOTO sdkobjdirnotfound

echo ;-------------------------------- > %p%\installer\sdk_install.nsh
echo ;-------------------------------- > %p%\installer\sdk_uninstall.nsh
echo ;-------------------------------- > %p%\installer\sdk_startmenu_install.nsh
echo ;-------------------------------- > %p%\installer\sdk_startmenu_uninstall.nsh

set cf=
IF "%dual%" == "no" GOTO start
set d=release
set cf=\source\%d%

:start
set op=%CD%
cd %p%
set rp=%CD%

echo ### processing docs ###
cd %rp%
echo SetOutPath "$INSTDIR\docs" >> installer\sdk_install.nsh
FOR %%c in (docs\*.pdf) DO echo File "${Path}\%%c" >> installer\sdk_install.nsh
FOR %%c in (docs\libdashsdk-integratedwebserver-help.doc) DO echo File "${Path}\%%c" >> installer\sdk_install.nsh
cd docs
FOR %%c in (*.pdf) DO echo Delete "$INSTDIR\docs\%%c" >> ..\installer\sdk_uninstall.nsh
echo RMDir "$INSTDIR\docs" >> ..\installer\sdk_uninstall.nsh

echo ### processing doc links ###
FOR %%c in (*.pdf) DO echo CreateShortCut "$SMPROGRAMS\$StartMenuFolder\%%c.lnk" "$\"$INSTDIR\docs\%%c$\"" >> ..\installer\sdk_startmenu_install.nsh
FOR %%c in (*.pdf) DO echo Delete "$SMPROGRAMS\$StartMenuFolder\%%c.lnk" >> ..\installer\sdk_startmenu_uninstall.nsh

echo ### processing include files ###
cd %rp%
echo SetOutPath "$INSTDIR\include" >> installer\sdk_install.nsh
echo File /r "${Path}\windows\win32pkg\include\*" >> installer\sdk_install.nsh
echo RMDir /r "$INSTDIR\include" >> installer\sdk_uninstall.nsh

echo ### processing examples ###
cd %rp%
echo SetOutPath "$INSTDIR\example" >> installer\sdk_install.nsh
FOR %%c in (test\dashapitest\*.cpp) DO echo File "${Path}\%%c" >> installer\sdk_install.nsh
cd test\dashapitest
FOR %%c in (*.cpp) DO echo Delete "$INSTDIR\example\%%c" >> ..\..\installer\sdk_uninstall.nsh
echo RMDir "$INSTDIR\example" >> ..\..\installer\sdk_uninstall.nsh

echo ### processing executables links ###
cd %rp%
cd windows\win32pkg\%d%
echo SetOutPath "$INSTDIR%cf%" >> ..\..\..\installer\sdk_startmenu_install.nsh
FOR %%c in (*.exe) DO echo CreateShortCut "$SMPROGRAMS\$StartMenuFolder\%%c.lnk" "cmd" "/k $\"$INSTDIR%cf%\%%c$\"" >> ..\..\..\installer\sdk_startmenu_install.nsh
FOR %%c in (*.exe) DO echo Delete "$SMPROGRAMS\$StartMenuFolder\%%c.lnk" >> ..\..\..\installer\sdk_startmenu_uninstall.nsh
echo SetOutPath "$INSTDIR" >> ..\..\..\installer\sdk_startmenu_install.nsh

echo ### Webserver configuration file ###
cd %rp%
echo SetOutPath "$INSTDIR\" >> installer\sdk_install.nsh
FOR %%c in (webserver\mongoose.conf) DO echo File "${Path}\%%c" >> installer\sdk_install.nsh
cd webserver
FOR %%c in (*.conf) DO echo Delete "$INSTDIR\%%c" >> ..\installer\sdk_uninstall.nsh

:processlibs
echo ### processing %d% libs and executables ###
cd %rp%
echo SetOutPath "$INSTDIR%cf%" >> installer\sdk_install.nsh
FOR %%c in (windows\win32pkg\%d%\*.*) DO echo File "${Path}\%%c" >> installer\sdk_install.nsh
cd windows\win32pkg\%d%
FOR %%c in (*.*) DO echo Delete "$INSTDIR%cf%\%%c" >> ..\..\..\installer\sdk_uninstall.nsh

IF "%dual%" == "no" GOTO finalize
echo RMDir "$INSTDIR%cf%" >> ..\..\..\installer\sdk_uninstall.nsh
IF "%d%" == "debug" GOTO dualfinalize
set d=debug
set cf=\source\%d%
GOTO processlibs

:dualfinalize
echo RMDir "$INSTDIR\source" >> ..\..\..\installer\sdk_uninstall.nsh
:finalize
cd %op%
echo ### finalizing...
GOTO exit

:dashsdkdirnotfound
echo SDK folder not found!
exit /b 1

:sdkobjdirnotfound
echo SDK %d% folder not found!
exit /b 1

:outer
echo Need path to the installer folder!
exit /b 1

:exit
