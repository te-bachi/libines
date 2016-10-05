
dnl ****************************************************************************
dnl * NOT BUILD IN SRC DIR
dnl ****************************************************************************

AC_DEFUN([LIBJAM_CHECK_SRCDIR],[
if test "${srcdir}" = "." ; then
  AC_MSG_ERROR([Building in the source directory is not supported. Use build directory])
fi
])

dnl ****************************************************************************
dnl * PTHREAD + REALTIME EXTENSION
dnl ****************************************************************************
AC_DEFUN([LIBJAM_CHECK_PTHREAD],[
acx_pthread_ok=no

AC_MSG_CHECKING([for the pthreads library])

case "${host_cpu}-${host_os}" in
    *solaris*)
        PTHREAD_LIBS="-lpthread -lrt -ldl -ldemangle"
        CPPFLAGS="-D_REENTRANT $CPPFLAGS"
        ;;
        
    *freebsd*)
        PTHREAD_LIBS="-lpthread"
        CPPFLAGS="-D_THREAD_SAFE $CPPFLAGS"
        ;;
        
    *linux*)
        PTHREAD_LIBS="-rdynamic -lpthread -lrt -ldl"
        CPPFLAGS="-D_REENTRANT -D_THREAD_SAFE -fno-omit-frame-pointer $CPPFLAGS"
        ;;
        
    *)
        echo "cpu: ${host_cpu} os: ${host_os}"
        AC_MSG_ERROR("your system is not supported")
        ;;
esac

save_LIBS="$LIBS"
LIBS="$PTHREAD_LIBS"

AC_TRY_LINK([#include <pthread.h>],
            [pthread_t th; pthread_join(th, 0);
             pthread_attr_init(0); pthread_cleanup_push(0, 0);
             pthread_create(0,0,0,0); pthread_cleanup_pop(0); ],
            [acx_pthread_ok=yes])

LIBS="$save_LIBS"
    
AC_MSG_RESULT($acx_pthread_ok)

if test "x$acx_pthread_ok" = xno; then
    AC_MSG_ERROR("no pthread library found")
fi

AC_SUBST(PTHREAD_LIBS)

])

dnl ****************************************************************************
dnl * RECURSIVE LIBRARY LINK IN SUN COMPILER
dnl ****************************************************************************

AC_DEFUN([LIBJAM_CHECK_RECURSIVE_LIBRARY_QUIRK],[

AC_MSG_CHECKING([if Sun Compiler Suite is used])

if test "$CC" = "cc"; then
    if test "$CXX" = "CC"; then
        AC_MSG_RESULT([yes])
        
        LDFLAGS="$LDFLAGS -xildoff -z rescan"
        CXXFLAGS="$CXXFLAGS +w"
    else
        AC_MSG_RESULT([no])
    fi
else
    AC_MSG_RESULT([no])
fi
])

dnl ****************************************************************************
dnl * DEBUG INFO
dnl ****************************************************************************

AC_DEFUN([LIBJAM_CHECK_DEBUG_INFO],[
AC_ARG_WITH(debug,
[  --with-debug            enable debug info @<:@default=no@:>@],
[   with_debug=$withval;   ],
[   with_debug=no;	   ])

AC_MSG_CHECKING([if debug is enabled])
AC_MSG_RESULT($with_debug)

if test x$with_debug = xno; then
   CFLAGS="`echo $CFLAGS | sed 's/-g//'`"
   CXXFLAGS="`echo $CXXFLAGS | sed 's/-g//'`"
fi

if test x$with_debug = xyes; then
   if test x$GCC = xyes; then
      CFLAGS="`echo $CFLAGS | sed 's/-g/-ggdb/'`"
   fi
   
   if test x$GXX = xyes; then
      CXXFLAGS="`echo $CXXFLAGS | sed 's/-g/-ggdb/'`"
   fi
   
   CFLAGS="`echo $CFLAGS | sed 's/-O[[0-9]]//'`"
   CXXFLAGS="`echo $CXXFLAGS | sed 's/-O[[0-9]]//'`"
fi

if test x$GCC = xyes; then
   CFLAGS="$CFLAGS -Wall"
fi

if test x$GXX = xyes; then
   CXXFLAGS="$CXXFLAGS -std=gnu++11 -fpermissive -Wall -Wwrite-strings -Woverloaded-virtual"
fi
])

dnl ****************************************************************************
dnl * DEBUG TEXT
dnl ****************************************************************************

AC_DEFUN([LIBJAM_CHECK_DEBUG_TEXT],[
AC_ARG_WITH(debug_text,
[  --with-debug-text       enable debug-text @<:@default=no@:>@],
[   with_debug_text=$withval;   ],
[   with_debug_text=no;	   ])

AC_MSG_CHECKING([if debug-text is enabled])
AC_MSG_RESULT($with_debug_text)

DEBUG_FLAG=""

if test x$with_debug_text = xyes; then
   DEBUG_FLAG="-D__DEBUG__"
fi

AC_SUBST(DEBUG_FLAG)
])

