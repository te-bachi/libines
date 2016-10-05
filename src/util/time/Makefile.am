
noinst_LTLIBRARIES = \
    libtime.la

libtime_la_SOURCES = \
    Clock.cxx \
    Calendar.cxx \
    TimeZone.cxx

libtime_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libtime_la_includedir = \
    $(includedir)/jam/util/time

libtime_la_include_HEADERS = \
    $(top_srcdir)/include/jam/util/time/Clock.hxx \
    $(top_srcdir)/include/jam/util/time/Calendar.hxx \
    $(top_srcdir)/include/jam/util/time/TimeZone.hxx
