#include "jam/lang/String.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Character.hxx"
#include "jam/lang/IndexOutOfBoundsException.hxx"
#include "jam/util/StringBuffer.hxx"

#include <iostream>

using namespace jam::lang;
using namespace jam::util;

const Class String::klass = Class::newInstance("jam::lang::String");

/*** Reference ***/

String::String() : Object() {
    //
}

String::String(const Reference& ref) : Object(ref) {
    //
}

String::String(Implementation* impl) : Object(impl) {
    //
}

String::String(const char* chr) : Object(String::newInstance(chr)) {
    //
}

String::~String() {
    //
}

StringImpl& String::operator*() {
    return (StringImpl&) Object::operator*();
}

StringImpl* String::operator->() {
    return (StringImpl*) Object::operator->();
}

const String& String::operator=(const Reference& ref) {
    return (String&) Object::operator=(ref);
}

const String& String::operator=(Implementation* impl) {
    return (String&) Object::operator=(impl);
}

const String& String::operator=(const char* chr) {
    return (String&) Object::operator=(String::newInstance(chr));
}

String String::operator+(const String& ref) {
    return operator->()->concat(ref);
}

String String::operator+(const char* chr) {
    return operator->()->concat(String::newInstance(chr));
}

String String::newInstance() {
    return String(new StringImpl());
}

String String::newInstance(const char* chr) {
    return String(new StringImpl(chr));
}

String String::newInstance(char* chr, boolean copy) {
    return String(new StringImpl(chr, copy));
}

String String::newInstance(const char* chr, int length) {
    return String(new StringImpl(chr, length));
}

String String::newInstance(char* chr, int length, boolean copy) {
    return String(new StringImpl(chr, length, copy));
}

String String::valueOf(int number) {
    return String::valueOf((long) number, Number::DECIMAL, true);
}

String String::valueOf(int number, boolean padding) {
    return String::valueOf((long) number, Number::DECIMAL, padding);
}

String String::valueOf(int number, Number::Format format) {
    return String::valueOf((long) number, format, true);
}

String String::valueOf(int number, Number::Format format, boolean padding) {
    return String::valueOf((long) number, format, padding);
}

String String::valueOf(long number) {
    return String::valueOf(number, Number::DECIMAL, true);
}

String String::valueOf(long number, boolean padding) {
    return String::valueOf(number, Number::DECIMAL, padding);
}

String String::valueOf(long number, Number::Format format) {
    return String::valueOf(number, format, true);
}

String String::valueOf(long number, Number::Format format, boolean padding) {
    String  str;
    char*   chr;
    int     length;
    char*   reverse;
    int     i;
    long    tmpNumber;
    boolean isNegative;
    
    chr = 0;
    
    if (number < 0) {
        tmpNumber  = -number;
        isNegative = true;
    } else {
        tmpNumber  = number;
        isNegative = false;
    }
    
    switch (format) {
            
        case Number::BINARY:
            length = 32;
            chr    = Character::initialize(' ', length);
            i      = 0;
            reverse    = &(chr[length]);
            do {
                *--reverse = (tmpNumber & 1) + '0';
                tmpNumber >>= 1;
                i++;
            } while (tmpNumber);
            
            if (padding == true) {
                for (;i < length; i++) {
                    *--reverse = '0';
                }
            }
            break;
            
        case Number::DECIMAL:
            length = 11;
            chr    = Character::initialize(' ', length);
            i      = 0;
            reverse    = &(chr[length]);
            do {
                *--reverse = (tmpNumber % 10) + '0';
                tmpNumber /= 10;
            } while (tmpNumber != 0);
            
            if (isNegative == true) {
                *--reverse = '-';
            }
            
            break;
            
        case Number::HEXADECIMAL:
            length = 10;
            chr    = Character::initialize(' ', length);
            i      = 0;
            reverse    = &(chr[length]);
            do {
                *--reverse = Character::HEXADECIMAL_LOWER[tmpNumber & 15];
                tmpNumber >>= 4;
                i++;
            } while (tmpNumber);
            
            if (padding == true) {
                for (;i < length - 2; i++) {
                    *--reverse = '0';
                }
            }
            
            *--reverse = 'x';
            *--reverse = '0';
            
            break;
    }
    
    str = String::newInstance(chr, false);
    
    return str->trim();
}

