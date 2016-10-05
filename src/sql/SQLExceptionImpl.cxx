#include "jam/sql/SQLException.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

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
