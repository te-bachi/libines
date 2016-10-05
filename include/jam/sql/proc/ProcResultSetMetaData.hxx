#ifndef __PROC_RESULT_SET_META_DATA_HXX__
#define __PROC_RESULT_SET_META_DATA_HXX__

#include "jam/Global.hxx"
#include "jam/sql/ResultSetMetaData.hxx"

namespace jam {
    namespace sql {
        namespace proc {
            using namespace jam::lang;
            using namespace jam::sql;
            
            class ProcResultSetMetaDataImpl;
            
            class ProcResultSetMetaData : public ResultSetMetaData {
                public:
                    const static Class klass;
                    
                public:
                    ProcResultSetMetaData();
                    ProcResultSetMetaData(const Reference& ref);
                    ProcResultSetMetaData(Implementation* impl);
                    virtual ~ProcResultSetMetaData();
                    ProcResultSetMetaDataImpl& operator*();
                    ProcResultSetMetaDataImpl* operator->();
                    const ProcResultSetMetaData& operator=(const Reference& ref);
                    const ProcResultSetMetaData& operator=(Implementation* impl);
            };
            
            class ProcResultSetMetaDataImpl : public ResultSetMetaDataImpl {
                public:
                    
                private:
                    
                public:
                    ProcResultSetMetaDataImpl();
                    virtual ~ProcResultSetMetaDataImpl();
                    
                    virtual int getColumnCount();
                    virtual String getColumnName(int index);
                    virtual int getColumnType(int index);
                    virtual String getColumnTypeName(int index);
                    
                private:
                    ProcResultSetMetaDataImpl(const ProcResultSetMetaDataImpl& copy);
            };
        }
    }
}

#endif
