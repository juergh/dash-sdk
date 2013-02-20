
SUBDIRS = include

INCLUDES = -Iinclude/
INCLUDES += -I$(top_srcdir)/dash_client_lib/include
INCLUDES += -I$(top_srcdir)/dash_client_lib/include/cim
INCLUDES += -I$(top_srcdir)/dash_client_lib/source/common 
INCLUDES += -Isource/client/
INCLUDES += -Isource/common/
INCLUDES += -Isource/cim
INCLUDES += -I$(top_srcdir)/cim_client_lib/include/
INCLUDES += -I$(top_srcdir)/cim_client_lib/include/cmci
INCLUDES += -I$(top_srcdir)/cim_client_lib/wsman/include
INCLUDES += -I$(DESTDIR)$(PREFIX)/include
INCLUDES += -I$(top_srcdir)/libs/vmedia/include
INCLUDES += -DDSDK_Export= -Wall

lib_LTLIBRARIES = libdashapic.la

libdashapic_la_LIBADD = $(top_srcdir)/dash_client_lib/libdashapi.la

libdashapic_la_SOURCES = source/dsdk_c.cpp	\
			 source/bootconfig_c.cpp		\
			 source/cimmap_c.cpp			\
			 source/computersystem_c.cpp		\
			 source/fan_c.cpp			\
			 source/physicalasset_c.cpp		\
			 source/memory_c.cpp		\
			 source/powersupply_c.cpp		\
			 source/processor_c.cpp			\
			 source/sensor_c.cpp			\
			 source/software_c.cpp			\
			 source/subject_c.cpp			\
			 source/user_c.cpp			\
			 source/discoverer_c.cpp		\
			 source/eventsubscribe_c.cpp		\
			 source/eventreceiver_c.cpp		\
			 source/error_c.cpp		        \
                         source/operatingsystem_c.cpp           \
                         source/opaquemanagementdata_c.cpp      \
                         source/biosmanagement_c.cpp		\
			 source/textredirection_c.cpp		\
			 source/usbredirection_c.cpp		\
                         source/battery_c.cpp			\
                         source/networkport_c.cpp		\
                         source/dhcpclient_c.cpp                \
                         source/ipinterface_c.cpp               \
			 source/dnsclient_c.cpp			\
			 source/virtualmedia_c.cpp		\
			 source/registeredprofile_c.cpp	\
			 source/ethernetport_c.cpp	

EXTRA_DIST = windows/dashapic/dashapic.vcproj


