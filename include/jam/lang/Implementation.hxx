#ifndef __IMPLEMENTATION_HXX__
#define __IMPLEMENTATION_HXX__

#include "jam/Global.hxx"

namespace jam {
    namespace lang {
            
        class Class;
        class Reference;
        
        class Implementation {
            private:
                int* _refCounter;
                
            public:
                Implementation();
                virtual ~Implementation();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName() = 0;
                #endif
                
                virtual void initRefCounter();
                virtual boolean checkRefCounter();
                virtual void addRefCounter();
                virtual void releaseRefCounter();
                virtual int getRefCounter();
                
            private:
                Implementation(const Implementation& copy);
        };
    }
}

#endif
