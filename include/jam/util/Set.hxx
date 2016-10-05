#ifndef __SET_HXX__
#define __SET_HXX__

#include "jam/Global.hxx"
#include "jam/util/Collection.hxx"

namespace jam {
    namespace util {
        using namespace jam::lang;
        
        class SetImpl;
        
        class Set : public Collection {
            public:
                Set();
                Set(const Reference& ref);
                Set(Implementation* impl);
                virtual ~Set();
                SetImpl& operator*();
                SetImpl* operator->();
                const Set& operator=(const Reference& ref);
                const Set& operator=(Implementation* impl);
        };
        
        class SetImpl : public CollectionImpl {
            public:
        };
    }
}

#endif
