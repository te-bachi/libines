SUBDIRS = \
    proc

noinst_LTLIBRARIES = \
    libsql.la

libsql_la_SOURCES = \
    Connection.cxx \
    Statement.cxx \
    ResultSet.cxx \
    ResultSetMetaData.cxx \
    SQLException.cxx \
    SQLNotFoundException.cxx

libsql_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libsql_la_includedir = \
    $(includedir)/jam/sql

libsql_la_include_HEADERS = \
    $(top_srcdir)/include/jam/sql/Connection.hxx \
    $(top_srcdir)/include/jam/sql/Statement.hxx \
    $(top_srcdir)/include/jam/sql/ResultSet.hxx \
    $(top_srcdir)/include/jam/sql/ResultSetMetaData.hxx \
    $(top_srcdir)/include/jam/sql/SQLException.hxx \
    $(top_srcdir)/include/jam/sql/SQLNotFoundException.hxx
