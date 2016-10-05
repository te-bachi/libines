#include "jam/text/NumberFormat.hxx"
#include "jam/util/locale/Locale.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/IllegalArgumentException.hxx"
#include "jam/lang/Integer.hxx"
#include "jam/lang/Double.hxx"
#include "jam/lang/Long.hxx"
#include "jam/lang/Character.hxx"

#include <iostream>

using namespace jam::text;
using namespace jam::lang;

const Class NumberFormat::klass = Class::newInstance("jam::text::NumberFormat");

/*** Reference ***/

NumberFormat::NumberFormat() : Format() {
    //
}

NumberFormat::NumberFormat(const Reference& ref) : Format(ref) {
    //
}

NumberFormat::NumberFormat(Implementation* impl) : Format(impl) {
    //
}

NumberFormat::~NumberFormat() {
    //
}

NumberFormatImpl& NumberFormat::operator*() {
    return (NumberFormatImpl&) Format::operator*();
}

NumberFormatImpl* NumberFormat::operator->() {
    return (NumberFormatImpl*) Format::operator->();
}

const NumberFormat& NumberFormat::operator=(const Reference& ref) {
    return (NumberFormat&) Format::operator=(ref);
}

const NumberFormat& NumberFormat::operator=(Implementation* impl) {
    return (NumberFormat&) Format::operator=(impl);
}

NumberFormat NumberFormat::newInstance(String pattern) {
    return NumberFormat(new NumberFormatImpl(pattern));
}

NumberFormat NumberFormat::newInstance(int style) {
    return NumberFormat(new NumberFormatImpl(style));
}

NumberFormat NumberFormat::newInstance(int style, Locale locale) {
    return NumberFormat(new NumberFormatImpl(style, locale));
}

/*** Implementation ***/


NumberFormatImpl::NumberFormatImpl(String pattern) {
    init(pattern);
}

NumberFormatImpl::NumberFormatImpl(int style) {
    init(Locale::getDefault()->getCountry()->getNumberPattern(style));
}

NumberFormatImpl::NumberFormatImpl(int style, Locale locale) {
    init(locale->getCountry()->getNumberPattern(style));
}

NumberFormatImpl::~NumberFormatImpl() {
    
}

