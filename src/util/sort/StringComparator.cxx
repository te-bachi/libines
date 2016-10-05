#include "jam/util/sort/StringComparator.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Character.hxx"

using namespace jam::util::sort;
using namespace jam::lang;

const Class StringComparator::klass = Class::newInstance("jam::util::sort::StringComparator");

/*** Reference ***/

StringComparator::StringComparator() : Comparator() {
    //
}

StringComparator::StringComparator(const Reference& ref) : Comparator(ref) {
    //
}

StringComparator::StringComparator(Implementation* impl) : Comparator(impl) {
    //
}

StringComparator::~StringComparator() {
    //
}

StringComparatorImpl& StringComparator::operator*() {
    return (StringComparatorImpl&) Comparator::operator*();
}

StringComparatorImpl* StringComparator::operator->() {
    return (StringComparatorImpl*) Comparator::operator->();
}

const StringComparator& StringComparator::operator=(const Reference& ref) {
    return (StringComparator&) Comparator::operator=(ref);
}

const StringComparator& StringComparator::operator=(Implementation* impl) {
    return (StringComparator&) Comparator::operator=(impl);
}

StringComparator StringComparator::newInstance() {
    return StringComparator(new StringComparatorImpl());
}

StringComparator StringComparator::newInstance(int options) {
    return StringComparator(new StringComparatorImpl(options));
}

/*** Implementation ***/

StringComparatorImpl::StringComparatorImpl() {
    init(StringComparator::SORT_ASCENDING | StringComparator::IGNORE_CASE);
}

StringComparatorImpl::StringComparatorImpl(int options) {
    init(options);
}

StringComparatorImpl::~StringComparatorImpl() {
    
}

StringComparatorImpl::StringComparatorImpl(const StringComparatorImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StringComparatorImpl::debugClassName() {
    return "jam::util::sort::StringComparator";
}
#endif

Class StringComparatorImpl::getClass() {
    return StringComparator::klass;
}

void StringComparatorImpl::init(int options) {
    if (options & StringComparator::SORT_DESCENDING) {
        _result = -1;
    } else {
        _result = 1;
    }
    
    if (options & StringComparator::CASE_SENSITIVE) {
        _caseSensitive = true;
    } else {
        _caseSensitive = false;
    }
}

int StringComparatorImpl::compare(Object first, Object second) {
    return compare(first->toString(), second->toString());
}

int StringComparatorImpl::compare(String first, String second) {
    int    length;
    int    result;
    int    i;
    
    // are these numbers/currencys?
    if (checkCurrency(first) && checkCurrency(second)) {
        if (first->length() < second->length()) {
            return _result;
        } else if (first->length() > second->length()) {
            return -(_result);
        }
    }
    
    if (first->length() < second->length()) {
        length = first->length();
    } else {
        length = second->length();
    }
    
    for (i = 0; i < length; i++) {
        if (_caseSensitive == false) {
            result = checkCharacter(Character::toLowerCase(first->charAt(i)),
                                    Character::toLowerCase(second->charAt(i)));
            
            // case sensitive sort if characters match
            if (result == 0) {
                result = checkLength(first, second);
                
                if (result == 0) {
                    result = checkCharacter(first->charAt(i), second->charAt(i));
                }
            }
        } else {
            result = checkCharacter(first->charAt(i), second->charAt(i));
        }
        
        if (result != 0) {
            return result;
        }
    }
    
    return checkLength(first, second);
}

int StringComparatorImpl::checkCharacter(char first, char second) {
    int firstCategory;
    int secondCategory;
    
    firstCategory  = Character::analyze(first);
    secondCategory = Character::analyze(second);
    
    if (firstCategory > secondCategory) {
        return _result;
    } else if (firstCategory < secondCategory) {
        return -(_result);
    } else if (first < second) {
        return _result;
    } else if (first > second) {
        return -(_result);
    }
    
    return 0;
}

int StringComparatorImpl::checkLength(String first, String second) {
    if (first->length() < second->length()) {
        return _result;
    } else if (first->length() > second->length()) {
        return -(_result);
    }
    
    return 0;
}

boolean StringComparatorImpl::checkCurrency(String str) {
    boolean isValid;
    int     i;
    char    chr;
    
    isValid = true;
    for (i = 0; i < str->length(); i++) {
        chr = str->charAt(i);
        if (chr != '.' && chr != '.' && chr != ',' && chr != '\'' && (chr < 48 || chr > 57)) {
            isValid = false;
            break;
        }
    }
    
    return isValid;
}
