#include "jam/lang/Pointer.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;

const Class Pointer::klass = Class::newInstance("jam::lang::Pointer");

/*** Reference ***/

Pointer::Pointer() : Object() {
    //
}

Pointer::Pointer(const Reference& ref) : Object(ref) {
    //
}

Pointer::Pointer(Implementation* impl) : Object(impl) {
    //
}

Pointer::~Pointer() {
    //
}

PointerImpl& Pointer::operator*() {
    return (PointerImpl&) Object::operator*();
}

PointerImpl* Pointer::operator->() {
    return (PointerImpl*) Object::operator->();
}

const Pointer& Pointer::operator=(const Reference& ref) {
    return (Pointer&) Object::operator=(ref);
}

const Pointer& Pointer::operator=(Implementation* impl) {
    return (Pointer&) Object::operator=(impl);
}

Pointer Pointer::newInstance(void* pointer) {
    return Pointer(new PointerImpl(pointer));
}

/*** Implementation ***/

PointerImpl::PointerImpl(void* pointer) {
    _pointer = pointer;
}

PointerImpl::~PointerImpl() {
    //
}

PointerImpl::PointerImpl(const PointerImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* PointerImpl::debugClassName() {
    return "jam::lang::Pointer";
}
#endif

Class PointerImpl::getClass() {
    return Pointer::klass;
}

int PointerImpl::hashCode() {
    return (int) _pointer;
}

boolean PointerImpl::equals(Object obj) {
    if (obj->instanceOf(Pointer::klass)) {
        return PointerImpl::equals((Pointer) obj);
    }
    
    return ObjectImpl::equals(obj);
}

boolean PointerImpl::equals(Pointer pointer) {
    return (_pointer == pointer->_pointer);
}

void* PointerImpl::getPointer() {
    return _pointer;
}
