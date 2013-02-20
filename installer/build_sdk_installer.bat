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

@ECHO off
SETLOCAL EnableDelayedExpansion
GOTO main

:usage
REM DESC: displays usage message redirected to stderr.
REM arg1: name of or path to batch file.

ECHO Usage: >&2
ECHO.>&2
REM HINT: shows name and extension of the file specified by arg1
ECHO   %~nx1 [^<command^>^|^<build command^>]>&2
ECHO.>&2
ECHO.  possible commands:>&2
ECHO.       -?  ..................... display this help.>&2
ECHO.       -d  ..................... show dependencies.>&2
ECHO.  possible build commands:>&2
ECHO.       build [debug^|release] ... start building under debug/release mode.>&2
ECHO.       clean [debug^|release] ... clean solution under debug/release mode.>&2
ECHO.                                 build release are the default options if any
ECHO.                                 commands are omitted.>&2
ECHO.>&2

GOTO :EOF

:build_release
REM DESC: starts build process in release mode.
call patchDashSdkInstaller.bat .
makensis -DPath=".." dash_sdk.nsi
GOTO :EOF

:build_debug
REM DESC: starts build process in debug mode.
call patchDashSdkInstaller.bat .
makensis -DPath=".." dash_sdk.nsi
GOTO :EOF

:clean_release
REM DESC: cleans solution under release mode.
DEL /F libdashsdk-setup*.exe
GOTO :EOF

:clean_debug
REM DESC: cleans solution under debug mode.
DEL /F libdashsdk-setup*.exe
GOTO :EOF

:end
ENDLOCAL
EXIT /B 0

:error
ENDLOCAL
EXIT /B 1

:main

SET bcmd=build
SET mode=release

SET arg1=%1
SET arg2=%2
REM if the right value was empty the errorlevel will be set to value 1. the
REM following line will reset the errorlevel (in a dirty manner).
IF ERRORLEVEL 1 CD>NUL

IF "%arg1:~0,1%"=="-" (
  REM command switch handling.
  IF "%arg1:~1,1%"=="d" (
    REM ECHO.dependency_dirs
    ECHO.dashsdk
    GOTO end
  ) ELSE IF "%arg1:~1,1%"=="?" (
    CALL :usage %0
    GOTO end
  ) ELSE (
    CALL :usage %0
    GOTO error
  )
) ELSE (
  REM checks whether build or clean process is desired
  IF "%arg1%" == "build" (
    SET bcmd=build
  ) ELSE IF "%arg1%" == "clean" (
    SET bcmd=clean
  ) ELSE IF NOT "%arg1%" == "" (
    CALL :usage %0
    GOTO error
  )
  
  REM checks whether release or debug mode is desired
  IF "%arg2%" == "release" (
    SET mode=release
  ) ELSE IF "%arg2%" == "debug" (
    SET mode=debug
  ) ELSE IF NOT "%arg2%" == "" (
    CALL :usage %0
    GOTO error
  )
)

REM build commands
CALL :%bcmd%_%mode%
IF ERRORLEVEL 1 GOTO error

GOTO end
