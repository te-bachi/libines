#include "jam/sql/Connection.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class Connection::klass = Class::newInstance("jam::sql::Connection");

/*** Reference ***/

Connection::Connection() : Object() {
    //
}

Connection::Connection(const Reference& ref) : Object(ref) {
    //
}

Connection::Connection(Implementation* impl) : Object(impl) {
    //
}

Connection::~Connection() {
    //
}

ConnectionImpl& Connection::operator*() {
    return (ConnectionImpl&) Object::operator*();
}

ConnectionImpl* Connection::operator->() {
    return (ConnectionImpl*) Object::operator->();
}

const Connection& Connection::operator=(const Reference& ref) {
    return (Connection&) Object::operator=(ref);
}

const Connection& Connection::operator=(Implementation* impl) {
    return (Connection&) Object::operator=(impl);
}

/*** Implementation ***/

ConnectionImpl::ConnectionImpl() {
    //
}

ConnectionImpl::~ConnectionImpl() {
    //
}

ConnectionImpl::ConnectionImpl(const ConnectionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ConnectionImpl::debugClassName() {
    return "jam::sql::Connection";
}
#endif
