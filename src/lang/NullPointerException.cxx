#include "jam/lang/NullPointerException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class NullPointerException::klass = Class::newInstance("jam::lang::NullPointerException");

/*** Reference ***/

NullPointerException::NullPointerException() : Exception() {
    //
}

NullPointerException::NullPointerException(const Reference& ref) : Exception(ref) {
    //
}

NullPointerException::NullPointerException(Implementation* impl) : Exception(impl) {
    //
}

NullPointerException::~NullPointerException() {
    //
}

NullPointerExceptionImpl& NullPointerException::operator*() {
    return (NullPointerExceptionImpl&) Exception::operator*();
}

NullPointerExceptionImpl* NullPointerException::operator->() {
    return (NullPointerExceptionImpl*) Exception::operator->();
}

const NullPointerException& NullPointerException::operator=(const Reference& ref) {
    return (NullPointerException&) Exception::operator=(ref);
}

const NullPointerException& NullPointerException::operator=(Implementation* impl) {
    return (NullPointerException&) Exception::operator=(impl);
}

NullPointerException NullPointerException::newInstance() {
    return NullPointerException(new NullPointerExceptionImpl());
}

NullPointerException NullPointerException::newInstance(String message) {
    return NullPointerException(new NullPointerExceptionImpl(message));
}

NullPointerException NullPointerException::newInstance(Exception cause) {
    return NullPointerException(new NullPointerExceptionImpl(cause));
}

NullPointerException NullPointerException::newInstance(String message, Exception cause) {
    return NullPointerException(new NullPointerExceptionImpl(message, cause));
}

/*** Implementation ***/

NullPointerExceptionImpl::NullPointerExceptionImpl() : ExceptionImpl() {
    //
}

NullPointerExceptionImpl::NullPointerExceptionImpl(String message) : ExceptionImpl(message) {
    //
}

NullPointerExceptionImpl::NullPointerExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    //
}

NullPointerExceptionImpl::NullPointerExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    //
}

NullPointerExceptionImpl::~NullPointerExceptionImpl() {
    //
}

NullPointerExceptionImpl::NullPointerExceptionImpl(const NullPointerExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* NullPointerExceptionImpl::debugClassName() {
    return "jam::lang::NullPointerException";
}
#endif

String NullPointerExceptionImpl::toString() {
    return null;
}

Class NullPointerExceptionImpl::getClass() {
    return NullPointerException::klass;
}
