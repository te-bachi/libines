#include "jam/util/StringPadding.hxx"
#include "jam/lang/Character.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::util;

const Class StringPadding::klass = Class::newInstance("jam::util::StringPadding");

/*** Reference ***/

StringPadding::StringPadding() : Object() {
    //
}

StringPadding::StringPadding(const Reference& ref) : Object(ref) {
    //
}

StringPadding::StringPadding(Implementation* impl) : Object(impl) {
    //
}

StringPadding::~StringPadding() {
    //
}

StringPaddingImpl& StringPadding::operator*() {
    return (StringPaddingImpl&) Object::operator*();
}

StringPaddingImpl* StringPadding::operator->() {
    return (StringPaddingImpl*) Object::operator->();
}

const StringPadding& StringPadding::operator=(const Reference& ref) {
    return (StringPadding&) Object::operator=(ref);
}

const StringPadding& StringPadding::operator=(Implementation* impl) {
    return (StringPadding&) Object::operator=(impl);
}

StringPadding StringPadding::newInstance(int length) {
    return StringPadding(new StringPaddingImpl(length));
}

StringPadding StringPadding::newInstance(int length, boolean reverse) {
    return StringPadding(new StringPaddingImpl(length, reverse));
}

StringPadding StringPadding::newInstance(int length, char padding) {
    return StringPadding(new StringPaddingImpl(length, padding));
}

StringPadding StringPadding::newInstance(int length, char padding, boolean reverse) {
    return StringPadding(new StringPaddingImpl(length, padding, reverse));
}

/*** Implementation ***/

StringPaddingImpl::StringPaddingImpl(int length) {
    init(length, ' ', false);
}

StringPaddingImpl::StringPaddingImpl(int length, boolean reverse) {
    init(length, ' ', reverse);
}


StringPaddingImpl::StringPaddingImpl(int length, char padding) {
    init(length, padding, false);
}


StringPaddingImpl::StringPaddingImpl(int length, char padding, boolean reverse) {
    init(length, padding, reverse);
}

StringPaddingImpl::~StringPaddingImpl() {
    
}

StringPaddingImpl::StringPaddingImpl(const StringPaddingImpl& copy) {
    //
}

void StringPaddingImpl::init(int length, char padding, boolean reverse) {
    _length     = length;
    _padding    = padding;
    _reverse    = reverse;
}

#ifdef __DEBUG__
const char* StringPaddingImpl::debugClassName() {
    return "jam::lang::StringPadding";
}
#endif

// TODO
Object StringPaddingImpl::clone() {
    return null;
}

// TODO
String StringPaddingImpl::toString() {
    return null;
}

Class StringPaddingImpl::getClass() {
    return StringPadding::klass;
}

String StringPaddingImpl::doPadding(String input) {
    char* output;
    int   i;
    int   k;
    
    output = Character::initialize(_padding, _length);
    
    if (_reverse == true) {
        for (i = (_length - input->length()), k = 0; k < input->length() && i < _length; i++, k++) {
           output[i] = input->charAt(k);
        }
    } else {
        for (i = 0; i < input->length() && i < _length; i++) {
           output[i] = input->charAt(i);
        }
    }
    
    return String::newInstance(output, false);
}
