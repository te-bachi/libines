#ifndef __LIST_HXX__
#define __LIST_HXX__

#include "jam/Global.hxx"
#include "jam/util/Collection.hxx"

namespace jam {
    namespace util {
        
        class ListImpl;
        
        class List : public Collection {
            public:
                List();
                List(const Reference& ref);
                List(Implementation* impl);
                virtual ~List();
                ListImpl& operator*();
                ListImpl* operator->();
                const List& operator=(const Reference& ref);
                const List& operator=(Implementation* impl);
                const Object operator[](int index);
        };
        
        class ListImpl : public CollectionImpl {
            public:
                ListImpl();
                virtual ~ListImpl();
                
                virtual boolean add(Object obj) = 0;
                virtual boolean add(Collection collection) = 0;
                virtual void clear() = 0;
                virtual boolean contains(Object obj) = 0;
                virtual boolean contains(Collection collection) = 0;
                virtual boolean isEmpty() = 0;
                virtual Iterator iterator() = 0;
                virtual Object get(int index) = 0;
                virtual boolean remove(Object obj) = 0;
                virtual boolean remove(Collection collection) = 0;
                virtual Object remove(int index) = 0;
                virtual List subList(int fromIndex, int toIndex) = 0;
                virtual int size() = 0;
                virtual Collection sort(Comparator comparator) = 0;
                virtual void swap(int i1, int i2) = 0;
                
            private:
                ListImpl(const ListImpl& copy);
        };
    }
}

#endif
