#ifndef __CLOCK_HXX__
#define __CLOCK_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

#include <time.h>

namespace jam {
    namespace util {
        namespace time {
            using namespace jam::lang;
            
            class ClockImpl;
            
            class Clock : public Object {
                public:
                    const static Class klass;
                    
                public:
                    Clock();
                    Clock(const Reference& ref);
                    Clock(Implementation* impl);
                    virtual ~Clock();
                    ClockImpl& operator*();
                    ClockImpl* operator->();
                    const Clock& operator=(const Reference& ref);
                    const Clock& operator=(Implementation* impl);
                    
                    static Clock newInstance(time_t second, long nanosecond);
                    static long diff(Clock c1, Clock c2);
            };
            
            class ClockImpl : public ObjectImpl {
                
                private:
                    time_t  _second;
                    long    _nanosecond;
                    
                public:
                    ClockImpl(time_t second, long nanosecond);
                    virtual ~ClockImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Class getClass();
                    
                    virtual time_t getSecond();
                    virtual long getNanosecond();
                    
                private:
                    ClockImpl(const ClockImpl& copy);
            };
        }
    }
}

#endif
