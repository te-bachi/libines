#ifndef __LOG_EVENT_HXX__
#define __LOG_EVENT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/log/Log.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class LogEventImpl;
            
            class LogEvent : public Object {
                public:
                    const static Class klass;
                    
                public:
                    LogEvent();
                    LogEvent(const Reference& ref);
                    LogEvent(Implementation* impl);
                    virtual ~LogEvent();
                    LogEventImpl& operator*();
                    LogEventImpl* operator->();
                    const LogEvent& operator=(const Reference& ref);
                    const LogEvent& operator=(Implementation* impl);
            };
            
            class LogEventImpl : public ObjectImpl {
                public:
                    
                private:
                    String     _logName;
                    Log::Level _level;
                    String     _message;
                    
                public:
                    LogEventImpl(String logName, Log::Level level, String message);
                    virtual ~LogEventImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Object clone();
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual String getLogName();
                    virtual Log::Level getLevel();
                    virtual String getMessage();
                    
                private:
                    LogEventImpl(const LogEventImpl& copy);
            };
        }
    }
}

#endif
