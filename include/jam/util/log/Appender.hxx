#ifndef __APPENDER_HXX__
#define __APPENDER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/log/Layout.hxx"
#include "jam/util/log/LogEvent.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class AppenderImpl;
            
            class Appender : public Object {
                public:
                    Appender();
                    Appender(const Reference& ref);
                    Appender(Implementation* impl);
                    virtual ~Appender();
                    AppenderImpl& operator*();
                    AppenderImpl* operator->();
                    const Appender& operator=(const Reference& ref);
                    const Appender& operator=(Implementation* impl);
            };
            
            class AppenderImpl : public ObjectImpl {
                private:
                    String _name;
                    Layout _layout;
                    
                public:
                    AppenderImpl(String name, Layout layout);
                    virtual ~AppenderImpl();
                    
                    virtual void doAppend(LogEvent event) = 0;
                    virtual String getName();
                    virtual Layout getLayout();
                    
                protected:
                    AppenderImpl(const AppenderImpl& copy);
            };
        }
    }
}

#endif
