@echo off
setlocal
IF EXIST ..\..\src\version.h DEL ..\..\src\version.h
COPY ..\..\src\version.dummy.h ..\..\src\version.h
cd ..\..\..\
SubWCRev.exe  . cli\src\version.h cli\src\version.h
endlocal