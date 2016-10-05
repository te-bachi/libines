#include "jam/lang/RegisterElement.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/StringBuffer.hxx"

using namespace jam::lang;
using namespace jam::util;

const Class RegisterElement::klass = Class::newInstance("jam::lang::RegisterElement");

/*** Reference ***/

RegisterElement::RegisterElement() : Object() {
    //
}

RegisterElement::RegisterElement(const Reference& ref) : Object(ref) {
    //
}

RegisterElement::RegisterElement(Implementation* impl) : Object(impl) {
    //
}

RegisterElement::~RegisterElement() {
    //
}

RegisterElementImpl& RegisterElement::operator*() {
    return (RegisterElementImpl&) Object::operator*();
}

RegisterElementImpl* RegisterElement::operator->() {
    return (RegisterElementImpl*) Object::operator->();
}

const RegisterElement& RegisterElement::operator=(const Reference& ref) {
    return (RegisterElement&) Object::operator=(ref);
}

const RegisterElement& RegisterElement::operator=(Implementation* impl) {
    return (RegisterElement&) Object::operator=(impl);
}

RegisterElement RegisterElement::newInstance(String registerName, unsigned int value) {
    return RegisterElement(new RegisterElementImpl(registerName, value));
}

/*** Implementation ***/

RegisterElementImpl::RegisterElementImpl(String registerName, unsigned int value) {
    _registerName = registerName;
    _value        = value;
}

RegisterElementImpl::~RegisterElementImpl() {
    
}

RegisterElementImpl::RegisterElementImpl(const RegisterElementImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* RegisterElementImpl::debugClassName() {
    return "jam::lang::RegisterElement";
}
#endif

String RegisterElementImpl::toString() {
    StringBuffer buffer;
    
    buffer = StringBuffer::newInstance();
    
    buffer->append(_registerName);
    buffer->append(": ");
    buffer->append(String::valueOf((int) _value, Number::HEXADECIMAL, true));
    
    return buffer->toString();
}

Class RegisterElementImpl::getClass() {
    return RegisterElement::klass;
}

String RegisterElementImpl::getRegisterName() {
    return _registerName;
}

unsigned int RegisterElementImpl::getValue() {
    return _value;
}
