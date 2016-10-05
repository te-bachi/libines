#include "jam/util/locale/Language.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/locale/MessageResource.hxx"

using namespace jam::util;
using namespace jam::util::locale;
using namespace jam::lang;

const Class Language::klass = new ClassImpl("jam::util::locale::Language");

Language Language::GERMAN;
Language Language::FRENCH;
Language Language::ITALIAN;
Language Language::ENGLISH;
Language Language::CHINESE;
Language Language::MALAY;

boolean Language::_isInitialized = false;
Language Language::_default;

HashMap LanguageImpl::languageMap = HashMap::newInstance();

/*** Reference ***/

Language::Language() : Object() {
    //
}

Language::Language(const Reference& ref) : Object(ref) {
    //
}

Language::Language(Implementation* impl) : Object(impl) {
    //
}

Language::~Language() {
    //
}

LanguageImpl& Language::operator*() {
    return (LanguageImpl&) Object::operator*();
}

LanguageImpl* Language::operator->() {
    return (LanguageImpl*) Object::operator->();
}

const Language& Language::operator=(const Reference& ref) {
    return (Language&) Object::operator=(ref);
}

const Language& Language::operator=(Implementation* impl) {
    return (Language&) Object::operator=(impl);
}

void Language::init() {
    MessageResource resource;
    
    if (_isInitialized == true) {
        return;
    }
    
    _isInitialized = true;
    
    Language::GERMAN  = Language::newInstance(String::newInstance("de"), String::newInstance("deu"));
    Language::FRENCH  = Language::newInstance(String::newInstance("fr"), String::newInstance("fra"));
    Language::ITALIAN = Language::newInstance(String::newInstance("it"), String::newInstance("ita"));
    Language::ENGLISH = Language::newInstance(String::newInstance("en"), String::newInstance("eng"));
    Language::CHINESE = Language::newInstance(String::newInstance("zh"), String::newInstance("zho"));
    Language::MALAY   = Language::newInstance(String::newInstance("ms"), String::newInstance("msa"));
    
    // English
    resource = MessageResource::newInstance(((Class) Language::klass)->getName(), Language::ENGLISH);
    resource->addString(String::newInstance("de"), String::newInstance("German"));
    resource->addString(String::newInstance("fr"), String::newInstance("French"));
    resource->addString(String::newInstance("it"), String::newInstance("Italian"));
    resource->addString(String::newInstance("en"), String::newInstance("English"));
    resource->addString(String::newInstance("zh"), String::newInstance("Chinese"));
    resource->addString(String::newInstance("ms"), String::newInstance("Malay"));
    MessageResource::addMessageResource(resource);
    
    // German
    resource = MessageResource::newInstance(((Class) Language::klass)->getName(), Language::GERMAN);
    resource->addString(String::newInstance("de"), String::newInstance("Deutsch"));
    resource->addString(String::newInstance("fr"), String::newInstance("Französisch"));
    resource->addString(String::newInstance("it"), String::newInstance("Italienisch"));
    resource->addString(String::newInstance("en"), String::newInstance("Englisch"));
    resource->addString(String::newInstance("zh"), String::newInstance("Chinesisch"));
    resource->addString(String::newInstance("ms"), String::newInstance("Malaiisch"));
    MessageResource::addMessageResource(resource);
    
    // French
    resource = MessageResource::newInstance(((Class) Language::klass)->getName(), Language::FRENCH);
    resource->addString(String::newInstance("de"), String::newInstance("Allemand"));
    resource->addString(String::newInstance("fr"), String::newInstance("Français"));
    resource->addString(String::newInstance("it"), String::newInstance("Italien"));
    resource->addString(String::newInstance("en"), String::newInstance("Anglais"));
    resource->addString(String::newInstance("zh"), String::newInstance("Chinois"));
    resource->addString(String::newInstance("ms"), String::newInstance("Malais"));
    MessageResource::addMessageResource(resource);
    
    // Italian
    resource = MessageResource::newInstance(((Class) Language::klass)->getName(), Language::ITALIAN);
    resource->addString(String::newInstance("de"), String::newInstance("Tedesco"));
    resource->addString(String::newInstance("fr"), String::newInstance("Francese"));
    resource->addString(String::newInstance("it"), String::newInstance("Italiano"));
    resource->addString(String::newInstance("en"), String::newInstance("Inglesi"));
    resource->addString(String::newInstance("zh"), String::newInstance("Cinese"));
    resource->addString(String::newInstance("ms"), String::newInstance("Malese"));
    MessageResource::addMessageResource(resource);
    
    _default = Language::ENGLISH;
}

boolean Language::isInitialized() {
    return _isInitialized;
}

Language Language::newInstance(String iso2, String iso3) {
    return Language(new LanguageImpl(iso2, iso3));
}

Language Language::getLanguage(String iso) {
    if (isInitialized() == false) {
        init();
    }
    
    return LanguageImpl::languageMap->get(iso);
}

List Language::getAvailableLanguages() {
    List     langList;
    String   iso;
    Iterator iter;
    
    if (isInitialized() == false) {
        init();
    }
    
    langList = ArrayList::newInstance();
    iter     = LanguageImpl::languageMap->keyIterator();
    
    while (iter->hasNext()) {
        iso = (String) iter->next();
        if (iso->length() == 2) {
            langList->add(LanguageImpl::languageMap->get(iso));
        }
    }
    
    return langList;
}

Language Language::getDefault() {
    if (isInitialized() == false) {
        init();
    }
    
    return _default;
}

void Language::setDefault(Language language) {
    _default = language;
}

/*** Implementation ***/

LanguageImpl::LanguageImpl(String iso2, String iso3) {
    _iso2 = iso2;
    _iso3 = iso3;
    
    languageMap->put(iso2, Language(this));
    languageMap->put(iso3, Language(this));
}

LanguageImpl::~LanguageImpl() {
    
}

LanguageImpl::LanguageImpl(const LanguageImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LanguageImpl::debugClassName() {
    return "jam::util::locale::Language";
}
#endif

int LanguageImpl::hashCode() {
    return _iso3->hashCode();
}

String LanguageImpl::toString() {
    return _iso2;
}

Class LanguageImpl::getClass() {
    return Language::klass;
}

String LanguageImpl::getISO2() {
    return _iso2;
}

String LanguageImpl::getISO3() {
    return _iso3;
}

String LanguageImpl::getDisplayName(Language lang) {
    return MessageResource::getMessageResource(((Class) Language::klass)->getName(), lang)->getString(_iso2);
}
