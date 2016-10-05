#ifndef __CLONE_NOT_SUPPORTED_EXCEPTION_HXX__
#define __CLONE_NOT_SUPPORTED_EXCEPTION_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Exception.hxx"

namespace jam {
    namespace lang {
        
        class CloneNotSupportedExceptionImpl;
        
        class CloneNotSupportedException : public Exception {
            public:
                const static Class klass;
                
            public:
                CloneNotSupportedException();
                CloneNotSupportedException(const Reference& ref);
                CloneNotSupportedException(Implementation* impl);
                virtual ~CloneNotSupportedException();
                CloneNotSupportedExceptionImpl& operator*();
                CloneNotSupportedExceptionImpl* operator->();
                const CloneNotSupportedException& operator=(const Reference& ref);
                const CloneNotSupportedException& operator=(Implementation* impl);
        };
    }
}

#endif
