#ifndef __SORTED_MAP_HXX__
#define __SORTED_MAP_HXX__

#include "jam/Global.hxx"
#include "jam/util/Map.hxx"
#include "jam/util/sort/Comparator.hxx"

namespace jam {
    namespace util {
        using namespace jam::util::sort;
        
        class SortedMapImpl;
        
        class SortedMap : public Map {
            public:
                const static Class klass;
                
            public:
                SortedMap();
                SortedMap(const Reference& ref);
                SortedMap(Implementation* impl);
                virtual ~SortedMap();
                SortedMapImpl& operator*();
                SortedMapImpl* operator->();
                const SortedMap& operator=(const Reference& ref);
                const SortedMap& operator=(Implementation* impl);
                
                static SortedMap newInstance(Comparator comparator);
                static SortedMap newInstance(Comparator comparator, int initialCapacity);
        };
        
        class SortedMapImpl : public MapImpl {
            friend class SortedMapIteratorImpl;
            
            private:
                
                struct Entry {
                    Object _key;
                    Object _value;
                };
                
                Entry**     _map;
                Comparator  _comparator;
                int         _size;
                int         _capacity;
                
            public:
                SortedMapImpl(Comparator comparator);
                SortedMapImpl(Comparator comparator, int initialCapacity);
                virtual ~SortedMapImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual Object put(Object key, Object value);
                virtual void putAll(Map t);
                virtual boolean containsKey(Object key);
                virtual boolean containsValue(Object value);
                virtual Iterator keyIterator();
                virtual Iterator valueIterator();
                virtual Object get(Object key);
                virtual Object remove(Object key);
                virtual boolean isEmpty();
                virtual int size();
                virtual void clear();
                
            private:
                SortedMapImpl(const SortedMapImpl& copy);
                void init(Comparator comparator, int initialCapacity);
                void initMap();
                void increaseMap();
                Entry* findEntry(Object key);
                int findIndex(Object key);
        };
    }
}

#endif
