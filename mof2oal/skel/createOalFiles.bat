@echo off
setlocal

IF "%1" == ""       GOTO outer

set cfg=%2
if [%cfg%]==[] set cfg=Release
set cfg=%cfg:"=%


set p=%1
echo Creating OAL Files: %p%
echo.
IF NOT EXIST %p%\dashsdk4cs\wrapperCpp GOTO cppdirnotfound
IF NOT EXIST %p%\dashsdk4cs\wrapperCsharp\src GOTO csdirnotfound


IF EXIST %p%\dashsdk4cs\wrapperCpp\src\include GOTO step2
mkdir %p%\dashsdk4cs\wrapperCpp\src\include
:step2
IF EXIST %p%\dashsdk4cs\wrapperCpp\src\include\oaldll GOTO step3
mkdir %p%\dashsdk4cs\wrapperCpp\src\include\oaldll
:step3

%p%\install_root\%cfg%\mof2oal -oaldll -w -s %p%\mof2oal\skel\mof2oaldll -m %p%\cim_mof\DRI_Schema.mof -o %p%\dashsdk4cs\wrapperCpp\src\include\oaldll\ -b %p%\dashsdk\classblacklist.txt -cf %p%\dashsdk4cs\wrapperCpp\src\cimfactory.cpp
%p%\install_root\%cfg%\mof2oal -oalcs  -w -s %p%\mof2oal\skel\mof2oalcs -m %p%\cim_mof\DRI_Schema.mof -o %p%\dashsdk4cs\wrapperCsharp\src -b %p%\dashsdk\classblacklist.txt
GOTO exit

:csdirnotfound
echo wrapperCsharp folder not found!
GOTO exit

:cppdirnotfound
echo wrapperCpp folder not found!
GOTO exit

:outer
echo Let only Visual Studio call this one!

:exit
endlocal
