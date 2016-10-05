#ifndef __LANGUAGE_HXX__
#define __LANGUAGE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/List.hxx"
#include "jam/util/HashMap.hxx"

namespace jam {
    namespace util {
        namespace locale {
            using namespace jam::lang;
            using namespace jam::util;
            
            class LanguageImpl;
            
            class Language : public Object {
                public:
                    const static Class klass;
                    
                    static Language GERMAN;
                    static Language FRENCH;
                    static Language ITALIAN;
                    static Language ENGLISH;
                    static Language CHINESE;
                    static Language MALAY;
                    
                private:
                    static boolean  _isInitialized;
                    static Language _default;
                    
                public:
                    Language();
                    Language(const Reference& ref);
                    Language(Implementation* impl);
                    virtual ~Language();
                    LanguageImpl& operator*();
                    LanguageImpl* operator->();
                    const Language& operator=(const Reference& ref);
                    const Language& operator=(Implementation* impl);
                    
                    static void init();
                    static boolean isInitialized();
                    static Language newInstance(String iso2, String iso3);
                    static Language getLanguage(String iso);
                    static List getAvailableLanguages();
                    static Language getDefault();
                    static void setDefault(Language language);
            };
            
            class LanguageImpl : public ObjectImpl {
                friend class Language;
                
                private:
                    static HashMap  languageMap;
                    
                    String          _iso2;
                    String          _iso3;
                    
                public:
                    LanguageImpl(String iso2, String iso3);
                    virtual ~LanguageImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual int hashCode();
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual String getISO2();
                    virtual String getISO3();
                    virtual String getDisplayName(Language lang);
                    
                private:
                    LanguageImpl(const LanguageImpl& copy);
            };
        }
    }
}

#endif
