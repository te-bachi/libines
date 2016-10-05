#ifndef __LINKED_LIST_HXX__
#define __LINKED_LIST_HXX__

#include "jam/Global.hxx"
#include "jam/util/List.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class LinkedListImpl;
        
        class LinkedList : public List {
            public:
                const static Class klass;
                
            public:
                LinkedList();
                LinkedList(const Reference& ref);
                LinkedList(Implementation* impl);
                virtual ~LinkedList();
                LinkedListImpl& operator*();
                LinkedListImpl* operator->();
                const LinkedList& operator=(const Reference& ref);
                const LinkedList& operator=(Implementation* impl);
                const Object operator[](int index);
                
                static LinkedList newInstance();
        };
        
        class LinkedListImpl : public ListImpl {
            private:
                struct Entry {
                    Object _obj;
                    Entry* _previous;
                    Entry* _next;
                    
                    Entry(Object obj, Entry *previous, Entry *next);
                };
                
                Entry* _head;
                Entry* _tail;
                int    _size;
                
            public:
                LinkedListImpl();
                virtual ~LinkedListImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual boolean add(Object obj);
                virtual boolean add(Collection collection);
                virtual void addFirst(Object obj);
                virtual void addLast(Object obj);
                virtual boolean contains(Object obj);
                virtual boolean contains(Collection collection);
                virtual Object get(int index);
                virtual Object getFirst();
                virtual Object getLast();
                virtual boolean remove(Object obj);
                virtual boolean remove(Collection collection);
                virtual Object remove(int index);     
                virtual Object removeFirst();
                virtual Object removeLast();
                virtual boolean isEmpty();
                virtual Iterator iterator();
                virtual int size();
                virtual void clear();
                virtual List subList(int fromIndex, int toIndex);
                virtual Collection sort(Comparator comparator);
                virtual void swap(int i1, int i2);
                
            private:
                LinkedListImpl(const LinkedListImpl& copy);
                void removeEntry(Entry* entry);
                Entry* findEntry(int index);
                Entry* findEntry(Object obj);
        };
    }
}

#endif
