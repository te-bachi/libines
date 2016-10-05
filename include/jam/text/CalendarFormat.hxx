#ifndef __CALENDAR_FORMAT_HXX__
#define __CALENDAR_FORMAT_HXX__

#include "jam/Global.hxx"
#include "jam/text/Format.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/locale/Locale.hxx"

namespace jam {
    namespace util {
        class StringBuffer;
        namespace time {
            class Calendar;
        }
    }
    namespace text {
        using namespace jam::lang;
        using namespace jam::util::locale;
        using namespace jam::util::time;
        
        class CalendarFormatImpl;
        
        class CalendarFormat : public Format {
            public:
                const static Class klass;
                
                typedef enum {
                    DATE_SHORT  = 1,
                    DATE_MEDIUM = 2,
                    DATE_LONG   = 4,
                    DATE_FULL   = 8,
                    TIME_SHORT  = 16,
                    TIME_MEDIUM = 32,
                    TIME_LONG   = 64,
                    TIME_FULL   = 128
                } Style;
                
            private:
                static boolean _isInitialized;
                
            public:
                CalendarFormat();
                CalendarFormat(const Reference& ref);
                CalendarFormat(Implementation* impl);
                virtual ~CalendarFormat();
                CalendarFormatImpl& operator*();
                CalendarFormatImpl* operator->();
                const CalendarFormat& operator=(const Reference& ref);
                const CalendarFormat& operator=(Implementation* impl);
                
                static void init();
                static boolean isInitialized();
                static CalendarFormat newInstance(String pattern);
                static CalendarFormat newInstance(short style);
                static CalendarFormat newInstance(Locale locale, short style);
                
        };
        
        class CalendarFormatImpl : public FormatImpl {
            private:
                Locale _locale;
                String _pattern;
                int    _cursor;
                int    _minLength;
                int    _maxLength;
                
            public:
                CalendarFormatImpl(String pattern);
                CalendarFormatImpl(short style);
                CalendarFormatImpl(Locale locale, short style);
                virtual ~CalendarFormatImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
                virtual String format(Object obj);
                virtual String format(Calendar calendar);
                virtual Object parse(String str);
                virtual Calendar parseCalendar(String str);
                
            private:
                CalendarFormatImpl(const CalendarFormatImpl& copy);
                void init(Locale locale, short style);
                boolean isEOF();
                boolean isCharacter(char chr);
                int letterLength(char chr);
                void formatNumber(StringBuffer buffer, String str, int length);
                String formatMonth(int month);
                String formatWeekday(int weekday);
                void calcPatternLength();
        };
    }
}

#endif
