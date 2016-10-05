#ifndef __CLASS_HXX__
#define __CLASS_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace lang {
        
        class ClassImpl;
        
        class Class : public Object {
            public:
                const static Class klass;
            
            public:
                Class();
                Class(const Reference& ref);
                Class(Implementation* impl);
                virtual ~Class();
                ClassImpl& operator*();
                ClassImpl* operator->();
                const Class& operator=(const Reference& ref);
                const Class& operator=(Implementation* impl);
                
                static Class newInstance(const char* name);
        };
        
        class ClassImpl : public ObjectImpl {
            public:
                
            private:
                String _name;
                
            public:
                ClassImpl(const char* name);
                virtual ~ClassImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String getName();
                virtual boolean equals(Object obj);
                virtual boolean equals(Class klass);
                
            private:
                ClassImpl(const ClassImpl& copy);
                
        };
    }
}

#endif
