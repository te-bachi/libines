#ifndef __STRING_TOKENIZER_HXX__
#define __STRING_TOKENIZER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace util {
        using namespace lang;
        
        class StringTokenizerImpl;
        
        class StringTokenizer : public Object {
            public:
                const static Class klass;
                
            public:
                StringTokenizer();
                StringTokenizer(const Reference& ref);
                StringTokenizer(Implementation* impl);
                virtual ~StringTokenizer();
                StringTokenizerImpl& operator*();
                StringTokenizerImpl* operator->();
                const StringTokenizer& operator=(const Reference& ref);
                const StringTokenizer& operator=(Implementation* impl);
                
                static StringTokenizer newInstance(String str);
                static StringTokenizer newInstance(String str, String delimiter);
        };
        
        class StringTokenizerImpl : public ObjectImpl {
            private:
                String  _str;
                String  _delimiter;
                int     _strLength;
                int     _delimiterLength;
                int     _currentPosition;
                int     _newPosition;
                
            public:
                StringTokenizerImpl(String str);
                StringTokenizerImpl(String str, String delimiter);
                virtual ~StringTokenizerImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual boolean hasMoreTokens();
                virtual String nextToken();
                
            private:
                StringTokenizerImpl(const StringTokenizerImpl& copy);
                void init(String str, String delimiter);
                int skipDelimiters();
                int scanToken();
        };
    }
}

#endif
