#ifndef __ITERATOR_HXX__
#define __ITERATOR_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class IteratorImpl;
        
        class Iterator : public Object {
            public:
                Iterator();
                Iterator(const Reference& ref);
                Iterator(Implementation* impl);
                virtual ~Iterator();
                IteratorImpl& operator*();
                IteratorImpl* operator->();
                const Iterator& operator=(const Reference& ref);
                const Iterator& operator=(Implementation* impl);
        };
        
        class IteratorImpl : public ObjectImpl {
            public:
                IteratorImpl();
                virtual ~IteratorImpl() = 0;
                
                virtual boolean hasNext() = 0;
                virtual Object next() = 0;
                virtual Object remove() = 0;
                
            private:
                IteratorImpl(const IteratorImpl& copy);
        };
    }
}

#endif
