#ifndef __INTEGER_HXX__
#define __INTEGER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Number.hxx"

namespace jam {
    namespace lang {
        
        class String;
        class IntegerImpl;
        
        class Integer : public Number {
            public:
                const static Class klass;
                
            public:
                Integer();
                Integer(const Reference& ref);
                Integer(Implementation* impl);
                virtual ~Integer();
                IntegerImpl& operator*();
                IntegerImpl* operator->();
                const Integer& operator=(const Reference& ref);
                const Integer& operator=(Implementation* impl);
                
                static Integer newInstance(int value);
                static int parseInt(String str);
                static int parseInt(String str, Number::Format format);
        };
        
        class IntegerImpl : public NumberImpl {
            private:
                int _value;
                
            public:
                IntegerImpl(int value);
                virtual ~IntegerImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                virtual String toString();
                virtual int hashCode();
                virtual boolean equals(Object obj);
                virtual boolean equals(Integer value);
                
                virtual byte byteValue();
                virtual double doubleValue();
                virtual float floatValue();
                virtual int intValue();
                virtual long longValue();
                virtual short shortValue();
                
            private:
                IntegerImpl(const IntegerImpl& copy);
        };
    }
}

#endif
