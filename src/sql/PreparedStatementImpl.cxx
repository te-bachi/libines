#include "jam/sql/PreparedStatement.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;
    
PreparedStatementImpl::PreparedStatementImpl() {
    
}

PreparedStatementImpl::~PreparedStatementImpl() {
    
}

PreparedStatementImpl::PreparedStatementImpl(const PreparedStatementImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* PreparedStatementImpl::debugClassName() {
    return "jam::sql::PreparedStatement";
}
#endif

Object PreparedStatementImpl::clone() {
    
}

String PreparedStatementImpl::toString() {
    
}

Class PreparedStatementImpl::getClass() {
    return PreparedStatement::klass;
}

