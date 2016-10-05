SUBDIRS = 

noinst_LTLIBRARIES = \
    libproc.la

nodist_libproc_la_SOURCES = \
    ProcConnection.cxx \
    ProcStatement.cxx \
    ProcResultSet.cxx \
    ProcResultSetMetaData.cxx

libproc_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(ORACLE_CFLAGS) \
    $(DEBUG_FLAG)

libproc_la_includedir = \
    $(includedir)/jam/sql/proc

libproc_la_include_HEADERS = \
    $(top_srcdir)/include/jam/sql/proc/ProcConnection.hxx \
    $(top_srcdir)/include/jam/sql/proc/ProcStatement.hxx \
    $(top_srcdir)/include/jam/sql/proc/ProcResultSet.hxx \
    $(top_srcdir)/include/jam/sql/proc/ProcResultSetMetaData.hxx

CLEANFILES = \
    $(nondist_libproc_la_SOURCES)

EXTRA_DIST = \
    $(nondist_libproc_la_SOURCES:%.cxx=%.pcxx)

%.cxx: %.pcxx
	$(ORACLE_PREFIX)/bin/proc \
         MODE=ANSI \
         DYNAMIC=ANSI \
         CHAR_MAP=CHARZ \
         PARSE=PARTIAL \
         SQLCHECK=SEMANTICS \
         USERID=APOLLO/APOLLO \
         CODE=CPP \
         SYS_INCLUDE=/usr/include \
         INCLUDE=$(top_srcdir)/include \
         CPP_SUFFIX=cxx \
         INAME=$< \
         ONAME=$@