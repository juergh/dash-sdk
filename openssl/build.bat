@ECHO off
SETLOCAL 
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
    ECHO.
    GOTO end
  ) ELSE IF "%arg1:~1,1%"=="?" (
    CALL :usage %0
    GOTO end
  ) ELSE (
    CALL :usage %0
    GOTO error
  )
)

SET cfg=%2

IF [%cfg%]==[] GOTO no_cfg

SET cfg=%cfg:"=%
SET cfg=%cfg:"=%
SET cfg=%cfg:A=a%
SET cfg=%cfg:B=b%
SET cfg=%cfg:C=c%
SET cfg=%cfg:D=d%
SET cfg=%cfg:E=e%
SET cfg=%cfg:F=f%
SET cfg=%cfg:G=g%
SET cfg=%cfg:H=h%
SET cfg=%cfg:I=i%
SET cfg=%cfg:J=j%
SET cfg=%cfg:K=k%
SET cfg=%cfg:L=l%
SET cfg=%cfg:M=m%
SET cfg=%cfg:N=n%
SET cfg=%cfg:O=o%
SET cfg=%cfg:P=p%
SET cfg=%cfg:Q=q%
SET cfg=%cfg:R=r%
SET cfg=%cfg:S=s%
SET cfg=%cfg:T=t%
SET cfg=%cfg:U=u%
SET cfg=%cfg:V=v%
SET cfg=%cfg:W=w%
SET cfg=%cfg:X=x%
SET cfg=%cfg:Y=y%
SET cfg=%cfg:Z=z%
SET cfg=%cfg: =_%

:no_cfg

rem determine which configuration to build/clean
IF [%cfg%]==[] (
    SET need_build_debug_static=1
    SET need_build_debug_dll=1
    SET need_build_release_static=1
    SET need_build_release_dll=1
) ELSE IF [%cfg%]==[all] (
    SET need_build_debug_static=1
    SET need_build_debug_dll=1
    SET need_build_release_static=1
    SET need_build_release_dll=1
) ELSE IF [%cfg%]==[debug] (
    SET need_build_debug_static=0
    SET need_build_debug_dll=1
    SET need_build_release_static=0
    SET need_build_release_dll=0
) ELSE IF [%cfg%]==[release] (
    SET need_build_debug_static=0
    SET need_build_debug_dll=0
    SET need_build_release_static=0
    SET need_build_release_dll=1
) ELSE IF [%cfg%]==[debug_static] (
    SET need_build_debug_static=1
    SET need_build_debug_dll=0
    SET need_build_release_static=0
    SET need_build_release_dll=0
) ELSE IF [%cfg%]==[release_static] (
    SET need_build_debug_static=0
    SET need_build_debug_dll=0
    SET need_build_release_static=1
    SET need_build_release_dll=0
) ELSE (
    ECHO Wrong build type %2!
    GOTO error
)

rem determine what to do
IF [%1]==[] (
    GOTO do_build
) ELSE IF [%1]==[build] (
    GOTO do_build
) ELSE IF [%1]==[clean] (
    GOTO do_cleanonly
) ELSE IF [%1]==[cleanbuild] (
    GOTO do_cleanbuild
) ELSE IF [%1]==[buildifneeded] (
    GOTO do_buildifneeded
) ELSE (
    ECHO Unknown command %1!
    GOTO error
)

:do_cleanbuild
CALL :do_clean
GOTO do_build

:do_cleanonly
CALL :do_clean
GOTO end

:do_buildifneeded
IF [%need_build_release_dll%]==[1] (
    IF not exist out32dll\libeay32MD.dll GOTO do_build
    IF not exist out32dll\libeay32MD.lib GOTO do_build
    IF not exist out32dll\ssleay32MD.dll GOTO do_build
    IF not exist out32dll\ssleay32MD.lib GOTO do_build
    IF not exist out32dll\openssl.exe GOTO do_build
)

IF [%need_build_debug_dll%]==[1] (
    IF not exist out32dll.dbg\libeay32MDd.dll GOTO do_build
    IF not exist out32dll.dbg\libeay32MDd.lib GOTO do_build
    IF not exist out32dll.dbg\ssleay32MDd.dll GOTO do_build
    IF not exist out32dll.dbg\ssleay32MDd.lib GOTO do_build
    IF not exist out32dll.dbg\openssl.exe GOTO do_build
)

IF [%need_build_release_static%]==[1] (
    IF not exist out32\libeay32MT.lib GOTO do_build
    IF not exist out32\ssleay32MT.lib GOTO do_build
    IF not exist out32\openssl.exe GOTO do_build
)

IF [%need_build_debug_static%]==[1] (
    IF not exist out32.dbg\libeay32MTd.lib GOTO do_build
    IF not exist out32.dbg\ssleay32MTd.lib GOTO do_build
    IF not exist out32.dbg\openssl.exe GOTO do_build
)

rem no build needed
GOTO end

