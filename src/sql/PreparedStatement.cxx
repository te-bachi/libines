#include "jam/sql/PreparedStatement.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::sql;
using namespace jam::lang;

const Class PreparedStatement::klass = Class::newInstance("jam::sql::PreparedStatement");

PreparedStatement::PreparedStatement() : Object() {
    //
}

PreparedStatement::PreparedStatement(const Reference& ref) : Object(ref) {
    //
}

PreparedStatement::PreparedStatement(Implementation* impl) : Object(impl) {
    //
}

PreparedStatement::PreparedStatement(const PreparedStatement& ref) : Object(ref) {
    //
}

PreparedStatement::PreparedStatement(PreparedStatementImpl* impl) : Object(impl) {
    //
}

PreparedStatement::~PreparedStatement() {
    //
}

PreparedStatementImpl& PreparedStatement::operator*() {
    return (PreparedStatementImpl&) Object::operator*();
}

PreparedStatementImpl* PreparedStatement::operator->() {
    return (PreparedStatementImpl*) Object::operator->();
}

const PreparedStatement& PreparedStatement::operator=(const Reference& ref) {
    return (PreparedStatement&) Object::operator=(ref);
}

const PreparedStatement& PreparedStatement::operator=(Implementation* impl) {
    return (PreparedStatement&) Object::operator=(impl);
}

const PreparedStatement& PreparedStatement::operator=(const PreparedStatement& ref) {
    return (PreparedStatement&) Object::operator=(ref);
}

const PreparedStatement& PreparedStatement::operator=(PreparedStatementImpl* impl) {
    return (PreparedStatement&) Object::operator=(impl);
}

PreparedStatement PreparedStatement::newInstance() {
    return PreparedStatement(new PreparedStatementImpl());
}

