
SUBDIRS = 	libs 				\
		mof2oal/src			\
		tools				\
		cim_client_lib 			\
		dash_client_lib 		\
		dash_client_libc 		\
		cli 					\
		webserver

RPMDIR   = rpmbuild

AUTOMAKE_OPTIONS = dist-zip

package: dist
	mkdir -p $(RPMDIR)/{BUILD,RPMS,SRPMS,SOURCES,SPECS,tmp}
	cp dash-sdk.spec $(RPMDIR)/SPEC
	cp dash-sdk-*.tar.gz $(RPMDIR)/SOURCES
	rpmbuild -ba --define="_topdir `pwd`/rpmbuild" dash-sdk.spec

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = dash-sdk.pc


EXTRA_DIST = docs/*.dox					\
		windows/dash/dash.sln			\
		windows/dash/dash.vcproj		\
		windows/dash/debugpkg.bat		\
		windows/dash/releasepkg.bat		\
		windows/dash/debugstaticpkg.bat		\
		windows/dash/releasestaticpkg.bat	\
		doxyfile				\
		dashsdk.css

