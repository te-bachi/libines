#ifndef __CALENDAR_HXX__
#define __CALENDAR_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/time/TimeZone.hxx"

#include <time.h>

namespace jam {
    namespace util {
        namespace time {
            using namespace jam::lang;
            
            class CalendarImpl;
            class TimeZone;
            
            class Calendar : public Object {
                public:
                    const static Class klass;
                    
                    const static int SECS_PER_MINUTE;
                    const static int SECS_PER_HOUR;
                    const static int SECS_PER_DAY;
                    const static int SECS_PER_MONTH;
                    const static int SECS_PER_YEAR;
                    
                    typedef enum {
                        SUNDAY = 0,
                        MONDAY,
                        TUESDAY,
                        WEDNESDAY,
                        THURSDAY,
                        FRIDAY,
                        SATURDAY
                    } Weekday;
                    
                    typedef enum {
                        JANUARY = 0,
                        FEBRUARY,
                        MARCH,
                        APRIL,
                        MAY,
                        JUNE,
                        JULY,
                        AUGUST,
                        SEPTEMBER,
                        OCTOBER,
                        NOVEMBER,
                        DECEMBER
                    } Month;
                    
                public:
                    Calendar();
                    Calendar(const Reference& ref);
                    Calendar(Implementation* impl);
                    virtual ~Calendar();
                    CalendarImpl& operator*();
                    CalendarImpl* operator->();
                    const Calendar& operator=(const Reference& ref);
                    const Calendar& operator=(Implementation* impl);
                    
                    static Calendar newInstance();
                    static Calendar newInstance(TimeZone zone);
                    static Calendar newInstance(time_t unixtime);
                    static Calendar newInstance(time_t unixtime, TimeZone zone);
                    static Calendar newInstance(int day, int month, int year);
                    static Calendar newInstance(int day, int month, int year, TimeZone zone);
                    static Calendar newInstance(int day, int month, int year, int hour, int minute, int second);
                    static Calendar newInstance(int day, int month, int year, int hour, int minute, int second, TimeZone zone);
                    
                    static boolean isLeapYear(int year);
                    static int getJulianDay(int day, int month, int year);
                    static int getDayOfYear(int day, int month, int year);
                    static int getWeekday(int day, int month, int year);
                    static int getFirstWeekdayOfMonth(int month, int year);                 //                      return weekday
                    static int getLastWeekdayOfMonth(int month, int year);                  //                      return weekday
                    static int getDayOfMonth(int week, int weekday, int month, int year);   // param week weekday   return day
                    static int getFirstDayOfMonth(int weekday, int month, int year);        // param weekday        return day
                    static int getLastDayOfMonth(int weekday, int month, int year);         // param weekday        return day
                    static int getLastDayOfMonth(int month, int year);                      //                      return day
            };
            
            class CalendarImpl : public ObjectImpl {
                private:
                    
                    TimeZone _zone;
                    time_t   _unixtime;
                    int      _milisecond;
                    int      _second;
                    int      _minute;
                    int      _hour;
                    int      _day;
                    int      _month;
                    int      _year;
                    int      _weekday;
                    int      _yearday;
                    
                public:
                    CalendarImpl();
                    CalendarImpl(TimeZone zone);
                    CalendarImpl(time_t unixtime);
                    CalendarImpl(time_t unixtime, TimeZone zone);
                    CalendarImpl(int day, int month, int year);
                    CalendarImpl(int day, int month, int year, TimeZone zone);
                    CalendarImpl(int day, int month, int year, int hour, int minute, int second);
                    CalendarImpl(int day, int month, int year, int hour, int minute, int second, TimeZone zone);
                    virtual ~CalendarImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual time_t getUnixtime();
                    virtual int getMilisecond();
                    virtual int getSecond();
                    virtual int getMinute();
                    virtual int getHour();
                    virtual int getDay();
                    virtual int getMonth();
                    virtual int getYear();
                    virtual int getWeekday();
                    virtual int getYearday();
                    virtual int getDayOfYear();
                    virtual void changeTimeZone(TimeZone zone);
                    virtual TimeZone getTimeZone();
                    virtual void setDate(int day, int month, int year);
                    virtual void setTime(int hour, int minute, int second);
                    virtual void setDateAndTime(int day, int month, int year, int hour, int minute, int second);
                    
                private:
                    CalendarImpl(const CalendarImpl& copy);
                    void initNow(TimeZone zone);
                    void initUnixtime(time_t unixtime, TimeZone zone);
                    void initLocal(time_t unixtime, TimeZone zone);
                    void initStatic(int second, int minute, int hour, int day, int month, int year, TimeZone zone);
            };
        }
    }
}

#endif
