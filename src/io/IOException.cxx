#include "jam/io/IOException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;

const Class IOException::klass = Class::newInstance("jam::io::IOException");

/*** Reference ***/

IOException::IOException() : Exception() {
    //
}

IOException::IOException(const Reference& ref) : Exception(ref) {
    //
}

IOException::IOException(Implementation* impl) : Exception(impl) {
    //
}

IOException::~IOException() {
    //
}

IOExceptionImpl& IOException::operator*() {
    return (IOExceptionImpl&) Exception::operator*();
}

IOExceptionImpl* IOException::operator->() {
    return (IOExceptionImpl*) Exception::operator->();
}

const IOException& IOException::operator=(const Reference& ref) {
    return (IOException&) Exception::operator=(ref);
}

const IOException& IOException::operator=(Implementation* impl) {
    return (IOException&) Exception::operator=(impl);
}

IOException IOException::newInstance() {
    return IOException(new IOExceptionImpl());
}

IOException IOException::newInstance(String message) {
    return IOException(new IOExceptionImpl(message));
}

/*** Implementation ***/

IOExceptionImpl::IOExceptionImpl()  : ExceptionImpl() {
    
}

IOExceptionImpl::IOExceptionImpl(String message)  : ExceptionImpl(message) {
    
}

IOExceptionImpl::~IOExceptionImpl() {
    
}

IOExceptionImpl::IOExceptionImpl(const IOExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* IOExceptionImpl::debugClassName() {
    return "jam::io::IOException";
}
#endif

Object IOExceptionImpl::clone() {
    return null;
}

String IOExceptionImpl::toString() {
    return null;
}

Class IOExceptionImpl::getClass() {
    return IOException::klass;
}
