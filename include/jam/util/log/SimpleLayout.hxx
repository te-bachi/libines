#ifndef __SIMPLE_LAYOUT_HXX__
#define __SIMPLE_LAYOUT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/log/Layout.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class SimpleLayoutImpl;
            
            class SimpleLayout : public Object, public Layout {
                public:
                    const static Class klass;
                    
                public:
                    SimpleLayout();
                    SimpleLayout(const Reference& ref);
                    SimpleLayout(Implementation* impl);
                    virtual ~SimpleLayout();
                    SimpleLayoutImpl& operator*();
                    SimpleLayoutImpl* operator->();
                    const SimpleLayout& operator=(const Reference& ref);
                    const SimpleLayout& operator=(Implementation* impl);
            };
            
            class SimpleLayoutImpl : public ObjectImpl, public LayoutImpl {
                public:
                    
                private:
                    
                public:
                    SimpleLayoutImpl();
                    virtual ~SimpleLayoutImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Object clone();
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual String format(LogEvent event);
                    
                private:
                    SimpleLayoutImpl(const SimpleLayoutImpl& copy);
            };
        }
    }
}

#endif
