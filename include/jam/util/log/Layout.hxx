#ifndef __LAYOUT_HXX__
#define __LAYOUT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class LayoutImpl;
            class LogEvent;
            
            class Layout : public Object {
                public:
                    Layout();
                    Layout(const Reference& ref);
                    Layout(Implementation* impl);
                    virtual ~Layout();
                    LayoutImpl& operator*();
                    LayoutImpl* operator->();
                    const Layout& operator=(const Reference& ref);
                    const Layout& operator=(Implementation* impl);
            };
            
            class LayoutImpl : public ObjectImpl {
                public:
                    LayoutImpl();
                    virtual ~LayoutImpl();
                    
                    virtual String format(LogEvent event) = 0;
                    
                private:
                    LayoutImpl(const LayoutImpl& copy);
            };
        }
    }
}

#endif
