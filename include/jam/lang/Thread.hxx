#ifndef __THREAD_HXX__
#define __THREAD_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"
#include "jam/util/HashMap.hxx"
#include "jam/lang/String.hxx"

namespace jam {
    namespace lang {
        using namespace jam::util;
        
        class ThreadImpl;
        
        class Thread : public Object {
            public:
                const static Class klass;
                
                typedef enum {
                    POLICY_FIFO = 0,
                    POLICY_RR,
                    POLICY_OTHER,
                    POLICY_MAX
                } Policy;
                
                typedef enum {
                    PRIORITY_REALTIME = 0,
                    PRIORITY_HIGH,
                    PRIORITY_NORMAL,
                    PRIORITY_LOW
                } Priority;
                
            public:
                Thread();
                Thread(const Reference& ref);
                Thread(Implementation* impl);
                virtual ~Thread();
                ThreadImpl& operator*();
                ThreadImpl* operator->();
                const Thread& operator=(const Reference& ref);
                const Thread& operator=(Implementation* impl);
                
                static Thread newInstance();
                static Thread newInstance(Policy policy);
                static Thread newInstance(Priority priority);
                static Thread newInstance(Policy policy, Priority priority);
                static Thread newInstance(String name);
                static Thread newInstance(String name, Policy policy);
                static Thread newInstance(String name, Priority priority);
                static Thread newInstance(String name, Policy policy, Priority priority);
                static Thread self();
        };
        
        class ThreadImpl : public ObjectImpl {
            
            friend class Thread;
                
            private:
                static HashMap   threadMap;
                static boolean   isInitialized;
                
                static int       counter;
                
                static int       realtimePriority[];
                static int       highPriority[];
                static int       normalPriority[];
                static int       lowPriority[];
                
                String           _name;
                pthread_t        _thread;
                pthread_attr_t   _attribute;
                boolean          _isAlive;
                Thread::Policy   _policy;
                Thread::Priority _priority;
                
            public:
                ThreadImpl();
                ThreadImpl(Thread::Policy policy);
                ThreadImpl(Thread::Priority priority);
                ThreadImpl(Thread::Policy policy, Thread::Priority priority);
                ThreadImpl(String name);
                ThreadImpl(String name, Thread::Policy policy);
                ThreadImpl(String name, Thread::Priority priority);
                ThreadImpl(String name, Thread::Policy policy, Thread::Priority priority);
                virtual ~ThreadImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual String toString();
                virtual Class getClass();
                
                virtual void start();
                virtual void run();
                virtual void join();
                virtual void yield();
                virtual void setName(String name);
                virtual String getName();
                virtual void setPolicy(Thread::Policy policy);
                virtual Thread::Policy getPolicy();
                virtual void setPriority(Thread::Priority priority);
                virtual Thread::Priority getPriority();
                virtual boolean isAlive();
                virtual void sleep(short milisecond);
                virtual void sleep(short second, short milisecond);
                
            private:
                ThreadImpl(const ThreadImpl& copy);
                void init(String name, Thread::Policy policy, Thread::Priority priority);
                static String calculateName();
                static void calculatePriority();
                static void* create(void* thr);
        };
    }
}

#endif

