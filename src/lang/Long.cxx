#include "jam/lang/Long.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::lang;
using namespace jam::lang;

const Class Long::klass = new ClassImpl("jam::lang::Long");

const long Long::MIN_VALUE = -2147483648;
const long Long::MAX_VALUE = 2147483647;
const unsigned long Long::MAX_UNSIGNED = 4294967295;

/*** Reference ***/

Long::Long() : Number() {
    //
}

Long::Long(const Reference& ref) : Number(ref) {
    //
}

Long::Long(Implementation* impl) : Number(impl) {
    //
}

Long::~Long() {
    //
}

LongImpl& Long::operator*() {
    return (LongImpl&) Number::operator*();
}

LongImpl* Long::operator->() {
    return (LongImpl*) Number::operator->();
}

const Long& Long::operator=(const Reference& ref) {
    return (Long&) Number::operator=(ref);
}

const Long& Long::operator=(Implementation* impl) {
    return (Long&) Number::operator=(impl);
}

Long Long::newInstance(long value) {
    return Long(new LongImpl(value));
}

long Long::parseLong(String str) {
    return Long::parseLong(str, Number::DECIMAL);
}

long Long::parseLong(String str, Number::Format format) {
    long    result;
    char    chr;
    int     length;
    int     i;
    int     negative;
    
    result   = 0;
    i        = 0;
    negative = 1;
    str      = str->trim();
    length   = str->length();
    
    if (length > 0) {
        if (length > 2 && str->charAt(0) == '0' &&
           (str->charAt(1) == 'x' || str->charAt(1) == 'X')) {
            i += 2;
        } else if (str->charAt(0) == '-') {
            negative = -1;
            i += 1;
        } else if (str->charAt(0) == '+') {
            i += 1;
        }
        
        for (; i < length; i++) {
            chr = str->charAt(i);
            
            if (chr >= '0' && chr <= '9') {
                chr -= '0';
            } else if (chr >= 'A' && chr <= 'Z') {
                chr -= 'A' - 10;
            } else if (chr >= 'a' && chr <= 'z') {
                chr -= 'a' - 10;
            } else {
                break;
            }
            
            result *= format;
            result += chr;
        }
    }
    
    return (negative * result);
}

/*** Implementation ***/

LongImpl::LongImpl(long value) {
    _value = value;
}

LongImpl::~LongImpl() {
    
}

LongImpl::LongImpl(const LongImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LongImpl::debugClassName() {
    return "jam::lang::Long";
}
#endif

Class LongImpl::getClass() {
    return Long::klass;
}

String LongImpl::toString() {
    return String::valueOf(_value);
}

int LongImpl::hashCode() {
    return (int) _value;
}

boolean LongImpl::equals(Object obj) {
    if (obj->instanceOf(Long::klass)) {
        return LongImpl::equals((Long) obj);
    }
    
    return ObjectImpl::equals(obj);
}

boolean LongImpl::equals(Long value) {
    if (_value == value->longValue()) {
        return true;
    }
    
    return false;
}

byte LongImpl::byteValue() {
    return (byte) _value;
}

double LongImpl::doubleValue() {
    return (double) _value;
}

float LongImpl::floatValue() {
    return (float) _value;
}

int LongImpl::intValue() {
    return (int) _value;
}

long LongImpl::longValue() {
    return (long) _value;
}

short LongImpl::shortValue() {
    return (short) _value;
}
