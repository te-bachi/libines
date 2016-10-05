#include "jam/util/time/Calendar.hxx"
#include "jam/util/time/Clock.hxx"
#include "jam/util/time/TimeZone.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/System.hxx"

#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace jam::util::time;
using namespace jam::lang;

extern char** environ;
extern char *tzname[2];

const Class Calendar::klass = Class::newInstance("jam::util::time::Calendar");

const int Calendar::SECS_PER_MINUTE   = 60;
const int Calendar::SECS_PER_HOUR     = 3600;
const int Calendar::SECS_PER_DAY      = 86400;
const int Calendar::SECS_PER_MONTH    = 2592000;
const int Calendar::SECS_PER_YEAR     = 31536000;

/*** Reference ***/

Calendar::Calendar() : Object() {
    //
}

Calendar::Calendar(const Reference& ref) : Object(ref) {
    //
}

Calendar::Calendar(Implementation* impl) : Object(impl) {
    //
}

Calendar::~Calendar() {
    //
}

CalendarImpl& Calendar::operator*() {
    return (CalendarImpl&) Object::operator*();
}

CalendarImpl* Calendar::operator->() {
    return (CalendarImpl*) Object::operator->();
}

const Calendar& Calendar::operator=(const Reference& ref) {
    return (Calendar&) Object::operator=(ref);
}

const Calendar& Calendar::operator=(Implementation* impl) {
    return (Calendar&) Object::operator=(impl);
}

Calendar Calendar::newInstance() {
    return Calendar(new CalendarImpl());
}

Calendar Calendar::newInstance(TimeZone zone) {
    return Calendar(new CalendarImpl(zone));
}

Calendar Calendar::newInstance(time_t unixtime) {
    return Calendar(new CalendarImpl(unixtime));
}

Calendar Calendar::newInstance(time_t unixtime, TimeZone zone) {
    return Calendar(new CalendarImpl(unixtime, zone));
}

Calendar Calendar::newInstance(int day, int month, int year) {
    return Calendar(new CalendarImpl(day, month, year));
}

Calendar Calendar::newInstance(int day, int month, int year, TimeZone zone) {
    return Calendar(new CalendarImpl(day, month, year, zone));
}

Calendar Calendar::newInstance(int day, int month, int year, int hour, int minute, int second) {
    return Calendar(new CalendarImpl(day, month, year, hour, minute, second));
}

Calendar Calendar::newInstance(int day, int month, int year, int hour, int minute, int second, TimeZone zone) {
    return Calendar(new CalendarImpl(day, month, year, hour, minute, second, zone));
}

boolean Calendar::isLeapYear(int year) {
    if (((year % 4 == 0)  && (year % 100 != 0)) || (year % 400 == 0)) {
        return true;
    }
    
    return false;
}

int Calendar::getJulianDay(int day, int month, int year) {
    int julian;
    int tmpDay;
    int tmpMonth;
    int tmpYear;
    
    if(month > Calendar::FEBRUARY) {
        tmpYear  = year;
        tmpMonth = month + 1;
    } else {
        tmpYear  = year - 1;
        tmpMonth = month + 13;
    }
    
    julian = (int) (floor(365.25  * tmpYear) + 
                    floor(30.6001 * tmpMonth) + day + 1720995);
    
    tmpDay = (int) (0.01 * tmpYear);
    
    julian += 2 - tmpDay + (int) (0.25 * tmpDay);
    
    return julian;
} 

int Calendar::getDayOfYear(int day, int month, int year) {
    int now;
    int first;
    
    now   = getJulianDay(day, month, year);
    first = getJulianDay(1, 1, year);
    
    return (now - first + 1);
}

int Calendar::getWeekday(int day, int month, int year) {
    return ((Calendar::getJulianDay(day, month, year) + 1) % 7);
}

int Calendar::getFirstWeekdayOfMonth(int month, int year) {
    return getWeekday(1, month, year);
}

int Calendar::getLastWeekdayOfMonth(int month, int year) {
    return getWeekday(Calendar::getLastDayOfMonth(month, year), month, year);
}

int Calendar::getFirstDayOfMonth(int weekday, int month, int year) {
    int day;
    
    day = 1;
    
    while (Calendar::getWeekday(day, month, year) != weekday) {
        day++;
    }
    
    return day;
}

int Calendar::getDayOfMonth(int week, int weekday, int month, int year) {
    int day;
    int end;
    int count;
    
    end   = Calendar::getLastDayOfMonth(month, year);
    count = 0;
    
    for (day = 0; day < end && count < week; day++) {
        if (Calendar::getWeekday(day + 1, month, year) == weekday) {
            count++;
        }
    }
    
    return day - 1;
}

int Calendar::getLastDayOfMonth(int weekday, int month, int year) {
    int day;
    
    day = Calendar::getLastDayOfMonth(month, year);
    
    while (Calendar::getWeekday(day, month, year) != weekday) {
        day--;
    }
    
    return day;
}

int Calendar::getLastDayOfMonth(int month, int year) {
    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            
        default:
            return 31;
    }
}

/*** Implementation ***/

