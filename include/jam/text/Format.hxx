#ifndef __FORMAT_HXX__
#define __FORMAT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace text {
        using namespace jam::lang;
        
        class FormatImpl;
        
        class Format : public Object {
            public:
                const static Class klass;
                
            public:
                Format();
                Format(const Reference& ref);
                Format(Implementation* impl);
                virtual ~Format();
                FormatImpl& operator*();
                FormatImpl* operator->();
                const Format& operator=(const Reference& ref);
                const Format& operator=(Implementation* impl);
        };
        
        class FormatImpl : public ObjectImpl {
            public:
                FormatImpl();
                virtual ~FormatImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Class getClass();
                
                virtual String format(Object obj) = 0;
                virtual Object parse(String str) = 0;
                
            private:
                FormatImpl(const FormatImpl& copy);
        };
    }
}

#endif
