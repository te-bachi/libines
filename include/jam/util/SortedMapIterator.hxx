#ifndef __SORTED_MAP_ITERATOR_HXX__
#define __SORTED_MAP_ITERATOR_HXX__

#include "jam/Global.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/SortedMap.hxx"

namespace jam {
    namespace util {
        using namespace lang;
        
        class SortedMapIteratorImpl;
        class SortedMap;
        
        class SortedMapIterator : public Iterator {
            public:
                const static Class klass;
                
                enum {
                    KEY_SET = 0,
                    VALUE_SET
                };
                
            public:
                SortedMapIterator();
                SortedMapIterator(const Reference& ref);
                SortedMapIterator(Implementation* impl);
                virtual ~SortedMapIterator();
                SortedMapIteratorImpl& operator*();
                SortedMapIteratorImpl* operator->();
                const SortedMapIterator& operator=(const Reference& ref);
                const SortedMapIterator& operator=(Implementation* impl);
                
                static SortedMapIterator newInstance(SortedMap map, int set);
        };
        
        class SortedMapIteratorImpl : public IteratorImpl {
            private:
                int         _set;
                SortedMap   _map;
                int         _size;
                int         _index;
                
            public:
                SortedMapIteratorImpl(SortedMap map, int set);
                virtual ~SortedMapIteratorImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
                virtual boolean hasNext();
                virtual Object next();
                virtual Object remove();
                
            private:
                SortedMapIteratorImpl(const SortedMapIteratorImpl& copy);
        };
    }
}

#endif
