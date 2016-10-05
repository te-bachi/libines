#ifndef __CONNECTION_HXX__
#define __CONNECTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace sql {
        using namespace jam::lang;
        
        class ConnectionImpl;
        class Statement;
        
        class Connection : public Object {
            public:
                const static Class klass;
                
            public:
                Connection();
                Connection(const Reference& ref);
                Connection(Implementation* impl);
                virtual ~Connection();
                ConnectionImpl& operator*();
                ConnectionImpl* operator->();
                const Connection& operator=(const Reference& ref);
                const Connection& operator=(Implementation* impl);
        };
        
        class ConnectionImpl : public ObjectImpl {
            public:
                ConnectionImpl();
                virtual ~ConnectionImpl();
                
                virtual void commit() = 0;
                virtual void rollback() = 0;
                virtual void close() = 0;
                virtual void setAutoCommit(boolean autoCommit) = 0;
                virtual boolean getAutoCommit() = 0;
                virtual Statement createStatement(String sql) = 0;
                
            private:
                ConnectionImpl(const ConnectionImpl& copy);
        };
    }
}

#endif
