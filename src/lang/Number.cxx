#include "jam/lang/Number.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::lang;

const Class Number::klass = Class::newInstance("jam::lang::Number");

/*** Reference ***/

Number::Number() : Object() {
    //
}

Number::Number(const Reference& ref) : Object(ref) {
    //
}

Number::Number(Implementation* impl) : Object(impl) {
    //
}

Number::~Number() {
    //
}

NumberImpl& Number::operator*() {
    return (NumberImpl&) Object::operator*();
}

NumberImpl* Number::operator->() {
    return (NumberImpl*) Object::operator->();
}

const Number& Number::operator=(const Reference& ref) {
    return (Number&) Object::operator=(ref);
}

const Number& Number::operator=(Implementation* impl) {
    return (Number&) Object::operator=(impl);
}

/*** Implementation ***/

NumberImpl::NumberImpl() {
    
}

NumberImpl::~NumberImpl() {
    
}

NumberImpl::NumberImpl(const NumberImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* NumberImpl::debugClassName() {
    return "jam::lang::Number";
}
#endif

Class NumberImpl::getClass() {
    return Number::klass;
}
