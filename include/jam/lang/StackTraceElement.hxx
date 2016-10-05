#ifndef __STACK_TRACE_ELEMENT_HXX__
#define __STACK_TRACE_ELEMENT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace lang {
        
        class StackTraceElementImpl;
        
        class StackTraceElement : public Object {
            public:
                const static Class klass;
                
            public:
                StackTraceElement();
                StackTraceElement(const Reference& ref);
                StackTraceElement(Implementation* impl);
                virtual ~StackTraceElement();
                StackTraceElementImpl& operator*();
                StackTraceElementImpl* operator->();
                const StackTraceElement& operator=(const Reference& ref);
                const StackTraceElement& operator=(Implementation* impl);
                
                static StackTraceElement newInstance(String library, unsigned int stackAddress,
                                                     String function, unsigned int symbolAddress);
        };
        
        class StackTraceElementImpl : public ObjectImpl {
            private:
                String       _library;
                String       _function;
                unsigned int _stackAddress;
                unsigned int _symbolAddress;
                
            public:
                StackTraceElementImpl(String library, unsigned int stackAddress,
                                      String function, unsigned int symbolAddress);
                virtual ~StackTraceElementImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
                virtual String getLibrary();
                virtual String getFunction();
                virtual unsigned int getStackAddress();
                virtual unsigned int getSymbolAddress();
                
            private:
                StackTraceElementImpl(const StackTraceElementImpl& copy);
        };
    }
}

#endif
