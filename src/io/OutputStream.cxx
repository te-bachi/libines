#include "jam/io/OutputStream.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class OutputStream::klass = Class::newInstance("jam::io::OutputStream");

/*** Reference ***/

OutputStream::OutputStream() : Object() {
    //
}

OutputStream::OutputStream(const Reference& ref) : Object(ref) {
    //
}

OutputStream::OutputStream(Implementation* impl) : Object(impl) {
    //
}

OutputStream::~OutputStream() {
    //
}

OutputStreamImpl& OutputStream::operator*() {
    return (OutputStreamImpl&) Object::operator*();
}

OutputStreamImpl* OutputStream::operator->() {
    return (OutputStreamImpl*) Object::operator->();
}

const OutputStream& OutputStream::operator=(const Reference& ref) {
    return (OutputStream&) Object::operator=(ref);
}

const OutputStream& OutputStream::operator=(Implementation* impl) {
    return (OutputStream&) Object::operator=(impl);
}

/*** Implementation ***/

OutputStreamImpl::OutputStreamImpl() {
    
}

OutputStreamImpl::~OutputStreamImpl() {
    
}

OutputStreamImpl::OutputStreamImpl(const OutputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* OutputStreamImpl::debugClassName() {
    return "jam::io::OutputStream";
}
#endif

Class OutputStreamImpl::getClass() {
    return OutputStream::klass;
}
