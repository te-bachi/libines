#include "jam/util/log/SimpleLayout.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util::log;
using namespace jam::lang;

const Class SimpleLayout::klass = new ClassImpl("jam::util::log::SimpleLayout");

/*** Reference ***/

SimpleLayout::SimpleLayout() : Object() {
    //
}

SimpleLayout::SimpleLayout(const Reference& ref) : Object(ref) {
    //
}

SimpleLayout::SimpleLayout(Implementation* impl) : Object(impl) {
    //
}

SimpleLayout::~SimpleLayout() {
    //
}

SimpleLayoutImpl& SimpleLayout::operator*() {
    return (SimpleLayoutImpl&) Object::operator*();
}

SimpleLayoutImpl* SimpleLayout::operator->() {
    return (SimpleLayoutImpl*) Object::operator->();
}

const SimpleLayout& SimpleLayout::operator=(const Reference& ref) {
    return (SimpleLayout&) Object::operator=(ref);
}

const SimpleLayout& SimpleLayout::operator=(Implementation* impl) {
    return (SimpleLayout&) Object::operator=(impl);
}

/*** Implementation ***/

SimpleLayoutImpl::SimpleLayoutImpl() {
    
}

SimpleLayoutImpl::~SimpleLayoutImpl() {
    
}

SimpleLayoutImpl::SimpleLayoutImpl(const SimpleLayoutImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* SimpleLayoutImpl::debugClassName() {
    return "jam::util::log::SimpleLayout";
}
#endif

Object SimpleLayoutImpl::clone() {
    return null;
}

String SimpleLayoutImpl::toString() {
    return null;
}

Class SimpleLayoutImpl::getClass() {
    return SimpleLayout::klass;
}

String SimpleLayoutImpl::format(LogEvent event) {
    return null;
}
