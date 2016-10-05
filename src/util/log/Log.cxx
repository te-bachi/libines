#include "jam/util/log/Log.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util::log;
using namespace jam::lang;

const Class Log::klass = new ClassImpl("jam::util::log::Log");

/*** Reference ***/

Log::Log() : Object() {
    //
}

Log::Log(const Reference& ref) : Object(ref) {
    //
}

Log::Log(Implementation* impl) : Object(impl) {
    //
}

Log::~Log() {
    //
}

LogImpl& Log::operator*() {
    return (LogImpl&) Object::operator*();
}

LogImpl* Log::operator->() {
    return (LogImpl*) Object::operator->();
}

const Log& Log::operator=(const Reference& ref) {
    return (Log&) Object::operator=(ref);
}

const Log& Log::operator=(Implementation* impl) {
    return (Log&) Object::operator=(impl);
}

/*** Implementation ***/

LogImpl::LogImpl(String name, Log::Level level) {
    
}

LogImpl::~LogImpl() {
    
}

LogImpl::LogImpl(const LogImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LogImpl::debugClassName() {
    return "jam::util::log::Log";
}
#endif

Object LogImpl::clone() {
    return null;
}

String LogImpl::toString() {
    return null;
}

Class LogImpl::getClass() {
    return Log::klass;
}

void LogImpl::addAppender(Appender appender) {
    
}

void LogImpl::setLevel(Log::Level level) {
    
}

void LogImpl::debug(String message) {
    
}

void LogImpl::debug(const char* message) {
    
}

void LogImpl::info(String message) {
    
}

void LogImpl::info(const char* message) {
    
}

void LogImpl::warn(String message) {
    
}

void LogImpl::warn(const char* message) {
    
}

void LogImpl::error(String message) {
    
}

void LogImpl::error(const char* message) {
    
}

void LogImpl::fatal(String message) {
    
}

void LogImpl::fatal(const char* message) {
    
}

void LogImpl::log(Log::Level level, String message) {
    
}
