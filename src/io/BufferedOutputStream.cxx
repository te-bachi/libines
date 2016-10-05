#include "jam/io/BufferedOutputStream.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class BufferedOutputStream::klass = Class::newInstance("jam::io::BufferedOutputStream");

const int BufferedOutputStream::DEFAULT_SIZE = 512;

/*** Reference ***/

BufferedOutputStream::BufferedOutputStream() : OutputStream() {
    //
}

BufferedOutputStream::BufferedOutputStream(const Reference& ref) : OutputStream(ref) {
    //
}

BufferedOutputStream::BufferedOutputStream(Implementation* impl) : OutputStream(impl) {
    //
}

BufferedOutputStream::~BufferedOutputStream() {
    //
}

BufferedOutputStreamImpl& BufferedOutputStream::operator*() {
    return (BufferedOutputStreamImpl&) OutputStream::operator*();
}

BufferedOutputStreamImpl* BufferedOutputStream::operator->() {
    return (BufferedOutputStreamImpl*) OutputStream::operator->();
}

const BufferedOutputStream& BufferedOutputStream::operator=(const Reference& ref) {
    return (BufferedOutputStream&) OutputStream::operator=(ref);
}

const BufferedOutputStream& BufferedOutputStream::operator=(Implementation* impl) {
    return (BufferedOutputStream&) OutputStream::operator=(impl);
}

BufferedOutputStream BufferedOutputStream::newInstance(OutputStream out) {
    return BufferedOutputStream(new BufferedOutputStreamImpl(out));
}

BufferedOutputStream BufferedOutputStream::newInstance(OutputStream out, int size) {
    return BufferedOutputStream(new BufferedOutputStreamImpl(out, size));
}

/*** Implementation ***/

BufferedOutputStreamImpl::BufferedOutputStreamImpl(OutputStream out) {
    _out  = out;
    _size = BufferedOutputStream::DEFAULT_SIZE;
}

BufferedOutputStreamImpl::BufferedOutputStreamImpl(OutputStream out, int size) {
    _out  = out;
    _size = size;
}

BufferedOutputStreamImpl::~BufferedOutputStreamImpl() {
    
}

BufferedOutputStreamImpl::BufferedOutputStreamImpl(const BufferedOutputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* BufferedOutputStreamImpl::debugClassName() {
    return "jam::io::BufferedOutputStream";
}
#endif

Class BufferedOutputStreamImpl::getClass() {
    return BufferedOutputStream::klass;
}
