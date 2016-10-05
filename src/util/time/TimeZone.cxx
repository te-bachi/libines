#include "jam/util/time/TimeZone.hxx"
#include "jam/util/time/Calendar.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/Iterator.hxx"

#include <iostream>

using namespace jam::lang;
using namespace jam::util;
using namespace jam::util::time;

const Class TimeZone::klass = new ClassImpl("jam::util::time::TimeZone");

const int TimeZone::FIRST_DAY_OF_MONTH = 1;
const int TimeZone::LAST_DAY_OF_MONTH  = -1;

boolean TimeZone::_isInitialized = false;

HashMap TimeZoneImpl::zoneMap     = HashMap::newInstance();
HashMap TimeZoneImpl::locationMap = HashMap::newInstance();

/*** Reference ***/

TimeZone::TimeZone() : Object() {
    //
}

TimeZone::TimeZone(const Reference& ref) : Object(ref) {
    //
}

TimeZone::TimeZone(Implementation* impl) : Object(impl) {
    //
}

TimeZone::~TimeZone() {
    //
}

TimeZoneImpl& TimeZone::operator*() {
    return (TimeZoneImpl&) Object::operator*();
}

TimeZoneImpl* TimeZone::operator->() {
    return (TimeZoneImpl*) Object::operator->();
}

const TimeZone& TimeZone::operator=(const Reference& ref) {
    return (TimeZone&) Object::operator=(ref);
}

const TimeZone& TimeZone::operator=(Implementation* impl) {
    return (TimeZone&) Object::operator=(impl);
}

TimeZone TimeZone::newInstance(int offset, String id) {
    return TimeZone(new TimeZoneImpl(offset, id));
}

TimeZone TimeZone::newInstance(int offset, String id,
                               int startMonth, int startDay, int startWeekday, int startTime,
                               int endMonth, int endDay, int endWeekday, int endTime,
                               int dstSaving) {
    return TimeZone(new TimeZoneImpl(offset, id,
                                     startMonth, startDay, startWeekday, startTime,
                                     endMonth, endDay, endWeekday, endTime,
                                     dstSaving));
}

