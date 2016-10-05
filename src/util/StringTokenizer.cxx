#include "jam/util/StringTokenizer.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::lang;
using namespace jam::util;

const Class StringTokenizer::klass = Class::newInstance("jam::util::StringTokenizer");

/*** Reference ***/

StringTokenizer::StringTokenizer() : Object() {
    //
}

StringTokenizer::StringTokenizer(const Reference& ref) : Object(ref) {
    //
}

StringTokenizer::StringTokenizer(Implementation* impl) : Object(impl) {
    //
}

StringTokenizer::~StringTokenizer() {
    //
}

StringTokenizerImpl& StringTokenizer::operator*() {
    return (StringTokenizerImpl&) Object::operator*();
}

StringTokenizerImpl* StringTokenizer::operator->() {
    return (StringTokenizerImpl*) Object::operator->();
}

const StringTokenizer& StringTokenizer::operator=(const Reference& ref) {
    return (StringTokenizer&) Object::operator=(ref);
}

const StringTokenizer& StringTokenizer::operator=(Implementation* impl) {
    return (StringTokenizer&) Object::operator=(impl);
}

StringTokenizer StringTokenizer::newInstance(String str) {
    return StringTokenizer(new StringTokenizerImpl(str));
}

StringTokenizer StringTokenizer::newInstance(String str, String delimiter) {
    return StringTokenizer(new StringTokenizerImpl(str, delimiter));
}

/*** Implementation ***/

StringTokenizerImpl::StringTokenizerImpl(String str) {
    init(str, "\n");
}

StringTokenizerImpl::StringTokenizerImpl(String str, String delimiter) {
    init(str, delimiter);
}

StringTokenizerImpl::~StringTokenizerImpl() {
    
}

StringTokenizerImpl::StringTokenizerImpl(const StringTokenizerImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StringTokenizerImpl::debugClassName() {
    return "jam::lang::StringTokenizer";
}
#endif

// TODO
Object StringTokenizerImpl::clone() {
    return null;
}

// TODO
String StringTokenizerImpl::toString() {
    return null;
}

Class StringTokenizerImpl::getClass() {
    return StringTokenizer::klass;
}

boolean StringTokenizerImpl::hasMoreTokens() {
    _newPosition = skipDelimiters();
    return (_newPosition < _strLength);
}

String StringTokenizerImpl::nextToken() {
    int start;
    
    _currentPosition = _newPosition >= 0 ? _newPosition : skipDelimiters();
    _newPosition     = -1;
    start            = _currentPosition;
    _currentPosition = scanToken();
    return _str->substring(start, _currentPosition);
}

void StringTokenizerImpl::init(String str, String delimiter) {
    _str             = str;
    _strLength       = str->length();
    _delimiter       = delimiter;
    _delimiterLength = delimiter->length();
    _currentPosition = 0;
    _newPosition     = 0;
    
    if (str->endsWith(delimiter)) {
        _strLength -= _delimiterLength;
    }
}

int StringTokenizerImpl::skipDelimiters() {
    int startPosition;
    int endPosition;
    
    startPosition = _currentPosition;
    endPosition   = _currentPosition + _delimiterLength;
    
    if (endPosition <= _strLength) {
        if (_delimiter->equals(_str->substring(startPosition, endPosition))) {
            return endPosition;
        }
    }
    return startPosition;
}

int StringTokenizerImpl::scanToken() {
    int endPosition;
    
    endPosition = _str->indexOf(_delimiter, _currentPosition);
    
    return endPosition == -1 ? _strLength : endPosition;
}