NumberFormatImpl::NumberFormatImpl(const NumberFormatImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* NumberFormatImpl::debugClassName() {
    return "jam::text::NumberFormat";
}
#endif

String NumberFormatImpl::toString() {
    return null;
}

Class NumberFormatImpl::getClass() {
    return NumberFormat::klass;
}

void NumberFormatImpl::init(String pattern) {
    char    lastChar;
    int     groupingIndex;
    int     i;
    boolean afterGroupingSeparator;
    boolean afterDecimalSeparator;
    
    groupingIndex          = -1;
    afterGroupingSeparator = false;
    afterDecimalSeparator  = false;
    
    _groupingSeparator     = 0;
    _decimalSeparator      = 0;
    _necessaryFraction     = 0;
    _optionalFraction      = 0;
    _necessaryInteger      = 0;
    _optionalInteger       = 0;
    
    for (i = 0; i < pattern->length(); i++) {
        if (pattern->charAt(i) == '0') {
            lastChar = '0';
            if (afterDecimalSeparator == true) {
                _necessaryFraction++;
            } else {
                _necessaryInteger++;
            }
        } else if (pattern->charAt(i) == '#') {
            lastChar = '#';
            if (afterDecimalSeparator == true) {
                _optionalFraction++;
            } else {
                _optionalInteger++;
            }
        } else if (pattern->charAt(i) == '%') {
            if (i != (pattern->length() - 1)) {
                throw IllegalArgumentException::newInstance(String::newInstance("exception.format.obj.missmatch"));
            }
        } else {
            if (lastChar == '0') {
                _decimalSeparator     = pattern->charAt(i);
                afterDecimalSeparator = true;
                if (afterGroupingSeparator == true) {
                    _groupingOffset = i - groupingIndex - 1;
                }
            } else if (lastChar == '#') {
                _groupingSeparator     = pattern->charAt(i);
                groupingIndex          = i;
                afterGroupingSeparator = true;
            }
        }
    }
    
    if (afterGroupingSeparator == true && afterDecimalSeparator == false) {
        _groupingOffset = pattern->length() - groupingIndex - 1;
    }
    
    /*
    printf("pattern:           %s\n", pattern->toChar());
    printf("groupingSeparator: %c\n", _groupingSeparator);
    printf("decimalSeparator:  %c\n", _decimalSeparator);
    printf("necessaryFraction: %d\n", _necessaryFraction);
    printf("optionalFraction:  %d\n", _optionalFraction);
    printf("necessaryInteger:  %d\n", _necessaryInteger);
    printf("optionalInteger:   %d\n", _optionalInteger);
    printf("groupingOffset:    %d\n\n", _groupingOffset);
    */
}

String NumberFormatImpl::format(Object obj) {
    if (obj->instanceOf(Number::klass)) {
        return NumberFormatImpl::format((Number) obj);
    } else if (obj->instanceOf(String::klass)) {
         return NumberFormatImpl::format((String) obj);
    }
    throw IllegalArgumentException::newInstance(String::newInstance("exception.format.obj.missmatch"));
}

String NumberFormatImpl::format(Number number) {
    if (number->instanceOf(Integer::klass) || number->instanceOf(Long::klass)) {
        return NumberFormatImpl::format(String::valueOf(number->longValue()));
    } else if (number->instanceOf(Double::klass)) {
        // quirk
        return NumberFormatImpl::format(String::valueOf(number->doubleValue(), _necessaryFraction + _optionalFraction));
    }
    throw IllegalArgumentException::newInstance(String::newInstance("exception.format.obj.missmatch"));
}

String NumberFormatImpl::format(long value) {
    return format(String::valueOf(value));
}

String NumberFormatImpl::format(double value) {
    // quirk
    return format(String::valueOf(value, _necessaryFraction + _optionalFraction));
}

String NumberFormatImpl::format(String input) {
    char*  buffer;
    int    bufferIndex;
    int    integerIndex;
    int    fractionIndex;
    int    fractionLength;
    int    padding;
    int    decimalSeparatorIndex;
    int    i;
    int    groupCounter;
    
    buffer       = Character::initialize(' ', 255);
    bufferIndex  = 254;
    groupCounter = 0;
    
    // fraction in input
    decimalSeparatorIndex = input->firstIndexOf('.');
    if (decimalSeparatorIndex != -1) {
        integerIndex   = decimalSeparatorIndex - 1;
        fractionLength = input->length() - decimalSeparatorIndex - 1;
        
        if (_decimalSeparator != 0) {
            // trim fraction - quirk will not pass trough this lines
            if (fractionLength > (_necessaryFraction + _optionalFraction)) {
                fractionIndex = decimalSeparatorIndex + _necessaryFraction + _optionalFraction;
            // expand with padding
            } else if (fractionLength < _necessaryFraction) {
                fractionIndex = decimalSeparatorIndex + fractionLength;
                
                // fraction padding
                if (_necessaryFraction > fractionLength) {
                    for (i = (input->length() - 1); i >= fractionIndex; i--, bufferIndex--) {
                        buffer[bufferIndex] = '0';
                    }
                }
            // fraction fits in pattern
            } else {
                fractionIndex = decimalSeparatorIndex + fractionLength;
            }
            
            for (i = fractionIndex; i >= (decimalSeparatorIndex + 1); i--, bufferIndex--) {
                buffer[bufferIndex] = input->charAt(i);
            }
            
            // separator
            buffer[bufferIndex] = _decimalSeparator;
            bufferIndex--;
        }
    // no fraction in input
    } else {
        integerIndex = input->length() - 1;
        
        // fraction padding
        if (_decimalSeparator != 0 && _necessaryFraction > 0) {
            for (i = 0; i < _necessaryFraction; i++, bufferIndex--) {
                buffer[bufferIndex] = '0';
            }
            
            // separator
            buffer[bufferIndex] = _decimalSeparator;
            bufferIndex--;
        }
    }
    
    // integer
    for (i = integerIndex; i >= 0; i--, bufferIndex--, groupCounter++) {
        // grouping
        if (_groupingSeparator != 0) {
            if (groupCounter % _groupingOffset == 0 && groupCounter != 0) {
                buffer[bufferIndex] = _groupingSeparator;
                bufferIndex--;
            }
        }
        buffer[bufferIndex] = input->charAt(i);
    }
    // integer padding
    if (_necessaryInteger > (integerIndex + 1)) {
        padding = _necessaryInteger - (integerIndex + 1);
        for (i = 0; i < padding; i++, bufferIndex--, groupCounter++) {
            // grouping
            if (_groupingSeparator != 0) {
                if (groupCounter % _groupingOffset == 0 && groupCounter != 0) {
                    buffer[bufferIndex] = _groupingSeparator;
                    bufferIndex--;
                }
            }
            buffer[bufferIndex] = '0';
        }
    }
    
    return String::newInstance(buffer, false)->trim();
}

// TODO
Object NumberFormatImpl::parse(String str) {
    return null;
}

// TODO
Number NumberFormatImpl::parseNumber(String str) {
    return null;
}

// TODO
long NumberFormatImpl::parseLong(String str) {
    return 0;
}

double NumberFormatImpl::parseDouble(String str) {
    char*   chr;
    int     i;
    int     k;
    double  result;
    
    chr = new char[str->length() + 1];
    
    for (i = 0, k = 0; i < str->length(); i++) {
        if (str->charAt(i) >= '0' && str->charAt(i) <= '9') {
            chr[k] = str->charAt(i);
            k++;
        } else if (str->charAt(i) == _decimalSeparator) {
            chr[k] = '.';
            k++;
        }
    }
    chr[k] = '\0';
    
    result = Double::parseDouble((String) chr);
    
    delete[] chr;
    
    return result;
}
