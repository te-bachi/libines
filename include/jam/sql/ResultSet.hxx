#ifndef __RESULT_SET_HXX__
#define __RESULT_SET_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace lang {
        class String;
    }
    namespace util {
        namespace time {
            class Calendar;
        }
    }
    namespace sql {
        using namespace jam::lang;
        using namespace jam::util::time;
        
        class ResultSetImpl;
        class ResultSetMetaData;
        
        class ResultSet : public Object {
            public:
                const static Class klass;
                
            public:
                ResultSet();
                ResultSet(const Reference& ref);
                ResultSet(Implementation* impl);
                virtual ~ResultSet();
                ResultSetImpl& operator*();
                ResultSetImpl* operator->();
                const ResultSet& operator=(const Reference& ref);
                const ResultSet& operator=(Implementation* impl);
        };
        
        class ResultSetImpl : public ObjectImpl {
            public:
                
            private:
                
            public:
                ResultSetImpl();
                virtual ~ResultSetImpl();
                
                virtual boolean next() = 0;
                virtual boolean previous() = 0;
                virtual void close() = 0;
                virtual ResultSetMetaData getMetaData() = 0;
                
                virtual int getInteger(int index) = 0;
                virtual int getInteger(String column) = 0;
                virtual long getLong(int index) = 0;
                virtual long getLong(String column) = 0;
                virtual double getDouble(int index) = 0;
                virtual double getDouble(String column) = 0;
                virtual String getString(int index) = 0;
                virtual String getString(String column) = 0;
                virtual Calendar getCalendar(int index) = 0;
                virtual Calendar getCalendar(String column) = 0;
                
            private:
                ResultSetImpl(const ResultSetImpl& copy);
        };
    }
}

#endif
