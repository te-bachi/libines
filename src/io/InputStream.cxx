#include "jam/io/InputStream.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class InputStream::klass = Class::newInstance("jam::io::InputStream");

/*** Reference ***/

InputStream::InputStream() : Object() {
    //
}

InputStream::InputStream(const Reference& ref) : Object(ref) {
    //
}

InputStream::InputStream(Implementation* impl) : Object(impl) {
    //
}

InputStream::~InputStream() {
    //
}

InputStreamImpl& InputStream::operator*() {
    return (InputStreamImpl&) Object::operator*();
}

InputStreamImpl* InputStream::operator->() {
    return (InputStreamImpl*) Object::operator->();
}

const InputStream& InputStream::operator=(const Reference& ref) {
    return (InputStream&) Object::operator=(ref);
}

const InputStream& InputStream::operator=(Implementation* impl) {
    return (InputStream&) Object::operator=(impl);
}

/*** Implementation ***/

InputStreamImpl::InputStreamImpl() {
    
}

InputStreamImpl::~InputStreamImpl() {
    
}

InputStreamImpl::InputStreamImpl(const InputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* InputStreamImpl::debugClassName() {
    return "jam::io::InputStream";
}
#endif

Class InputStreamImpl::getClass() {
    return InputStream::klass;
}
