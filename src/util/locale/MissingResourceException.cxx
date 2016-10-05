#include "jam/util/locale/MissingResourceException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::util::locale;

const Class MissingResourceException::klass = Class::newInstance("jam::util::locale::MissingResourceException");

/*** Reference ***/

MissingResourceException::MissingResourceException() : Exception() {
    //
}

MissingResourceException::MissingResourceException(const Reference& ref) : Exception(ref) {
    //
}

MissingResourceException::MissingResourceException(Implementation* impl) : Exception(impl) {
    //
}

MissingResourceException::~MissingResourceException() {
    //
}

MissingResourceExceptionImpl& MissingResourceException::operator*() {
    return (MissingResourceExceptionImpl&) Exception::operator*();
}

MissingResourceExceptionImpl* MissingResourceException::operator->() {
    return (MissingResourceExceptionImpl*) Exception::operator->();
}

const MissingResourceException& MissingResourceException::operator=(const Reference& ref) {
    return (MissingResourceException&) Exception::operator=(ref);
}

const MissingResourceException& MissingResourceException::operator=(Implementation* impl) {
    return (MissingResourceException&) Exception::operator=(impl);
}

MissingResourceException MissingResourceException::newInstance() {
    return MissingResourceException(new MissingResourceExceptionImpl());
}

MissingResourceException MissingResourceException::newInstance(String message) {
    return MissingResourceException(new MissingResourceExceptionImpl(message));
}

MissingResourceException MissingResourceException::newInstance(Exception cause) {
    return MissingResourceException(new MissingResourceExceptionImpl(cause));
}

MissingResourceException MissingResourceException::newInstance(String message, Exception cause) {
    return MissingResourceException(new MissingResourceExceptionImpl(message, cause));
}

/*** Implementation ***/

MissingResourceExceptionImpl::MissingResourceExceptionImpl() : ExceptionImpl() {
    //
}

MissingResourceExceptionImpl::MissingResourceExceptionImpl(String message) : ExceptionImpl(message) {
    //
}

MissingResourceExceptionImpl::MissingResourceExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    //
}

MissingResourceExceptionImpl::MissingResourceExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    //
}

MissingResourceExceptionImpl::~MissingResourceExceptionImpl() {
    //
}

MissingResourceExceptionImpl::MissingResourceExceptionImpl(const MissingResourceExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* MissingResourceExceptionImpl::debugClassName() {
    return "jam::util::locale::MissingResourceException";
}
#endif

String MissingResourceExceptionImpl::toString() {
    return null;
}

Class MissingResourceExceptionImpl::getClass() {
    return MissingResourceException::klass;
}
