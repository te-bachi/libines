#ifndef __INPUT_STREAM_HXX__
#define __INPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/ByteArray.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class InputStreamImpl;
        
        class InputStream : public Object {
            public:
                const static Class klass;
                
            public:
                InputStream();
                InputStream(const Reference& ref);
                InputStream(Implementation* impl);
                virtual ~InputStream();
                InputStreamImpl& operator*();
                InputStreamImpl* operator->();
                const InputStream& operator=(const Reference& ref);
                const InputStream& operator=(Implementation* impl);
        };
        
        class InputStreamImpl : public ObjectImpl {
            public:
                InputStreamImpl();
                virtual ~InputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual int read(ByteArray bytes);
                virtual int read(ByteArray bytes, int offset, int length);
                virtual int skip(int n);
                virtual void close();
                */
                
            private:
                InputStreamImpl(const InputStreamImpl& copy);
        };
    }
}

#endif
