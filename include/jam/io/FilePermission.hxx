#ifndef __FILE_PERMISSION_HXX__
#define __FILE_PERMISSION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace io {
        using namespace jam::lang;
        
        class FilePermissionImpl;
        
        class FilePermission : public Object {
            public:
                const static Class klass;
                
                const static short USER;
                const static short GROUP;
                const static short OTHER;
                
                const static short READ;
                const static short WRITE;
                const static short EXECUTE;
                
            public:
                FilePermission();
                FilePermission(const Reference& ref);
                FilePermission(Implementation* impl);
                virtual ~FilePermission();
                FilePermissionImpl& operator*();
                FilePermissionImpl* operator->();
                const FilePermission& operator=(const Reference& ref);
                const FilePermission& operator=(Implementation* impl);
                
                static FilePermission newInstance(short );
                static FilePermission newInstance(String pathname);
                static FilePermission newInstance(String pathname);
        };
        
        class FilePermissionImpl : public ObjectImpl {
            private:
                String _pathname;
                
            public:
                FilePermissionImpl(String pathname);
                virtual ~FilePermissionImpl();
                
                virtual Class getClass();
                
                virtual int getMode();
                
            private:
                FilePermissionImpl(const FilePermissionImpl& copy);
        };
    }
}

#endif
