#include "jam/lang/StackTraceElement.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/StringBuffer.hxx"

using namespace jam::lang;
using namespace jam::util;

const Class StackTraceElement::klass = Class::newInstance("jam::lang::StackTraceElement");

StackTraceElement::StackTraceElement() : Object() {
    //
}

StackTraceElement::StackTraceElement(const Reference& ref) : Object(ref) {
    //
}

StackTraceElement::StackTraceElement(Implementation* impl) : Object(impl) {
    //
}

StackTraceElement::~StackTraceElement() {
    //
}

StackTraceElementImpl& StackTraceElement::operator*() {
    return (StackTraceElementImpl&) Object::operator*();
}

StackTraceElementImpl* StackTraceElement::operator->() {
    return (StackTraceElementImpl*) Object::operator->();
}

const StackTraceElement& StackTraceElement::operator=(const Reference& ref) {
    return (StackTraceElement&) Object::operator=(ref);
}

const StackTraceElement& StackTraceElement::operator=(Implementation* impl) {
    return (StackTraceElement&) Object::operator=(impl);
}

StackTraceElement StackTraceElement::newInstance(String library, unsigned int stackAddress,
                                                 String function, unsigned int symbolAddress) {
    return StackTraceElement(new StackTraceElementImpl(library, stackAddress, function, symbolAddress));
}

/*** Implementation ***/

StackTraceElementImpl::StackTraceElementImpl(String library, unsigned int stackAddress,
                                             String function, unsigned int symbolAddress) {
    _library       = library;
    _function      = function;
    _stackAddress  = stackAddress;
    _symbolAddress = symbolAddress;
}

StackTraceElementImpl::~StackTraceElementImpl() {
    
}

StackTraceElementImpl::StackTraceElementImpl(const StackTraceElementImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StackTraceElementImpl::debugClassName() {
    return "jam::lang::StackTraceElement";
}
#endif

String StackTraceElementImpl::toString() {
    StringBuffer buffer;
    
    buffer = StringBuffer::newInstance();
    
    buffer->append(String::valueOf((int) _stackAddress, Number::HEXADECIMAL, true));
    buffer->append(" ");
    buffer->append(String::valueOf((int) _symbolAddress, Number::HEXADECIMAL, true));
    buffer->append(" ");
    buffer->append(_library);
    buffer->append(" ");
    buffer->append(_function);
    
    return buffer->toString();
}

Class StackTraceElementImpl::getClass() {
    return StackTraceElement::klass;
}

String StackTraceElementImpl::getLibrary() {
    return _library;
}

String StackTraceElementImpl::getFunction() {
    return _function;
}

unsigned int StackTraceElementImpl::getStackAddress() {
    return _stackAddress;
}

unsigned int StackTraceElementImpl::getSymbolAddress() {
    return _symbolAddress;
}
