#ifndef __CONSOLE_APPENDER_HXX__
#define __CONSOLE_APPENDER_HXX__

#include "jam/Global.hxx"
#include "jam/util/log/Appender.hxx"
#include "jam/util/log/ConsoleAppender.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class ConsoleAppenderImpl;
            
            class ConsoleAppender : public Appender {
                public:
                    const static Class klass;
                    
                public:
                    ConsoleAppender();
                    ConsoleAppender(const Reference& ref);
                    ConsoleAppender(Implementation* impl);
                    virtual ~ConsoleAppender();
                    ConsoleAppenderImpl& operator*();
                    ConsoleAppenderImpl* operator->();
                    const ConsoleAppender& operator=(const Reference& ref);
                    const ConsoleAppender& operator=(Implementation* impl);
            };
            
            class ConsoleAppenderImpl : public AppenderImpl {
                public:
                    
                private:
                    
                public:
                    ConsoleAppenderImpl(String name, Layout layout);
                    virtual ~ConsoleAppenderImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Object clone();
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual void doAppend(LogEvent event);
                    
                private:
                    ConsoleAppenderImpl(const ConsoleAppenderImpl& copy);
            };
        }
    }
}

#endif
