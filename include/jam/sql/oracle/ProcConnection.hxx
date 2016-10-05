#ifndef __PROC_CONNECTION_HXX__
#define __PROC_CONNECTION_HXX__

#include "jam/Global.hxx"
#include "jam/sql/Connection.hxx"

namespace jam {
    namespace sql {
        namespace proc {
            using namespace jam::lang;
            using namespace jam::sql;
            
            class ProcConnectionImpl;
            
            class ProcConnection : public Connection {
                public:
                    const static Class klass;
                    
                public:
                    ProcConnection();
                    ProcConnection(const Reference& ref);
                    ProcConnection(Implementation* impl);
                    virtual ~ProcConnection();
                    ProcConnectionImpl& operator*();
                    ProcConnectionImpl* operator->();
                    const ProcConnection& operator=(const Reference& ref);
                    const ProcConnection& operator=(Implementation* impl);
                    
                    static ProcConnection newInstance(String username, String password);
            };
            
            class ProcConnectionImpl : public ConnectionImpl {
                public:
                    ProcConnectionImpl();
                    ProcConnectionImpl(String username, String password);
                    virtual ~ProcConnectionImpl();
                    
                    virtual void commit();
                    virtual void rollback();
                    virtual void close();
                    virtual void setAutoCommit(boolean autoCommit);
                    virtual boolean getAutoCommit();
                    virtual Statement createStatement(String sql);
                    
                private:
                    ProcConnectionImpl(const ProcConnectionImpl& copy);
            };
        }
    }
}

#endif
