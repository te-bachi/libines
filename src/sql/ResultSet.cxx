#include "jam/sql/ResultSet.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class ResultSet::klass = Class::newInstance("jam::sql::ResultSet");

ResultSet::ResultSet() : Object() {
    //
}

ResultSet::ResultSet(const Reference& ref) : Object(ref) {
    //
}

ResultSet::ResultSet(Implementation* impl) : Object(impl) {
    //
}

ResultSet::~ResultSet() {
    //
}

ResultSetImpl& ResultSet::operator*() {
    return (ResultSetImpl&) Object::operator*();
}

ResultSetImpl* ResultSet::operator->() {
    return (ResultSetImpl*) Object::operator->();
}

const ResultSet& ResultSet::operator=(const Reference& ref) {
    return (ResultSet&) Object::operator=(ref);
}

const ResultSet& ResultSet::operator=(Implementation* impl) {
    return (ResultSet&) Object::operator=(impl);
}

/*** Implementation ***/

ResultSetImpl::ResultSetImpl() {
    //
}

ResultSetImpl::~ResultSetImpl() {
    //
}

ResultSetImpl::ResultSetImpl(const ResultSetImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ResultSetImpl::debugClassName() {
    return "jam::sql::ResultSet";
}
#endif
