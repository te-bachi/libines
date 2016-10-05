SUBDIRS = \
    lang \
    io \
    util \
    text

lib_LTLIBRARIES = \
    libjam.la

libjam_la_SOURCES =

libjam_la_LIBADD = \
    $(top_builddir)/src/lang/liblang.la \
    $(top_builddir)/src/io/libio.la \
    $(top_builddir)/src/util/libutil.la \
    $(top_builddir)/src/util/locale/liblocale.la \
    $(top_builddir)/src/util/sort/libsort.la \
    $(top_builddir)/src/util/time/libtime.la \
    $(top_builddir)/src/text/libtext.la

libjam_la_LDFLAGS = \
    -version-info $(VERSION)

libjam_la_includedir = \
    $(includedir)/jam

libjam_la_include_HEADERS = \
    $(top_srcdir)/include/jam/Global.hxx

bin_PROGRAMS = \
    test
    
test_SOURCES = \
    main.cxx

test_LDADD = \
    libjam.la \
    $(PTHREAD_LIBS) \
    $(ORACLE_LIBS)

test_LDFLAGS = \
    $(ORACLE_LDFLAGS)

test_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)
