#include "jam/sql/ResultSetMetaData.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class ResultSetMetaData::klass = Class::newInstance("jam::sql::ResultSetMetaData");

ResultSetMetaData::ResultSetMetaData() : Object() {
    //
}

ResultSetMetaData::ResultSetMetaData(const Reference& ref) : Object(ref) {
    //
}

ResultSetMetaData::ResultSetMetaData(Implementation* impl) : Object(impl) {
    //
}

ResultSetMetaData::~ResultSetMetaData() {
    //
}

ResultSetMetaDataImpl& ResultSetMetaData::operator*() {
    return (ResultSetMetaDataImpl&) Object::operator*();
}

ResultSetMetaDataImpl* ResultSetMetaData::operator->() {
    return (ResultSetMetaDataImpl*) Object::operator->();
}

const ResultSetMetaData& ResultSetMetaData::operator=(const Reference& ref) {
    return (ResultSetMetaData&) Object::operator=(ref);
}

const ResultSetMetaData& ResultSetMetaData::operator=(Implementation* impl) {
    return (ResultSetMetaData&) Object::operator=(impl);
}

/*** Implementation ***/

ResultSetMetaDataImpl::ResultSetMetaDataImpl() {
    //
}

ResultSetMetaDataImpl::~ResultSetMetaDataImpl() {
    //
}

ResultSetMetaDataImpl::ResultSetMetaDataImpl(const ResultSetMetaDataImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ResultSetMetaDataImpl::debugClassName() {
    return "jam::sql::ResultSetMetaData";
}
#endif
