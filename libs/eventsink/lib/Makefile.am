AM_CFLAGS = @CFLAGS@
SUBDIRS = .

CFLAGS = \
       $(OPENWSMAN_CFLAGS)


libwseventlistener_la_SOURCES = \
	shttpd.h \
	shttpd.c \
	eventlistener.h \
	eventlistener.c

libwseventlistener_la_LIBADD = $(OPENWSMAN_LIBS) -lpthread

lib_LTLIBRARIES = libwseventlistener.la