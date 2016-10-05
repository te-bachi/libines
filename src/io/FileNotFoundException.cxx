#include "jam/io/FileNotFoundException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;

const Class FileNotFoundException::klass = Class::newInstance("jam::io::FileNotFoundException");

/*** Reference ***/

FileNotFoundException::FileNotFoundException() : IOException() {
    //
}

FileNotFoundException::FileNotFoundException(const Reference& ref) : IOException(ref) {
    //
}

FileNotFoundException::FileNotFoundException(Implementation* impl) : IOException(impl) {
    //
}

FileNotFoundException::~FileNotFoundException() {
    //
}

FileNotFoundExceptionImpl& FileNotFoundException::operator*() {
    return (FileNotFoundExceptionImpl&) IOException::operator*();
}

FileNotFoundExceptionImpl* FileNotFoundException::operator->() {
    return (FileNotFoundExceptionImpl*) IOException::operator->();
}

const FileNotFoundException& FileNotFoundException::operator=(const Reference& ref) {
    return (FileNotFoundException&) IOException::operator=(ref);
}

const FileNotFoundException& FileNotFoundException::operator=(Implementation* impl) {
    return (FileNotFoundException&) IOException::operator=(impl);
}

FileNotFoundException FileNotFoundException::newInstance() {
    return FileNotFoundException(new FileNotFoundExceptionImpl());
}

FileNotFoundException FileNotFoundException::newInstance(String message) {
    return FileNotFoundException(new FileNotFoundExceptionImpl(message));
}

/*** Implementation ***/

FileNotFoundExceptionImpl::FileNotFoundExceptionImpl() : IOExceptionImpl() {
    //
}

FileNotFoundExceptionImpl::FileNotFoundExceptionImpl(String message) : IOExceptionImpl(message) {
    //
}

FileNotFoundExceptionImpl::~FileNotFoundExceptionImpl() {
    
}

FileNotFoundExceptionImpl::FileNotFoundExceptionImpl(const FileNotFoundExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* FileNotFoundExceptionImpl::debugClassName() {
    return "jam::io::FileNotFoundException";
}
#endif

Object FileNotFoundExceptionImpl::clone() {
    return null;
}

String FileNotFoundExceptionImpl::toString() {
    return null;
}

Class FileNotFoundExceptionImpl::getClass() {
    return FileNotFoundException::klass;
}
