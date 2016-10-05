#ifndef __NUMBER_FORMAT_HXX__
#define __NUMBER_FORMAT_HXX__

#include "jam/Global.hxx"
#include "jam/text/Format.hxx"

namespace jam {
    namespace lang {
        class Number;
    }
    namespace util {
        namespace locale {
            class Locale;
        }
    }
    namespace text {
        using namespace jam::lang;
        using namespace jam::util::locale;
        
        class NumberFormatImpl;
        
        class NumberFormat : public Format {
            public:
                const static Class klass;
                
                typedef enum {
                    DECIMAL = 0,
                    INTEGER,
                    CURRENCY,
                    PERCENT,
                    STYLE_LENGTH
                } Style;
                
            public:
                NumberFormat();
                NumberFormat(const Reference& ref);
                NumberFormat(Implementation* impl);
                virtual ~NumberFormat();
                NumberFormatImpl& operator*();
                NumberFormatImpl* operator->();
                const NumberFormat& operator=(const Reference& ref);
                const NumberFormat& operator=(Implementation* impl);
                
                static NumberFormat newInstance(String pattern);
                static NumberFormat newInstance(int style);
                static NumberFormat newInstance(int style, Locale locale);
                
        };
        
        class NumberFormatImpl : public FormatImpl {
            private:
                char   _groupingSeparator;
                char   _decimalSeparator;
                int    _necessaryFraction;
                int    _optionalFraction;
                int    _necessaryInteger;
                int    _optionalInteger;
                int    _groupingOffset;
                
            public:
                NumberFormatImpl(String pattern);
                NumberFormatImpl(int style);
                NumberFormatImpl(int style, Locale locale);
                virtual ~NumberFormatImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
                virtual String format(Object obj);
                virtual String format(String str);
                virtual String format(Number number);
                virtual String format(long value);
                virtual String format(double value);
                virtual Object parse(String str);
                virtual Number parseNumber(String str);
                virtual long parseLong(String str);
                virtual double parseDouble(String str);
                
            private:
                NumberFormatImpl(const NumberFormatImpl& copy);
                void init(String pattern);
        };
    }
}

#endif
