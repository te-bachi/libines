#ifndef __ILLEGAL_ARGUMENT_EXCEPTION_HXX__
#define __ILLEGAL_ARGUMENT_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace lang {
        
        class IllegalArgumentExceptionImpl;
        class String;
        
        class IllegalArgumentException : public Exception {
            public:
                const static Class klass;
                
            public:
                IllegalArgumentException();
                IllegalArgumentException(const Reference& ref);
                IllegalArgumentException(Implementation* impl);
                virtual ~IllegalArgumentException();
                IllegalArgumentExceptionImpl& operator*();
                IllegalArgumentExceptionImpl* operator->();
                const IllegalArgumentException& operator=(const Reference& ref);
                const IllegalArgumentException& operator=(Implementation* impl);
                
                static IllegalArgumentException newInstance();
                static IllegalArgumentException newInstance(String message);
                static IllegalArgumentException newInstance(Exception cause);
                static IllegalArgumentException newInstance(String message, Exception cause);
        };
        
        class IllegalArgumentExceptionImpl : public ExceptionImpl {
            private:
                
            public:
                IllegalArgumentExceptionImpl();
                IllegalArgumentExceptionImpl(String message);
                IllegalArgumentExceptionImpl(Exception cause);
                IllegalArgumentExceptionImpl(String message, Exception cause);
                virtual ~IllegalArgumentExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
            private:
                IllegalArgumentExceptionImpl(const IllegalArgumentExceptionImpl& copy);
        };
    }
}

#endif

