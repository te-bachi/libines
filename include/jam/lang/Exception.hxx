#ifndef __EXCEPTION_HXX__
#define __EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/List.hxx"

namespace jam {
    namespace lang {
        using namespace jam::util;
        
        class ExceptionImpl;
        
        class Exception : public Object {
            public:
                const static Class klass;
                
            public:
                Exception();
                Exception(const Reference& ref);
                Exception(Implementation* impl);
                virtual ~Exception();
                ExceptionImpl& operator*();
                ExceptionImpl* operator->();
                const Exception& operator=(const Reference& ref);
                const Exception& operator=(Implementation* impl);
                
                static Exception newInstance();
                static Exception newInstance(String message);
                static Exception newInstance(Exception nested);
                static Exception newInstance(String message, Exception nested);
        };
        
        class ExceptionImpl : public ObjectImpl {
            private:
                String    _message;
                Exception _cause;
                List      _stackTraceList;
                int       _maxLibraryLength;
                List      _registerList;
                
            public:
                ExceptionImpl();
                ExceptionImpl(String message);
                ExceptionImpl(Exception cause);
                ExceptionImpl(String message, Exception cause);
                virtual ~ExceptionImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                virtual String getMessage();
                virtual List getStackTrace();
                virtual String printStackTrace();
                virtual List getRegisters();
                virtual String printRegisters();
                virtual String printFullInfos();
                
            private:
                ExceptionImpl(const ExceptionImpl& copy);
                void init(String key, Exception nested);
        };
    }
}

#endif
