#ifndef __SQL_NOT_FOUND_EXCEPTION_HXX__
#define __SQL_NOT_FOUND_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/sql/SQLException.hxx"

namespace jam {
    namespace sql {
        using namespace jam::lang;
    
        class SQLNotFoundExceptionImpl;
        
        class SQLNotFoundException : public SQLException {
            public:
                const static Class klass;
                
            public:
                SQLNotFoundException();
                SQLNotFoundException(const Reference& ref);
                SQLNotFoundException(Implementation* impl);
                virtual ~SQLNotFoundException();
                SQLNotFoundExceptionImpl& operator*();
                SQLNotFoundExceptionImpl* operator->();
                const SQLNotFoundException& operator=(const Reference& ref);
                const SQLNotFoundException& operator=(Implementation* impl);
                
                static SQLNotFoundException newInstance();
                static SQLNotFoundException newInstance(int sqlcode);
                static SQLNotFoundException newInstance(String message);
                static SQLNotFoundException newInstance(int sqlcode, String message);
                static SQLNotFoundException newInstance(Exception cause);
                static SQLNotFoundException newInstance(String message, Exception cause);
        };
        
        class SQLNotFoundExceptionImpl : public SQLExceptionImpl {
            public:
                
            private:
                
            public:
                SQLNotFoundExceptionImpl();
                SQLNotFoundExceptionImpl(int sqlCode);
                SQLNotFoundExceptionImpl(String message);
                SQLNotFoundExceptionImpl(int sqlCode, String message);
                SQLNotFoundExceptionImpl(Exception cause);
                SQLNotFoundExceptionImpl(String message, Exception cause);
                virtual ~SQLNotFoundExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
            private:
                SQLNotFoundExceptionImpl(const SQLNotFoundExceptionImpl& copy);
        };
    }
}

#endif
