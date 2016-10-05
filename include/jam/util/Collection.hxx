#ifndef __COLLECTION_HXX__
#define __COLLECTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/sort/Comparator.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        using namespace jam::util::sort;
        
        class CollectionImpl;
        class Iterator;
        
        class Collection : public Object {
            public:
                Collection();
                Collection(const Reference& ref);
                Collection(Implementation* impl);
                virtual ~Collection();
                CollectionImpl& operator*();
                CollectionImpl* operator->();
                const Collection& operator=(const Reference& ref);
                const Collection& operator=(Implementation* impl);
        };
        
        class CollectionImpl : public ObjectImpl {
            public:
                CollectionImpl();
                virtual ~CollectionImpl() = 0;
                
                virtual boolean add(Object obj) = 0;
                virtual boolean add(Collection collection) = 0;
                virtual void clear() = 0;
                virtual boolean contains(Object obj) = 0;
                virtual boolean contains(Collection collection) = 0;
                virtual boolean isEmpty() = 0;
                virtual Iterator iterator() = 0;
                virtual boolean remove(Object obj) = 0;
                virtual boolean remove(Collection collection) = 0;
                virtual int size() = 0;
                virtual Collection sort(Comparator comparator) = 0;
                
            private:
                CollectionImpl(const CollectionImpl& copy);
        };
    }
}

#endif
