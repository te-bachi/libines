#ifndef __BUFFERED_INPUT_STREAM_HXX__
#define __BUFFERED_INPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/io/InputStream.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class BufferedInputStreamImpl;
        
        class BufferedInputStream : public InputStream {
            public:
                const static Class klass;
                
                const static int DEFAULT_SIZE;
                
            public:
                BufferedInputStream();
                BufferedInputStream(const Reference& ref);
                BufferedInputStream(Implementation* impl);
                virtual ~BufferedInputStream();
                BufferedInputStreamImpl& operator*();
                BufferedInputStreamImpl* operator->();
                const BufferedInputStream& operator=(const Reference& ref);
                const BufferedInputStream& operator=(Implementation* impl);
                
                static BufferedInputStream newInstance(InputStream in);
                static BufferedInputStream newInstance(InputStream in, int size);
        };
        
        class BufferedInputStreamImpl : public InputStreamImpl {
            private:
                InputStream _in;
                int          _size;
                ByteArray    _data;
                
            public:
                BufferedInputStreamImpl(InputStream in);
                BufferedInputStreamImpl(InputStream in, int size);
                virtual ~BufferedInputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual int read(ByteArray bytes);
                virtual int read(ByteArray bytes, int offset, int length);
                virtual int skip(int n);
                virtual void close();
                */
                
            private:
                BufferedInputStreamImpl(const BufferedInputStreamImpl& copy);
        };
    }
}

#endif
