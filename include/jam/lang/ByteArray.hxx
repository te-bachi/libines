#ifndef __BYTE_ARRAY_HXX__
#define __BYTE_ARRAY_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace lang {
        
        class ByteArrayImpl;
        
        class ByteArray : public Object {
            public:
                const static Class klass;
                
            public:
                ByteArray();
                ByteArray(const Reference& ref);
                ByteArray(Implementation* impl);
                virtual ~ByteArray();
                ByteArrayImpl& operator*();
                ByteArrayImpl* operator->();
                const ByteArray& operator=(const Reference& ref);
                const ByteArray& operator=(Implementation* impl);
                byte& operator[](int index);
                
                static ByteArray newInstance(int size);
        };
        
        class ByteArrayImpl : public ObjectImpl {
            friend class ByteArray;
            
            public:
                
            private:
                byte*   _byteArray;
                int     _length;
                
            public:
                ByteArrayImpl(int size);
                virtual ~ByteArrayImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
                virtual int length();
                
            private:
                ByteArrayImpl(const ByteArrayImpl& copy);
        };
    }
}

#endif
