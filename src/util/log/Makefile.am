
noinst_LTLIBRARIES = \
    liblog.la

liblog_la_SOURCES = \
    Appender.cxx \
    ConsoleAppender.cxx \
    Layout.cxx \
    SimpleLayout.cxx \
    Log.cxx \
    LogEvent.cxx \
    LogManager.cxx

liblog_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

liblog_la_includedir = \
    $(includedir)/jam/util/log

liblog_la_include_HEADERS = \
    $(top_srcdir)/include/jam/util/log/Appender.hxx \
    $(top_srcdir)/include/jam/util/log/ConsoleAppender.hxx \
    $(top_srcdir)/include/jam/util/log/Layout.hxx \
    $(top_srcdir)/include/jam/util/log/SimpleLayout.hxx \
    $(top_srcdir)/include/jam/util/log/Log.hxx \
    $(top_srcdir)/include/jam/util/log/LogEvent.hxx \
    $(top_srcdir)/include/jam/util/log/LogManager.hxx
