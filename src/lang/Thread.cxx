#include "jam/lang/Thread.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Integer.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Integer.hxx"
#include "jam/lang/NotImplementedException.hxx"

#include <pthread.h>
#include <sched.h>
#include <iostream>
#include <errno.h>

using namespace jam::lang;

const Class Thread::klass = Class::newInstance("jam::lang::Thread");

HashMap ThreadImpl::threadMap           = HashMap::newInstance();
boolean ThreadImpl::isInitialized       = false;
int     ThreadImpl::counter             = 1;
int     ThreadImpl::realtimePriority[3] = { 0, 0, 0 };
int     ThreadImpl::highPriority[3]     = { 0, 0, 0 };
int     ThreadImpl::normalPriority[3]   = { 0, 0, 0 };
int     ThreadImpl::lowPriority[3]      = { 0, 0, 0 };

/*** Reference ***/

Thread::Thread() : Object() {
    //
}

Thread::Thread(const Reference& ref) : Object(ref) {
    //
}

Thread::Thread(Implementation* impl) : Object(impl) {
    //
}

Thread::~Thread() {
    //
}

ThreadImpl& Thread::operator*() {
    return (ThreadImpl&) Object::operator*();
}

ThreadImpl* Thread::operator->() {
    return (ThreadImpl*) Object::operator->();
}

const Thread& Thread::operator=(const Reference& ref) {
    return (Thread&) Object::operator=(ref);
}

const Thread& Thread::operator=(Implementation* impl) {
    return (Thread&) Object::operator=(impl);
}

Thread Thread::newInstance() {
    return Thread(new ThreadImpl());
}

Thread Thread::newInstance(Policy policy) {
    return Thread(new ThreadImpl(policy));
}

Thread Thread::newInstance(Priority priority) {
    return Thread(new ThreadImpl(priority));
}

Thread Thread::newInstance(Policy policy, Priority priority) {
    return Thread(new ThreadImpl(policy, priority));
}

Thread Thread::newInstance(String name) {
    return Thread(new ThreadImpl(name));
}

Thread Thread::newInstance(String name, Policy policy) {
    return Thread(new ThreadImpl(name, policy));
}

Thread Thread::newInstance(String name, Priority priority) {
    return Thread(new ThreadImpl(name, priority));
}

Thread Thread::newInstance(String name, Policy policy, Priority priority) {
    return Thread(new ThreadImpl(name, policy, priority));
}

Thread Thread::self() {
    Integer key;
    Thread  self;
    
    key  = Integer(new IntegerImpl((int) pthread_self()));
    self = ThreadImpl::threadMap->get(key);
    
    return self;
}

/*** Implementation ***/

ThreadImpl::ThreadImpl() {
    init(calculateName(), Thread::POLICY_RR, Thread::PRIORITY_NORMAL);
}

ThreadImpl::ThreadImpl(Thread::Policy policy) {
    init(calculateName(), policy, Thread::PRIORITY_NORMAL);
}

ThreadImpl::ThreadImpl(Thread::Priority priority) {
    init(calculateName(), Thread::POLICY_RR, priority);
}

ThreadImpl::ThreadImpl(Thread::Policy policy, Thread::Priority priority) {
    init(calculateName(), policy, priority);
}

ThreadImpl::ThreadImpl(String name) {
    init(name, Thread::POLICY_RR, Thread::PRIORITY_NORMAL);
}

ThreadImpl::ThreadImpl(String name, Thread::Policy policy) {
    init(name, policy, Thread::PRIORITY_NORMAL);
}

ThreadImpl::ThreadImpl(String name, Thread::Priority priority) {
    init(name, Thread::POLICY_RR, priority);
}

ThreadImpl::ThreadImpl(String name, Thread::Policy policy, Thread::Priority priority) {
    init(name, policy, priority);
}

ThreadImpl::~ThreadImpl() {
    pthread_attr_destroy(&_attribute);
}

ThreadImpl::ThreadImpl(const ThreadImpl& copy) {
    
}

void ThreadImpl::init(String name, Thread::Policy policy, Thread::Priority priority) {
    if (isInitialized == false) {
        isInitialized = true;
        ThreadImpl::calculatePriority();
    }
    
    _name = name;
    
    pthread_attr_init(&_attribute);
    
    setPolicy(policy);
    setPriority(priority);
}

