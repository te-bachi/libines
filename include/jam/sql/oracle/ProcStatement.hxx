#ifndef __PROC_STATEMENT_HXX__
#define __PROC_STATEMENT_HXX__

#include "jam/Global.hxx"
#include "jam/sql/Statement.hxx"

namespace jam {
    namespace sql {
        namespace proc {
            using namespace jam::lang;
            using namespace jam::sql;
            
            class ProcStatementImpl;
            
            class ProcStatement : public Statement {
                public:
                    const static Class klass;
                    
                public:
                    ProcStatement();
                    ProcStatement(const Reference& ref);
                    ProcStatement(Implementation* impl);
                    virtual ~ProcStatement();
                    ProcStatementImpl& operator*();
                    ProcStatementImpl* operator->();
                    const ProcStatement& operator=(const Reference& ref);
                    const ProcStatement& operator=(Implementation* impl);
                    
                    static ProcStatement newInstance();
            };
            
            class ProcStatementImpl : public StatementImpl {
                public:
                    
                private:
                    
                public:
                    ProcStatementImpl();
                    virtual ~ProcStatementImpl();
                    
                    virtual ResultSet executeQuery();
                    virtual void close();
                    
                private:
                    ProcStatementImpl(const ProcStatementImpl& copy);
            };
        }
    }
}

#endif
