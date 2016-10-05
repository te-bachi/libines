#ifndef __LOG_HXX__
#define __LOG_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/List.hxx"

namespace jam {
    namespace util {
        namespace log {
            using namespace jam::lang;
            
            class LogImpl;
            class Appender;
            
            class Log : public Object {
                public:
                    const static Class klass;
                    
                    typedef enum {
                        OFF,
                        FATAL,
                        ERROR,
                        WARN,
                        INFO,
                        DEBUG
                    } Level;
                    
                public:
                    Log();
                    Log(const Reference& ref);
                    Log(Implementation* impl);
                    virtual ~Log();
                    LogImpl& operator*();
                    LogImpl* operator->();
                    const Log& operator=(const Reference& ref);
                    const Log& operator=(Implementation* impl);
            };
            
            class LogImpl : public ObjectImpl {
                public:
                    
                private:
                    List appenderList;
                    
                public:
                    LogImpl(String name, Log::Level level);
                    
                    virtual ~LogImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Object clone();
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual void addAppender(Appender appender);
                    virtual void setLevel(Log::Level level);
                    
                    virtual void debug(String message);
                    virtual void debug(const char* message);
                    virtual void info(String message);
                    virtual void info(const char* message);
                    virtual void warn(String message);
                    virtual void warn(const char* message);
                    virtual void error(String message);
                    virtual void error(const char* message);
                    virtual void fatal(String message);
                    virtual void fatal(const char* message);
                    
                private:
                    LogImpl(const LogImpl& copy);
                    void log(Log::Level level, String message);
            };
        }
    }
}


#endif
