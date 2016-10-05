#ifndef __REFERENCE_HXX__
#define __REFERENCE_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Implementation.hxx"

namespace jam {
    namespace lang {
        
        class Reference {
            private:
                Implementation* _impl;
                
            public:
                Reference();
                Reference(const Reference& ref);
                Reference(Implementation* impl);
                virtual ~Reference();
                Implementation& operator*();
                Implementation* operator->();
                const Reference& operator=(const Reference& ref);
                const Reference& operator=(Implementation* impl);
                boolean operator==(const Reference& ref) const;
                boolean operator==(Implementation* impl) const;
                boolean operator!=(const Reference& ref) const;
                boolean operator!=(Implementation* impl) const;
                
                virtual boolean hasReferences();
                virtual const Implementation* getImplementation();
                
            private:
                void addReference();
                void releaseReference();
                void initReference();
                void checkReference();
        };
    }
}

#endif
