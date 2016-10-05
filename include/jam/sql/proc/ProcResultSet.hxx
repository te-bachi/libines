#ifndef __PROC_RESULT_SET_HXX__
#define __PROC_RESULT_SET_HXX__

#include "jam/Global.hxx"
#include "jam/sql/ResultSet.hxx"

namespace jam {
    namespace sql {
        namespace proc {
            using namespace jam::lang;
            using namespace jam::util::time;
            using namespace jam::sql;
            
            class ProcResultSetImpl;
            
            class ProcResultSet : public ResultSet {
                public:
                    const static Class klass;
                    
                public:
                    ProcResultSet();
                    ProcResultSet(const Reference& ref);
                    ProcResultSet(Implementation* impl);
                    virtual ~ProcResultSet();
                    ProcResultSetImpl& operator*();
                    ProcResultSetImpl* operator->();
                    const ProcResultSet& operator=(const Reference& ref);
                    const ProcResultSet& operator=(Implementation* impl);
                    
                    static ProcResultSet newInstance();
            };
            
            class ProcResultSetImpl : public ResultSetImpl {
                public:
                    
                private:
                    
                public:
                    ProcResultSetImpl();
                    virtual ~ProcResultSetImpl();
                    
                    virtual boolean next();
                    virtual boolean previous();
                    virtual void close();
                    virtual ResultSetMetaData getMetaData();
                    
                    virtual int getInteger(int index);
                    virtual int getInteger(String column);
                    virtual long getLong(int index);
                    virtual long getLong(String column);
                    virtual double getDouble(int index);
                    virtual double getDouble(String column);
                    virtual String getString(int index);
                    virtual String getString(String column);
                    virtual Calendar getCalendar(int index);
                    virtual Calendar getCalendar(String column);
                    
                private:
                    ProcResultSetImpl(const ProcResultSetImpl& copy);
            };
        }
    }
}

#endif
