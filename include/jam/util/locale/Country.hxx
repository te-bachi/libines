#ifndef __COUNTRY_HXX__
#define __COUNTRY_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/List.hxx"
#include "jam/util/HashMap.hxx"
#include "jam/util/locale/Language.hxx"

namespace jam {
    namespace util {
        namespace locale {
            using namespace jam::lang;
            
            class CountryImpl;
            
            class Country : public Object {
                public:
                    const static Class klass;
                    
                    static Country SWITZERLAND;
                    static Country GERMANY;
                    static Country GREAT_BRITAIN;
                    static Country UNITED_STATES;
                    static Country CHINA;
                    static Country SINGAPORE;
                    
                private:
                    static boolean _isInitialized;
                    static Country _default;
                    
                public:
                    Country();
                    Country(const Reference& ref);
                    Country(Implementation* impl);
                    virtual ~Country();
                    CountryImpl& operator*();
                    CountryImpl* operator->();
                    const Country& operator=(const Reference& ref);
                    const Country& operator=(Implementation* impl);
                    
                    static void init();
                    static boolean isInitialized();
                    static Country newInstance(int number, String iso2, String iso3, List numberPatternList, List calendarPatternList);
                    static Country getCountry(int number);
                    static Country getCountry(String iso);
                    static List getAvailableCountries();
                    static Country getDefault();
                    static void setDefault(Country country);
            };
            
            
            class CountryImpl : public ObjectImpl {
                
                friend class Country;
                
                private:                    
                    static HashMap countryMap;
                    
                    int    _number;
                    String _iso2;
                    String _iso3;
                    List   _numberPatternList;
                    List   _calendarPatternList;
                    
                public:
                    CountryImpl(int number, String iso2, String iso3, List numberPatternList, List calendarPatternList);
                    virtual ~CountryImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual int getNumber();
                    virtual String getISO2();
                    virtual String getISO3();
                    virtual String getDisplayName(Language lang);
                    virtual String getNumberPattern(int style);
                    virtual String getCalendarPattern(int style);
                    
                private:
                    CountryImpl(const CountryImpl& copy);
            };
        }
    }
}

#endif
