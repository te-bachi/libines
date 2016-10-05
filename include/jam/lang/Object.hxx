#ifndef __OBJECT_HXX__
#define __OBJECT_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Reference.hxx"

#include <pthread.h>

namespace jam {
    namespace lang {
        
        class Class;
        class String;
        class ObjectImpl;
        
        class Object : public Reference {
            public:
                const static Class klass;
            
            public:
                Object();
                Object(const Reference& ref);
                Object(Implementation* impl);
                virtual ~Object();
                ObjectImpl& operator*();
                ObjectImpl* operator->();
                const Object& operator=(const Reference& ref);
                const Object& operator=(Implementation* impl);
        };
        
        class ObjectImpl : public Implementation {
            public:
            
            private:
                boolean         _isInitialized;
                pthread_mutex_t _mutex;
                pthread_cond_t  _condition;
                
            public:
                ObjectImpl();
                virtual ~ObjectImpl();
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual boolean instanceOf(Class klass);
                virtual boolean equals(Object obj);
                virtual int hashCode();
                
                virtual void lock();
                virtual void unlock();
                virtual void wait(); 
                virtual void wait(long milisec);
                virtual void notify();
                virtual void notifyAll();
                
            private:
                ObjectImpl(const ObjectImpl& copy);
                void initMutex();
        };
    }
}

#endif
