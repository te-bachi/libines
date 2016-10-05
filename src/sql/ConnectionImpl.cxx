#include "jam/sql/Connection.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;
    
ConnectionImpl::ConnectionImpl() {
    
}

ConnectionImpl::~ConnectionImpl() {
    
}

ConnectionImpl::ConnectionImpl(const ConnectionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ConnectionImpl::debugClassName() {
    return "jam::sql::Connection";
}
#endif

Object ConnectionImpl::clone() {
    
}

String ConnectionImpl::toString() {
    
}

Class ConnectionImpl::getClass() {
    return Connection::klass;
}

