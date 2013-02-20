
SUBDIRS = .

OPENWSMAN_DIR = $(top_srcdir)/libs/openwsman
INCLUDES = -Iinclude -I../include -I../include/cmci -I../include/cimc
INCLUDES += -I$(DESTDIR)$(PREFIX)/include
INCLUDES += -I$(OPENWSMAN_DIR)/include -I$(OPENWSMAN_DIR)/include/u -I$(top_srcdir)/libs/eventsink/include
INCLUDES += -I$(top_srcdir)/cim_client_lib/wsman/src/utils
INCLUDES += -Wall
if BUILD_DEBUG
INCLUDES += -D_DEBUG
endif

INCLUDES += -DENABLE_RMCP_PING

lib_LTLIBRARIES = libwsmanapi.la

libwsmanapi_la_LIBADD = $(OPENWSMAN_DIR)/src/lib/libwsman.la $(top_srcdir)/libs/eventsink/libwseventsink.la

libwsmanapi_la_SOURCES = src/args.c src/array.c src/cimcclient.c src/client.c src/constClass.c 	\
				src/datetime.c src/enumeration.c src/genericlist.c src/instance.c 	\
				src/objectpath.c src/property.c src/qualifier.c src/string.c src/value.c \
				src/dashping.c src/wsmanidentify.c


EXTRA_DIST =  	src/*.h src/*.c src/utils/*.c src/utils/*.h \
		windows/win32port.h 					\
		windows/wsman_client_lib/wsman_client_lib.sln 		\
		windows/wsman_client_lib/wsman_client_lib.vcproj



