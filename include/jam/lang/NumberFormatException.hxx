#ifndef __NUMBER_FORMAT_EXCEPTION_HXX__
#define __NUMBER_FORMAT_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace lang {
        
        class NumberFormatExceptionImpl;
        
        class NumberFormatException : public Exception {
            public:
                const static Class klass;
                
            public:
                NumberFormatException();
                NumberFormatException(const Reference& ref);
                NumberFormatException(Implementation* impl);
                virtual ~NumberFormatException();
                NumberFormatExceptionImpl& operator*();
                NumberFormatExceptionImpl* operator->();
                const NumberFormatException& operator=(const Reference& ref);
                const NumberFormatException& operator=(Implementation* impl);
        };
        
        class NumberFormatExceptionImpl : public ExceptionImpl {
            public:
                
            private:
                
            public:
                NumberFormatExceptionImpl();
                virtual ~NumberFormatExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
            private:
                NumberFormatExceptionImpl(const NumberFormatExceptionImpl& copy);
        };
    }
}

#endif
