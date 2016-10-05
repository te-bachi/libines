#include "jam/util/locale/Country.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Integer.hxx"
#include "jam/util/locale/Language.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/locale/MessageResource.hxx"

using namespace jam::util;
using namespace jam::util::locale;
using namespace jam::lang;

const Class Country::klass = Class::newInstance("jam::util::locale::Country");

Country Country::SWITZERLAND;
Country Country::GERMANY;
Country Country::GREAT_BRITAIN;
Country Country::UNITED_STATES;
Country Country::CHINA;
Country Country::SINGAPORE;

boolean Country::_isInitialized = false;
Country Country::_default;

HashMap CountryImpl::countryMap = HashMap::newInstance();

/*** Reference ***/

Country::Country() : Object() {
    //
}

Country::Country(const Reference& ref) : Object(ref) {
    //
}

Country::Country(Implementation* impl) : Object(impl) {
    //
}

Country::~Country() {
    //
}

CountryImpl& Country::operator*() {
    return (CountryImpl&) Object::operator*();
}

CountryImpl* Country::operator->() {
    return (CountryImpl*) Object::operator->();
}

const Country& Country::operator=(const Reference& ref) {
    return (Country&) Object::operator=(ref);
}

const Country& Country::operator=(Implementation* impl) {
    return (Country&) Object::operator=(impl);
}

void Country::init() {
    MessageResource resource;
    List            chNumberPattern;
    List            deNumberPattern;
    List            usNumberPattern;
    
    List            chCalendarPattern;
    List            gbCalendarPattern;
    List            usCalendarPattern;
    
    if (_isInitialized == true) {
        return;
    }
    
    Language::init();
    
    chNumberPattern = ArrayList::newInstance(4);
    chNumberPattern->add(String::newInstance("#'##0.###"));
    chNumberPattern->add(String::newInstance("#'##0"));
    chNumberPattern->add(String::newInstance("#'##0.00"));
    chNumberPattern->add(String::newInstance("#'##0%"));
    
    deNumberPattern = ArrayList::newInstance(4);
    deNumberPattern->add(String::newInstance("#.##0,###"));
    deNumberPattern->add(String::newInstance("#.##0"));
    deNumberPattern->add(String::newInstance("#.##0,00"));
    deNumberPattern->add(String::newInstance("#.##0%"));
    
    usNumberPattern = ArrayList::newInstance(4);
    usNumberPattern->add(String::newInstance("#,##0.###"));
    usNumberPattern->add(String::newInstance("#,##0"));
    usNumberPattern->add(String::newInstance("#,##0.00"));
    usNumberPattern->add(String::newInstance("#,##0%"));
    
    chCalendarPattern = ArrayList::newInstance(8);
    chCalendarPattern->add(String::newInstance("dd.MM.yy"));
    chCalendarPattern->add(String::newInstance("dd.MM.yyyy"));
    chCalendarPattern->add(String::newInstance("dd. MMMM yyyy"));
    chCalendarPattern->add(String::newInstance("EEEE, dd. MMMM yyyy"));
    chCalendarPattern->add(String::newInstance("HH:mm"));
    chCalendarPattern->add(String::newInstance("HH:mm:ss"));
    chCalendarPattern->add(String::newInstance("HH:mm:ss Z"));
    chCalendarPattern->add(String::newInstance("HH:mm:ss ZZ"));
    
    gbCalendarPattern = ArrayList::newInstance(8);
    gbCalendarPattern->add(String::newInstance("dd/MM/yy"));
    gbCalendarPattern->add(String::newInstance("dd/MM/yyyy"));
    gbCalendarPattern->add(String::newInstance("dd MMMM yyyy"));
    gbCalendarPattern->add(String::newInstance("EEEE, dd MMMM yyyy"));
    gbCalendarPattern->add(String::newInstance("HH:mm"));
    gbCalendarPattern->add(String::newInstance("HH:mm:ss"));
    gbCalendarPattern->add(String::newInstance("HH:mm:ss Z"));
    gbCalendarPattern->add(String::newInstance("HH:mm:ss ZZ"));
    
    usCalendarPattern = ArrayList::newInstance(8);
    usCalendarPattern->add(String::newInstance("MM/dd/yy"));
    usCalendarPattern->add(String::newInstance("MM/dd/yyyy"));
    usCalendarPattern->add(String::newInstance("MMMM dd, yyyy"));
    usCalendarPattern->add(String::newInstance("EEEE, MMMM dd, yyyy"));
    usCalendarPattern->add(String::newInstance("hh:mm A"));
    usCalendarPattern->add(String::newInstance("hh:mm:ss A"));
    usCalendarPattern->add(String::newInstance("hh:mm:ss A Z"));
    usCalendarPattern->add(String::newInstance("hh:mm:ss A ZZ"));
    
    _isInitialized = true;
    
    Country::SWITZERLAND   = Country::newInstance(756, String::newInstance("CH"), String::newInstance("CHE"), chNumberPattern, chCalendarPattern);
    Country::GERMANY       = Country::newInstance(276, String::newInstance("DE"), String::newInstance("DEU"), deNumberPattern, chCalendarPattern);
    Country::GREAT_BRITAIN = Country::newInstance(826, String::newInstance("GB"), String::newInstance("GBR"), usNumberPattern, gbCalendarPattern);
    Country::UNITED_STATES = Country::newInstance(840, String::newInstance("US"), String::newInstance("USA"), usNumberPattern, usCalendarPattern);
    Country::CHINA         = Country::newInstance(156, String::newInstance("CN"), String::newInstance("CHN"), usNumberPattern, usCalendarPattern);
    Country::SINGAPORE     = Country::newInstance(702, String::newInstance("SG"), String::newInstance("SGP"), usNumberPattern, usCalendarPattern);
    
    // English
    resource = MessageResource::newInstance(((Class) Country::klass)->getName(), Language::ENGLISH);
    resource->addString(String::newInstance("CH"), String::newInstance("Switzerland"));
    resource->addString(String::newInstance("DE"), String::newInstance("Germany"));
    resource->addString(String::newInstance("GB"), String::newInstance("Great Britain"));
    resource->addString(String::newInstance("US"), String::newInstance("United States"));
    resource->addString(String::newInstance("CN"), String::newInstance("China"));
    resource->addString(String::newInstance("SG"), String::newInstance("Singapore"));
    MessageResource::addMessageResource(resource);
    
    // German
    resource = MessageResource::newInstance(((Class) Country::klass)->getName(), Language::GERMAN);
    resource->addString(String::newInstance("CH"), String::newInstance("Schweiz"));
    resource->addString(String::newInstance("DE"), String::newInstance("Deutschland"));
    resource->addString(String::newInstance("GB"), String::newInstance("Grossbritannien"));
    resource->addString(String::newInstance("US"), String::newInstance("Vereinigte Staaten"));
    resource->addString(String::newInstance("CN"), String::newInstance("China"));
    resource->addString(String::newInstance("SG"), String::newInstance("Singapur"));
    MessageResource::addMessageResource(resource);
    
    // French
    resource = MessageResource::newInstance(((Class) Country::klass)->getName(), Language::FRENCH);
    resource->addString(String::newInstance("CH"), String::newInstance("Suisse"));
    resource->addString(String::newInstance("DE"), String::newInstance("Allemagne"));
    resource->addString(String::newInstance("GB"), String::newInstance("Grande-Bretagne"));
    resource->addString(String::newInstance("US"), String::newInstance("États-Unis"));
    resource->addString(String::newInstance("CN"), String::newInstance("Chine"));
    resource->addString(String::newInstance("SG"), String::newInstance("Singapour"));
    MessageResource::addMessageResource(resource);
    
    // Italian
    resource = MessageResource::newInstance(((Class) Country::klass)->getName(), Language::ITALIAN);
    resource->addString(String::newInstance("CH"), String::newInstance("Svizzera"));
    resource->addString(String::newInstance("DE"), String::newInstance("Germania"));
    resource->addString(String::newInstance("GB"), String::newInstance("Gran bretagna"));
    resource->addString(String::newInstance("US"), String::newInstance("Stati uniti"));
    resource->addString(String::newInstance("CN"), String::newInstance("Cina"));
    resource->addString(String::newInstance("SG"), String::newInstance("Singapour"));
    MessageResource::addMessageResource(resource);
    
    _default = Country::UNITED_STATES;
}

