
SUBDIRS = include

INCLUDES = -Iinclude/
INCLUDES += -Isource/client/
INCLUDES += -Isource/common/
INCLUDES += -Isource/cim
INCLUDES += -I$(top_srcdir)/cim_client_lib/include
INCLUDES += -I$(top_srcdir)/cim_client_lib/include/cimc 
INCLUDES += -I$(top_srcdir)/cim_client_lib/include/cmci 
INCLUDES += -I$(top_srcdir)/cim_client_lib/wsman/include
INCLUDES += -I$(top_srcdir)/dash_client_li/include/
INCLUDES += -DDSDK_Export= -Wall

if BUILD_DEBUG
INCLUDES += -D_DEBUG
endif

lib_LTLIBRARIES = libdashapi.la

libdashapi_la_LIBADD = $(top_srcdir)/cim_client_lib/wsman/libwsmanapi.la -lstdc++

libdashapi_la_SOURCES =	source/common/dsdk.cpp			\
			source/cim/cimargument.cpp 		\
			source/cim/cimarray.cpp 		\
			source/cim/cimconstclass.cpp		\
			source/cim/cimdata.cpp			\
			source/cim/cimdatetime.cpp		\
			source/cim/cimenumeration.cpp		\
			source/cim/ciminstance.cpp		\
			source/cim/cimobjectpath.cpp		\
			source/cim/cimstring.cpp		\
			source/cim/cimvalue.cpp			\
			source/cim/cimclasskeys.cpp		\
			source/client/sfccclient.cpp		\
			source/api/cimmap.cpp			\
			source/api/subject.cpp			\
			source/api/errorcode.c			\
			source/api/discoverer.cpp		\
			source/api/enumerator.cpp		\
			source/api/computersystem.cpp		\
			source/api/fan.cpp			\
			source/api/physicalasset.cpp		\
			source/api/memory.cpp			\
			source/api/powersupply.cpp		\
			source/api/processor.cpp		\
			source/api/sensor.cpp			\
			source/api/software.cpp			\
			source/api/operatingsystem.cpp		\
			source/api/bootconfig.cpp		\
			source/api/biosmanagement.cpp		\
			source/api/user.cpp			\
			source/api/privilege.cpp  		\
			source/api/textredirection.cpp		\
			source/api/usbredirection.cpp		\
			source/api/opaquemanagementdata.cpp	\
			source/api/eventreceiver.cpp		\
			source/api/eventsubscribe.cpp		\
			source/api/battery.cpp			\
                        source/api/networkport.cpp		\
                        source/api/dhcpclient.cpp               \
                        source/api/ipinterface.cpp              \
			source/api/dnsclient.cpp       	 	\
			source/api/registeredprofile.cpp	\
			source/api/ethernetport.cpp		\
			source/api/indications.cpp		\
			source/api/cimcapabilities.cpp


nodist_libdashapi_la_SOURCES =  $(top_srcdir)/dash_client_lib/include/dsdk/oal/CIM_ManagedElement.h
BUILT_SOURCES =  $(top_srcdir)/dash_client_lib/include/dsdk/oal/CIM_ManagedElement.h
CLEANFILES =  $(top_srcdir)/dash_client_lib/include/dsdk/oal/*.h

$(top_srcdir)/dash_client_lib/include/dsdk/oal/CIM_ManagedElement.h : Makefile
	echo Building oal header files.....
	-test -d "$(top_srcdir)/dash_client_lib/include/dsdk/oal" || mkdir -p $(top_srcdir)/dash_client_lib/include/dsdk/oal
	cp $(top_srcdir)/dash_client_lib/source/common/COALObject.h $(top_srcdir)/dash_client_lib/include/dsdk/oal
	$(top_srcdir)/mof2oal/src/mof2oal -m $(top_srcdir)/cim_mof/DRI_Schema.mof -o $(top_srcdir)/dash_client_lib/include/dsdk/oal -s $(top_srcdir)/mof2oal/skel/mof2cpp -w -b $(top_srcdir)/classblacklist.txt
	echo OAL header files generated


EXTRA_DIST = source/api/* 	\
		source/client/* 	\
		source/common/* 	\
		source/makeoal.bat 	\
		windows/dashapi/dashapi.sln	\
		windows/dashapi/dashapi.vcproj


