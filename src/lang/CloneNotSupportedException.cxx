#include "jam/lang/CloneNotSupportedException.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::lang;

const Class CloneNotSupportedException::klass = Class::newInstance("jam::lang::CloneNotSupportedException");

CloneNotSupportedException::CloneNotSupportedException() : Exception() {
    //
}

CloneNotSupportedException::CloneNotSupportedException(const Reference& ref) : Exception(ref) {
    //
}

CloneNotSupportedException::CloneNotSupportedException(Implementation* impl) : Exception(impl) {
    //
}

CloneNotSupportedException::~CloneNotSupportedException() {
    //
}

CloneNotSupportedExceptionImpl& CloneNotSupportedException::operator*() {
    return (CloneNotSupportedExceptionImpl&) Exception::operator*();
}

CloneNotSupportedExceptionImpl* CloneNotSupportedException::operator->() {
    return (CloneNotSupportedExceptionImpl*) Exception::operator->();
}

const CloneNotSupportedException& CloneNotSupportedException::operator=(const Reference& ref) {
    return (CloneNotSupportedException&) Exception::operator=(ref);
}

const CloneNotSupportedException& CloneNotSupportedException::operator=(Implementation* impl) {
    return (CloneNotSupportedException&) Exception::operator=(impl);
}
