#ifndef __BUFFERED_OUTPUT_STREAM_HXX__
#define __BUFFERED_OUTPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/io/OutputStream.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class BufferedOutputStreamImpl;
        
        class BufferedOutputStream : public OutputStream {
            public:
                const static Class klass;
                
                const static int DEFAULT_SIZE;
                
            public:
                BufferedOutputStream();
                BufferedOutputStream(const Reference& ref);
                BufferedOutputStream(Implementation* impl);
                virtual ~BufferedOutputStream();
                BufferedOutputStreamImpl& operator*();
                BufferedOutputStreamImpl* operator->();
                const BufferedOutputStream& operator=(const Reference& ref);
                const BufferedOutputStream& operator=(Implementation* impl);
                
                static BufferedOutputStream newInstance(OutputStream out);
                static BufferedOutputStream newInstance(OutputStream out, int size);
        };
        
        class BufferedOutputStreamImpl : public OutputStreamImpl {
            private:
                OutputStream _out;
                int          _size;
                ByteArray    _data;
                
            public:
                BufferedOutputStreamImpl(OutputStream out);
                BufferedOutputStreamImpl(OutputStream out, int size);
                virtual ~BufferedOutputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual void write(ByteArray bytes);
                virtual void write(ByteArray bytes, int offset, int length);
                virtual void flush();
                virtual void close();
                */
                
            private:
                BufferedOutputStreamImpl(const BufferedOutputStreamImpl& copy);
        };
    }
}

#endif
