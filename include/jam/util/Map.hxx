#ifndef __MAP_HXX__
#define __MAP_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class Iterator;
        class MapImpl;
        
        class Map : public Object {
            public:
                Map();
                Map(const Reference& ref);
                Map(Implementation* impl);
                virtual ~Map();
                MapImpl& operator*();
                MapImpl* operator->();
                const Map& operator=(const Reference& ref);
                const Map& operator=(Implementation* impl);
        };
        
        class MapImpl : public ObjectImpl {
            public:
                MapImpl();
                virtual ~MapImpl();
                
                virtual Object put(Object key, Object value) = 0;
                virtual void putAll(Map map) = 0;
                virtual boolean containsKey(Object key) = 0;
                virtual boolean containsValue(Object value) = 0;
                virtual Iterator keyIterator() = 0;
                virtual Iterator valueIterator() = 0;
                virtual Object get(Object key) = 0;
                virtual Object remove(Object key) = 0;
                virtual boolean isEmpty() = 0;
                virtual int size() = 0;
                virtual void clear() = 0;
                
            private:
                MapImpl(const MapImpl& copy);
        };
    }
}

#endif
