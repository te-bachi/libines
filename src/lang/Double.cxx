#include "jam/lang/Double.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Long.hxx"

#include <stdlib.h>

using namespace jam::lang;

const Class Double::klass = Class::newInstance("jam::lang::Double");

/*** Reference ***/

Double::Double() : Number() {
    //
}

Double::Double(const Reference& ref) : Number(ref) {
    //
}

Double::Double(Implementation* impl) : Number(impl) {
    //
}

Double::~Double() {
    //
}

DoubleImpl& Double::operator*() {
    return (DoubleImpl&) Number::operator*();
}

DoubleImpl* Double::operator->() {
    return (DoubleImpl*) Number::operator->();
}

const Double& Double::operator=(const Reference& ref) {
    return (Double&) Number::operator=(ref);
}

const Double& Double::operator=(Implementation* impl) {
    return (Double&) Number::operator=(impl);
}

Double Double::newInstance(double value) {
    return Double(new DoubleImpl(value));
}

Double Double::valueOf(String str) {
    return Double(new DoubleImpl(atof(str->toChar())));
}

double Double::parseDouble(String str) {
    return atof(str->toChar());
}

/*** Implementation ***/

DoubleImpl::DoubleImpl(double value) {
    _value = value;
}

DoubleImpl::~DoubleImpl() {
    
}

DoubleImpl::DoubleImpl(const DoubleImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* DoubleImpl::debugClassName() {
    return "jam::lang::Double";
}
#endif

Class DoubleImpl::getClass() {
    return Double::klass;
}

String DoubleImpl::toString() {
    return String::valueOf((long) _value);
}

int DoubleImpl::hashCode() {
    return _value;
}

boolean DoubleImpl::equals(Object obj) {
    if (obj->instanceOf(Double::klass)) {
        return DoubleImpl::equals((Double) obj);
    }
    
    return ObjectImpl::equals(obj);
}

boolean DoubleImpl::equals(Double value) {
    if (_value == value->doubleValue()) {
        return true;
    }
    
    return false;
}

byte DoubleImpl::byteValue() {
    return (byte) _value;
}

double DoubleImpl::doubleValue() {
    return (double) _value;
}

float DoubleImpl::floatValue() {
    return (float) _value;
}

int DoubleImpl::intValue() {
    return (int) _value;
}

long DoubleImpl::longValue() {
    return (long) _value;
}

short DoubleImpl::shortValue() {
    return (short) _value;
}
