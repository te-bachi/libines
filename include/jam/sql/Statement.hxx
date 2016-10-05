#ifndef __STATEMENT_HXX__
#define __STATEMENT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace sql {
        using namespace jam::lang;
        
        class StatementImpl;
        class ResultSet;
        
        class Statement : public Object {
            public:
                const static Class klass;
                
            public:
                Statement();
                Statement(const Reference& ref);
                Statement(Implementation* impl);
                virtual ~Statement();
                StatementImpl& operator*();
                StatementImpl* operator->();
                const Statement& operator=(const Reference& ref);
                const Statement& operator=(Implementation* impl);
        };
        
        class StatementImpl : public ObjectImpl {
            public:
                
            private:
                
            public:
                StatementImpl();
                virtual ~StatementImpl();
                
                virtual ResultSet executeQuery() = 0;
                virtual void close() = 0;
                
            private:
                StatementImpl(const StatementImpl& copy);
        };
    }
}

#endif
