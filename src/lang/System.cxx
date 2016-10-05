#include "jam/lang/System.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/time/Clock.hxx"

#include <stdlib.h>
#include <time.h>

using namespace jam::lang;
using namespace jam::util::time;

System::System() {
    //
}

System::System(const System& copy) {
    //
}

System::~System() {
    
}

void System::memoryCopy(const char* srcPtr, char* destPtr, int length) {
    for (; length > 0; length--, srcPtr++, destPtr++) {
        *destPtr = *srcPtr;
    }
}

String System::getProperty(String key) {
    String value;
    char* chr;
    
    chr = getenv(key->toChar());
    
    if (chr != 0) {
        value = chr;
    }
    
    return value;
}

Clock System::getTime() {
    struct timespec now;
    
    clock_gettime(CLOCK_REALTIME, &now);
    
    return Clock::newInstance(now.tv_sec, now.tv_nsec);
}
