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



mkdir ..\win32pkg\debug

@copy %source_dir%\openwsmanlibD.lib          ..\win32pkg\debug\.
@copy %source_dir%\eventsinkD.lib             ..\win32pkg\debug\.
@copy %source_dir%\eventsinkD.dll             ..\win32pkg\debug\.
@copy %source_dir%\libxml2D.lib               ..\win32pkg\debug\.
@copy %source_dir%\libxml2D.dll               ..\win32pkg\debug\.
@copy %source_dir%\wsman_client_libD.lib      ..\win32pkg\debug\.
@copy %source_dir%\wsman_client_libD.dll      ..\win32pkg\debug\.
@copy %source_dir%\dashapiD.lib               ..\win32pkg\debug\.
@copy %source_dir%\dashapiD.dll               ..\win32pkg\debug\.
@copy %source_dir%\dashapicD.lib              ..\win32pkg\debug\.
@copy %source_dir%\dashapicD.dll              ..\win32pkg\debug\.
@copy %source_dir%\dashcli.exe                ..\win32pkg\debug\.
@copy %source_dir%\webserver.exe              ..\win32pkg\debug\.
@copy %source_dir%\ssl_client.exe             ..\win32pkg\debug\.

exit /b 0
