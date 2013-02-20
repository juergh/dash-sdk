@SET source_dir=.

if [%1]==[] goto nodir
@SET source_dir=%1
:nodir

@mkdir ..\win32pkg

@mkdir ..\win32pkg\include
ECHO .svn > __excludes__
@xcopy /EXCLUDE:__excludes__ /Y /S /I ..\..\install_root\include\dsdk        ..\win32pkg\include\dsdk
@xcopy /EXCLUDE:__excludes__ /Y /S /I ..\..\install_root\include\dsdkc       ..\win32pkg\include\dsdkc
@xcopy /EXCLUDE:__excludes__ /Y /S /I ..\..\install_root\include\cimc        ..\win32pkg\include\cimc
@xcopy /EXCLUDE:__excludes__ /Y /S /I ..\..\install_root\include\cmci        ..\win32pkg\include\cmci
@xcopy /EXCLUDE:__excludes__ /Y /S /I ..\..\install_root\include\wsman       ..\win32pkg\include\wsman


mkdir ..\win32pkg\release

@copy %source_dir%\openwsmanlib.lib           ..\win32pkg\release\.
@copy %source_dir%\eventsink.lib              ..\win32pkg\release\.
@copy %source_dir%\eventsink.dll              ..\win32pkg\release\.
@copy %source_dir%\libxml2.lib                ..\win32pkg\release\.
@copy %source_dir%\libxml2.dll                ..\win32pkg\release\.
@copy %source_dir%\wsman_client_lib.lib       ..\win32pkg\release\.
@copy %source_dir%\wsman_client_lib.dll       ..\win32pkg\release\.
@copy %source_dir%\dashapi.lib                ..\win32pkg\release\.
@copy %source_dir%\dashapi.dll                ..\win32pkg\release\.
@copy %source_dir%\dashapiC.lib               ..\win32pkg\release\.
@copy %source_dir%\dashapiC.dll               ..\win32pkg\release\.
@copy %source_dir%\dashcli.exe                ..\win32pkg\release\.
@copy %source_dir%\webserver.exe              ..\win32pkg\release\.
@copy %source_dir%\ssl_client.exe             ..\win32pkg\release\.


exit /b 0
