#include "jam/sql/SQLException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class SQLException::klass = Class::newInstance("jam::sql::SQLException");

/*** Reference ***/

SQLException::SQLException() : Exception() {
    //
}

SQLException::SQLException(const Reference& ref) : Exception(ref) {
    //
}

SQLException::SQLException(Implementation* impl) : Exception(impl) {
    //
}

SQLException::~SQLException() {
    //
}

SQLExceptionImpl& SQLException::operator*() {
    return (SQLExceptionImpl&) Exception::operator*();
}

SQLExceptionImpl* SQLException::operator->() {
    return (SQLExceptionImpl*) Exception::operator->();
}

const SQLException& SQLException::operator=(const Reference& ref) {
    return (SQLException&) Exception::operator=(ref);
}

const SQLException& SQLException::operator=(Implementation* impl) {
    return (SQLException&) Exception::operator=(impl);
}

SQLException SQLException::newInstance() {
    return SQLException(new SQLExceptionImpl());
}

SQLException SQLException::newInstance(int sqlcode) {
    return SQLException(new SQLExceptionImpl(sqlcode));
}

SQLException SQLException::newInstance(String message) {
    return SQLException(new SQLExceptionImpl(message));
}

SQLException SQLException::newInstance(int sqlcode, String message) {
    return SQLException(new SQLExceptionImpl(sqlcode, message));
}

SQLException SQLException::newInstance(Exception cause) {
    return SQLException(new SQLExceptionImpl(cause));
}

SQLException SQLException::newInstance(String message, Exception cause) {
    return SQLException(new SQLExceptionImpl(message, cause));
}

/*** Implementation ***/

SQLExceptionImpl::SQLExceptionImpl() : ExceptionImpl() {
    _sqlCode = 0;
}

SQLExceptionImpl::SQLExceptionImpl(int sqlCode) : ExceptionImpl() {
    _sqlCode = sqlCode;
}

SQLExceptionImpl::SQLExceptionImpl(String message) : ExceptionImpl(message) {
    _sqlCode = 0;
}

SQLExceptionImpl::SQLExceptionImpl(int sqlCode, String message) : ExceptionImpl(message) {
    _sqlCode = sqlCode;
}

SQLExceptionImpl::SQLExceptionImpl(Exception cause) : ExceptionImpl(cause) {
    _sqlCode = 0;
}

SQLExceptionImpl::SQLExceptionImpl(String message, Exception cause) : ExceptionImpl(message, cause) {
    _sqlCode = 0;
}

SQLExceptionImpl::~SQLExceptionImpl() {
    //
}

SQLExceptionImpl::SQLExceptionImpl(const SQLExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* SQLExceptionImpl::debugClassName() {
    return "jam::sql::SQLException";
}
#endif

Class SQLExceptionImpl::getClass() {
    return SQLException::klass;
}

int SQLExceptionImpl::getSqlCode() {
    return _sqlCode;
}
