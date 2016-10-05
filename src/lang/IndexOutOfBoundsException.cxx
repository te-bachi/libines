#include "jam/lang/IndexOutOfBoundsException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class IndexOutOfBoundsException::klass = Class::newInstance("jam::lang::IndexOutOfBoundsException");

/*** Reference ***/

IndexOutOfBoundsException::IndexOutOfBoundsException() : Exception() {
    //
}

IndexOutOfBoundsException::IndexOutOfBoundsException(const Reference& ref) : Exception(ref) {
    //
}

IndexOutOfBoundsException::IndexOutOfBoundsException(Implementation* impl) : Exception(impl) {
    //
}

IndexOutOfBoundsException::~IndexOutOfBoundsException() {
    //
}

IndexOutOfBoundsExceptionImpl& IndexOutOfBoundsException::operator*() {
    return (IndexOutOfBoundsExceptionImpl&) Exception::operator*();
}

IndexOutOfBoundsExceptionImpl* IndexOutOfBoundsException::operator->() {
    return (IndexOutOfBoundsExceptionImpl*) Exception::operator->();
}

const IndexOutOfBoundsException& IndexOutOfBoundsException::operator=(const Reference& ref) {
    return (IndexOutOfBoundsException&) Exception::operator=(ref);
}

const IndexOutOfBoundsException& IndexOutOfBoundsException::operator=(Implementation* impl) {
    return (IndexOutOfBoundsException&) Exception::operator=(impl);
}

IndexOutOfBoundsException IndexOutOfBoundsException::newInstance() {
    return IndexOutOfBoundsException(new IndexOutOfBoundsExceptionImpl());
}

IndexOutOfBoundsException IndexOutOfBoundsException::newInstance(String message) {
    return IndexOutOfBoundsException(new IndexOutOfBoundsExceptionImpl(message));
}

IndexOutOfBoundsException IndexOutOfBoundsException::newInstance(Exception cause) {
    return IndexOutOfBoundsException(new IndexOutOfBoundsExceptionImpl(cause));
}

IndexOutOfBoundsException IndexOutOfBoundsException::newInstance(String message, Exception cause) {
    return IndexOutOfBoundsException(new IndexOutOfBoundsExceptionImpl(message, cause));
}

/*** Implementation ***/

IndexOutOfBoundsExceptionImpl::IndexOutOfBoundsExceptionImpl() : ExceptionImpl() {
    //
}

IndexOutOfBoundsExceptionImpl::IndexOutOfBoundsExceptionImpl(String message) : ExceptionImpl(message) {
    //
}

IndexOutOfBoundsExceptionImpl::IndexOutOfBoundsExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    //
}

IndexOutOfBoundsExceptionImpl::IndexOutOfBoundsExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    //
}

IndexOutOfBoundsExceptionImpl::~IndexOutOfBoundsExceptionImpl() {
    //
}

IndexOutOfBoundsExceptionImpl::IndexOutOfBoundsExceptionImpl(const IndexOutOfBoundsExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* IndexOutOfBoundsExceptionImpl::debugClassName() {
    return "jam::lang::IndexOutOfBoundsException";
}
#endif

String IndexOutOfBoundsExceptionImpl::toString() {
    return null;
}

Class IndexOutOfBoundsExceptionImpl::getClass() {
    return IndexOutOfBoundsException::klass;
}
