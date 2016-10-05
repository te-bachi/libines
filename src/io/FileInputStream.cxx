#include "jam/io/FileInputStream.hxx"
#include "jam/lang/Class.hxx"
#include "jam/io/File.hxx"

using namespace jam::io;
using namespace jam::lang;

const Class FileInputStream::klass = Class::newInstance("jam::io::FileInputStream");

/*** Reference ***/

FileInputStream::FileInputStream() : InputStream() {
    //
}

FileInputStream::FileInputStream(const Reference& ref) : InputStream(ref) {
    //
}

FileInputStream::FileInputStream(Implementation* impl) : InputStream(impl) {
    //
}

FileInputStream::~FileInputStream() {
    //
}

FileInputStreamImpl& FileInputStream::operator*() {
    return (FileInputStreamImpl&) InputStream::operator*();
}

FileInputStreamImpl* FileInputStream::operator->() {
    return (FileInputStreamImpl*) InputStream::operator->();
}

const FileInputStream& FileInputStream::operator=(const Reference& ref) {
    return (FileInputStream&) InputStream::operator=(ref);
}

const FileInputStream& FileInputStream::operator=(Implementation* impl) {
    return (FileInputStream&) InputStream::operator=(impl);
}

FileInputStream FileInputStream::newInstance(File file) {
    return FileInputStream(new FileInputStreamImpl(file));
}

FileInputStream FileInputStream::newInstance(String pathname) {
    return FileInputStream(new FileInputStreamImpl(pathname));
}

/*** Implementation ***/

FileInputStreamImpl::FileInputStreamImpl(File file) {
    
}

FileInputStreamImpl::FileInputStreamImpl(String pathname) {
    
}

FileInputStreamImpl::~FileInputStreamImpl() {
    
}

FileInputStreamImpl::FileInputStreamImpl(const FileInputStreamImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* FileInputStreamImpl::debugClassName() {
    return "jam::io::FileInputStream";
}
#endif

Class FileInputStreamImpl::getClass() {
    return FileInputStream::klass;
}
