#ifndef __TIME_ZONE_HXX__
#define __TIME_ZONE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/List.hxx"
#include "jam/util/HashMap.hxx"

namespace jam {
    namespace util {
        namespace time {
            using namespace jam::lang;
            using namespace jam::util;
            
            class TimeZoneImpl;
            class Calendar;
            
            class TimeZone : public Object {
                public:
                    const static Class klass;
                    
                    const static int FIRST_DAY_OF_MONTH;
                    const static int LAST_DAY_OF_MONTH;
                    
                private:
                    static boolean _isInitialized;
                    
                public:
                    TimeZone();
                    TimeZone(const Reference& ref);
                    TimeZone(Implementation* impl);
                    virtual ~TimeZone();
                    TimeZoneImpl& operator*();
                    TimeZoneImpl* operator->();
                    const TimeZone& operator=(const Reference& ref);
                    const TimeZone& operator=(Implementation* impl);
                    
                    static void init();
                    static boolean isInitialized();
                    static TimeZone newInstance(int offset, String id);
                    static TimeZone newInstance(int offset, String id,
                                                int startMonth, int startDay, int startWeekday, int startTime,
                                                int endMonth, int endDay, int endWeekday, int endTime,
                                                int dstSaving);
                    static List getAvailableTimeZones();
                    static List getAvailableLocations();
                    static void addLocation(String location, TimeZone zone);
                    static TimeZone getTimeZone(String id);
                    static TimeZone getLocation(String location);
                    static TimeZone getDefault();
            };
            
            class TimeZoneImpl : public ObjectImpl {
                friend class TimeZone;
                
                private:
                    static HashMap  zoneMap;
                    static HashMap  locationMap;
                    
                    int             _offset;
                    String          _id;
                    int             _startMonth;
                    int             _startDay;
                    int             _startWeekday;
                    int             _startTime;
                    int             _endMonth;
                    int             _endDay;
                    int             _endWeekday;
                    int             _endTime;
                    int             _dstSaving;
                    
                public:
                    TimeZoneImpl(int offset, String id);
                    TimeZoneImpl(int offset, String id,
                                 int startMonth, int startDay, int startWeekday, int startTime,
                                 int endMonth, int endDay, int endWeekday, int endTime,
                                 int dstSaving);
                    virtual ~TimeZoneImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual String getId();
                    virtual int getRawOffset();
                    virtual int getOffset(Calendar calendar);
                    virtual int getOffset(long unixtime);
                    virtual boolean useDaylightTime();
                    virtual boolean inDaylightTime(Calendar calendar);
                    virtual boolean inDaylightTime(long unixtime);
                    
                private:
                    TimeZoneImpl(const TimeZoneImpl& copy);
                    void init(int offset, String id,
                              int startMonth, int startDay, int startWeekday, int startTime,
                              int endMonth, int endDay, int endWeekday, int endTime,
                              int dstSaving);
            };
        }
    }
}

#endif
