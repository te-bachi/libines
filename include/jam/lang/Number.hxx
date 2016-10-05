#ifndef __NUMBER_HXX__
#define __NUMBER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace lang {
        
        class NumberImpl;
        
        class Number : public Object {
            public:
                const static Class klass;
                
                typedef enum {
                    BINARY      = 2,
                    DECIMAL     = 10,
                    HEXADECIMAL = 16
                } Format;
                
            public:
                Number();
                Number(const Reference& ref);
                Number(Implementation* impl);
                virtual ~Number();
                NumberImpl& operator*();
                NumberImpl* operator->();
                const Number& operator=(const Reference& ref);
                const Number& operator=(Implementation* impl);
        };
        
        class NumberImpl : public ObjectImpl {
            private:
                
            public:
                NumberImpl();
                virtual ~NumberImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
                virtual byte byteValue() = 0;
                virtual double doubleValue() = 0;
                virtual float floatValue() = 0;
                virtual int intValue() = 0;
                virtual long longValue() = 0;
                virtual short shortValue() = 0;
                
            private:
                NumberImpl(const NumberImpl& copy);
        };
    }
}

#endif
