#include "jam/lang/ByteArray.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

using namespace jam::lang;

const Class ByteArray::klass = Class::newInstance("jam::lang::ByteArray");

/*** Reference ***/

ByteArray::ByteArray() : Object() {
    //
}

ByteArray::ByteArray(const Reference& ref) : Object(ref) {
    //
}

ByteArray::ByteArray(Implementation* impl) : Object(impl) {
    //
}

ByteArray::~ByteArray() {
    //
}

ByteArrayImpl& ByteArray::operator*() {
    return (ByteArrayImpl&) Object::operator*();
}

ByteArrayImpl* ByteArray::operator->() {
    return (ByteArrayImpl*) Object::operator->();
}

const ByteArray& ByteArray::operator=(const Reference& ref) {
    return (ByteArray&) Object::operator=(ref);
}

const ByteArray& ByteArray::operator=(Implementation* impl) {
    return (ByteArray&) Object::operator=(impl);
}

byte& ByteArray::operator[](int index) {
    return (byte&) operator->()->_byteArray[index];
}

ByteArray ByteArray::newInstance(int size) {
    return ByteArray(new ByteArrayImpl(size));
}

/*** Implementation ***/

ByteArrayImpl::ByteArrayImpl(int size) {
    _byteArray = new byte[size];
    _length    = size;
}

ByteArrayImpl::ByteArrayImpl(const ByteArrayImpl& copy) {
    //
}

ByteArrayImpl::~ByteArrayImpl() {
    delete[] _byteArray;
}

#ifdef __DEBUG__
const char* ByteArrayImpl::debugClassName() {
    return "jam::lang::ByteArray";
}
#endif

Class ByteArrayImpl::getClass() {
    return ByteArray::klass;
}

int ByteArrayImpl::length() {
    return _length;
}