/**
 * Q U I R K
 *
 * Should be replaced with own implementation
 * without ndigit
 */
String String::valueOf(double number, int ndigit) {
    StringBuffer format;
    char         chr[128];
    int          i;
    
    format = StringBuffer::newInstance();
    format->append("%.");
    format->append(ndigit);
    format->append("lf");
    
    sprintf(chr, format->toString()->toChar(), number);
    
    for (i = 0; i < sizeof(chr); i++) {
        if (chr[i] == '\0') {
            break;
        }
    }
    
    i--;
    while (true) {
        if (chr[i] == '0' && i > 0) {
            chr[i] = '\0';
            i--;
            continue;
        }
        break;
    }
    
    if (chr[i] == '.') {
        chr[i] = '\0';
    }
    
    return String::newInstance(chr, true)->trim();
}

/*** Implementation ***/

StringImpl::StringImpl() {
    _data = NULL;
}

StringImpl::StringImpl(const char *chr) {
    copyCharacters(chr, -1);
}

StringImpl::StringImpl(char *chr, boolean copy) {
    init(chr, -1, copy);
}

StringImpl::StringImpl(const char *chr, int length) {
   copyCharacters(chr, length);
}

StringImpl::StringImpl(char *chr, int length, boolean copy) {
   init(chr, length, copy);
}

StringImpl::~StringImpl() {
    if (_data != NULL) {
        delete[] _data;
    }
}

