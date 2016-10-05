#ifndef __SYSTEM_HXX__
#define __SYSTEM_HXX__

#include "jam/Global.hxx"

namespace jam {
    namespace util {
        namespace time {
            class Clock;
        }
    }
    namespace lang {
        using namespace jam::util::time;
        
        class String;
        
        class System {
            
            public:
                static void memoryCopy(const char* srcPtr, char* destPtr, int length);
                static String getProperty(String key);
                static Clock getTime();
                
            private:
                System();
                System(const System& copy);
                virtual ~System();
        };
    }
}

#endif

