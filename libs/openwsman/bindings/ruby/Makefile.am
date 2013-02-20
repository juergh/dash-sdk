#
# Makefile.am for openwsman/bindings/ruby
#

SUBDIRS = openwsman tests
rubyarchdir = $(shell ruby -r rbconfig -e "vad = Config::CONFIG['vendorarchdir']; print(vad ? vad : Config::CONFIG['sitearchdir'])")
rubydir = $(shell ruby -r rbconfig -e "print Config::CONFIG['sitearchdir']")
rubyincdir = $(shell ruby -r rbconfig -e "print(Config::CONFIG['archdir'])")

INCLUDES =  \
           -I$(top_srcdir) \
	   -I$(top_srcdir)/include \
	   -I$(top_srcdir)/bindings \
	    $(OPENSSL_CFLAGS) \
	   -DSYSCONFDIR=\""$(sysconfdir)/openwsman"\" \
	   -I${rbincdir}

LDADD = \
       ${rbldadd}       

LIBS = \
       $(OPENSSL_LIBS) \
       $(top_builddir)/src/lib/libwsman.la \
       $(top_builddir)/src/lib/libwsman_client.la \
       $(top_builddir)/src/lib/libwsman_curl_client_transport.la


GENERATED = openwsman_wrap.c \
	    rbwsman.rb
SWIG_SOURCES = ../openwsman.i
rbwsman_la_SOURCES = openwsman_wrap.c \
			 $(SWIG_SOURCES)


rbwsman_la_LIBADD = $(LIBS) -lpthread $(CURL_LIBS)

rbwsman_la_CFLAGS = $(RUBY_CFLAGS)

rbwsman_la_LDFLAGS = -module -avoid-version $(NO_UNDEFINED)

ruby_LTLIBRARIES = rbwsman.la

openwsman_wrap.c: $(SWIG_SOURCES)
	$(SWIG) -ruby -I$(top_srcdir)/include -o $@ $<

install-data-hook:
	rm -f $(DESTDIR)${rubydir}/$(ruby_LTLIBRARIES)

CLEANFILES= $(GENERATED)

dist-hook:
	rm -f $(distdir)/openwsman_wrap.c

EXTRA_DIST=helpers.c