StringImpl::StringImpl(const StringImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* StringImpl::debugClassName() {
    return "jam::lang::String";
}
#endif

void StringImpl::init(char* chr, int length, boolean copy) {
    if (copy == true) {
        copyCharacters(chr, length);
    } else {
        _data   = chr;
        _length = Character::length(chr);
        _hash   = 0;
    }
}

/*******************************************************************************
 * clone
 *
 * @return object
 */
Object StringImpl::clone() {
    return String(new StringImpl(_data));
}

/*******************************************************************************
 * toString
 *
 * @return string
 */
String StringImpl::toString() {
    return String(this);
}

/*******************************************************************************
 * getClass
 *
 * @return class
 */
Class StringImpl::getClass() {
    return String::klass;
}

/*******************************************************************************
 * hashCode
 *
 * @return hash
 */
int StringImpl::hashCode() {
    int i;
    
    if (_hash == 0) {
        for (i = 0; i < _length; i++) {
            _hash = (31 * _hash) + _data[i];
        }
    }
    
    return _hash;
}

/*******************************************************************************
 * charAt
 *
 * @param index
 * @return char
 */
char StringImpl::charAt(const int index) {
    if (index < 0 || index > (_length - 1)) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    return _data[index];
}

/*******************************************************************************
 * concat
 *
 * @param str
 * @return string
 */
String StringImpl::concat(String str) {
    char*  chr;
    int    counter;
    int    i;
    
    chr    = new char[_length + str->_length + 1];
    
    for (i = 0, counter = 0; i < _length; i++, counter++) {
        chr[counter] = _data[i];
    }
    
    for (i = 0; i < str->_length; i++, counter++) {
        chr[counter] = str->_data[i];
    }
    
    chr[counter] = '\0';
    
    return String(new StringImpl(chr, counter, false));
}

/*******************************************************************************
 * startsWith
 *
 * @param str
 * @return boolean
 */
boolean StringImpl::startsWith(String str) {
    int     i;
    boolean isValid;
    
    if (_length < str->_length) {
        return false;
    }
    
    isValid = true;
    for (i = 0; i < str->_length; i++) {
        if (_data[i] != str->_data[i]) {
            isValid = false;
            break;
        }
    }
    
    return isValid;
}

/*******************************************************************************
 * endsWith
 *
 * @param str
 * @return boolean
 */
boolean StringImpl::endsWith(String str) {
    int     i;
    int     k;
    boolean isValid;
    
    if (_length < str->_length) {
        return false;
    }
    
    isValid = true;
    for (i = (_length - 1), k = (str->_length - 1); k >= 0; i--, k--) {
        if (_data[i] != str->_data[k]) {
            isValid = false;
            break;
        }
    }
    
    return isValid;
}

/*******************************************************************************
 * equals
 *
 * @param obj
 * @return boolean
 */
boolean StringImpl::equals(Object obj) {
    if (obj->instanceOf(String::klass)) {
        return StringImpl::equals((String) obj);
    }
    
    return ObjectImpl::equals(obj);
}

/*******************************************************************************
 * equals
 *
 * @param str
 * @return boolean
 */
boolean StringImpl::equals(String str) {
    int     i;
    boolean isValid;
    
    if (str == null) {
        return false;
    }
    
    isValid = false;
    if (_length == str->_length) {
        isValid = true;
        for (i = 0; i < _length; i++) {
            if (_data[i] != str->_data[i]) {
                isValid = false;
                break;
            }
        }
    }
    
    return isValid;
}

/*******************************************************************************
 * equalsIgnoreCase
 *
 * @param str
 * @return boolean
 */
boolean StringImpl::equalsIgnoreCase(String str) {
    String local;
    String remote;
    
    if (str == null) {
        return false;
    }
    
    local  = toLowerCase();
    remote = str->toLowerCase();
    
    return local->equals(remote);
}

int StringImpl::indexOf(const char chr) {
    return firstIndexOf(chr, 0);
}

int StringImpl::indexOf(const char chr, int fromIndex) {
    return firstIndexOf(chr, fromIndex);
}

int StringImpl::indexOf(String str) {
    return firstIndexOf(str, 0);
}

int StringImpl::indexOf(String str, int fromIndex) {
    return firstIndexOf(str, fromIndex);
}

/*******************************************************************************
 * firstIndexOf
 *
 * @param chr
 * @return index
 */
int StringImpl::firstIndexOf(const char chr) {
    return firstIndexOf(chr, 0);
}

/*******************************************************************************
 * firstIndexOf
 *
 * @param chr
 * @param fromIndex
 * @return index
 */
int StringImpl::firstIndexOf(const char chr, int fromIndex) {
    int i;
    
    for (i = fromIndex; i < _length; i++) {
        if (chr == _data[i]) {
            return i;
        }
    }
    
    return -1;
}

/*******************************************************************************
 * firstIndexOf - TODO
 *
 * @param str
 * @return index
 */
int StringImpl::firstIndexOf(String str) {
    return firstIndexOf(str, 0);
}

int StringImpl::firstIndexOf(String str, int fromIndex) {
    int     i;
    int     k;
    boolean isValid;
    
    if (_length == str->length()) {
        if (equals(str)) {
            return 0;
        }
    } else if (_length > str->length()) {
        for (i = fromIndex; i < (_length - str->length()); i++) {
            isValid = true;
            for (k = 0; k < str->length(); k++) {
                if (str->charAt(k) != _data[i + k]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                return i;
            }
        }
    }
    
    return -1;
}

/*******************************************************************************
 * lastIndexOf
 *
 * @param chr
 * @return index
 */
int StringImpl::lastIndexOf(const char chr) {
    int i;
    
    for (i = (_length - 1); i >= 0; i--) {
        if (chr == _data[i]) {
            return i;
        }
    }
    
    return -1;
}

int StringImpl::lastIndexOf(const char chr, int fromIndex) {
    return 0;
}

/*******************************************************************************
 * lastIndexOf - TODO
 *
 * @param str
 * @return index
 */
int StringImpl::lastIndexOf(String str) {
    return 0;
}

int StringImpl::lastIndexOf(String str, int fromIndex) {
    return 0;
}

/*******************************************************************************
 * length
 *
 * @return length
 */
int StringImpl::length() {
    return _length;
}

/*******************************************************************************
 * toLowerCase
 *
 * @return string
 */
String StringImpl::toLowerCase() {
    String copy;
    int    i;
    
    copy = clone();
    
    for (i = 0; i < copy->length(); i++) {
        if (copy->_data[i] >= 65 && copy->_data[i] <= 90) {
            copy->_data[i] += 32;
        }
    }
    
    return copy;
}

/*******************************************************************************
 * toUpperCase
 *
 * @return string
 */
String StringImpl::toUpperCase() {
    String copy;
    int    i;
    
    copy = clone();
    
    for (i = 0; i < copy->length(); i++) {
        if (copy->_data[i] >= 97 && copy->_data[i] <= 122) {
            copy->_data[i] -= 32;
        }
    }
    
    return copy;
}

/*******************************************************************************
 * trim
 *
 * @return string
 */
String StringImpl::trim() {
    return trim(' ');
}

/*******************************************************************************
 * trim
 *
 * @return string
 */
String StringImpl::trim(const char chr) {
    int left;
    int right;
    int i;
    
    left  = 0;
    right = _length;
    
    for (i = 0; i < _length; i++) {
        if (_data[i] != chr) {
            break;
        }
        left = (i + 1);
    }
    
    for (i = (_length - 1); i >= 0; i--) {
        if (_data[i] != chr) {
            break;
        }
        right = i;
    }
    
    if (left > right) {
        return String(new StringImpl(""));
    }
    
    return substring(left, right);
}

/*******************************************************************************
 * trimLeft                                                              leading
 *
 * @return string
 */
String StringImpl::trimLeft() {
    return trimLeft(' ');
}

/*******************************************************************************
 * trimLeft                                                              leading
 *
 * @param chr
 * @return string
 */
String StringImpl::trimLeft(const char chr) {
    int left;
    int i;
    
    left = 0;
    
    for (i = 0; i < _length; i++) {
        if (_data[i] != chr) {
            break;
        }
        left = (i + 1);
    }
    
    return substring(left, _length);
}

/*******************************************************************************
 * trimRight                                                            trailing
 *
 * @return string
 */
String StringImpl::trimRight() {
    return trimRight(' ');
}

/*******************************************************************************
 * trimRight                                                            trailing
 *
 * @param  chr
 * @return string
 */
String StringImpl::trimRight(const char chr) {
    int right;
    int i;
    
    right = _length;
    
    for (i = (_length - 1); i >= 0; i--) {
        if (_data[i] != chr) {
            break;
        }
        right = i;
    }
    
    return substring(0, right);
}

/*******************************************************************************
 * substring
 *
 * @param beginIndex
 * @param endIndex
 * @return string
 */
String StringImpl::substring(const int beginIndex, const int endIndex) {
    char*  chr;
    int    length;
    int    i;
    int    k;
    
    length = endIndex - beginIndex;
    chr    = new char[length + 1];
    
    for (i = 0, k = beginIndex; k < endIndex; i++, k++) {
        chr[i] = _data[k];
    }
    chr[i] = '\0';
    
    return String(new StringImpl(chr, length, false));
}

/*******************************************************************************
 * replace
 *
 * @param oldChar
 * @param newChar
 * @return string
 */
String StringImpl::replace(const char oldChar, const char newChar) {
    char*   chr;
    int     i;
    
    chr = new char[_length + 1];
    
    for (i = 0; i < _length; i++) {
        if (_data[i] == oldChar) {
            chr[i] = newChar;
        } else {
            chr[i] = _data[i];
        }
    }
    chr[i] = '\0';
    
    return String(new StringImpl(chr, _length, false));
}

/*******************************************************************************
 * replace
 *
 * @param oldString
 * @param newString
 * @return string
 */
String StringImpl::replace(String oldString, String newString) {
    return null;
}

/*******************************************************************************
 * toChar
 *
 * @return char array
 */
const char* StringImpl::toChar() {
    return _data;
}

/*******************************************************************************
 * isEmpty
 *
 * @return true or false
 */
boolean StringImpl::isEmpty() {
    return isEmpty(false);
}

/*******************************************************************************
 * isEmpty
 *
 * @param with or without whitespaces
 * @return true or false
 */
boolean StringImpl::isEmpty(boolean withWhitespace) {
    boolean isValid;
    int     i;
    
    isValid = false;
    
    if (_length == 0 || withWhitespace == true) {
        isValid = true;
        for (i = 0; i < _length; i++) {
            if (_data[i] != ' ') {
                isValid = false;
                break;
            }
        }
    }
    
    return isValid;
}

/*******************************************************************************
 * isDigit
 *
 * @return true or false
 */
boolean StringImpl::isDigit() {
    boolean isValid;
    int     i;
    
    isValid = true;
    for (i = 0; i < _length; i++) {
        if ((_data[i] < 48 || _data[i] > 57) && _data[i] != '.' && _data[i] != '-') {
            isValid = false;
            break;
        }
    }
    
    return isValid;
}

/*******************************************************************************
 * isAlpha
 *
 * @return true or false
 */
boolean StringImpl::isAlpha() {
    return false; // TODO
}

/*******************************************************************************
 * digitFormat
 *
 * @return
 * @deprecated This code will be transfered to jam::text::NumberFormat
 */
String StringImpl::digitFormat() {
    char* chr;
    int   i;
    int   k;
    
    k   = 0;
    chr = new char[_length + 1];
    
    for (i = 0; i < _length; i++) {
        if (_data[i] > 47 && _data[i] < 58) {
            chr[k++] = _data[i];
        }
    }
    chr[k++] = '\0';
    
    return String(new StringImpl(chr, false))->trim();
}

/*******************************************************************************
 * alphaFormat
 *
 * @return 
 * @deprecated This code will be transfered to jam::text::NumberFormat
 */
String StringImpl::alphaFormat() {
    return null; // TODO
}

/*******************************************************************************
 * currencyFormat
 *
 * @return
 * @deprecated This code will be transfered to jam::text::NumberFormat
 */
String StringImpl::currencyFormat() {
    return currencyFormat(true);
}

/*******************************************************************************
 * currencyFormat
 *
 * @return 
 * @deprecated This code will be transfered to jam::text::NumberFormat
 */
String StringImpl::currencyFormat(boolean withDecimalPlaces) {
    char* chr;
    int   i;
    int   k;
    int   length;
    
    k      = 0;
    length = _length + ((_length / 3) - 1) + 3; // current length + 
    chr    = new char[length + 1];              // ((current length / 3) - 1) for "'"
                                                // 3 for ".--"
    
    for (i = 0; i < _length; i++) {
        if ((_length - i) % 3 || !i) {
            chr[k++] = _data[i];
        } else {
            chr[k++] = 39;
            chr[k++] = _data[i];
        }
    }
    
    if (withDecimalPlaces == true) {
        chr[k++] = '.';
        chr[k++] = '-';
        chr[k++] = '-';
    }
    chr[k++] = '\0';
    
    return String(new StringImpl(chr, length - 1, false))->trim();
}

/*******************************************************************************
 * copyCharacters
 *
 * @param chr
 * @param length
 */
void StringImpl::copyCharacters(const char* chr, int length) {
    int   i;
    int   chrLength;
    
    if (length == -1) {
        length = chrLength = Character::length(chr);
    } else {
        chrLength = length;
        for (i = 0; i < length; i ++) {
            if (chr[i] == '\0') {
                chrLength = i;
                break;
            }
        }
    }
    
    _data = new char[length + 1];
    
    for (i = 0; i < chrLength; i++) {
        _data[i] = chr[i];
    }
    
    if (chrLength < length) {
        for (; i < length; i++) {
            _data[i] = ' ';
        }
    }
    _data[i] = '\0';
    _length  = length;
    _hash    = 0;
}
