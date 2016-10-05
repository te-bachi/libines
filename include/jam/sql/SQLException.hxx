#ifndef __SQL_EXCEPTION_HXX__
#define __SQL_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace sql {
        using namespace jam::lang;
    
        class SQLExceptionImpl;
        
        class SQLException : public Exception {
            public:
                const static Class klass;
                
            public:
                SQLException();
                SQLException(const Reference& ref);
                SQLException(Implementation* impl);
                virtual ~SQLException();
                SQLExceptionImpl& operator*();
                SQLExceptionImpl* operator->();
                const SQLException& operator=(const Reference& ref);
                const SQLException& operator=(Implementation* impl);
                
                static SQLException newInstance();
                static SQLException newInstance(int sqlcode);
                static SQLException newInstance(String message);
                static SQLException newInstance(int sqlcode, String message);
                static SQLException newInstance(Exception cause);
                static SQLException newInstance(String message, Exception cause);
        };
        
        class SQLExceptionImpl : public ExceptionImpl {
            private:
                int _sqlCode;
                
            public:
                SQLExceptionImpl();
                SQLExceptionImpl(int sqlCode);
                SQLExceptionImpl(String message);
                SQLExceptionImpl(int sqlCode, String message);
                SQLExceptionImpl(Exception cause);
                SQLExceptionImpl(String message, Exception cause);
                virtual ~SQLExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                virtual int getSqlCode();
                
            private:
                SQLExceptionImpl(const SQLExceptionImpl& copy);
        };
    }
}

#endif
