#include "jam/util/log/Appender.hxx"

using namespace jam::util::log;
using namespace jam::lang;

/*** Reference ***/

Appender::Appender() : Object() {
    //
}

Appender::Appender(const Reference& ref) : Object(ref) {
    //
}

Appender::Appender(Implementation* impl) : Object(impl) {
    //
}

Appender::~Appender() {
    //
}

AppenderImpl& Appender::operator*() {
    return (AppenderImpl&) Object::operator*();
}

AppenderImpl* Appender::operator->() {
    return (AppenderImpl*) Object::operator->();
}

const Appender& Appender::operator=(const Reference& ref) {
    return (Appender&) Object::operator=(ref);
}

const Appender& Appender::operator=(Implementation* impl) {
    return (Appender&) Object::operator=(impl);
}

/*** Implementation ***/

AppenderImpl::AppenderImpl(String name, Layout layout) {
    _name   = name;
    _layout = layout;
}

AppenderImpl::~AppenderImpl() {
    //
}

AppenderImpl::AppenderImpl(const AppenderImpl& copy) {
    //
}

String AppenderImpl::getName() {
    return _name;
}

Layout AppenderImpl::getLayout() {
    return _layout;
}
