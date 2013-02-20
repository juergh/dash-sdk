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

!include EnvVarUpdate.nsh
!include LogicLib.nsh

!macro Putty EXE EXE_URL EXE_INST_CMD EXE_INST_DEST EXE_ADD_TO_PATH

  Push $0
  Push $1
  Push $2
  Push $3
 
#  ExecWait '${EXE}' $0
#  DetailPrint "Returned $0."
#  ${If} $0 != 0
  	DetailPrint "The third party software ${EXE} is required for this program to run."
    MessageBox MB_YESNOCANCEL|MB_ICONEXCLAMATION \
    "The third party software ${EXE} is required for this program to run.$\n \
    $\n \
    Download ${EXE}?$\n \
    $\n \
    Please note that otherwise you have to download the tool and set the $\n \
    PATH variable manually." \
    /SD IDYES IDYES DownloadEXE IDNO DoneEXE
#  ${EndIf}
  goto DoneEXE
 
DownloadEXE:
  DetailPrint "Beginning download of ${EXE}."

  inetc::get /caption "${EXE} Download" "${EXE_URL}" "$TEMP\${EXE}" /end
  DetailPrint "Completed download."
  Pop $0
  ${If} $0 == "Cancelled"
    MessageBox MB_YESNO|MB_ICONEXCLAMATION \
    "Download cancelled.  Continue Installation?" \
    IDYES DoneEXE IDNO GiveUpEXE
  ${ElseIf} $0 != "OK"
    MessageBox MB_YESNO|MB_ICONEXCLAMATION \
    "Download failed:$\n$0$\n$\nContinue Installation?" \
    IDYES DoneEXE IDNO GiveUpEXE
  ${EndIf}
  ${If} "${EXE_INST_CMD}" != ""
		DetailPrint "Pausing installation while installing ${EXE}."
		ExecWait 'cmd /c mkdir $\"${EXE_INST_DEST}$\"'
		ExecWait 'cmd /c ${EXE_INST_CMD}'
		DetailPrint "Completed."
  ${EndIf}
  Delete "$TEMP\${EXE}"
  DetailPrint "${EXE} removed."
  ${If} "${EXE_ADD_TO_PATH}" == "yes"
    ${If} $MultiUser.InstallMode == "AllUsers"
			${EnvVarUpdate} $0 "PATH" "A" "HKLM" "${EXE_INST_DEST}"
    ${Else}
			${EnvVarUpdate} $0 "PATH" "A" "HKCU" "${EXE_INST_DEST}"
    ${EndIf}
    DetailPrint "Added '${EXE_INST_DEST}' to PATH env variable."
  ${EndIf}

  goto DoneEXE
 
GiveUpEXE:
  Abort "Installation cancelled by user."
 
DoneEXE:
  DetailPrint "Proceeding with remainder of installation."
  Pop $3
  Pop $2
  Pop $1
  Pop $0
!macroend

!define mStrLoc "!insertmacro StrLoc"
 
!macro StrLoc ResultVar String SubString StartPoint
  Push "${String}"
  Push "${SubString}"
  Push "${StartPoint}"
  Call StrLoc
  Pop "${ResultVar}"
!macroend
 
Function StrLoc
/*After this point:
  ------------------------------------------
   $R0 = StartPoint (input)
   $R1 = SubString (input)
   $R2 = String (input)
   $R3 = SubStringLen (temp)
   $R4 = StrLen (temp)
   $R5 = StartCharPos (temp)
   $R6 = TempStr (temp)*/
 
  ;Get input from user
  Exch $R0
  Exch
  Exch $R1
  Exch 2
  Exch $R2
  Push $R3
  Push $R4
  Push $R5
  Push $R6
 
  ;Get "String" and "SubString" length
  StrLen $R3 $R1
  StrLen $R4 $R2
  ;Start "StartCharPos" counter
  StrCpy $R5 0
 
  ;Loop until "SubString" is found or "String" reaches its end
  ${Do}
    ;Remove everything before and after the searched part ("TempStr")
    StrCpy $R6 $R2 $R3 $R5
 
    ;Compare "TempStr" with "SubString"
    ${If} $R6 == $R1
      ${If} $R0 == `<`
        IntOp $R6 $R3 + $R5
        IntOp $R0 $R4 - $R6
      ${Else}
        StrCpy $R0 $R5
      ${EndIf}
      ${ExitDo}
    ${EndIf}
    ;If not "SubString", this could be "String"'s end
    ${If} $R5 >= $R4
      StrCpy $R0 ``
      ${ExitDo}
    ${EndIf}
    ;If not, continue the loop
    IntOp $R5 $R5 + 1
  ${Loop}
 
  ;Return output to user
  Pop $R6
  Pop $R5
  Pop $R4
  Pop $R3
  Pop $R2
  Exch
  Pop $R1
  Exch $R0
FunctionEnd