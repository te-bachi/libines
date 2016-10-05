SUBDIRS = \
    locale \
    sort \
    time
    
noinst_LTLIBRARIES = \
    libutil.la

libutil_la_SOURCES = \
    StringBuffer.cxx \
    StringTokenizer.cxx \
    StringPadding.cxx \
    Iterator.cxx \
    Collection.cxx \
    List.cxx \
    ListIterator.cxx \
    LinkedList.cxx \
    ArrayList.cxx \
    Set.cxx \
    Map.cxx \
    HashMap.cxx \
    HashMapIterator.cxx \
    SortedMap.cxx \
    SortedMapIterator.cxx

libutil_la_CXXFLAGS = \
    -I$(top_srcdir)/include \
    $(DEBUG_FLAG)

libutil_la_includedir = \
    $(includedir)/jam/util

libutil_la_include_HEADERS = \
    $(top_srcdir)/include/jam/util/StringBuffer.hxx \
    $(top_srcdir)/include/jam/util/StringTokenizer.hxx \
    $(top_srcdir)/include/jam/util/StringPadding.hxx \
    $(top_srcdir)/include/jam/util/Iterator.hxx \
    $(top_srcdir)/include/jam/util/Collection.hxx \
    $(top_srcdir)/include/jam/util/List.hxx \
    $(top_srcdir)/include/jam/util/ListIterator.hxx \
    $(top_srcdir)/include/jam/util/LinkedList.hxx \
    $(top_srcdir)/include/jam/util/ArrayList.hxx \
    $(top_srcdir)/include/jam/util/Set.hxx \
    $(top_srcdir)/include/jam/util/Map.hxx \
    $(top_srcdir)/include/jam/util/HashMap.hxx \
    $(top_srcdir)/include/jam/util/HashMapIterator.hxx \
    $(top_srcdir)/include/jam/util/SortedMap.hxx \
    $(top_srcdir)/include/jam/util/SortedMapIterator.hxx
