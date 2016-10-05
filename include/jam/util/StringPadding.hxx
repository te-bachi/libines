#ifndef __STRING_PADDING_HXX__
#define __STRING_PADDING_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace util {
        using namespace lang;
        
        class StringPaddingImpl;
        
        class StringPadding : public Object {
            public:
                const static Class klass;
                
            public:
                StringPadding();
                StringPadding(const Reference& ref);
                StringPadding(Implementation* impl);
                virtual ~StringPadding();
                StringPaddingImpl& operator*();
                StringPaddingImpl* operator->();
                const StringPadding& operator=(const Reference& ref);
                const StringPadding& operator=(Implementation* impl);
                
                static StringPadding newInstance(int length);
                static StringPadding newInstance(int length, boolean reverse);
                static StringPadding newInstance(int length, char padding);
                static StringPadding newInstance(int length, char padding, boolean reverse);
        };
        
        class StringPaddingImpl : public ObjectImpl {
            private:
                int     _length;
                char    _padding;
                boolean _reverse;
                
            public:
                StringPaddingImpl(int length);
                StringPaddingImpl(int length, boolean reverse);
                StringPaddingImpl(int length, char padding);
                StringPaddingImpl(int length, char padding, boolean reverse);
                virtual ~StringPaddingImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual String doPadding(String input);
                
            private:
                StringPaddingImpl(const StringPaddingImpl& copy);
                void init(int length, char padding, boolean reverse);
        };
    }
}

#endif
