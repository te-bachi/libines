#include "jam/io/BufferedInputStream.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class BufferedInputStream::klass = Class::newInstance("jam::io::BufferedInputStream");

const int BufferedInputStream::DEFAULT_SIZE = 2048;

/*** Reference ***/

BufferedInputStream::BufferedInputStream() : InputStream() {
    //
}

BufferedInputStream::BufferedInputStream(const Reference& ref) : InputStream(ref) {
    //
}

BufferedInputStream::BufferedInputStream(Implementation* impl) : InputStream(impl) {
    //
}

BufferedInputStream::~BufferedInputStream() {
    //
}

BufferedInputStreamImpl& BufferedInputStream::operator*() {
    return (BufferedInputStreamImpl&) InputStream::operator*();
}

BufferedInputStreamImpl* BufferedInputStream::operator->() {
    return (BufferedInputStreamImpl*) InputStream::operator->();
}

const BufferedInputStream& BufferedInputStream::operator=(const Reference& ref) {
    return (BufferedInputStream&) InputStream::operator=(ref);
}

const BufferedInputStream& BufferedInputStream::operator=(Implementation* impl) {
    return (BufferedInputStream&) InputStream::operator=(impl);
}

BufferedInputStream BufferedInputStream::newInstance(InputStream in) {
    return BufferedInputStream(new BufferedInputStreamImpl(in));
}

BufferedInputStream BufferedInputStream::newInstance(InputStream in, int size) {
    return BufferedInputStream(new BufferedInputStreamImpl(in, size));
}

/*** Implementation ***/

BufferedInputStreamImpl::BufferedInputStreamImpl(InputStream in) {
    _in   = in;
    _size = BufferedInputStream::DEFAULT_SIZE;
}

BufferedInputStreamImpl::BufferedInputStreamImpl(InputStream in, int size) {
    _in   = in;
    _size = size;
}

BufferedInputStreamImpl::~BufferedInputStreamImpl() {
    
}

BufferedInputStreamImpl::BufferedInputStreamImpl(const BufferedInputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* BufferedInputStreamImpl::debugClassName() {
    return "jam::io::BufferedInputStream";
}
#endif

Class BufferedInputStreamImpl::getClass() {
    return BufferedInputStream::klass;
}
