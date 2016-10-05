
noinst_LTLIBRARIES = \
    liblocale.la

liblocale_la_SOURCES = \
    Country.cxx \
    Language.cxx \
    Locale.cxx \
    MessageResource.cxx \
    MissingResourceException.cxx

liblocale_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

liblocale_la_includedir = \
    $(includedir)/jam/util/locale

liblocale_la_include_HEADERS = \
    $(top_srcdir)/include/jam/util/locale/Country.hxx \
    $(top_srcdir)/include/jam/util/locale/Language.hxx \
    $(top_srcdir)/include/jam/util/locale/Locale.hxx \
    $(top_srcdir)/include/jam/util/locale/MessageResource.hxx \
    $(top_srcdir)/include/jam/util/locale/MissingResourceException.hxx
    
