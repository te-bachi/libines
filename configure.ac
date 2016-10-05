AC_INIT([libines], [0.5], [bacr@zhaw.ch], [libInES C++ Library])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS(config/config.h)

PACKAGE=libjam
VERSION=1:0:0

if test "${srcdir}" = "." ; then
  AC_MSG_ERROR([Building in the source directory is not supported. Use build directory])
fi

AM_INIT_AUTOMAKE($PACKAGE,$VERSION)
AM_MAINTAINER_MODE

AC_DISABLE_FAST_INSTALL
AC_DISABLE_STATIC

AC_PROG_CXX
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

echo " "
echo "*** LIBJAM CHECKING ***"
echo " "

LIBJAM_CHECK_SRCDIR
LIBJAM_CHECK_PTHREAD
LIBJAM_CHECK_RECURSIVE_LIBRARY_QUIRK
LIBJAM_CHECK_DEBUG_INFO
LIBJAM_CHECK_DEBUG_TEXT

echo " "

AC_CONFIG_COMMANDS([default],[[ echo timestamp > stamp-h ]],[[]])

AC_OUTPUT([Makefile
           src/Makefile
           src/lang/Makefile
           src/io/Makefile
           src/util/Makefile
           src/util/locale/Makefile
           src/util/log/Makefile
           src/util/sort/Makefile
           src/util/time/Makefile
           src/sql/Makefile
           src/sql/proc/Makefile
           src/text/Makefile])

echo " "
echo " "
echo "          CFLAGS          = $CFLAGS"
echo "          CXXFLAGS        = $CXXFLAGS"
echo "          CPPFLAGS        = $CPPFLAGS"
echo "          LDFLAGS         = $LDFLAGS"
echo "          DEBUG_FLAG      = $DEBUG_FLAG"
echo "          PTHREAD_LIBS    = $PTHREAD_LIBS"
echo " "
echo " "

