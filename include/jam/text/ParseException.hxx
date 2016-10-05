#ifndef __PARSE_EXCEPTION_HXX__
#define __PARSE_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace text {
        using namespace jam::lang;
    
        class ParseExceptionImpl;
        
        class ParseException : public Exception {
            public:
                const static Class klass;
                
            public:
                ParseException();
                ParseException(const Reference& ref);
                ParseException(Implementation* impl);
                virtual ~ParseException();
                ParseExceptionImpl& operator*();
                ParseExceptionImpl* operator->();
                const ParseException& operator=(const Reference& ref);
                const ParseException& operator=(Implementation* impl);
                
                static ParseException newInstance();
                static ParseException newInstance(String message);
                static ParseException newInstance(Exception cause);
                static ParseException newInstance(String message, Exception cause);
        };
        
        class ParseExceptionImpl : public ExceptionImpl {
            private:
                
            public:
                ParseExceptionImpl();
                ParseExceptionImpl(String message);
                ParseExceptionImpl(Exception cause);
                ParseExceptionImpl(String message, Exception cause);
                virtual ~ParseExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
            private:
                ParseExceptionImpl(const ParseExceptionImpl& copy);
        };
    }
}

#endif
