#include "jam/sql/ResultSet.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;
    
ResultSetImpl::ResultSetImpl() {
    
}

ResultSetImpl::~ResultSetImpl() {
    
}

ResultSetImpl::ResultSetImpl(const ResultSetImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ResultSetImpl::debugClassName() {
    return "jam::sql::ResultSet";
}
#endif

Object ResultSetImpl::clone() {
    
}

String ResultSetImpl::toString() {
    
}

Class ResultSetImpl::getClass() {
    return ResultSet::klass;
}

