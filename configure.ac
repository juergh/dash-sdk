
AC_INIT([dash-sdk], [1.1.0])
#AC_DISABLE_STATIC
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CXXCPP
AC_AIX
AC_ISC_POSIX
AC_MINIX
AC_HEADER_STDC
AM_PROG_LIBTOOL
AC_PROG_INSTALL
AM_PROG_LEX
AC_PROG_YACC
AC_CONFIG_SUBDIRS([mof2oal/src])
AC_CONFIG_SUBDIRS([libs/openwsman])
AC_CONFIG_SUBDIRS([libs/eventsink])
AC_CONFIG_SUBDIRS([tools/ssl_client])

AC_PROG_LIBTOOL
AM_PATH_PYTHON(2.3)
AC_PROG_SWIG(1.3.21)
SWIG_ENABLE_CXX
SWIG_PYTHON

DASHSDK_PKG=$PACKAGE_NAME
AC_SUBST(DASHSDK_PKG)
 	

#check for gcc version.
echo "Checking for gcc version... "
GCCVER=`(gcc -dumpversion) 2>/dev/null`
GCCVER=`echo $GCCVER | LC_ALL=C sed "s/^@<:@a-zA-Z@:>@*\-//"`
GCCVER=`echo $GCCVER | sed "s/\(@<:@0-9@:>@\)\.\(@<:@0-9@:>@\).*/\1\2/"`
if test $GCCVER -lt 41; then
   echo "gcc version 4.1 or later is required to build DASH SDK, please upgrade your version to 4.1"
   GCCVER=`(gcc -dumpversion) 2>/dev/null`
   echo "Your gcc version is $GCCVER"
   exit 1
fi

#check for openssl-devel package
PKG_CHECK_MODULES(OPENSSL, openssl , opensslpkg="yes", opensslpkg="no")
if test "$opensslpkg" != "yes"; then
    AC_MSG_ERROR([openssl-devel package not found, install openssl-devel package]);
fi


## conditional builds 

#conditional build for unit debug
AC_ARG_ENABLE(builddebug,
[  --enable-builddebug    Build debugs (default=disabled)],
[case "${enableval}" in
  yes) builddebug=true ;;
  no)  builddebug=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-builddebug) ;;
esac],[builddebug=false])
AM_CONDITIONAL([BUILD_DEBUG], [test $builddebug = true])

#conditional build for unit test
AC_ARG_ENABLE(buildtest,
[  --enable-buildtest    Build tests (default=disabled)],
[case "${enableval}" in
  yes) buildtest=true ;;
  no)  buildtest=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-buildtest) ;;
esac],[buildtest=false])
AM_CONDITIONAL([BUILD_TEST], [test $buildtest = true])


AC_CONFIG_FILES([Makefile
		mof2oal/src/Makefile
		libs/Makefile
		tools/Makefile
		cim_client_lib/Makefile
		cim_client_lib/wsman/Makefile
		cim_client_lib/include/Makefile
		cim_client_lib/include/cmci/Makefile
		cim_client_lib/include/cimc/Makefile
		dash_client_lib/Makefile
		dash_client_lib/include/Makefile
		dash_client_libc/Makefile
		dash_client_libc/include/Makefile
		cli/Makefile
		dash-sdk.spec
		dash-sdk.pc
		])
AC_OUTPUT

