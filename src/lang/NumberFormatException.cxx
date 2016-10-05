#include "jam/lang/NumberFormatException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class NumberFormatException::klass = Class::newInstance("jam::lang::NumberFormatException");

/*** Reference ***/

NumberFormatException::NumberFormatException() : Exception() {
    //
}

NumberFormatException::NumberFormatException(const Reference& ref) : Exception(ref) {
    //
}

NumberFormatException::NumberFormatException(Implementation* impl) : Exception(impl) {
    //
}

NumberFormatException::~NumberFormatException() {
    //
}

NumberFormatExceptionImpl& NumberFormatException::operator*() {
    return (NumberFormatExceptionImpl&) Exception::operator*();
}

NumberFormatExceptionImpl* NumberFormatException::operator->() {
    return (NumberFormatExceptionImpl*) Exception::operator->();
}

const NumberFormatException& NumberFormatException::operator=(const Reference& ref) {
    return (NumberFormatException&) Exception::operator=(ref);
}

const NumberFormatException& NumberFormatException::operator=(Implementation* impl) {
    return (NumberFormatException&) Exception::operator=(impl);
}

/*** Implementation ***/

NumberFormatExceptionImpl::NumberFormatExceptionImpl() {
    
}

NumberFormatExceptionImpl::~NumberFormatExceptionImpl() {
    
}

NumberFormatExceptionImpl::NumberFormatExceptionImpl(const NumberFormatExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* NumberFormatExceptionImpl::debugClassName() {
    return "jam::lang::NumberFormatException";
}
#endif

Object NumberFormatExceptionImpl::clone() {
    return null;
}

String NumberFormatExceptionImpl::toString() {
    return null;
}

Class NumberFormatExceptionImpl::getClass() {
    return NumberFormatException::klass;
}
