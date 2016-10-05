#include "jam/lang/IllegalArgumentException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class IllegalArgumentException::klass = Class::newInstance("jam::lang::IllegalArgumentException");

/*** Reference ***/

IllegalArgumentException::IllegalArgumentException() : Exception() {
    //
}

IllegalArgumentException::IllegalArgumentException(const Reference& ref) : Exception(ref) {
    //
}

IllegalArgumentException::IllegalArgumentException(Implementation* impl) : Exception(impl) {
    //
}

IllegalArgumentException::~IllegalArgumentException() {
    //
}

IllegalArgumentExceptionImpl& IllegalArgumentException::operator*() {
    return (IllegalArgumentExceptionImpl&) Exception::operator*();
}

IllegalArgumentExceptionImpl* IllegalArgumentException::operator->() {
    return (IllegalArgumentExceptionImpl*) Exception::operator->();
}

const IllegalArgumentException& IllegalArgumentException::operator=(const Reference& ref) {
    return (IllegalArgumentException&) Exception::operator=(ref);
}

const IllegalArgumentException& IllegalArgumentException::operator=(Implementation* impl) {
    return (IllegalArgumentException&) Exception::operator=(impl);
}

IllegalArgumentException IllegalArgumentException::newInstance() {
    return IllegalArgumentException(new IllegalArgumentExceptionImpl());
}

IllegalArgumentException IllegalArgumentException::newInstance(String message) {
    return IllegalArgumentException(new IllegalArgumentExceptionImpl(message));
}

IllegalArgumentException IllegalArgumentException::newInstance(Exception cause) {
    return IllegalArgumentException(new IllegalArgumentExceptionImpl(cause));
}

IllegalArgumentException IllegalArgumentException::newInstance(String message, Exception cause) {
    return IllegalArgumentException(new IllegalArgumentExceptionImpl(message, cause));
}

/*** Implementation ***/

IllegalArgumentExceptionImpl::IllegalArgumentExceptionImpl() : ExceptionImpl() {
    //
}

IllegalArgumentExceptionImpl::IllegalArgumentExceptionImpl(String message) : ExceptionImpl(message) {
    //
}

IllegalArgumentExceptionImpl::IllegalArgumentExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    //
}

IllegalArgumentExceptionImpl::IllegalArgumentExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    //
}

IllegalArgumentExceptionImpl::~IllegalArgumentExceptionImpl() {
    //
}

IllegalArgumentExceptionImpl::IllegalArgumentExceptionImpl(const IllegalArgumentExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* IllegalArgumentExceptionImpl::debugClassName() {
    return "jam::lang::IllegalArgumentException";
}
#endif

String IllegalArgumentExceptionImpl::toString() {
    return null;
}

Class IllegalArgumentExceptionImpl::getClass() {
    return IllegalArgumentException::klass;
}
