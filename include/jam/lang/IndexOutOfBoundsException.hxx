#ifndef __INDEX_OUT_OF_BOUNDS_EXCEPTION_HXX__
#define __INDEX_OUT_OF_BOUNDS_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace lang {
        
        class IndexOutOfBoundsExceptionImpl;
        class String;
        
        class IndexOutOfBoundsException : public Exception {
            public:
                const static Class klass;
                
            public:
                IndexOutOfBoundsException();
                IndexOutOfBoundsException(const Reference& ref);
                IndexOutOfBoundsException(Implementation* impl);
                virtual ~IndexOutOfBoundsException();
                IndexOutOfBoundsExceptionImpl& operator*();
                IndexOutOfBoundsExceptionImpl* operator->();
                const IndexOutOfBoundsException& operator=(const Reference& ref);
                const IndexOutOfBoundsException& operator=(Implementation* impl);
                
                static IndexOutOfBoundsException newInstance();
                static IndexOutOfBoundsException newInstance(String message);
                static IndexOutOfBoundsException newInstance(Exception cause);
                static IndexOutOfBoundsException newInstance(String message, Exception cause);
        };
        
        class IndexOutOfBoundsExceptionImpl : public ExceptionImpl {
            private:
                
            public:
                IndexOutOfBoundsExceptionImpl();
                IndexOutOfBoundsExceptionImpl(String message);
                IndexOutOfBoundsExceptionImpl(Exception cause);
                IndexOutOfBoundsExceptionImpl(String message, Exception cause);
                virtual ~IndexOutOfBoundsExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
            private:
                IndexOutOfBoundsExceptionImpl(const IndexOutOfBoundsExceptionImpl& copy);
        };
    }
}

#endif

