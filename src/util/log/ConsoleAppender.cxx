#include "jam/util/log/ConsoleAppender.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util::log;
using namespace jam::lang;

const Class ConsoleAppender::klass = Class::newInstance("jam::util::log::ConsoleAppender");

ConsoleAppender::ConsoleAppender() : Appender() {
    //
}

ConsoleAppender::ConsoleAppender(const Reference& ref) : Appender(ref) {
    //
}

ConsoleAppender::ConsoleAppender(Implementation* impl) : Appender(impl) {
    //
}

ConsoleAppender::~ConsoleAppender() {
    //
}

ConsoleAppenderImpl& ConsoleAppender::operator*() {
    return (ConsoleAppenderImpl&) Appender::operator*();
}

ConsoleAppenderImpl* ConsoleAppender::operator->() {
    return (ConsoleAppenderImpl*) Appender::operator->();
}

const ConsoleAppender& ConsoleAppender::operator=(const Reference& ref) {
    return (ConsoleAppender&) Appender::operator=(ref);
}

const ConsoleAppender& ConsoleAppender::operator=(Implementation* impl) {
    return (ConsoleAppender&) Appender::operator=(impl);
}

/*** Implementation ***/

ConsoleAppenderImpl::ConsoleAppenderImpl(String name, Layout layout) : AppenderImpl(name, layout) {
    
}

ConsoleAppenderImpl::~ConsoleAppenderImpl() {
    
}

ConsoleAppenderImpl::ConsoleAppenderImpl(const ConsoleAppenderImpl& copy) : AppenderImpl(copy) {
    //
}

#ifdef __DEBUG__
const char* ConsoleAppenderImpl::debugClassName() {
    return "jam::util::log::ConsoleAppender";
}
#endif

Object ConsoleAppenderImpl::clone() {
    return null;
}

String ConsoleAppenderImpl::toString() {
    return null;
}

Class ConsoleAppenderImpl::getClass() {
    return ConsoleAppender::klass;
}

void ConsoleAppenderImpl::doAppend(LogEvent event) {
    
}
