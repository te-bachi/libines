#ifndef __LIST_ITERATOR_HXX__
#define __LIST_ITERATOR_HXX__

#include "jam/Global.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/List.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class List;
        class ListIteratorImpl;
        
        class ListIterator : public Iterator {
            public:
                const static Class klass;
                
            public:
                ListIterator();
                ListIterator(const Reference& ref);
                ListIterator(Implementation* impl);
                virtual ~ListIterator();
                ListIteratorImpl& operator*();
                ListIteratorImpl* operator->();
                const ListIterator& operator=(const Reference& ref);
                const ListIterator& operator=(Implementation* impl);
                
                static ListIterator newInstance(List list);
        };
        
        class ListIteratorImpl : public IteratorImpl {
            private:
                List _list;
                int  _index;
                
            public:
                ListIteratorImpl(List list);
                virtual ~ListIteratorImpl();
                        
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual boolean hasNext();
                virtual Object next();
                virtual boolean hasPrevious();
                virtual Object previous();
                virtual Object remove();
                
            private:
                ListIteratorImpl(const ListIteratorImpl& copy);
        };
    }
}

#endif
