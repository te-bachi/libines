#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"

#include <time.h>
#include <iostream>

using namespace jam::lang;

const Class Object::klass = Class::newInstance("jam::lang::Object");

/*** Reference ***/

Object::Object() : Reference() {
    //
}

Object::Object(const Reference& ref) : Reference(ref) {
    //
}

Object::Object(Implementation* impl) : Reference(impl) {
    //
}

Object::~Object() {
    //
}

ObjectImpl& Object::operator*() {
    return (ObjectImpl&) Reference::operator*();
}

ObjectImpl* Object::operator->() {
    return (ObjectImpl*) Reference::operator->();
}

const Object& Object::operator=(const Reference& ref) {
    return (Object&) Reference::operator=(ref);
}

const Object& Object::operator=(Implementation* impl) {
    return (Object&) Reference::operator=(impl);
}

/*** Implementation ***/


ObjectImpl::ObjectImpl() {
    _isInitialized = false;
}

ObjectImpl::ObjectImpl(const ObjectImpl& objImpl) {
    //
}

ObjectImpl::~ObjectImpl() {
    if (_isInitialized == true) {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_condition);
    }
}

// TODO
Object ObjectImpl::clone() {
    //throw CloneNotSupportedException();
    return null;
}

String ObjectImpl::toString() {
    return String::valueOf((int) this, Number::HEXADECIMAL, true);
}

Class ObjectImpl::getClass() {
    return Object::klass;
}

boolean ObjectImpl::instanceOf(Class other) {
    return this->getClass()->equals(other);
}

boolean ObjectImpl::equals(Object obj) {
    return (this == obj.getImplementation());
}

int ObjectImpl::hashCode() {
    return (int) this;
}

void ObjectImpl::lock() {
    initMutex();
    pthread_mutex_lock(&_mutex);
}

void ObjectImpl::unlock() {
    pthread_mutex_unlock(&_mutex);
}

void ObjectImpl::wait() {
    initMutex();
    pthread_cond_wait(&_condition, &_mutex);
}

void ObjectImpl::wait(long milisec) {
    struct timespec timeout;
    
    initMutex();
    clock_gettime(CLOCK_REALTIME, &timeout);
    timeout.tv_nsec += (milisec * 1000000);
    pthread_cond_timedwait(&_condition, &_mutex, &timeout);
}

void ObjectImpl::notify() {
    pthread_cond_signal(&_condition);
}

void ObjectImpl::notifyAll() {
    pthread_cond_broadcast(&_condition);
}

void ObjectImpl::initMutex() {
    if (_isInitialized == false) {
        _isInitialized = true;
        pthread_mutex_init(&_mutex, NULL);
        pthread_cond_init(&_condition, NULL);
    }
}

