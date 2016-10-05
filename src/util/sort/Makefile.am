SUBDIRS = 

noinst_LTLIBRARIES = \
    libsort.la

libsort_la_SOURCES = \
    Comparator.cxx \
    StringComparator.cxx

libsort_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libsort_la_includedir = \
    $(includedir)/jam/util/sort

libsort_la_include_HEADERS = \
    $(top_srcdir)/include/jam/util/sort/Comparator.hxx \
    $(top_srcdir)/include/jam/util/sort/StringComparator.hxx
