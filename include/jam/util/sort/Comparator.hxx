#ifndef __COMPARATOR_HXX__
#define __COMPARATOR_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace util {
        namespace sort {
            using namespace jam::lang;
            
            class ComparatorImpl;
            
            class Comparator : public Object {
                public:
                    const static Class klass;
                    
                public:
                    Comparator();
                    Comparator(const Reference& ref);
                    Comparator(Implementation* impl);
                    virtual ~Comparator();
                    ComparatorImpl& operator*();
                    ComparatorImpl* operator->();
                    const Comparator& operator=(const Reference& ref);
                    const Comparator& operator=(Implementation* impl);
            };
            
            class ComparatorImpl : public ObjectImpl {
                private:
                    
                public:
                    ComparatorImpl();
                    virtual ~ComparatorImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Class getClass();
                    virtual int compare(Object first, Object second) = 0;
                    
                private:
                    ComparatorImpl(const ComparatorImpl& copy);
            };
        }
    }
}

#endif
