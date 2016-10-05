#include "jam/util/locale/Locale.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/List.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/Iterator.hxx"

using namespace jam::util::locale;
using namespace jam::lang;
using namespace jam::util;

const Class Locale::klass = new ClassImpl("jam::util::locale::Locale");

boolean Locale::_isInitialized = false;
Locale Locale::_default;

HashMap LocaleImpl::localeMap = HashMap::newInstance();

/*** Reference ***/

Locale::Locale() : Object() {
    //
}

Locale::Locale(const Reference& ref) : Object(ref) {
    //
}

Locale::Locale(Implementation* impl) : Object(impl) {
    //
}

Locale::~Locale() {
    //
}

LocaleImpl& Locale::operator*() {
    return (LocaleImpl&) Object::operator*();
}

LocaleImpl* Locale::operator->() {
    return (LocaleImpl*) Object::operator->();
}

const Locale& Locale::operator=(const Reference& ref) {
    return (Locale&) Object::operator=(ref);
}

const Locale& Locale::operator=(Implementation* impl) {
    return (Locale&) Object::operator=(impl);
}

void Locale::init() {
    if (_isInitialized == true) {
        return;
    }
    
    Language::init();
    Country::init();
    
    _isInitialized = true;
    
    Locale::newInstance(Language::GERMAN, Country::SWITZERLAND);
    Locale::newInstance(Language::GERMAN, Country::GERMANY);
    Locale::newInstance(Language::FRENCH, Country::SWITZERLAND);
    Locale::newInstance(Language::ITALIAN, Country::SWITZERLAND);
    Locale::newInstance(Language::ENGLISH, Country::UNITED_STATES);
    Locale::newInstance(Language::ENGLISH, Country::GREAT_BRITAIN);
}

boolean Locale::isInitialized() {
    return _isInitialized;
}

Locale Locale::newInstance(String isoLanguage, String isoCountry) {
    return Locale(new LocaleImpl(isoLanguage, isoCountry));
}

Locale Locale::newInstance(Language language, Country country) {
    return Locale(new LocaleImpl(language, country));
}

List Locale::getAvailableLocales() {
    List     localeList;
    Iterator iter;
    Locale   locale;
    
    if (isInitialized() == false) {
        init();
    }
    
    localeList = ArrayList::newInstance();
    iter       = LocaleImpl::localeMap->valueIterator();
    
    while (iter->hasNext()) {
        locale = (Locale) iter->next();
        localeList->add(locale);
    }
    
    return localeList;;
}

Locale Locale::getLocale(String identifier) {
    if (isInitialized() == false) {
        init();
    }
    
    return LocaleImpl::localeMap->get(identifier);
}

Locale Locale::getDefault() {
    if (isInitialized() == false) {
        init();
    }
    
    return getLocale(Language::getDefault()->getISO2() + "_" + Country::getDefault()->getISO2());;
}

void Locale::setDefault(Locale locale) {
    Language::setDefault(locale->getLanguage());
    Country::setDefault(locale->getCountry());
}

/*** Implementation ***/

LocaleImpl::LocaleImpl(String isoLanguage, String isoCountry) {
    String identifier;
    
    _language  = Language::getLanguage(isoLanguage);
    _country   = Country::getCountry(isoCountry);
    identifier = _language->getISO2() + "_" + _country->getISO2();
    
    localeMap->put(identifier, Locale(this));
}

LocaleImpl::LocaleImpl(Language language, Country country) {
    String identifier;
    
    _language  = language;
    _country   = country;
    identifier = _language->getISO2() + "_" + _country->getISO2();
    
    localeMap->put(identifier, Locale(this));
}

LocaleImpl::~LocaleImpl() {
    //
}

LocaleImpl::LocaleImpl(const LocaleImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LocaleImpl::debugClassName() {
    return "jam::util::locale::Locale";
}
#endif

String LocaleImpl::toString() {
    return getIdentifier();
}

Class LocaleImpl::getClass() {
    return Locale::klass;
}

Language LocaleImpl::getLanguage() {
    return _language;
}

Country LocaleImpl::getCountry() {
    return _country;
}

String LocaleImpl::getDisplayName() {
    return getDisplayName(Language::getDefault());
}

String LocaleImpl::getDisplayName(Language lang) {
    return _language->getDisplayName(lang) + " (" + _country->getDisplayName(lang) + ")";
}

String LocaleImpl::getIdentifier() {
    return _language->getISO2() + "_" + _country->getISO2();
}