void TimeZone::init() {
    if (_isInitialized == true) {
        return;
    }
    
    _isInitialized = true;
    
    TimeZone::newInstance(-39600, String::newInstance("MIT"));  // West Samoa Time
    TimeZone::newInstance(-36000, String::newInstance("HST"));  // Hawaii Standard Time
    TimeZone::newInstance(-25200, String::newInstance("PNT"));  // Mountain Standard Time
    TimeZone::newInstance(-18000, String::newInstance("IET"));  // Eastern Standard Time
    TimeZone::newInstance(-14400, String::newInstance("PRT"));  // Atlantic Standard Time
    TimeZone::newInstance(-10800, String::newInstance("AGT"));  // Argentine Time
    TimeZone::newInstance(0, String::newInstance("UTC"));       // Coordinated Universal Time
    TimeZone::newInstance(0, String::newInstance("UCT"));       // Coordinated Universal Time
    TimeZone::newInstance(0, String::newInstance("GMT"));       // Greenwich Mean Time
    TimeZone::newInstance(3600, String::newInstance("WAT"));    // Western African Time
    TimeZone::newInstance(7200, String::newInstance("CAT"));    // Central African Time
    TimeZone::newInstance(10800, String::newInstance("EAT"));   // Eastern African Time
    TimeZone::newInstance(18000, String::newInstance("PLT"));   // Pakistan Time
    TimeZone::newInstance(19800, String::newInstance("IST"));   // India Standard Time
    TimeZone::newInstance(21600, String::newInstance("BST"));   // Bangladesh Time
    TimeZone::newInstance(25200, String::newInstance("VST"));   // Indochina Time
    TimeZone::newInstance(28800, String::newInstance("CTT"));   // Chinesische Standard Time
    TimeZone::newInstance(28800, String::newInstance("PRC"));   // China Standard Time
    TimeZone::newInstance(28800, String::newInstance("HKT"));   // Hong Kong Time
    TimeZone::newInstance(28800, String::newInstance("AWT"));   // Australian Western Standard Time
    TimeZone::newInstance(32400, String::newInstance("JST"));   // Japan Standard Time
    TimeZone::newInstance(32400, String::newInstance("ROK"));   // Korea Standard Time
        
    TimeZone::newInstance(-32400, String::newInstance("AST"),   // Alaska Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(-28800, String::newInstance("PST"),   // Pacific Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(-25200, String::newInstance("MST"),   // Mountain Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(-21600, String::newInstance("CST"),   // Central Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(-18000, String::newInstance("EST"),   // Eastern Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(-12600, String::newInstance("CNT"),   // Newfoundland Standard Time
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 1,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 1,
                          3600);
    
    TimeZone::newInstance(-10800, String::newInstance("BET"),   // Brazil Time
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 0,
                          Calendar::FEBRUARY, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 0,
                          3600);
    
    TimeZone::newInstance(3600, String::newInstance("WET"),     // Western European Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 3600,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          3600);
    
    TimeZone::newInstance(3600, String::newInstance("CET"),     // Central European Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          3600);
    
    TimeZone::newInstance(3600, String::newInstance("ECT"),     // Central European Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          3600);
    
    TimeZone::newInstance(3600, String::newInstance("MET"),     // Middle Europe Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          3600);
    
    TimeZone::newInstance(7200, String::newInstance("ART"),     // Eastern European Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 14400,
                          3600);
    
    TimeZone::newInstance(7200, String::newInstance("EET"),     // Eastern European Time
                          Calendar::MARCH, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 14400,
                          3600);
    
    TimeZone::newInstance(34200, String::newInstance("ACT"),    // Australian Central Standard Time
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          3600);
    
    TimeZone::newInstance(36000, String::newInstance("AET"),    // Australian Eastern Standard Time
                          Calendar::OCTOBER, TimeZone::LAST_DAY_OF_MONTH, Calendar::SUNDAY, 7200,
                          Calendar::APRIL, TimeZone::FIRST_DAY_OF_MONTH, Calendar::SUNDAY, 10800,
                          3600);
    
    
    TimeZone::addLocation(String::newInstance("Asia/Singapore"), TimeZone::getTimeZone(String::newInstance("PRC")));
    TimeZone::addLocation(String::newInstance("Asia/Hong Kong"), TimeZone::getTimeZone(String::newInstance("PRC")));
    TimeZone::addLocation(String::newInstance("Europe/Zurich"), TimeZone::getTimeZone(String::newInstance("CET")));
    TimeZone::addLocation(String::newInstance("Europe/Berlin"), TimeZone::getTimeZone(String::newInstance("CET")));
    TimeZone::addLocation(String::newInstance("Europe/Paris"), TimeZone::getTimeZone(String::newInstance("CET")));
    TimeZone::addLocation(String::newInstance("America/Hawaii"), TimeZone::getTimeZone(String::newInstance("HST")));
    TimeZone::addLocation(String::newInstance("America/New York"), TimeZone::getTimeZone(String::newInstance("EST")));
    TimeZone::addLocation(String::newInstance("America/San Francisco"), TimeZone::getTimeZone(String::newInstance("PST")));
}

boolean TimeZone::isInitialized() {
    return _isInitialized;
}

List TimeZone::getAvailableTimeZones() {
    ArrayList list;
    Iterator  iter;
    
    if (isInitialized() == false) {
        init();
    }
    
    list = ArrayList::newInstance();
    iter = TimeZoneImpl::zoneMap->valueIterator();
    
    while (iter->hasNext()) {
        list->add(iter->next());
    }
    
    return list;
}


List TimeZone::getAvailableLocations() {
    ArrayList list;
    Iterator  iter;
    
    if (isInitialized() == false) {
        init();
    }
    
    list = ArrayList::newInstance();
    iter = TimeZoneImpl::locationMap->keyIterator();
    
    while (iter->hasNext()) {
        list->add(iter->next());
    }
    
    return list;
}

void TimeZone::addLocation(String location, TimeZone zone) {
    if (isInitialized() == false) {
        init();
    }
    
    TimeZoneImpl::locationMap->put(location, zone);
}

TimeZone TimeZone::getTimeZone(String id) {
    if (isInitialized() == false) {
        init();
    }
    
    return TimeZoneImpl::zoneMap->get(id);
}

TimeZone TimeZone::getLocation(String location) {
    if (isInitialized() == false) {
        init();
    }
    
    return TimeZoneImpl::locationMap->get(location);
}

TimeZone TimeZone::getDefault() {
    TimeZone zone;
    String   name;
    
    if (isInitialized() == false) {
        init();
    }
    
    // Quirk
    name = getenv("TZ");
    if (name != null && name->length() >= 3) {
        if ((zone = TimeZoneImpl::zoneMap->get(name->substring(0, 3))) == null) {
            name = "UTC";
            zone = TimeZoneImpl::zoneMap->get(name);
        }
    }
    
    return zone;
}

/*** Implementation ***/

TimeZoneImpl::TimeZoneImpl(int offset, String id) {
    init(offset, id,
         Calendar::JANUARY, 0, Calendar::SUNDAY, 0,
         Calendar::JANUARY, 0, Calendar::SUNDAY, 0,
         0);
}

TimeZoneImpl::TimeZoneImpl(int offset, String id,
                           int startMonth, int startDay, int startWeekday, int startTime,
                           int endMonth, int endDay, int endWeekday, int endTime,
                           int dstSaving) {
    init(offset, id,
         startMonth, startDay, startWeekday, startTime,
         endMonth, endDay, endWeekday, endTime,
         dstSaving);
}

TimeZoneImpl::~TimeZoneImpl() {
    
}

TimeZoneImpl::TimeZoneImpl(const TimeZoneImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* TimeZoneImpl::debugClassName() {
    return "jam::util::time::TimeZone";
}
#endif

String TimeZoneImpl::toString() {
    return _id;
}

Class TimeZoneImpl::getClass() {
    return TimeZone::klass;
}

void TimeZoneImpl::init(int offset, String id,
                        int startMonth, int startDay, int startWeekday, int startTime,
                        int endMonth, int endDay, int endWeekday, int endTime,
                        int dstSaving) {
    _offset         = offset;
    _id             = id;
    _startMonth     = startMonth;
    _startDay       = startDay;
    _startWeekday   = startWeekday;
    _startTime      = startTime;
    _endMonth       = endMonth;
    _endDay         = endDay;
    _endWeekday     = endWeekday;
    _endTime        = endTime;
    _dstSaving      = dstSaving;
    
    TimeZoneImpl::zoneMap->put(id, TimeZone(this));
}

String TimeZoneImpl::getId() {
    return _id;
}

int TimeZoneImpl::getRawOffset() {
    return _offset;
}

int TimeZoneImpl::getOffset(Calendar calendar) {
    return getOffset(calendar->getUnixtime());
}

int TimeZoneImpl::getOffset(long unixtime) {
    if (inDaylightTime(unixtime)) {
        return (_offset + _dstSaving);
    }
    
    return _offset;
}

boolean TimeZoneImpl::useDaylightTime() {
    return _dstSaving != 0 ? true : false;
}

boolean TimeZoneImpl::inDaylightTime(Calendar calendar) {
    return inDaylightTime(calendar->getUnixtime());
}

boolean TimeZoneImpl::inDaylightTime(long unixtime) {
    time_t      offtime;
    struct tm   record;
    int         day;
    int         month;
    int         year;
    int         time;
    int         point;
    int         startMonth;
    int         endMonth;
    
    point      = 0;
    startMonth = _startMonth + 1;
    endMonth   = _endMonth   + 1;
    
    if (_dstSaving != 0) {
        offtime = unixtime + _offset;
        
        gmtime_r(&offtime, &record);
        
        day     = record.tm_mday;
        month   = record.tm_mon  + 1;
        year    = record.tm_year + 1900;
        time    = record.tm_sec  +
                 (record.tm_min  * Calendar::SECS_PER_MINUTE) +
                 (record.tm_hour * Calendar::SECS_PER_HOUR);
        
        // Middle DST
        if (startMonth > endMonth && (month > startMonth || month < endMonth)) {
            return true;
        } else if (startMonth < endMonth && (month > startMonth && month < endMonth)) {
            return true;
            
        // Start DST
        } else if (month == startMonth)  {
            if (_startDay == TimeZone::FIRST_DAY_OF_MONTH) {
                point = Calendar::getFirstDayOfMonth(_startWeekday, startMonth, year);
            } else if (_startDay == TimeZone::LAST_DAY_OF_MONTH) {
                point = Calendar::getLastDayOfMonth(_startWeekday, startMonth, year);
            }
            
            if (day > point || (day == point && time >= _startTime)) {
                return true;
            }
            
        // End DST
        } else if (month == endMonth) {
            if (_endDay == TimeZone::FIRST_DAY_OF_MONTH) {
                point = Calendar::getFirstDayOfMonth(_endWeekday, endMonth, year);
            } else if (_endDay == TimeZone::LAST_DAY_OF_MONTH) {
                point = Calendar::getLastDayOfMonth(_endWeekday, endMonth, year);
            }
            
            if (day < point || (day == point && time < _startTime)) {
                return true;
            }
        }
    }
    
    return false;
}
