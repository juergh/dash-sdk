SUBDIRS =  init

noinst_DATA = ssleay.cnf openwsman.conf openwsman_client.conf
pamdir = $(sysconfdir)/pam.d
pam_DATA = pam/openwsman
openwsmanconf_DATA = owsmangencert.sh
openwsmanconfdir = $(sysconfdir)/openwsman

EXTRA_DIST = openwsman.conf owsmangencert.sh ssleay.cnf openwsman
CLEANFILES = owsmangencert

