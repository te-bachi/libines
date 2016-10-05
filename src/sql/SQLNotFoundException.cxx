#include "jam/sql/SQLNotFoundException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class SQLNotFoundException::klass = Class::newInstance("jam::sql::SQLNotFoundException");

/*** Reference ***/

SQLNotFoundException::SQLNotFoundException() : SQLException() {
    //
}

SQLNotFoundException::SQLNotFoundException(const Reference& ref) : SQLException(ref) {
    //
}

SQLNotFoundException::SQLNotFoundException(Implementation* impl) : SQLException(impl) {
    //
}

SQLNotFoundException::~SQLNotFoundException() {
    //
}

SQLNotFoundExceptionImpl& SQLNotFoundException::operator*() {
    return (SQLNotFoundExceptionImpl&) SQLException::operator*();
}

SQLNotFoundExceptionImpl* SQLNotFoundException::operator->() {
    return (SQLNotFoundExceptionImpl*) SQLException::operator->();
}

const SQLNotFoundException& SQLNotFoundException::operator=(const Reference& ref) {
    return (SQLNotFoundException&) SQLException::operator=(ref);
}

const SQLNotFoundException& SQLNotFoundException::operator=(Implementation* impl) {
    return (SQLNotFoundException&) SQLException::operator=(impl);
}

SQLNotFoundException SQLNotFoundException::newInstance() {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl());
}

SQLNotFoundException SQLNotFoundException::newInstance(int sqlcode) {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl(sqlcode));
}

SQLNotFoundException SQLNotFoundException::newInstance(String message) {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl(message));
}

SQLNotFoundException SQLNotFoundException::newInstance(int sqlcode, String message) {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl(sqlcode, message));
}

SQLNotFoundException SQLNotFoundException::newInstance(Exception cause) {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl(cause));
}

SQLNotFoundException SQLNotFoundException::newInstance(String message, Exception cause) {
    return SQLNotFoundException(new SQLNotFoundExceptionImpl(message, cause));
}

/*** Implementation ***/

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl() : SQLExceptionImpl() {
    //
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(int sqlCode) : SQLExceptionImpl(sqlCode) {
    //
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(String message) : SQLExceptionImpl(message) {
    //
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(int sqlCode, String message) : SQLExceptionImpl(sqlCode, message) {
    //
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(Exception cause) : SQLExceptionImpl(cause) {
    //
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(String message, Exception cause) : SQLExceptionImpl(message, cause) {
    //
}

SQLNotFoundExceptionImpl::~SQLNotFoundExceptionImpl() {
    
}

SQLNotFoundExceptionImpl::SQLNotFoundExceptionImpl(const SQLNotFoundExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* SQLNotFoundExceptionImpl::debugClassName() {
    return "jam::sql::SQLNotFoundException";
}
#endif

Class SQLNotFoundExceptionImpl::getClass() {
    return SQLNotFoundException::klass;
}
