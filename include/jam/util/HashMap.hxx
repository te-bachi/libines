#ifndef __HASH_MAP_HXX__
#define __HASH_MAP_HXX__

#include "jam/Global.hxx"
#include "jam/util/Map.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class HashMapImpl;
        class Map;
        class Iterator;
        
        class HashMap : public Map {
            public:
                const static Class klass;
                
            public:
                HashMap();
                HashMap(const Reference& ref);
                HashMap(Implementation* impl);
                virtual ~HashMap();
                HashMapImpl& operator*();
                HashMapImpl* operator->();
                const HashMap& operator=(const Reference& ref);
                const HashMap& operator=(Implementation* impl);
                
                static HashMap newInstance();
                static HashMap newInstance(int initialCapacity);
                static HashMap newInstance(int initialCapacity, float loadFactor);
        };
        
        class HashMapImpl : public MapImpl {
            
            friend class HashMapIteratorImpl;
            
            private:
                
                struct Entry {
                    Object _key;
                    Object _value;
                    Entry* _next;
                    Entry* _previous;
                    
                    Entry(Object key, Object value);
                    Entry(Object key, Object value, Entry* entry);
                };
                
                Entry** _map;
                int     _size;
                int     _capacity;
                float   _loadFactor;
                int     _threshold;
                
            public:
                HashMapImpl();
                HashMapImpl(int initialCapacity);
                HashMapImpl(int initialCapacity, float loadFactor);
                virtual ~HashMapImpl();
                
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
                HashMapImpl(const HashMapImpl& copy);
                void init(int initialCapacity, float loadFactor);
                void initMap();
                void rehash();
                Entry* findEntry(Object key);
        };
    }
}

#endif
