#include "jam/util/locale/MessageResource.hxx"
#include "jam/util/locale/MissingResourceException.hxx"
#include "jam/lang/Class.hxx"
#include "jam/util/Iterator.hxx"

#include <iostream>

using namespace jam::util::locale;
using namespace jam::lang;
using namespace jam::util;

const Class MessageResource::klass = Class::newInstance("jam::util::locale::MessageResource");

HashMap MessageResourceImpl::domainMap = HashMap::newInstance();

/*** Reference ***/

MessageResource::MessageResource() : Object() {
    //
}

MessageResource::MessageResource(const Reference& ref) : Object(ref) {
    //
}

MessageResource::MessageResource(Implementation* impl) : Object(impl) {
    //
}

MessageResource::~MessageResource() {
    //
}

MessageResourceImpl& MessageResource::operator*() {
    return (MessageResourceImpl&) Object::operator*();
}

MessageResourceImpl* MessageResource::operator->() {
    return (MessageResourceImpl*) Object::operator->();
}

const MessageResource& MessageResource::operator=(const Reference& ref) {
    return (MessageResource&) Object::operator=(ref);
}

const MessageResource& MessageResource::operator=(Implementation* impl) {
    return (MessageResource&) Object::operator=(impl);
}

MessageResource MessageResource::newInstance(String domain, Language lang) {
    return MessageResource(new MessageResourceImpl(domain, lang));
}

void MessageResource::addMessageResource(MessageResource resource) {
    HashMap         languageMap;
    MessageResource other;
    
    // domain found
    languageMap = (HashMap) MessageResourceImpl::domainMap->get(resource->getDomain());
    if (languageMap != null) {
        
        // language found
        other = (MessageResource) languageMap->get(resource->getLanguage());
        if (other != null) {
            other->addString(resource);
        } else {
            languageMap->put(resource->getLanguage(), resource);
        }
    } else {
        languageMap = HashMap::newInstance();
        languageMap->put(resource->getLanguage(), resource);
        MessageResourceImpl::domainMap->put(resource->getDomain(), languageMap);
    }
}

MessageResource MessageResource::getMessageResource(String domain, Language lang) {
    HashMap         languageMap;
    MessageResource resource;
    
    // domain found
    languageMap = (HashMap) MessageResourceImpl::domainMap->get(domain);
    if (languageMap != null) {
        // language found
        resource = (MessageResource) languageMap->get(lang);
        if (resource != null) {
            return resource;
        }
    }
    
    throw MissingResourceException::newInstance();
}

/*** Implementation ***/

MessageResourceImpl::MessageResourceImpl(String domain, Language lang) {
    _domain     = domain;
    _lang       = lang;
    _messageMap = HashMap::newInstance();
}

MessageResourceImpl::~MessageResourceImpl() {
    
}

MessageResourceImpl::MessageResourceImpl(const MessageResourceImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* MessageResourceImpl::debugClassName() {
    return "jam::util::locale::MessageResource";
}
#endif

String MessageResourceImpl::toString() {
    return _domain + _lang->getISO2();
}

Class MessageResourceImpl::getClass() {
    return MessageResource::klass;
}

String MessageResourceImpl::getDomain() {
    return _domain;
}

Language MessageResourceImpl::getLanguage() {
    return _lang;
}

void MessageResourceImpl::addString(MessageResource resource) {
    _messageMap->putAll(resource->_messageMap);
}

void MessageResourceImpl::addString(String key, String value) {
    _messageMap->put(key, value);
}

String MessageResourceImpl::getString(String key) {
    String value;
    
    value = _messageMap->get(key);
    if (value == null) {
        throw MissingResourceException::newInstance();
    }
    
    return value;
}

String MessageResourceImpl::findKey(String value) {
    String   key;
    Iterator iter;
    
    // match
    iter = _messageMap->keyIterator();
    while (iter->hasNext()) {
        key = (String) iter->next();
        if (((String) _messageMap->get(key))->equals(value)) {
            return key;
        }
    }
    
    // starts with
    iter = _messageMap->keyIterator();
    while (iter->hasNext()) {
        key = (String) iter->next();
        if (((String) _messageMap->get(key))->startsWith(value)) {
            return key;
        }
    }
    
    throw MissingResourceException::newInstance();
}
