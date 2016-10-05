#include "jam/lang/Character.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/NumberFormatException.hxx"

using namespace jam::lang;
using namespace jam::lang;

const Class Character::klass = new ClassImpl("jam::lang::Character");
const char Character::HEXADECIMAL_LOWER[17] = "0123456789abcdef";
const char Character::HEXADECIMAL_UPPER[17] = "0123456789ABCDEF";

/*** Reference ***/

Character::Character() : Object() {
    //
}

Character::Character(const Reference& ref) : Object(ref) {
    //
}

Character::Character(Implementation* impl) : Object(impl) {
    //
}

Character::~Character() {
    //
}

CharacterImpl& Character::operator*() {
    return (CharacterImpl&) Object::operator*();
}

CharacterImpl* Character::operator->() {
    return (CharacterImpl*) Object::operator->();
}

const Character& Character::operator=(const Reference& ref) {
    return (Character&) Object::operator=(ref);
}

const Character& Character::operator=(Implementation* impl) {
    return (Character&) Object::operator=(impl);
}

Character Character::newInstance() {
    return Character(new CharacterImpl());
}

char* Character::initialize(char filler, int length) {
    char* chr;
    int   i;
    
    chr = new char[length + 1];
    
    for (i = 0; i < length; i++) {
        chr[i] = filler;
    }
    chr[i] = '\0';
    
    return chr;
}

int Character::length(const char* chr) {
    int i;
    
    if (chr != NULL) {
        for (i = 0; true; i++) {
            if (chr[i] == '\0') {
                return i;
            }
        }
    }
    
    return -1;
}

int Character::digit(char chr) {
    if (chr >= 48 && chr <= 57) {
        return (chr - 48);
    } else if (chr >= 65 && chr <= 70) {
        return (chr - 55);
    }
    
    throw NumberFormatException();
}

char Character::toUpperCase(char chr) {
    if (chr >= 97 && chr <= 122) {
        return chr - 32;
    }
    
    return chr;
}

char Character::toLowerCase(char chr) {
    if (chr >= 65 && chr <= 90) {
        return chr + 32;
    }
    
    return chr;
}

boolean Character::isDigit(char chr) {
    if (chr >= 48 && chr <= 57) {
        return true;
    }
    
    return false;
}

boolean Character::isLetter(char chr) {
    if ((chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122)) {
        return true;
    }
    
    return false;
}

boolean Character::isLowerCase(char chr) {
    if (chr >= 97 && chr <= 122) {
        return true;
    }
    
    return false;
}

boolean Character::isUpperCase(char chr) {
    if (chr >= 65 && chr <= 90) {
        return true;
    }
    
    return false;
}

boolean Character::isWhitespace(char chr) {
    if (chr == 32) {
        return true;
    }
    
    return false;
}

boolean Character::isSpecialCharacter(char chr) {
    if ((chr >= 33 && chr <= 47) || (chr >=  58 && chr <=  64) ||
        (chr >= 91 && chr <= 96) || (chr >= 123 && chr <= 126)) {
            return true;
    }
    
    return false;
}
int Character::analyze(char chr) {
    
    if (isUpperCase(chr)) {
        return UPPER_CASE;
    }
    
    if (isLowerCase(chr)) {
        return LOWER_CASE;
    }
    
    if (isDigit(chr)) {
        return DIGIT;
    }
    
    if (isSpecialCharacter(chr)) {
        return SPECIAL;
    }
    
    return UNKNOW;
}

/*** Implementation ***/

CharacterImpl::CharacterImpl() {
    
}

CharacterImpl::~CharacterImpl() {
    
}

CharacterImpl::CharacterImpl(const CharacterImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* CharacterImpl::debugClassName() {
    return "jam::lang::Character";
}
#endif

Object CharacterImpl::clone() {
    return null;
}

String CharacterImpl::toString() {
    return null;
}

Class CharacterImpl::getClass() {
    return Character::klass;
}
