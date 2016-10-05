#ifndef __MESSAGE_RESOURCE_HXX__
#define __MESSAGE_RESOURCE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/HashMap.hxx"
#include "jam/util/locale/Language.hxx"

namespace jam {
    namespace util {
        namespace locale {
            using namespace jam::lang;
            using namespace jam::util;
            
            class MessageResourceImpl;
            
            class MessageResource : public Object {
                public:
                    const static Class klass;
                    
                public:
                    MessageResource();
                    MessageResource(const Reference& ref);
                    MessageResource(Implementation* impl);
                    virtual ~MessageResource();
                    MessageResourceImpl& operator*();
                    MessageResourceImpl* operator->();
                    const MessageResource& operator=(const Reference& ref);
                    const MessageResource& operator=(Implementation* impl);
                    
                    static MessageResource newInstance(String domain, Language lang);
                    static void addMessageResource(MessageResource resource); 
                    static MessageResource getMessageResource(String domain, Language lang);
            };
            
            class MessageResourceImpl : public ObjectImpl {
                friend class MessageResource;
                
                private:
                    static HashMap  domainMap;
                    
                    HashMap         _messageMap;
                    String          _domain;
                    Language        _lang;
                    
                public:
                    MessageResourceImpl(String domain, Language lang);
                    virtual ~MessageResourceImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual String toString();
                    virtual Class getClass();
                    
                    virtual String getDomain();
                    virtual Language getLanguage();
                    virtual void addString(MessageResource resource);
                    virtual void addString(String key, String value);
                    virtual String getString(String key);
                    virtual String findKey(String value);
                    
                private:
                    MessageResourceImpl(const MessageResourceImpl& copy);
            };
        }
    }
}

#endif
