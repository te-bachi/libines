#ifndef __FILE_OUTPUT_STREAM_HXX__
#define __FILE_OUTPUT_STREAM_HXX__

#include "jam/Global.hxx"
#include "jam/io/OutputStream.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class FileOutputStreamImpl;
        class File;
        
        class FileOutputStream : public OutputStream {
            public:
                const static Class klass;
                
            public:
                FileOutputStream();
                FileOutputStream(const Reference& ref);
                FileOutputStream(Implementation* impl);
                virtual ~FileOutputStream();
                FileOutputStreamImpl& operator*();
                FileOutputStreamImpl* operator->();
                const FileOutputStream& operator=(const Reference& ref);
                const FileOutputStream& operator=(Implementation* impl);
                
                static FileOutputStream newInstance(File file);
                static FileOutputStream newInstance(File file, boolean append);
                static FileOutputStream newInstance(String pathname);
                static FileOutputStream newInstance(String pathname, boolean append);
        };
        
        class FileOutputStreamImpl : public OutputStreamImpl {
            private:
                int _fd;
                
            public:
                FileOutputStreamImpl(File file);
                FileOutputStreamImpl(File file, boolean append);
                FileOutputStreamImpl(String pathname);
                FileOutputStreamImpl(String pathname, boolean append);
                virtual ~FileOutputStreamImpl();
                
                virtual Class getClass();
                
                /*
                virtual void write(ByteArray bytes);
                virtual void write(ByteArray bytes, int offset, int length);
                virtual void flush();
                virtual void close();
                */
                
            private:
                FileOutputStreamImpl(const FileOutputStreamImpl& copy);
        };
    }
}

#endif
