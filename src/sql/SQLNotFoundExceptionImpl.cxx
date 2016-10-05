#include "jam/sql/SQLNotFoundException.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

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

