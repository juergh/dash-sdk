# This file is part of Mongoose project, http://code.google.com/p/webservice
# $Id: Makefile 433 2009-06-30 12:15:27Z valenok $

PROG=	webservice

all:	linux

# Possible COPT values: (in brackets are rough numbers for 'gcc -O2' on i386)
# -DHAVE_MD5		- use system md5 library (-2kb)
# -DNDEBUG		- strip off all debug code (-5kb)
# -DDEBUG		- build debug version (very noisy) (+7kb)
# -DNO_CGI		- disable CGI support (-5kb)
# -DNO_SSL		- disable SSL functionality (-2kb)
# -DCONFIG_FILE=\"file\" - use `file' as the default config file
# -DNO_SSI		- disable SSI support (-4kb)
# -DHAVE_STRTOUI64	- use system strtoui64() function for strtoull()


##########################################################################
###                 UNIX build: linux, bsd, mac, rtems
##########################################################################

CC=g++
CFLAGS=		-W -Wall
INCLUDES= -I../libs/eventsink/lib
LIB= -lwseventsink -lwsman
LIB_PATH= -L../install_root/lib

linux:
	#$(CC) $(CFLAGS) -I../libs/eventsink/lib  webservice_main.cpp  -o webserver


#linux:
#	$(CC) $(LINFLAGS) webservice.c -shared -fPIC -fpic -s -o $(LIB)
#	$(CC) $(LINFLAGS) webservice.c main.c -s -o $(PROG)

##########################################################################
###            Manuals, cleanup, release
##########################################################################

man:
	cat webserver.1 | tbl | groff -man -Tascii | col -b > webserver.1.txt
	cat webserver.1 | tbl | groff -man -Tascii | less
install:
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_PATH) webservice_main.cpp -o webserver $(LIB)
	mv webserver ../install_root/bin/

release: clean
	rm webserver 
	
clean:
	rm -rf *.o *.core $(PROG) *.obj $(PROG).1.txt *.dSYM *.tgz *.so
