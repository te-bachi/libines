#ifndef __LOCALE_HXX__
#define __LOCALE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/List.hxx"
#include "jam/util/HashMap.hxx"
#include "jam/util/locale/Language.hxx"
#include "jam/util/locale/Country.hxx"

namespace jam {
    namespace util {
        namespace locale {
            using namespace jam::lang;
            using namespace jam::util;
            
            class LocaleImpl;
            
            class Locale : public Object {
                public:
                    const static Class klass;
                    
                private:
                    static boolean _isInitialized;
                    static Locale  _default;
                    
                public:
                    Locale();
                    Locale(const Reference& ref);
                    Locale(Implementation* impl);
                    virtual ~Locale();
                    LocaleImpl& operator*();
                    LocaleImpl* operator->();
                    const Locale& operator=(const Reference& ref);
                    const Locale& operator=(Implementation* impl);
                    
                    static void init();
                    static boolean isInitialized();
                    static Locale newInstance(String isoLanguage, String isoCountry);
                    static Locale newInstance(Language language, Country country);
                    static Locale getLocale(String identifier);
                    static List getAvailableLocales();
                    static Locale getDefault();
                    static void setDefault(Locale locale);
            };
            
            class LocaleImpl : public ObjectImpl {
                friend class Locale;
                
                private:
                    static HashMap localeMap;
                    
                    Language _language;
                    Country  _country;
                    
                public:
                    LocaleImpl(String isoLanguage, String isoCountry);
                    LocaleImpl(Language language, Country country);
                    virtual ~LocaleImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual Language getLanguage();
                    virtual Country getCountry();
                    virtual String getDisplayName();
                    virtual String getDisplayName(Language lang);
                    virtual String getIdentifier();
                    
                private:
                    LocaleImpl(const LocaleImpl& copy);
            };
        }
    }
}

#endif
