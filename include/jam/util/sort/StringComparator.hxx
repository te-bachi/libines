#ifndef __STRING_COMPARATOR_HXX__
#define __STRING_COMPARATOR_HXX__

#include "jam/Global.hxx"
#include "jam/util/sort/Comparator.hxx"

namespace jam {
    namespace util {
        namespace sort {
            class StringComparatorImpl;
            
            class StringComparator : public Comparator {
                public:
                    const static Class klass;
                    
                    enum {
                        SORT_ASCENDING  = 1,
                        SORT_DESCENDING = 2,
                        IGNORE_CASE     = 4,
                        CASE_SENSITIVE  = 8
                    };
                    
                public:
                    StringComparator();
                    StringComparator(const Reference& ref);
                    StringComparator(Implementation* impl);
                    virtual ~StringComparator();
                    StringComparatorImpl& operator*();
                    StringComparatorImpl* operator->();
                    const StringComparator& operator=(const Reference& ref);
                    const StringComparator& operator=(Implementation* impl);
                    
                    static StringComparator newInstance();
                    static StringComparator newInstance(int options);
            };
            
            class StringComparatorImpl : public ComparatorImpl {
                private:
                    int     _result;
                    boolean _caseSensitive;
                    
                public:
                    StringComparatorImpl();
                    StringComparatorImpl(int options);
                    virtual ~StringComparatorImpl();
                    
                    #ifdef __DEBUG__
                    virtual const char* debugClassName();
                    #endif
                    
                    virtual Class getClass();
                    virtual int compare(Object first, Object second);
                    virtual int compare(String first, String second);
                    
                private:
                    StringComparatorImpl(const StringComparatorImpl& copy);
                    void init(int options);
                    int checkCharacter(char first, char second);
                    int checkLength(String first, String second);
                    boolean checkCurrency(String str);
            };
        }
    }
}

#endif
