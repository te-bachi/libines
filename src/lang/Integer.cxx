#include "jam/lang/Integer.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Long.hxx"

using namespace jam::lang;

const Class Integer::klass = Class::newInstance("jam::lang::Integer");

/*** Reference ***/

Integer::Integer() : Number() {
    //
}

Integer::Integer(const Reference& ref) : Number(ref) {
    //
}

Integer::Integer(Implementation* impl) : Number(impl) {
    //
}

Integer::~Integer() {
    //
}

IntegerImpl& Integer::operator*() {
    return (IntegerImpl&) Number::operator*();
}

IntegerImpl* Integer::operator->() {
    return (IntegerImpl*) Number::operator->();
}

const Integer& Integer::operator=(const Reference& ref) {
    return (Integer&) Number::operator=(ref);
}

const Integer& Integer::operator=(Implementation* impl) {
    return (Integer&) Number::operator=(impl);
}

Integer Integer::newInstance(int value) {
    return Integer(new IntegerImpl(value));
}

int Integer::parseInt(String str) {
    return (int) Long::parseLong(str, Number::DECIMAL);
}

int Integer::parseInt(String str, Number::Format format) {
    return (int) Long::parseLong(str, format);
}

/*** Implementation ***/

IntegerImpl::IntegerImpl(int value) {
    _value = value;
}

IntegerImpl::~IntegerImpl() {
    
}

IntegerImpl::IntegerImpl(const IntegerImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* IntegerImpl::debugClassName() {
    return "jam::lang::Integer";
}
#endif

Class IntegerImpl::getClass() {
    return Integer::klass;
}

String IntegerImpl::toString() {
    return String::valueOf(_value);
}

int IntegerImpl::hashCode() {
    return _value;
}

boolean IntegerImpl::equals(Object obj) {
    if (obj->instanceOf(Integer::klass)) {
        return IntegerImpl::equals((Integer) obj);
    }
    
    return ObjectImpl::equals(obj);
}

boolean IntegerImpl::equals(Integer value) {
    if (_value == value->intValue()) {
        return true;
    }
    
    return false;
}

byte IntegerImpl::byteValue() {
    return (byte) _value;
}

double IntegerImpl::doubleValue() {
    return (double) _value;
}

float IntegerImpl::floatValue() {
    return (float) _value;
}

int IntegerImpl::intValue() {
    return (int) _value;
}

long IntegerImpl::longValue() {
    return (long) _value;
}

short IntegerImpl::shortValue() {
    return (short) _value;
}
