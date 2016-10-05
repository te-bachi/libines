#include "jam/util/time/Clock.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::util::time;

const Class Clock::klass = Class::newInstance("jam::util::time::Clock");

/*** Reference ***/

Clock::Clock() : Object() {
    //
}

Clock::Clock(const Reference& ref) : Object(ref) {
    //
}

Clock::Clock(Implementation* impl) : Object(impl) {
    //
}

Clock::~Clock() {
    //
}

ClockImpl& Clock::operator*() {
    return (ClockImpl&) Object::operator*();
}

ClockImpl* Clock::operator->() {
    return (ClockImpl*) Object::operator->();
}

const Clock& Clock::operator=(const Reference& ref) {
    return (Clock&) Object::operator=(ref);
}

const Clock& Clock::operator=(Implementation* impl) {
    return (Clock&) Object::operator=(impl);
}

Clock Clock::newInstance(time_t second, long nanosecond) {
    return Clock(new ClockImpl(second, nanosecond));
}

/**
 * Make difference of two clock objects and
 * return time in milisecond
 *
 * @param clock 1
 * @param clock 2
 * @return diff in milisecond
 */
long Clock::diff(Clock c1, Clock c2) {
    Clock   oldClock;
    Clock   newClock;
    long    diff;
    
    if (c1->getSecond() > c2->getSecond()) {
        oldClock = c2;
        newClock = c1;
    } else if (c1->getSecond() < c2->getSecond()) {
        oldClock = c1;
        newClock = c2;
    } else if (c1->getNanosecond() > c2->getNanosecond()) {
        oldClock = c2;
        newClock = c1;
    } else {
        oldClock = c1;
        newClock = c2;
    }
    
    diff  = (newClock->getSecond() - oldClock->getSecond()) * 1000;
    diff += (newClock->getNanosecond() - oldClock->getNanosecond()) / 1000000;
    
    return diff;
}

/*** Implementation ***/

ClockImpl::ClockImpl(time_t second, long nanosecond) {
    _second     = second;
    _nanosecond = nanosecond;
}

ClockImpl::~ClockImpl() {
    
}

ClockImpl::ClockImpl(const ClockImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ClockImpl::debugClassName() {
    return "jam::util::time::Clock";
}
#endif

Class ClockImpl::getClass() {
    return Clock::klass;
}

time_t ClockImpl::getSecond() {
    return _second;
}

long ClockImpl::getNanosecond() {
    return _nanosecond;
}