boolean Country::isInitialized() {
    return _isInitialized;
}

Country Country::newInstance(int number, String iso2, String iso3, List numberPatternList, List calendarPatternList) {
    return Country(new CountryImpl(number, iso2, iso3, numberPatternList, calendarPatternList));
}

Country Country::getCountry(int number) {
    if (isInitialized() == false) {
        init();
    }
    
    return CountryImpl::countryMap->get(Integer::newInstance(number));
}

Country Country::getCountry(String iso) {
    if (isInitialized() == false) {
        init();
    }
    
    return CountryImpl::countryMap->get(iso);
}

List Country::getAvailableCountries() {
    List     countryList;
    Object   obj;
    String   iso;
    Iterator iter;
    
    if (isInitialized() == false) {
        init();
    }
    
    countryList = ArrayList::newInstance();
    iter        = CountryImpl::countryMap->keyIterator();
    
    while (iter->hasNext()) {
        obj = iter->next();
        if (obj->getClass()->equals(String::klass)) {
            iso = (String) obj;
            if (iso->length() == 2) {
                countryList->add(CountryImpl::countryMap->get(iso));
            }
        }
    }
    
    return countryList;
}

Country Country::getDefault() {
    if (isInitialized() == false) {
        init();
    }
    
    return _default;
}

void Country::setDefault(Country country) {
    _default = country;
}

/*** Implementation ***/

CountryImpl::CountryImpl(int number, String iso2, String iso3, List numberPatternList, List calendarPatternList) {
    
    _number              = number;
    _iso2                = iso2;
    _iso3                = iso3;
    _numberPatternList   = numberPatternList;
    _calendarPatternList = calendarPatternList;
    
    countryMap->put(Integer::newInstance(number), Country(this));
    countryMap->put(iso2, Country(this));
    countryMap->put(iso3, Country(this));
}

CountryImpl::~CountryImpl() {
    
}

CountryImpl::CountryImpl(const CountryImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* CountryImpl::debugClassName() {
    return "jam::util::locale::Country";
}
#endif

String CountryImpl::toString() {
    return _iso2;
}

Class CountryImpl::getClass() {
    return Country::klass;
}

int CountryImpl::getNumber() {
    return _number;
}

String CountryImpl::getISO2() {
    return _iso2;
}

String CountryImpl::getISO3() {
    return _iso3;
}

String CountryImpl::getDisplayName(Language lang) {
    return MessageResource::getMessageResource(((Class) Country::klass)->getName(), lang)->getString(_iso2);
}

String CountryImpl::getNumberPattern(int style) {
    return (String) _numberPatternList->get(style);
}

String CountryImpl::getCalendarPattern(int style) {
    return (String) _calendarPatternList->get(style);
}
