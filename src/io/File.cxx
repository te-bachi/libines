#include "jam/io/File.hxx"
#include "jam/io/IOException.hxx"
#include "jam/io/FileNotFoundException.hxx"
#include "jam/lang/Class.hxx"

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


#define FILE_PERMISSION S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define DIR_PERMISSION  S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH

using namespace jam::io;
using namespace jam::lang;

const Class File::klass = Class::newInstance("jam::io::File");

static void throwIOException() {
#if defined (__SVR4) && defined (__sun)
    throw IOException::newInstance(strerror(errno));
#else
    char buf[1024];
    char *error;
    error = strerror_r(errno, buf, sizeof(buf));
    throw IOException::newInstance(error);
#endif
}

static void throwFileNotFoundException() {
#if defined (__SVR4) && defined (__sun)
    throw FileNotFoundException::newInstance(strerror(errno));
#else
    char buf[1024];
    char *error;
    error = strerror_r(errno, buf, sizeof(buf));
    throw FileNotFoundException::newInstance(error);
#endif
}

/*** Reference ***/

File::File() : Object() {
    //
}

File::File(const Reference& ref) : Object(ref) {
    //
}

File::File(Implementation* impl) : Object(impl) {
    //
}

File::~File() {
    //
}

FileImpl& File::operator*() {
    return (FileImpl&) Object::operator*();
}

FileImpl* File::operator->() {
    return (FileImpl*) Object::operator->();
}

const File& File::operator=(const Reference& ref) {
    return (File&) Object::operator=(ref);
}

const File& File::operator=(Implementation* impl) {
    return (File&) Object::operator=(impl);
}

File File::newInstance(String pathname) {
    return File(new FileImpl(pathname));
}

/*** Implementation ***/

FileImpl::FileImpl(String pathname) {
    _pathname = pathname;
}

FileImpl::~FileImpl() {
    
}

FileImpl::FileImpl(const FileImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* FileImpl::debugClassName() {
    return "jam::io::File";
}
#endif

Class FileImpl::getClass() {
    return File::klass;
}

void FileImpl::createFile() {
    struct stat sb;
    const char* path;
    int         fd;
    
    path = _pathname->toChar();
    
    // See if the file exists
    if (stat(path, &sb) == 0) {
        throw IOException::newInstance("File exist");
    }
    
    // Create the file
    fd = open(path, O_WRONLY | O_CREAT, FILE_PERMISSION);
    if (fd == -1 || fstat(fd, &sb) || close(fd)) {
        throwIOException();
    }
}

void FileImpl::createDirectory() {
    struct stat sb;
    const char* path;
    
    path = _pathname->toChar();
    
    // See if the directory exists
    if (stat(path, &sb) == 0) {
        throw IOException::newInstance("File exist");
    }
    
    // Create the directory
    if (mkdir(path, DIR_PERMISSION)) {
        throwIOException();
    }
}

void FileImpl::remove() {
    struct stat sb;
    const char* path;
    int         rval;
    
    path = _pathname->toChar();
    
    // See if the file/directory exists
    if (stat(path, &sb) != 0) {
        throwFileNotFoundException();
    }
    
    if (S_ISDIR(sb.st_mode)) {
        rval = rmdir(path);
    } else {
        rval = unlink(path);
    }
    
    if (rval) {
        throwIOException();
    }
}

void FileImpl::renameTo(File destination) {
    
}

boolean FileImpl::canRead() {
    if (access(_pathname->toChar(), R_OK)) {
        return false;
    }
    
    return true;
}

boolean FileImpl::canWrite() {
    if (access(_pathname->toChar(), W_OK)) {
        return false;
    }
    
    return true;
}

boolean FileImpl::canExecute() {
    if (access(_pathname->toChar(), X_OK)) {
        return false;
    }
    
    return true;
}

boolean FileImpl::exists() {
    if (access(_pathname->toChar(), F_OK)) {
        return false;
    }
    
    return true;
}

boolean FileImpl::isDirectory() {
    struct stat sb;
    const char* path;
    int         rval;
    
    path = _pathname->toChar();
    
    // See if the file/directory exists
    if (stat(path, &sb) != 0) {
        throwFileNotFoundException();
    }
    
    if (S_ISDIR(sb.st_mode)) {
        rval = rmdir(path);
    } else {
        rval = unlink(path);
    }
}

boolean FileImpl::isFile() {
    return true;
}

boolean FileImpl::isDevice() {
    return true;
}

boolean FileImpl::isLink() {
    return true;
}

boolean FileImpl::isAbsolute() {
    return _pathname->startsWith("/");
}

String FileImpl::getAbsolutePath() {
    if (isAbsolute()) {
        return _pathname;
    }
    return null;
}

File FileImpl::getAbsoluteFile() {
    if (isAbsolute()) {
        return this;
    }
    return null;
}