:do_build
rem
rem generate some include files
rem NOTE: please keep these rules up-to-date with changing OpenSSL versions!
rem
perl crypto\bn\bn_prime.pl > crypto\bn\bn_prime.h
perl crypto\objects\objects.pl crypto\objects\objects.txt crypto\objects\obj_mac.num crypto\objects\obj_mac.h
perl crypto\objects\obj_dat.pl crypto\objects\obj_mac.h crypto\objects\obj_dat.h
perl apps\progs.pl verify asn1pars req dgst dh dhparam enc passwd gendh errstr ca crl rsa rsautl dsa dsaparam ec ecparam x509 genrsa gendsa s_server s_client speed s_time version pkcs7 crl2pkcs7 sess_id ciphers nseq pkcs12 pkcs8 spkac smime rand engine ocsp prime > apps\progs.h

rem
rem configure openssl
rem
perl Configure VC-WIN32 no-hw_safenet
IF errorlevel 1 GOTO error

CALL ms\do_masm.bat
IF errorlevel 1 GOTO error

rem
rem build the release dll version of openssl
rem
IF [%need_build_release_dll%]==[1] (
    nmake -f ms\ntdll.mak
    IF errorlevel 1 GOTO error
    
    nmake -f ms\ntdll.mak test
    IF errorlevel 1 GOTO error
)

rem
rem build the debug dll version of openssl
rem
IF [%need_build_debug_dll%]==[1] (
    nmake -f ms\ntdll_debug.mak
    IF errorlevel 1 GOTO error
    
    nmake -f ms\ntdll_debug.mak test
    IF errorlevel 1 GOTO error
)

rem
rem build the release static version of openssl
rem
IF [%need_build_release_static%]==[1] (
    nmake -f ms\nt.mak
    IF errorlevel 1 GOTO error
    
    nmake -f ms\nt.mak test
    IF errorlevel 1 GOTO error
)

rem
rem build the debug static version of openssl
rem
IF [%need_build_debug_static%]==[1] (
    nmake -f ms\nt_debug.mak
    IF errorlevel 1 GOTO error
    
    nmake -f ms\nt_debug.mak test
    IF errorlevel 1 GOTO error
)

rem
rem install the openssl files
rem
IF NOT EXIST ..\install_root MD ..\install_root

IF NOT EXIST ..\install_root\include MD ..\install_root\include
IF NOT EXIST ..\install_root\include\openssl MD ..\install_root\include\openssl
COPY inc32\openssl\*.c ..\install_root\include\openssl
COPY inc32\openssl\*.h ..\install_root\include\openssl

IF [%need_build_release_dll%]==[1] (
    IF NOT EXIST ..\install_root\release MD ..\install_root\release
    COPY out32dll\libeay32MD.dll ..\install_root\release
    COPY out32dll\libeay32MD.lib ..\install_root\release
    COPY out32dll\ssleay32MD.dll ..\install_root\release
    COPY out32dll\ssleay32MD.lib ..\install_root\release
    COPY out32dll\openssl.exe ..\install_root\release
)

IF [%need_build_debug_dll%]==[1] (
    IF NOT EXIST ..\install_root\debug MD ..\install_root\debug
    COPY out32dll.dbg\libeay32MDd.dll ..\install_root\debug
    COPY out32dll.dbg\libeay32MDd.lib ..\install_root\debug
    COPY out32dll.dbg\ssleay32MDd.dll ..\install_root\debug
    COPY out32dll.dbg\ssleay32MDd.lib ..\install_root\debug
    COPY out32dll.dbg\openssl.exe ..\install_root\debug
)

IF [%need_build_release_static%]==[1] (
    IF NOT EXIST "..\install_root\release static" MD "..\install_root\release static"
    COPY out32\libeay32MT.lib "..\install_root\release static"
    COPY out32\ssleay32MT.lib "..\install_root\release static"
    COPY out32\openssl.exe "..\install_root\release static"
)

IF [%need_build_debug_static%]==[1] (
    IF NOT EXIST "..\install_root\debug static" MD "..\install_root\debug static"
    COPY out32.dbg\libeay32MTd.lib "..\install_root\debug static"
    COPY out32.dbg\ssleay32MTd.lib "..\install_root\debug static"
    COPY out32.dbg\openssl.exe "..\install_root\debug static"
)

ECHO Successfully built OpenSSL library
GOTO end


:do_clean

IF [%need_build_release_dll%]==[1] (
    DEL /f /q out32dll\*.*
    RD out32dll
    DEL /f /q tmp32dll\*.*
    RD tmp32dll
)

IF [%need_build_debug_dll%]==[1] (
    DEL /f /q out32dll.dbg\*.*
    RD out32dll.dbg
    DEL /f /q tmp32dll.dbg\*.*
    RD tmp32dll.dbg
)

IF [%need_build_release_static%]==[1] (
    DEL /f /q out32\*.*
    RD out32
    DEL /f /q tmp32\*.*
    RD tmp32
)

IF [%need_build_debug_static%]==[1] (
    DEL /f /q out32.dbg\*.*
    RD out32.dbg
    DEL /f /q tmp32.dbg\*.*
    RD tmp32.dbg
)

GOTO :EOF

:error
ECHO Error^^! Could not build OpenSSL^^!
ENDLOCAL
EXIT /B 1

:end
ENDLOCAL
EXIT /B 0