CalendarImpl::CalendarImpl() {
    initNow(TimeZone::getDefault());
}

CalendarImpl::CalendarImpl(TimeZone zone) {
    initNow(zone);
}

CalendarImpl::CalendarImpl(time_t unixtime) {
    initUnixtime(unixtime, TimeZone::getDefault());
}

CalendarImpl::CalendarImpl(time_t unixtime, TimeZone zone) {
    initUnixtime(unixtime, zone);
}

CalendarImpl::CalendarImpl(int day, int month, int year) {
    initStatic(day, month, year, 0, 0, 0, TimeZone::getDefault());
}

CalendarImpl::CalendarImpl(int day, int month, int year, TimeZone zone) {
    initStatic(day, month, year, 0, 0, 0, zone);
}

CalendarImpl::CalendarImpl(int day, int month, int year, int hour, int minute, int second) {
    initStatic(day, month, year, hour, minute, second, TimeZone::getDefault());
}

CalendarImpl::CalendarImpl(int day, int month, int year, int hour, int minute, int second, TimeZone zone) {
    initStatic(day, month, year, hour, minute, second, zone);
}

CalendarImpl::~CalendarImpl() {
    
}

CalendarImpl::CalendarImpl(const CalendarImpl& copy) {
    //
}


void CalendarImpl::initNow(TimeZone zone) {
    Clock clock;
    
    clock = System::getTime();
    _milisecond = clock->getNanosecond() / 1000000;
    
    initLocal(clock->getSecond(), zone);
}

void CalendarImpl::initUnixtime(time_t unixtime, TimeZone zone) {
    _milisecond = 0;
    
    initLocal(unixtime, zone);
}


void CalendarImpl::initLocal(time_t unixtime, TimeZone zone) {
    struct tm record;
    time_t    localtime;
    
    localtime = unixtime;
    
    if (zone != null) {
        localtime += zone->getOffset(unixtime);
    }
    
    gmtime_r(&localtime, &record);
    
    _zone       = zone;
    _unixtime   = unixtime;
    _second     = record.tm_sec;
    _minute     = record.tm_min;
    _hour       = record.tm_hour;
    _day        = record.tm_mday;
    _month      = record.tm_mon + 1;
    _year       = record.tm_year + 1900;
    _weekday    = record.tm_wday;
    _yearday    = record.tm_yday;
}

void CalendarImpl::initStatic(int day, int month, int year, int hour, int minute, int second, TimeZone zone) {
    struct tm   record;
    char*       tz_in;      // Quirk
    static char tz_out[16]; // Quirk
    
    _zone       = zone;
    _second     = second;
    _minute     = minute;
    _hour       = hour;
    _day        = day;
    _month      = month;
    _year       = year;
    _weekday    = Calendar::getWeekday(day, month, year);
    _yearday    = Calendar::getDayOfYear(day, month, year);
    
    record.tm_sec  = second;
    record.tm_min  = minute;
    record.tm_hour = hour;
    record.tm_mday = day;
    record.tm_mon  = month - 1;
    record.tm_year = year - 1900;
    
    _milisecond = 0;
    
    // Quirk
    tz_in = getenv("TZ");
    putenv((char*)"TZ=UTC");
    _unixtime = mktime(&record);
    if (tz_in != NULL) {
        sprintf(tz_out, "TZ=%s", tz_in);
        putenv(tz_out);
    }
    
    if (zone != null) {
        _unixtime -= zone->getOffset(_unixtime);
    }
}

#ifdef __DEBUG__
const char* CalendarImpl::debugClassName() {
    return "jam::util::time::Calendar";
}
#endif

String CalendarImpl::toString() {
    return null;
}

Class CalendarImpl::getClass() {
    return Calendar::klass;
}

time_t CalendarImpl::getUnixtime() {
    return _unixtime;
}

int CalendarImpl::getMilisecond() {
    return _milisecond;
}

int CalendarImpl::getSecond() {
    return _second;
}

int CalendarImpl::getMinute() {
    return _minute;
}

int CalendarImpl::getHour() {
    return _hour;
}

int CalendarImpl::getDay() {
    return _day;
}

int CalendarImpl::getMonth() {
    return _month;
}

int CalendarImpl::getYear() {
    return _year;
}

int CalendarImpl::getWeekday() {
    return _weekday;
}

int CalendarImpl::getYearday() {
    return _yearday;
}

int CalendarImpl::getDayOfYear() {
    return Calendar::getDayOfYear(_day, _month, _year);
}

void CalendarImpl::changeTimeZone(TimeZone zone) {
    initLocal(_unixtime, zone);
}

TimeZone CalendarImpl::getTimeZone() {
    return _zone;
}

void CalendarImpl::setDate(int day, int month, int year) {
    initStatic(day, month, year, _hour, _minute, _second, _zone);
}

void CalendarImpl::setTime(int hour, int minute, int second) {
    initStatic(_day, _month, _year, hour, minute, second, _zone);
}

void CalendarImpl::setDateAndTime(int day, int month, int year, int hour, int minute, int second) {
    initStatic(day, month, year, hour, minute, second, _zone);
}
