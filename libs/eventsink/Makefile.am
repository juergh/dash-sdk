
SUBDIRS = 

OPENWSMAN_INCLUDE = $(top_srcdir)/../openwsman
INCLUDES = -Iinclude -Ilib -Iserver
INCLUDES += -I$(OPENWSMAN_INCLUDE)/include -DBUILD_AS_LIB


lib_LTLIBRARIES = libwseventsink.la
#libwseventsink_la_SOURCES = lib/eventlistener.c lib/shttpd.c server/eventsink.c
libwseventsink_la_SOURCES = lib/eventlistener.c lib/mongoose.c server/eventsink.c

EXTRA_DIST = 	include/*.h 				\
		lib/*.h lib/*.c				\
		server/*.c				\
		windows/eventsink/eventsink.vcproj	\
		windows/eventsink/eventsink.sln		\
		windows/eventsink/eventsink.suo



