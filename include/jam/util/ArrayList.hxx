#ifndef __ARRAY_LIST_HXX__
#define __ARRAY_LIST_HXX__

#include "jam/Global.hxx"
#include "jam/util/List.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class ArrayListImpl;
        
        class ArrayList : public List {
            public:
                const static Class klass;
                
            public:
                ArrayList();
                ArrayList(const Reference& ref);
                ArrayList(Implementation* impl);
                virtual ~ArrayList();
                ArrayListImpl& operator*();
                ArrayListImpl* operator->();
                const ArrayList& operator=(const Reference& ref);
                const ArrayList& operator=(Implementation* impl);
                const Object operator[](int index);
                
                static ArrayList newInstance();
                static ArrayList newInstance(int size);
        };
        
        class ArrayListImpl : public ListImpl {
            private:
                const static int NOT_FOUND;
                
                struct Entry {
                    Object _obj;
                    Entry(Object obj);
                };
                
                Entry** _list;
                int     _size;
                int     _capacity;
                
            public:
                ArrayListImpl();
                ArrayListImpl(int size);
                virtual ~ArrayListImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual boolean add(Object obj);
                virtual boolean add(Collection collection) ;
                virtual void clear();
                virtual boolean contains(Object obj);
                virtual boolean contains(Collection collection);
                virtual boolean isEmpty();
                virtual Iterator iterator();
                virtual Object get(int index);
                virtual boolean remove(Object obj);
                virtual boolean remove(Collection collection);
                virtual Object remove(int index);
                virtual List subList(int fromIndex, int toIndex);
                virtual int size();
                virtual int indexOf(Object obj);
                virtual Collection sort(Comparator comparator);
                virtual void swap(int i1, int i2);
                
            private:
                ArrayListImpl(const ArrayListImpl& copy);
                void init(int size);
                void initList();
                void resize();
                int findEntry(Object obj);
                void removeEntry(int index);
        };
    }
}

#endif
