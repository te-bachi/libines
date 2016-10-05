
noinst_LTLIBRARIES = \
    libio.la

libio_la_SOURCES = \
    File.cxx \
    IOException.cxx \
    FileNotFoundException.cxx \
    InputStream.cxx \
    OutputStream.cxx \
    FileInputStream.cxx \
    FileOutputStream.cxx \
    BufferedInputStream.cxx \
    BufferedOutputStream.cxx

libio_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libio_la_includedir = \
    $(includedir)/jam/io

libio_la_include_HEADERS = \
    $(top_srcdir)/include/jam/io/File.hxx \
    $(top_srcdir)/include/jam/io/IOException.hxx \
    $(top_srcdir)/include/jam/io/FileNotFoundException.hxx \
    $(top_srcdir)/include/jam/io/InputStream.hxx \
    $(top_srcdir)/include/jam/io/OutputStream.hxx \
    $(top_srcdir)/include/jam/io/FileInputStream.hxx \
    $(top_srcdir)/include/jam/io/FileOutputStream.hxx \
    $(top_srcdir)/include/jam/io/BufferedInputStream.hxx \
    $(top_srcdir)/include/jam/io/BufferedOutputStream.hxx
