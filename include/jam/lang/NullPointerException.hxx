#ifndef __NULL_POINTER_EXCEPTION_HXX__
#define __NULL_POINTER_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace lang {
        
        class NullPointerExceptionImpl;
        
        class NullPointerException : public Exception {
            public:
                const static Class klass;
                
            public:
                NullPointerException();
                NullPointerException(const Reference& ref);
                NullPointerException(Implementation* impl);
                virtual ~NullPointerException();
                NullPointerExceptionImpl& operator*();
                NullPointerExceptionImpl* operator->();
                const NullPointerException& operator=(const Reference& ref);
                const NullPointerException& operator=(Implementation* impl);
                
                static NullPointerException newInstance();
                static NullPointerException newInstance(String message);
                static NullPointerException newInstance(Exception cause);
                static NullPointerException newInstance(String message, Exception cause);
        };
        
        class NullPointerExceptionImpl : public ExceptionImpl {
            private:
                
            public:
                NullPointerExceptionImpl();
                NullPointerExceptionImpl(String message);
                NullPointerExceptionImpl(Exception cause);
                NullPointerExceptionImpl(String message, Exception cause);
                virtual ~NullPointerExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
            private:
                NullPointerExceptionImpl(const NullPointerExceptionImpl& copy);
        };
    }
}

#endif
