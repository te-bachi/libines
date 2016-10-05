#ifndef __MISSING_RESOURCE_EXCEPTION_HXX__
#define __MISSING_RESOURCE_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace util {
        namespace locale {
            using namespace jam::lang;
            
            class MissingResourceExceptionImpl;
            
            class MissingResourceException : public Exception {
                public:
                    const static Class klass;
                    
                public:
                    MissingResourceException();
                    MissingResourceException(const Reference& ref);
                    MissingResourceException(Implementation* impl);
                    virtual ~MissingResourceException();
                    MissingResourceExceptionImpl& operator*();
                    MissingResourceExceptionImpl* operator->();
                    const MissingResourceException& operator=(const Reference& ref);
                    const MissingResourceException& operator=(Implementation* impl);
                    
                    static MissingResourceException newInstance();
                    static MissingResourceException newInstance(String message);
                    static MissingResourceException newInstance(Exception cause);
                    static MissingResourceException newInstance(String message, Exception cause);
            };
            
            class MissingResourceExceptionImpl : public ExceptionImpl {
                private:
                    
                public:
                    MissingResourceExceptionImpl();
                    MissingResourceExceptionImpl(String message);
                    MissingResourceExceptionImpl(Exception cause);
                    MissingResourceExceptionImpl(String message, Exception cause);
                    virtual ~MissingResourceExceptionImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                private:
                    MissingResourceExceptionImpl(const MissingResourceExceptionImpl& copy);
            };
        }
    }
}

#endif
