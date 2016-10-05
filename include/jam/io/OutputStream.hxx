#ifndef __OUTPUT_STREAM_HXX__
#define __OUTPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/ByteArray.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class OutputStreamImpl;
        
        class OutputStream : public Object {
            public:
                const static Class klass;
                
            public:
                OutputStream();
                OutputStream(const Reference& ref);
                OutputStream(Implementation* impl);
                virtual ~OutputStream();
                OutputStreamImpl& operator*();
                OutputStreamImpl* operator->();
                const OutputStream& operator=(const Reference& ref);
                const OutputStream& operator=(Implementation* impl);
        };
        
        class OutputStreamImpl : public ObjectImpl {
            public:
                OutputStreamImpl();
                virtual ~OutputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual void write(ByteArray bytes);
                virtual void write(ByteArray bytes, int offset, int length);
                virtual void flush();
                virtual void close();
                */
                
            private:
                OutputStreamImpl(const OutputStreamImpl& copy);
        };
    }
}

#endif
