#ifndef __REGISTER_ELEMENT_HXX__
#define __REGISTER_ELEMENT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace lang {
        
        class RegisterElementImpl;
        
        class RegisterElement : public Object {
            public:
                const static Class klass;
                
            public:
                RegisterElement();
                RegisterElement(const Reference& ref);
                RegisterElement(Implementation* impl);
                virtual ~RegisterElement();
                RegisterElementImpl& operator*();
                RegisterElementImpl* operator->();
                const RegisterElement& operator=(const Reference& ref);
                const RegisterElement& operator=(Implementation* impl);
                
                static RegisterElement newInstance(String registerName, unsigned int value);
        };
        
        class RegisterElementImpl : public ObjectImpl {
            private:
                String       _registerName;
                unsigned int _value;
                
            public:
                RegisterElementImpl(String registerName, unsigned int value);
                virtual ~RegisterElementImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
                virtual String getRegisterName();
                virtual unsigned int getValue();
                
            private:
                RegisterElementImpl(const RegisterElementImpl& copy);
                void init(String key, RegisterElement nested);
        };
    }
}

#endif
