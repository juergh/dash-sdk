@echo off
setlocal
set old_dir=%cd%
cd ..\..\installer
call build_sdk_installer.bat
cd %old_dir%
endlocal
