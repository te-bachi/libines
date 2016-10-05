#ifndef __POINTER_HXX__
#define __POINTER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace lang {
        
        class PointerImpl;
        
        class Pointer : public Object {
            public:
                const static Class klass;
                
            public:
                Pointer();
                Pointer(const Reference& ref);
                Pointer(Implementation* impl);
                virtual ~Pointer();
                PointerImpl& operator*();
                PointerImpl* operator->();
                const Pointer& operator=(const Reference& ref);
                const Pointer& operator=(Implementation* impl);
                
                static Pointer newInstance(void* pointer);
        };
        
        class PointerImpl : public ObjectImpl {
            private:
                void* _pointer;
                
            public:
                PointerImpl(void* pointer);
                virtual ~PointerImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                virtual int hashCode();
                virtual boolean equals(Object obj);
                virtual boolean equals(Pointer pointer);
                virtual void* getPointer();
                
            private:
                PointerImpl(const PointerImpl& copy);
        };
    }
}

#endif
