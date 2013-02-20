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


mkdir ..\win32pkg\debug_static

@copy %source_dir%\openwsmanlibD_a.lib        ..\win32pkg\debug_static\.
@copy %source_dir%\eventsinkD_a.lib           ..\win32pkg\debug_static\.
@copy %source_dir%\libxml2D_a.lib             ..\win32pkg\debug_static\.
@copy %source_dir%\wsman_client_libD_a.lib    ..\win32pkg\debug_static\.
@copy %source_dir%\dashapiD_a.lib             ..\win32pkg\debug_static\.
@copy %source_dir%\dashapicD_a.lib            ..\win32pkg\debug_static\.
@copy %source_dir%\dashcli.exe                ..\win32pkg\debug_static\.
@copy %source_dir%\webserver.exe              ..\win32pkg\debug_static\.
@copy %source_dir%\ssl_client.exe             ..\win32pkg\debug_static\.

exit /b 0
