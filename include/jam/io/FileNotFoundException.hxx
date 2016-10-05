#ifndef __FILE_NOT_FOUND_EXCEPTION_HXX__
#define __FILE_NOT_FOUND_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/io/IOException.hxx"

namespace jam {
    namespace io {
        
        class FileNotFoundExceptionImpl;
        
        class FileNotFoundException : public IOException {
            public:
                const static Class klass;
                
            public:
                FileNotFoundException();
                FileNotFoundException(const Reference& ref);
                FileNotFoundException(Implementation* impl);
                virtual ~FileNotFoundException();
                FileNotFoundExceptionImpl& operator*();
                FileNotFoundExceptionImpl* operator->();
                const FileNotFoundException& operator=(const Reference& ref);
                const FileNotFoundException& operator=(Implementation* impl);
                
                static FileNotFoundException newInstance();
                static FileNotFoundException newInstance(String message);
        };
        
        class FileNotFoundExceptionImpl : public IOExceptionImpl {
            public:
                FileNotFoundExceptionImpl();
                FileNotFoundExceptionImpl(String message);
                virtual ~FileNotFoundExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
            private:
                FileNotFoundExceptionImpl(const FileNotFoundExceptionImpl& copy);
        };
    }
}

#endif
