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


;Common.nsh


!macro GetSystemProfilePath
  Push $1
  Push $2
  Push $3
  Push $4  
 
  StrCpy $1 ""
  StrCpy $2 "0x0023" # CSIDL_COMMON_APPDATA (0x0023)
  StrCpy $3 ""
  StrCpy $4 ""
 
  System::Call 'shell32::SHGetSpecialFolderPath(i $HWNDPARENT, t .r1, i r2, i r3) i .r4'

  Pop $4
  Pop $3
  Pop $2
!macroend

Function alreadyInstalledCheck
  Push $0
  Push $1
Start:
  StrCpy $0 ""  
  ReadRegStr $0 ${INST_REG_ROOT} "${INST_REG_KEY}" "InstallDir"
  StrCmp $0 "" Done

  MessageBox MB_YESNO|MB_ICONQUESTION \
               "An old installation of ${NAME} was detected.\
                $\nYou have to uninstall these files first.$\n$\nStart the uninstall process now?" \
                IDNO GiveUp
  ExecWait '"$0\${UNINST_FILENAME}" _?=$0'

  ; check that the used didn't canceled the uninstall process and remove the old uninstall.exe
  ; note: the uninstaller isn't able to delete itself cause we want to wait for it and 
  ;       pass the parameter _? (causes the uninstaller to not start a second uninstaller 
  ;       from a temporary location)

  ReadRegStr $1 ${INST_REG_ROOT} "${INST_REG_KEY}" "InstallDir"
  StrCmp $1 "" DeleteOldInstaller
  goto Start

DeleteOldInstaller:
  Delete "$0\${UNINST_FILENAME}"
  RMDir "$0"

  goto Start
GiveUp:
  IntCmp $7 0 0 DoneAbort DoneAbort
    SendMessage $HWNDPARENT "0x408" "-1" ""
DoneAbort:
  Abort
Done:
  Pop $1
  Pop $0
FunctionEnd

;Function debug
;   MessageBox MB_OK "$INSTDIR $\n$APPDATA"
;FunctionEnd
