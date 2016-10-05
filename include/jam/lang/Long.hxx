#ifndef __LONG_HXX__
#define __LONG_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Number.hxx"

namespace jam {
    namespace lang {
        
        class String;
        class LongImpl;
        
        class Long : public Number {
            public:
                const static Class klass;
                const static long MIN_VALUE;
                const static long MAX_VALUE;
                const static unsigned long MAX_UNSIGNED;
                
            public:
                Long();
                Long(const Reference& ref);
                Long(Implementation* impl);
                virtual ~Long();
                LongImpl& operator*();
                LongImpl* operator->();
                const Long& operator=(const Reference& ref);
                const Long& operator=(Implementation* impl);
                
                static Long newInstance(long value);
                static long parseLong(String str);
                static long parseLong(String str, Number::Format format);
        };
        
        class LongImpl : public NumberImpl {
            private:
                long _value;
                
            public:
                LongImpl(long value);
                virtual ~LongImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                virtual String toString();
                virtual int hashCode();
                virtual boolean equals(Object obj);
                virtual boolean equals(Long value);
                
                virtual byte byteValue();
                virtual double doubleValue();
                virtual float floatValue();
                virtual int intValue();
                virtual long longValue();
                virtual short shortValue();
                
            private:
                LongImpl(const LongImpl& copy);
        };
    }
}

#endif
