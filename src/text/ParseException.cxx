#include "jam/text/ParseException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::text;
using namespace jam::lang;

const Class ParseException::klass = Class::newInstance("jam::text::ParseException");

/*** Reference ***/

ParseException::ParseException() : Exception() {
    //
}

ParseException::ParseException(const Reference& ref) : Exception(ref) {
    //
}

ParseException::ParseException(Implementation* impl) : Exception(impl) {
    //
}

ParseException::~ParseException() {
    //
}

ParseExceptionImpl& ParseException::operator*() {
    return (ParseExceptionImpl&) Exception::operator*();
}

ParseExceptionImpl* ParseException::operator->() {
    return (ParseExceptionImpl*) Exception::operator->();
}

const ParseException& ParseException::operator=(const Reference& ref) {
    return (ParseException&) Exception::operator=(ref);
}

const ParseException& ParseException::operator=(Implementation* impl) {
    return (ParseException&) Exception::operator=(impl);
}

ParseException ParseException::newInstance() {
    return ParseException(new ParseExceptionImpl());
}

ParseException ParseException::newInstance(String message) {
    return ParseException(new ParseExceptionImpl(message));
}

ParseException ParseException::newInstance(Exception cause) {
    return ParseException(new ParseExceptionImpl(cause));
}

ParseException ParseException::newInstance(String message, Exception cause) {
    return ParseException(new ParseExceptionImpl(message, cause));
}

/*** Implementation ***/

ParseExceptionImpl::ParseExceptionImpl() : ExceptionImpl() {
    //
}

ParseExceptionImpl::ParseExceptionImpl(String message) : ExceptionImpl(message) {
    //
}

ParseExceptionImpl::ParseExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    //
}

ParseExceptionImpl::ParseExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    //
}

ParseExceptionImpl::~ParseExceptionImpl() {
    //
}

ParseExceptionImpl::ParseExceptionImpl(const ParseExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ParseExceptionImpl::debugClassName() {
    return "jam::text::ParseException";
}
#endif

Class ParseExceptionImpl::getClass() {
    return ParseException::klass;
}
