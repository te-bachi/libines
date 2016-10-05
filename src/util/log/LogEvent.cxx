#include "jam/util/log/LogEvent.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/ClassImpl.hxx"

using namespace jam::util::log;
using namespace jam::lang;

const Class LogEvent::klass = new ClassImpl("jam::util::log::LogEvent");

/*** Reference ***/

LogEvent::LogEvent() : Object() {
    //
}

LogEvent::LogEvent(const Reference& ref) : Object(ref) {
    //
}

LogEvent::LogEvent(Implementation* impl) : Object(impl) {
    //
}

LogEvent::~LogEvent() {
    //
}

LogEventImpl& LogEvent::operator*() {
    return (LogEventImpl&) Object::operator*();
}

LogEventImpl* LogEvent::operator->() {
    return (LogEventImpl*) Object::operator->();
}

const LogEvent& LogEvent::operator=(const Reference& ref) {
    return (LogEvent&) Object::operator=(ref);
}

const LogEvent& LogEvent::operator=(Implementation* impl) {
    return (LogEvent&) Object::operator=(impl);
}

/*** Implementation ***/

LogEventImpl::LogEventImpl(String logName, Log::Level level, String message) {
    
}

LogEventImpl::~LogEventImpl() {
    
}

LogEventImpl::LogEventImpl(const LogEventImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LogEventImpl::debugClassName() {
    return "jam::util::log::LogEvent";
}
#endif

Object LogEventImpl::clone() {
    return null;
}

String LogEventImpl::toString() {
    return null;
}

Class LogEventImpl::getClass() {
    return LogEvent::klass;
}

String LogEventImpl::getLogName() {
    return _logName;
}

Log::Level LogEventImpl::getLevel() {
    return _level;
}

String LogEventImpl::getMessage() {
    return _message;
}
