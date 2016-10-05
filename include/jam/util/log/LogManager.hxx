#ifndef __LOG_MANAGER_HXX__
#define __LOG_MANAGER_HXX__

#include "jam/Global.hxx"
#include "jam/util/HashMap.hxx"

namespace jam {
    namespace lang {
        class String;
    }
    
    namespace util {
        namespace log {
            using namespace util;
            using namespace jam::lang;
            
            class Log;
            
            class LogManager {
                private:
                    static HashMap repository;
                    
                public:
                    static Log getLog(String name);
                    
                private:
                    LogManager();
                    LogManager(const LogManager& ref);
                    virtual ~LogManager();
            };
        }
    }
}

#endif
