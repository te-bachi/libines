#include "jam/lang/Reference.hxx"
#include "jam/lang/Implementation.hxx"
#include "jam/lang/NullPointerException.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

#include <iostream>

using namespace jam::lang;

/**
 * Constructor
 */
Reference::Reference() {
    _impl = null;
    
    #ifdef __DEBUG__
    printf(" %#010x %#010x %02d       %s\n", (unsigned int) this, (unsigned int) _impl, 0, "(*)");
    #endif
}

/**
 * Copy-Constructor
 */
Reference::Reference(const Reference& ref) {
    _impl = ref._impl;
    
    if (_impl != null) {
        addReference();
        
        #ifdef __DEBUG__
        printf("%-8s %s\n", "<COPY>", _impl != null ? _impl->debugClassName() : "[null]");
        #endif
    }
}

Reference::Reference(Implementation* impl) {
    _impl = impl;
    if (_impl != null) {
        if (_impl->getRefCounter() == 0) {
            initReference();
        } else {
            addReference();
            #ifdef __DEBUG__
            printf("%-8s %s\n", "<REF>", _impl != null ? _impl->debugClassName() : "[null]");
            #endif
        }
    }
}

/**
 * Destructor
 */
Reference::~Reference() {
    checkReference();
}

Implementation& Reference::operator*() {
    if (_impl == null) {
        throw NullPointerException::newInstance(String::newInstance("jam.exception.reference.noimpl"));
    }
    
    return *_impl;
}

Implementation* Reference::operator->() {
    if (_impl == null) {
        throw NullPointerException::newInstance(String::newInstance("jam.exception.reference.noimpl"));
    }
    
    return _impl;
}

const Reference& Reference::operator=(const Reference& ref) {
    
    if (_impl != ref._impl) {
        checkReference();
        
        _impl = ref._impl;
        
        if (_impl != null) {
            addReference();
            
            #ifdef __DEBUG__
            printf("%-8s %s\n", "<REF>", _impl->debugClassName());
            #endif
        }
    }
    
    return *this;
}

const Reference& Reference::operator=(Implementation *impl) {
    
    if (_impl != impl) {
        checkReference();
        _impl = impl;
        if (_impl != null) {
            if (_impl->getRefCounter() == 0) {
                initReference();
            } else {
                addReference();
                #ifdef __DEBUG__
                printf("%-8s %s\n", "<REF>", _impl != null ? _impl->debugClassName() : "[null]");
                #endif
            }
        }
    }
    
    return *this;
}

boolean Reference::operator==(const Reference& ref) const {
    return _impl == ref._impl;
}

boolean Reference::operator==(Implementation* impl) const {
    return _impl == impl;
}

boolean Reference::operator!=(const Reference& ref) const {
    return _impl != ref._impl;
}

boolean Reference::operator!=(Implementation* impl) const {
    return _impl != impl;
}

boolean Reference::hasReferences() {
    if (_impl != null) {
        return _impl->checkRefCounter();
    }
    return false;
}

const Implementation* Reference::getImplementation() {
    return _impl;
}

void Reference::initReference() {
    #ifdef __DEBUG__
    printf(" %#010x %#010x %02d -> ", (unsigned int) this, (unsigned int) _impl,  _impl != null ? _impl->getRefCounter() : 0);
    #endif
    
    _impl->initRefCounter();
    
    #ifdef __DEBUG__
    printf("%02d %s %-8s %s\n", _impl != null ? _impl->getRefCounter() : 0, "(=)", "", _impl != null ? _impl->debugClassName() : "[null]");
    #endif
}

void Reference::addReference() {
    #ifdef __DEBUG__
    printf(" %#010x %#010x %02d -> ", (unsigned int) this, (unsigned int) _impl, _impl != null ? _impl->getRefCounter() : 0);
    #endif
    
    _impl->addRefCounter();
    
    #ifdef __DEBUG__
    printf("%02d %s ", _impl->getRefCounter(), "(+)");
    #endif
}

void Reference::releaseReference() {
    #ifdef __DEBUG__
    printf(" %#010x %#010x %02d -> ", (unsigned int) this, (unsigned int) _impl, _impl != null ? _impl->getRefCounter() : 0);
    #endif
    
    _impl->releaseRefCounter();
    
    #ifdef __DEBUG__
    printf("%02d %s ", _impl->getRefCounter(), "(-)");
    #endif
}

void Reference::checkReference() {
    if (_impl != null) {
        releaseReference();
        if (_impl->checkRefCounter() == false) {
            #ifdef __DEBUG__
            printf("%-8s %s\n", "<DELETE>", _impl != null ? _impl->debugClassName() : "[null]");
            #endif
            delete _impl;
        } else {
            #ifdef __DEBUG__
            printf("\n");
            #endif
        }
    }
}
