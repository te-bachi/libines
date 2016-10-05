#ifndef __HASH_MAP_ITERATOR_HXX__
#define __HASH_MAP_ITERATOR_HXX__

#include "jam/Global.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/HashMap.hxx"

namespace jam {
    namespace util {
        using namespace lang;
        
        class HashMapIteratorImpl;
        class HashMap;
        
        class HashMapIterator : public Iterator {
            public:
                const static Class klass;
                
                typedef enum {
                    KEY_SET = 0,
                    VALUE_SET
                } Set;
                
            public:
                HashMapIterator();
                HashMapIterator(const Reference& ref);
                HashMapIterator(Implementation* impl);
                virtual ~HashMapIterator();
                HashMapIteratorImpl& operator*();
                HashMapIteratorImpl* operator->();
                const HashMapIterator& operator=(const Reference& ref);
                const HashMapIterator& operator=(Implementation* impl);
                
                static HashMapIterator newInstance(HashMap map, Set set);
        };
        
        class HashMapIteratorImpl : public IteratorImpl {
            private:
                HashMapIterator::Set _set;
                HashMap              _map;
                HashMapImpl::Entry*  _current;
                HashMapImpl::Entry*  _next;
                int                  _size;
                int                  _index;
                
            public:
                HashMapIteratorImpl(HashMap map, HashMapIterator::Set set);
                virtual ~HashMapIteratorImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
                virtual boolean hasNext();
                virtual Object next();
                virtual Object remove();
                
            private:
                HashMapIteratorImpl(const HashMapIteratorImpl& copy);
        };
    }
}

#endif
