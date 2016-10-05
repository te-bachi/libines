#ifndef __RESULT_SET_META_DATA_HXX__
#define __RESULT_SET_META_DATA_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace sql {
        using namespace jam::lang;
        
        class ResultSetMetaDataImpl;
        
        class ResultSetMetaData : public Object {
            public:
                const static Class klass;
                
            public:
                ResultSetMetaData();
                ResultSetMetaData(const Reference& ref);
                ResultSetMetaData(Implementation* impl);
                virtual ~ResultSetMetaData();
                ResultSetMetaDataImpl& operator*();
                ResultSetMetaDataImpl* operator->();
                const ResultSetMetaData& operator=(const Reference& ref);
                const ResultSetMetaData& operator=(Implementation* impl);
        };
        
        class ResultSetMetaDataImpl : public ObjectImpl {
            public:
                
            private:
                
            public:
                ResultSetMetaDataImpl();
                virtual ~ResultSetMetaDataImpl();
                
                virtual int getColumnCount() = 0;
                virtual String getColumnName(int index) = 0;
                virtual int getColumnType(int index) = 0;
                virtual String getColumnTypeName(int index) = 0;
                
            private:
                ResultSetMetaDataImpl(const ResultSetMetaDataImpl& copy);
        };
    }
}

#endif
