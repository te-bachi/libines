#include "jam/io/FileOutputStream.hxx"
#include "jam/lang/Class.hxx"
#include "jam/io/File.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class FileOutputStream::klass = Class::newInstance("jam::io::FileOutputStream");

/*** Reference ***/

FileOutputStream::FileOutputStream() : OutputStream() {
    //
}

FileOutputStream::FileOutputStream(const Reference& ref) : OutputStream(ref) {
    //
}

FileOutputStream::FileOutputStream(Implementation* impl) : OutputStream(impl) {
    //
}

FileOutputStream::~FileOutputStream() {
    //
}

FileOutputStreamImpl& FileOutputStream::operator*() {
    return (FileOutputStreamImpl&) OutputStream::operator*();
}

FileOutputStreamImpl* FileOutputStream::operator->() {
    return (FileOutputStreamImpl*) OutputStream::operator->();
}

const FileOutputStream& FileOutputStream::operator=(const Reference& ref) {
    return (FileOutputStream&) OutputStream::operator=(ref);
}

const FileOutputStream& FileOutputStream::operator=(Implementation* impl) {
    return (FileOutputStream&) OutputStream::operator=(impl);
}

FileOutputStream FileOutputStream::newInstance(File file) {
    return FileOutputStream(new FileOutputStreamImpl(file));
}

FileOutputStream FileOutputStream::newInstance(File file, boolean append) {
    return FileOutputStream(new FileOutputStreamImpl(file, append));
}

FileOutputStream FileOutputStream::newInstance(String pathname) {
    return FileOutputStream(new FileOutputStreamImpl(pathname));
}

FileOutputStream FileOutputStream::newInstance(String pathname, boolean append) {
    return FileOutputStream(new FileOutputStreamImpl(pathname, append));
}

/*** Implementation ***/

FileOutputStreamImpl::FileOutputStreamImpl(File file) {
    
}

FileOutputStreamImpl::FileOutputStreamImpl(File file, boolean append) {
    
}

FileOutputStreamImpl::FileOutputStreamImpl(String pathname) {
    
}

FileOutputStreamImpl::FileOutputStreamImpl(String pathname, boolean append) {
    
}

FileOutputStreamImpl::~FileOutputStreamImpl() {
    
}

FileOutputStreamImpl::FileOutputStreamImpl(const FileOutputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* FileOutputStreamImpl::debugClassName() {
    return "jam::io::FileOutputStream";
}
#endif

Class FileOutputStreamImpl::getClass() {
    return FileOutputStream::klass;
}
