#ifndef __IO_EXCEPTION_HXX__
#define __IO_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class IOExceptionImpl;
        
        class IOException : public Exception {
            public:
                const static Class klass;
                
            public:
                IOException();
                IOException(const Reference& ref);
                IOException(Implementation* impl);
                virtual ~IOException();
                IOExceptionImpl& operator*();
                IOExceptionImpl* operator->();
                const IOException& operator=(const Reference& ref);
                const IOException& operator=(Implementation* impl);
                
                static IOException newInstance();
                static IOException newInstance(String message);
        };
        
        class IOExceptionImpl : public ExceptionImpl {
            public:
                IOExceptionImpl();
                IOExceptionImpl(String message);
                virtual ~IOExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
            private:
                IOExceptionImpl(const IOExceptionImpl& copy);
        };
    }
}

#endif
