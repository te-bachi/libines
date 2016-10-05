#ifndef __FILE_INPUT_STREAM_HXX__
#define __FILE_INPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/io/InputStream.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class FileInputStreamImpl;
        class File;
        
        class FileInputStream : public InputStream {
            public:
                const static Class klass;
                
            public:
                FileInputStream();
                FileInputStream(const Reference& ref);
                FileInputStream(Implementation* impl);
                virtual ~FileInputStream();
                FileInputStreamImpl& operator*();
                FileInputStreamImpl* operator->();
                const FileInputStream& operator=(const Reference& ref);
                const FileInputStream& operator=(Implementation* impl);
                
                static FileInputStream newInstance(File file);
                static FileInputStream newInstance(String pathname);
        };
        
        class FileInputStreamImpl : public InputStreamImpl {
            private:
                int _fd;
                
            public:
                FileInputStreamImpl(File file);
                FileInputStreamImpl(String pathname);
                virtual ~FileInputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual int read(ByteArray bytes);
                virtual int read(ByteArray bytes, int offset, int length);
                virtual int skip(int n);
                virtual void close();
                */
                
            private:
                FileInputStreamImpl(const FileInputStreamImpl& copy);
        };
    }
}

#endif
