#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class Class::klass = Class::newInstance("jam::lang::String");

/*** Reference ***/

Class::Class() : Object() {
    //
}

Class::Class(const Reference& ref) : Object(ref) {
    //
}

Class::Class(Implementation* impl) : Object(impl) {
    //
}

Class::~Class() {
    //
}

ClassImpl& Class::operator*() {
    return (ClassImpl&) Object::operator*();
}

ClassImpl* Class::operator->() {
    return (ClassImpl*) Object::operator->();
}

const Class& Class::operator=(const Reference& ref) {
    return (Class&) Object::operator=(ref);
}

const Class& Class::operator=(Implementation* impl) {
    return (Class&) Object::operator=(impl);
}

Class Class::newInstance(const char* name) {
    return Class(new ClassImpl(name));
}

/*** Implementation ***/

ClassImpl::ClassImpl(const char* name) {
    _name = name;
}

ClassImpl::~ClassImpl() {
    //
}

ClassImpl::ClassImpl(const ClassImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ClassImpl::debugClassName() {
    return "jam::lang::Class";
}
#endif

String ClassImpl::getName() {
    return _name;
}

boolean ClassImpl::equals(Object obj) {
    if (obj->instanceOf(Class::klass)) {
        return ClassImpl::equals((Class) obj);
    }
    
    return ObjectImpl::equals(obj);
}

boolean ClassImpl::equals(Class klass) {
    if (this == klass.getImplementation()) {
        return true;
    } else if (this->getName()->equals(klass->getName())) {
        return true;
    }
    return false;
}
