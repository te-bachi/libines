SUBDIRS = 

noinst_LTLIBRARIES = \
    libtext.la

libtext_la_SOURCES = \
    ParseException.cxx \
    Format.cxx \
    CalendarFormat.cxx \
    NumberFormat.cxx

libtext_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libtext_la_includedir = \
    $(includedir)/jam/text

libtext_la_include_HEADERS = \
    $(top_srcdir)/include/jam/text/ParseException.hxx \
    $(top_srcdir)/include/jam/text/Format.hxx \
    $(top_srcdir)/include/jam/text/CalendarFormat.hxx \
    $(top_srcdir)/include/jam/text/NumberFormat.hxx
