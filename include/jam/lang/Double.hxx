#ifndef __DOUBLE_HXX__
#define __DOUBLE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Number.hxx"

namespace jam {
    namespace lang {
        
        class String;
        class DoubleImpl;
        
        class Double : public Number {
            public:
                const static Class klass;
                
            public:
                Double();
                Double(const Reference& ref);
                Double(Implementation* impl);
                virtual ~Double();
                DoubleImpl& operator*();
                DoubleImpl* operator->();
                const Double& operator=(const Reference& ref);
                const Double& operator=(Implementation* impl);
                
                static Double newInstance(double value);
                static Double valueOf(String str);
                static double parseDouble(String str);
        };
        
        class DoubleImpl : public NumberImpl {
            private:
                double _value;
                
            public:
                DoubleImpl(double value);
                virtual ~DoubleImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                virtual String toString();
                virtual int hashCode();
                virtual boolean equals(Object obj);
                virtual boolean equals(Double value);
                
                virtual byte byteValue();
                virtual double doubleValue();
                virtual float floatValue();
                virtual int intValue();
                virtual long longValue();
                virtual short shortValue();
                
            private:
                DoubleImpl(const DoubleImpl& copy);
        };
    }
}

#endif
