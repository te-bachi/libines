#ifndef __FILE_HXX__
#define __FILE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class FileImpl;
        
        class File : public Object {
            public:
                const static Class klass;
                
            public:
                File();
                File(const Reference& ref);
                File(Implementation* impl);
                virtual ~File();
                FileImpl& operator*();
                FileImpl* operator->();
                const File& operator=(const Reference& ref);
                const File& operator=(Implementation* impl);
                
                static File newInstance(String pathname);
        };
        
        class FileImpl : public ObjectImpl {
            private:
                String _pathname;
                
            public:
                FileImpl(String pathname);
                virtual ~FileImpl();
                
                virtual Class getClass();
                
                virtual void createFile();
                virtual void createDirectory();
                virtual void remove();
                virtual void renameTo(File destination);
                virtual boolean canRead();
                virtual boolean canWrite();
                virtual boolean canExecute();
                virtual boolean exists();
                virtual boolean isDirectory();
                virtual boolean isFile();
                virtual boolean isDevice();
                virtual boolean isLink();
                virtual boolean isAbsolute();
                virtual String getAbsolutePath();
                virtual File getAbsoluteFile();
                
            private:
                FileImpl(const FileImpl& copy);
        };
    }
}

#endif
