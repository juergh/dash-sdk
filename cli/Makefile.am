
SUBDIRS = .


INCLUDES = -I$(DESTDIR)$(PREFIX)/include
INCLUDES += -I$(top_srcdir)/dash_client_lib/include
INCLUDES += -I$(top_srcdir)/cim_client_lib/include

INCLUDES += -DDSDK_Export= -Wall


LIBS = $(top_srcdir)/dash_client_lib/libdashapi.la $(top_srcdir)/cim_client_lib/wsman/libwsmanapi.la -lcurses



bin_PROGRAMS = dashcli
dashcli_SOURCES = 	src/dashcli.cpp		\
			src/discovery.cpp	\
			src/exec.cpp		\
			src/help.cpp		\
			src/raw.cpp		\
			src/indication.cpp	\
			src/targetpath.cpp	\
			src/eventviewer.cpp	

FORCE:

man_MANS  = dashcli.1

EXTRA_DIST = src/*.h windows/dashcli/dashcli.sln\
		windows/dashcli/dashcli.vcproj 	\
		windows/dashcli/svninfo.bat	\
		windows/dashcli/svninfo.exe	\
		dashcli.1
