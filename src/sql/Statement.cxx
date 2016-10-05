#include "jam/sql/Statement.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class Statement::klass = Class::newInstance("jam::sql::Statement");

/*** Reference ***/

Statement::Statement() : Object() {
    //
}

Statement::Statement(const Reference& ref) : Object(ref) {
    //
}

Statement::Statement(Implementation* impl) : Object(impl) {
    //
}

Statement::~Statement() {
    //
}

StatementImpl& Statement::operator*() {
    return (StatementImpl&) Object::operator*();
}

StatementImpl* Statement::operator->() {
    return (StatementImpl*) Object::operator->();
}

const Statement& Statement::operator=(const Reference& ref) {
    return (Statement&) Object::operator=(ref);
}

const Statement& Statement::operator=(Implementation* impl) {
    return (Statement&) Object::operator=(impl);
}

/*** Implementation ***/

StatementImpl::StatementImpl() {
    //
}

StatementImpl::~StatementImpl() {
    //
}

StatementImpl::StatementImpl(const StatementImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StatementImpl::debugClassName() {
    return "jam::sql::Statement";
}
#endif
