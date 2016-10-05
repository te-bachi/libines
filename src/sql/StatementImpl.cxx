#include "jam/sql/Statement.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;
    
StatementImpl::StatementImpl() {
    
}

StatementImpl::~StatementImpl() {
    
}

StatementImpl::StatementImpl(const StatementImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StatementImpl::debugClassName() {
    return "jam::sql::Statement";
}
#endif

Object StatementImpl::clone() {
    
}

String StatementImpl::toString() {
    
}

Class StatementImpl::getClass() {
    return Statement::klass;
}