String ThreadImpl::calculateName() {
    String name;
    String number;
    
    name   = "Thread ";
    number = String::valueOf(counter++);
    
    return name->concat(number);
}

void ThreadImpl::calculatePriority() {
    int     i;
    int     min_priority;
    int     max_priority;
    double  difference;
    
    for (i = 0; i < Thread::POLICY_MAX; i++) {
        min_priority        = sched_get_priority_min(i + 1);
        max_priority        = sched_get_priority_max(i + 1);
        difference          = max_priority - min_priority;
        
        realtimePriority[i] = min_priority + (int) (difference / 100.0 * 100.0);
        highPriority[i]     = min_priority + (int) (difference / 100.0 * 66.0);
        normalPriority[i]   = min_priority + (int) (difference / 100.0 * 33.0);
        lowPriority[i]      = min_priority + (int) (difference / 100.0 * 0.0);
    }
}

#ifdef __DEBUG__
const char* ThreadImpl::debugClassName() {
    return "jam::lang::Thread";
}
#endif

String ThreadImpl::toString() {
    return _name;
}

Class ThreadImpl::getClass() {
    return Thread::klass;
}

void ThreadImpl::start() {
    pthread_create(&_thread, &_attribute, ThreadImpl::create, this);
}

void* ThreadImpl::create(void* thr) {
    Integer key;
    Thread  thread;
    
    thread = Thread((ThreadImpl*) thr);
    key    = Integer(new IntegerImpl((int) thread->_thread));
    
    threadMap->put(key, thread);
    thread->_isAlive = true;
    
    thread->run();
    
    thread->_isAlive = false;
    threadMap->remove(key);
    
    return null;
}

void ThreadImpl::run() {
    Thread t1;
    Thread t2;
    
    t1 = Thread(this);
    t2 = Thread::self();
    
    if (t1->equals(t2)) {
        printf("YES!\n");
    } else {
        printf("NO!\n");
    }
}

void ThreadImpl::join() {
    pthread_join(_thread, NULL);
}

void ThreadImpl::yield() {
    sched_yield();
}

void ThreadImpl::setName(String name) {
    
}

// TODO
String ThreadImpl::getName() {
    return null;
}

void ThreadImpl::setPolicy(Thread::Policy policy) {
    int realPolicy;
    
    _policy = policy;
    
    switch (policy) {
        case Thread::POLICY_FIFO:   realPolicy = SCHED_FIFO;    break;
        case Thread::POLICY_RR:     realPolicy = SCHED_RR;      break;
        case Thread::POLICY_OTHER:  realPolicy = SCHED_OTHER;   break;
        default:                                                break;
    }
    
    pthread_attr_setschedpolicy(&_attribute, realPolicy);
}

Thread::Policy ThreadImpl::getPolicy() {
    throw NotImplementedException();
}

void ThreadImpl::setPriority(Thread::Priority priority) {
    struct sched_param param;
    
    _priority = priority;
    
    switch (priority) {
        case Thread::PRIORITY_REALTIME: param.sched_priority = realtimePriority[_policy];    break;
        case Thread::PRIORITY_HIGH:     param.sched_priority = highPriority[_policy];        break;
        case Thread::PRIORITY_NORMAL:   param.sched_priority = normalPriority[_policy];      break;
        case Thread::PRIORITY_LOW:      param.sched_priority = lowPriority[_policy];         break;
        default:                                                                             break;
    }
    
    pthread_attr_setschedparam(&_attribute, &param);
}

Thread::Priority ThreadImpl::getPriority() {
    throw NotImplementedException();
}

boolean ThreadImpl::isAlive() {
    return null;
}

void ThreadImpl::sleep(short milisecond) {
    short secs;
    short milis;
    
    secs  = milisecond / 1000;
    milis = milisecond % 1000;
    
    sleep(secs, milis);
}

void ThreadImpl::sleep(short second, short milisecond) {
    timespec rqts = { second, (long) milisecond * 1000000 };
    
    timespec remain;
    while (nanosleep(&rqts, &remain)) {
        if (errno == EINTR) {
            rqts.tv_sec  = remain.tv_sec;
            rqts.tv_nsec = remain.tv_nsec;
            continue;
        }
    }
}
