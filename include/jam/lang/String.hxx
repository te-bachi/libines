#ifndef __STRING_HXX__
#define __STRING_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Number.hxx"

namespace jam {
    namespace lang {
        
        class StringImpl;
        
        class String : public Object {
            public:
                const static Class klass;
                
            public:
                String();
                String(const Reference& ref);
                String(Implementation* impl);
                String(const char* chr);
                virtual ~String();
                StringImpl& operator*();
                StringImpl* operator->();
                const String& operator=(const Reference& ref);
                const String& operator=(Implementation* impl);
                const String& operator=(const char* chr);
                String operator+(const String& ref);
                String operator+(const char* chr);
                
                static String newInstance();
                static String newInstance(const char* chr);
                static String newInstance(char* chr, boolean copy);
                static String newInstance(const char* chr, int length);
                static String newInstance(char* chr, int length, boolean copy);
                
                static String valueOf(int number);
                static String valueOf(int number, boolean padding);
                static String valueOf(int number, Number::Format format);
                static String valueOf(int number, Number::Format format, boolean padding);
                static String valueOf(long number);
                static String valueOf(long number, boolean padding);
                static String valueOf(long number, Number::Format format);
                static String valueOf(long number, Number::Format format, boolean padding);
                static String valueOf(double number, int ndigit);
        };
        
        class StringImpl : public ObjectImpl {
            public:
                
            private:
                char*   _data;
                int     _length;
                int     _hash;
                
            public:
                StringImpl();
                StringImpl(const char* chr);
                StringImpl(char* chr, boolean copy);
                StringImpl(const char* chr, int length);
                StringImpl(char* chr, int length, boolean copy);
                virtual ~StringImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual char charAt(const int index);
                virtual String concat(String str);
                virtual boolean startsWith(String str);
                virtual boolean endsWith(String str);
                virtual boolean equals(Object obj);
                virtual boolean equals(String str);
                virtual boolean equalsIgnoreCase(String str);
                virtual int hashCode();
                virtual int indexOf(const char chr);
                virtual int indexOf(const char chr, int fromIndex);
                virtual int indexOf(String str);
                virtual int indexOf(String str, int fromIndex);
                virtual int firstIndexOf(const char chr);
                virtual int firstIndexOf(const char chr, int fromIndex);
                virtual int firstIndexOf(String str);
                virtual int firstIndexOf(String str, int fromIndex);
                virtual int lastIndexOf(const char chr);
                virtual int lastIndexOf(const char chr, int fromIndex); // TODO
                virtual int lastIndexOf(String str);  // TODO
                virtual int lastIndexOf(String str, int fromIndex); // TODO
                virtual int length();
                virtual String toLowerCase();
                virtual String toUpperCase();
                virtual String trim();
                virtual String trim(const char chr);
                virtual String trimLeft();
                virtual String trimLeft(const char chr);
                virtual String trimRight();
                virtual String trimRight(const char chr);
                virtual String substring(const int beginIndex, const int endIndex);
                virtual String replace(const char oldChar, const char newChar);
                virtual String replace(String oldString, String newString);
                virtual const char* toChar();
                virtual boolean isEmpty();
                virtual boolean isEmpty(boolean withWhitespace);
                virtual boolean isDigit();
                virtual boolean isAlpha(); // TODO
                virtual String digitFormat();
                virtual String alphaFormat(); // TODO
                virtual String currencyFormat();
                virtual String currencyFormat(boolean withDecimalPlaces);
                
            private:
                StringImpl(const StringImpl& copy);
                void init(char* chr, int length, boolean copy);
                void copyCharacters(const char* chr, int length);
        };
    }
}

#endif
