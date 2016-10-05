#include "jam/text/CalendarFormat.hxx"
#include "jam/text/NumberFormat.hxx"
#include "jam/text/ParseException.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Integer.hxx"
#include "jam/lang/IllegalArgumentException.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/util/locale/Locale.hxx"
#include "jam/util/time/Calendar.hxx"
#include "jam/util/locale/MessageResource.hxx"

using namespace jam::text;
using namespace jam::lang;
using namespace jam::util::locale;

const Class CalendarFormat::klass = Class::newInstance("jam::text::CalendarFormat");

boolean CalendarFormat::_isInitialized = false;

/*** Reference ***/

CalendarFormat::CalendarFormat() : Format() {
    //
}

CalendarFormat::CalendarFormat(const Reference& ref) : Format(ref) {
    //
}

CalendarFormat::CalendarFormat(Implementation* impl) : Format(impl) {
    //
}

CalendarFormat::~CalendarFormat() {
    //
}

CalendarFormatImpl& CalendarFormat::operator*() {
    return (CalendarFormatImpl&) Format::operator*();
}

CalendarFormatImpl* CalendarFormat::operator->() {
    return (CalendarFormatImpl*) Format::operator->();
}

const CalendarFormat& CalendarFormat::operator=(const Reference& ref) {
    return (CalendarFormat&) Format::operator=(ref);
}

const CalendarFormat& CalendarFormat::operator=(Implementation* impl) {
    return (CalendarFormat&) Format::operator=(impl);
}

void CalendarFormat::init() {
    MessageResource resource;
    
    if (_isInitialized == true) {
        return;
    }
    
    _isInitialized = true;
    
    Locale::init();
    
    // English
    resource = MessageResource::newInstance(((Class) CalendarFormat::klass)->getName(), Language::ENGLISH);
    resource->addString(String::newInstance("monday"), String::newInstance("Monday"));
    resource->addString(String::newInstance("tuesday"), String::newInstance("Tuesday"));
    resource->addString(String::newInstance("wednesday"), String::newInstance("Wednesday"));
    resource->addString(String::newInstance("thursday"), String::newInstance("Thursday"));
    resource->addString(String::newInstance("friday"), String::newInstance("Friday"));
    resource->addString(String::newInstance("saturday"), String::newInstance("Saturday"));
    resource->addString(String::newInstance("sunday"), String::newInstance("Sunday"));
    resource->addString(String::newInstance("january"), String::newInstance("January"));
    resource->addString(String::newInstance("february"), String::newInstance("February"));
    resource->addString(String::newInstance("march"), String::newInstance("March"));
    resource->addString(String::newInstance("april"), String::newInstance("April"));
    resource->addString(String::newInstance("may"), String::newInstance("May"));
    resource->addString(String::newInstance("june"), String::newInstance("June"));
    resource->addString(String::newInstance("july"), String::newInstance("July"));
    resource->addString(String::newInstance("august"), String::newInstance("August"));
    resource->addString(String::newInstance("september"), String::newInstance("September"));
    resource->addString(String::newInstance("october"), String::newInstance("October"));
    resource->addString(String::newInstance("november"), String::newInstance("November"));
    resource->addString(String::newInstance("december"), String::newInstance("December"));
    MessageResource::addMessageResource(resource);
    
    // German
    resource = MessageResource::newInstance(((Class) CalendarFormat::klass)->getName(), Language::GERMAN);
    resource->addString(String::newInstance("monday"), String::newInstance("Montag"));
    resource->addString(String::newInstance("tuesday"), String::newInstance("Dienstag"));
    resource->addString(String::newInstance("wednesday"), String::newInstance("Mittwoch"));
    resource->addString(String::newInstance("thursday"), String::newInstance("Donnerstag"));
    resource->addString(String::newInstance("friday"), String::newInstance("Freitag"));
    resource->addString(String::newInstance("saturday"), String::newInstance("Samstag"));
    resource->addString(String::newInstance("sunday"), String::newInstance("Sonntag"));
    resource->addString(String::newInstance("january"), String::newInstance("Januar"));
    resource->addString(String::newInstance("february"), String::newInstance("Februar"));
    resource->addString(String::newInstance("march"), String::newInstance("März"));
    resource->addString(String::newInstance("april"), String::newInstance("April"));
    resource->addString(String::newInstance("may"), String::newInstance("Mai"));
    resource->addString(String::newInstance("june"), String::newInstance("Juni"));
    resource->addString(String::newInstance("july"), String::newInstance("Juli"));
    resource->addString(String::newInstance("august"), String::newInstance("August"));
    resource->addString(String::newInstance("september"), String::newInstance("September"));
    resource->addString(String::newInstance("october"), String::newInstance("Oktober"));
    resource->addString(String::newInstance("november"), String::newInstance("November"));
    resource->addString(String::newInstance("december"), String::newInstance("Dezember"));
    MessageResource::addMessageResource(resource);
    
    // French
    resource = MessageResource::newInstance(((Class) CalendarFormat::klass)->getName(), Language::FRENCH);
    resource->addString(String::newInstance("monday"), String::newInstance("lundi"));
    resource->addString(String::newInstance("tuesday"), String::newInstance("mardi"));
    resource->addString(String::newInstance("wednesday"), String::newInstance("mercredi"));
    resource->addString(String::newInstance("thursday"), String::newInstance("jeudi"));
    resource->addString(String::newInstance("friday"), String::newInstance("vendredi"));
    resource->addString(String::newInstance("saturday"), String::newInstance("samedi"));
    resource->addString(String::newInstance("sunday"), String::newInstance("dimanche"));
    resource->addString(String::newInstance("january"), String::newInstance("janvier"));
    resource->addString(String::newInstance("february"), String::newInstance("février"));
    resource->addString(String::newInstance("march"), String::newInstance("mars"));
    resource->addString(String::newInstance("april"), String::newInstance("avril"));
    resource->addString(String::newInstance("may"), String::newInstance("mai"));
    resource->addString(String::newInstance("june"), String::newInstance("juin"));
    resource->addString(String::newInstance("july"), String::newInstance("juillet"));
    resource->addString(String::newInstance("august"), String::newInstance("août"));
    resource->addString(String::newInstance("september"), String::newInstance("septembre"));
    resource->addString(String::newInstance("october"), String::newInstance("octobre"));
    resource->addString(String::newInstance("november"), String::newInstance("novembre"));
    resource->addString(String::newInstance("december"), String::newInstance("décembre"));
    MessageResource::addMessageResource(resource);
    
    // Italian
    resource = MessageResource::newInstance(((Class) CalendarFormat::klass)->getName(), Language::ITALIAN);
    resource->addString(String::newInstance("monday"), String::newInstance("lunedì"));
    resource->addString(String::newInstance("tuesday"), String::newInstance("martedì"));
    resource->addString(String::newInstance("wednesday"), String::newInstance("mercoledì"));
    resource->addString(String::newInstance("thursday"), String::newInstance("giovedì"));
    resource->addString(String::newInstance("friday"), String::newInstance("venerdì"));
    resource->addString(String::newInstance("saturday"), String::newInstance("sabato"));
    resource->addString(String::newInstance("sunday"), String::newInstance("domenica"));
    resource->addString(String::newInstance("january"), String::newInstance("gennaio"));
    resource->addString(String::newInstance("february"), String::newInstance("febbraio"));
    resource->addString(String::newInstance("march"), String::newInstance("marzo"));
    resource->addString(String::newInstance("april"), String::newInstance("aprile"));
    resource->addString(String::newInstance("may"), String::newInstance("maggio"));
    resource->addString(String::newInstance("june"), String::newInstance("giugno"));
    resource->addString(String::newInstance("july"), String::newInstance("luglio"));
    resource->addString(String::newInstance("august"), String::newInstance("agosto"));
    resource->addString(String::newInstance("september"), String::newInstance("settembre"));
    resource->addString(String::newInstance("october"), String::newInstance("ottobre"));
    resource->addString(String::newInstance("november"), String::newInstance("novembre"));
    resource->addString(String::newInstance("december"), String::newInstance("dicembre"));
    MessageResource::addMessageResource(resource);
}

boolean CalendarFormat::isInitialized() {
    return _isInitialized;
}

CalendarFormat CalendarFormat::newInstance(String pattern) {
    if (isInitialized() == false) {
        init();
    }
    return CalendarFormat(new CalendarFormatImpl(pattern));
}

CalendarFormat CalendarFormat::newInstance(short style) {
    if (isInitialized() == false) {
        init();
    }
    return CalendarFormat(new CalendarFormatImpl(style));
}

CalendarFormat CalendarFormat::newInstance(Locale locale, short style) {
    if (isInitialized() == false) {
        init();
    }
    return CalendarFormat(new CalendarFormatImpl(locale, style));
}

/*** Implementation ***/

CalendarFormatImpl::CalendarFormatImpl(String pattern) {
    _pattern = pattern;
    _cursor  = 0;
}

CalendarFormatImpl::CalendarFormatImpl(short style) {
    init(Locale::getDefault(), style);
}

CalendarFormatImpl::CalendarFormatImpl(Locale locale, short style) {
    init(locale, style);
}

CalendarFormatImpl::~CalendarFormatImpl() {
    //
}

CalendarFormatImpl::CalendarFormatImpl(const CalendarFormatImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* CalendarFormatImpl::debugClassName() {
    return "jam::text::CalendarFormat";
}
#endif

String CalendarFormatImpl::toString() {
    return _pattern;
}

Class CalendarFormatImpl::getClass() {
    return CalendarFormat::klass;
}

void CalendarFormatImpl::init(Locale locale, short style) {
    StringBuffer buffer;
    int          i;
    boolean      isFirst;
    
    buffer  = StringBuffer::newInstance();
    i       = 0;
    isFirst = true;
    do {
        if (style & 1) {
            if (isFirst == false) {
                buffer->append(' ');
            }
            buffer->append(locale->getCountry()->getCalendarPattern(i));
            isFirst = false;
        }
        style >>= 1;
        i++;
    } while (style);
    
    _pattern = buffer->toString();
    _locale  = locale;
}

boolean CalendarFormatImpl::isEOF() {
    return (_cursor >= _pattern->length());
}

boolean CalendarFormatImpl::isCharacter(char chr) {
    return (_pattern->charAt(_cursor) == chr);
}

int CalendarFormatImpl::letterLength(char chr) {
    int length = 0;
    
    do {
        _cursor++;
        length++;
    } while (isEOF() == false && isCharacter(chr));
    
    return length;
}

void CalendarFormatImpl::formatNumber(StringBuffer buffer, String str, int length) {
    // fill with null
    if (length > str->length()) {
        while (length != str->length()) {
            buffer->append('0');
            length--;
        }
        buffer->append(str);
    // cut year
    } else {
        buffer->append(str->substring(str->length() - length, str->length()));
    }
}

String CalendarFormatImpl::format(Object obj) {
    if (obj->instanceOf(Calendar::klass)) {
        return CalendarFormatImpl::format((Calendar) obj);
    }
    throw IllegalArgumentException::newInstance(String::newInstance("exception.format.obj.missmatch"));
}

String CalendarFormatImpl::formatMonth(int month) {
    String result;
    int    lookup;
    
    lookup = month - 1;
    
    switch (lookup) {
        case Calendar::JANUARY:   result = "january";   break;
        case Calendar::FEBRUARY:  result = "february";  break;
        case Calendar::MARCH:     result = "march";     break;
        case Calendar::APRIL:     result = "april";     break;
        case Calendar::MAY:       result = "may";       break;
        case Calendar::JUNE:      result = "june";      break;
        case Calendar::JULY:      result = "july";      break;
        case Calendar::AUGUST:    result = "august";    break;
        case Calendar::SEPTEMBER: result = "september"; break;
        case Calendar::OCTOBER:   result = "october";   break;
        case Calendar::NOVEMBER:  result = "november";  break;
        case Calendar::DECEMBER:  result = "december";  break;
    }
    
    return MessageResource::getMessageResource(((Class) CalendarFormat::klass)->getName(), _locale->getLanguage())->getString(result);
}

String CalendarFormatImpl::formatWeekday(int weekday) {
    String result;
    
    switch (weekday) {
        case Calendar::SUNDAY:    result = "sunday";    break;
        case Calendar::MONDAY:    result = "monday";    break;
        case Calendar::TUESDAY:   result = "tuesday";   break;
        case Calendar::WEDNESDAY: result = "wednesday"; break;
        case Calendar::THURSDAY:  result = "thursday";  break;
        case Calendar::FRIDAY:    result = "friday";    break;
        case Calendar::SATURDAY:  result = "saturday";  break;
    }
    
    return MessageResource::getMessageResource(((Class) CalendarFormat::klass)->getName(), _locale->getLanguage())->getString(result);
}

void CalendarFormatImpl::calcPatternLength() {
    _minLength = 0;
    _maxLength = 0;
    _cursor    = 0;
    
    while (isEOF() == false) {
        // year
        if (isCharacter('y')) {
            if (letterLength('y') > 2) {
                _minLength += 4;
                _maxLength += 4;
            } else {
                _minLength += 2;
                _maxLength += 2;
            }
        // month of year
        } else if (isCharacter('M')) {
            if (letterLength('M') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // day of month
        } else if (isCharacter('d')) {
            if (letterLength('d') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // am/pm marker
        } else if (isCharacter('a')) {
            _minLength += 2;
            _maxLength += 2;
        // AM/PM marker
        } else if (isCharacter('A')) {
            _minLength += 2;
            _maxLength += 2;
        // hour in day 0-23
        } else if (isCharacter('H')) {
            if (letterLength('H') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // hour in day 1-24
        } else if (isCharacter('k')) {
            if (letterLength('k') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // hour in am/pm 0-11
        } else if (isCharacter('K')) {
            if (letterLength('K') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // hour in am/pm 1-12
        } else if (isCharacter('h')) {
            if (letterLength('h') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // minute in hour
        } else if (isCharacter('m')) {
            if (letterLength('m') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        // second in minute
        } else if (isCharacter('s')) {
            if (letterLength('s') > 1) {
                _minLength += 2;
                _maxLength += 2;
            } else {
                _minLength += 1;
                _maxLength += 2;
            }
        } else {
            _minLength += 1;
            _maxLength += 1;
            _cursor++;
        }
    }
}

String CalendarFormatImpl::format(Calendar calendar) {
    StringBuffer buffer;
    String       temp;
    int          length;
    
    _cursor = 0;
    buffer  = StringBuffer::newInstance();
    
    while (isEOF() == false) {
        // year
        if (isCharacter('y')) {
            length = letterLength('y');
            temp   = String::valueOf(calendar->getYear());
            formatNumber(buffer, temp, length);
            
        // month of year
        } else if (isCharacter('M')) {
            length = letterLength('M');
            if (length <= 2) {
                temp = String::valueOf(calendar->getMonth());
                formatNumber(buffer, temp, length);
            } else if (length == 3) {
                buffer->append(formatMonth(calendar->getMonth())->substring(0, 2));
            } else {
                buffer->append(formatMonth(calendar->getMonth()));
            }
            
        // TODO - week of year
        } else if (isCharacter('w')) {
            length = letterLength('w');
            buffer->append("<TODO: week of year>");
            
        // TODO - week of month
        } else if (isCharacter('W')) {
            length = letterLength('W');
            buffer->append("<TODO: week of month>");
            
        // day of year
        } else if (isCharacter('D')) {
            length = letterLength('D');
            temp   = String::valueOf(calendar->getDayOfYear());
            formatNumber(buffer, temp, length);
            
        // day of month
        } else if (isCharacter('d')) {
            length = letterLength('d');
            temp   = String::valueOf(calendar->getDay());
            formatNumber(buffer, temp, length);
            
        // day of week
        } else if (isCharacter('E')) {
            length = letterLength('E');
            if (length <= 2) {
                temp = String::valueOf(calendar->getWeekday());
                formatNumber(buffer, temp, length);
            } else if (length == 3) {
                buffer->append(formatWeekday(calendar->getWeekday())->substring(0, 2));
            } else {
                buffer->append(formatWeekday(calendar->getWeekday()));
            }
            
        // am/pm marker
        } else if (isCharacter('a')) {
            if (calendar->getHour() < 12) {
                buffer->append("am");
            } else {
                buffer->append("pm");
            }
            _cursor++;
            
        // AM/PM marker
        } else if (isCharacter('A')) {
            if (calendar->getHour() < 12) {
                buffer->append("AM");
            } else {
                buffer->append("PM");
            }
            _cursor++;
            
        // hour in day 0-23
        } else if (isCharacter('H')) {
            length = letterLength('H');
            temp   = String::valueOf(calendar->getHour());
            formatNumber(buffer, temp, length);
            
        // hour in day 1-24
        } else if (isCharacter('k')) {
            length = letterLength('k');
            if (calendar->getHour() == 0) {
                temp = "24";
            } else {
                temp = String::valueOf(calendar->getHour());
            }
            formatNumber(buffer, temp, length);
            
        // hour in am/pm 0-11
        } else if (isCharacter('K')) {
            length = letterLength('K');
            
            if (calendar->getHour() == 12) {
                temp = "12";
            } else if (calendar->getHour() < 12) {
                temp = String::valueOf(calendar->getHour());
            } else {
                temp = String::valueOf(calendar->getHour() - 12);
            }
            formatNumber(buffer, temp, length);
            
        // hour in am/pm 1-12
        } else if (isCharacter('h')) {
            length = letterLength('h');
            if (calendar->getHour() == 0 || calendar->getHour() == 12) {
                temp = "12";
            } else if (calendar->getHour() < 12) {
                temp = String::valueOf(calendar->getHour());
            } else {
                temp = String::valueOf(calendar->getHour() - 12);
            }
            formatNumber(buffer, temp, length);
            
        // minute in hour
        } else if (isCharacter('m')) {
            length = letterLength('m');
            temp   = String::valueOf(calendar->getMinute());
            formatNumber(buffer, temp, length);
            
        // second in minute
        } else if (isCharacter('s')) {
            length = letterLength('s');
            temp   = String::valueOf(calendar->getSecond());
            formatNumber(buffer, temp, length);
            
        // millisecond
        } else if (isCharacter('S')) {
            length = letterLength('S');
            temp   = String::valueOf(calendar->getMilisecond());
            formatNumber(buffer, temp, length);
            
        // timezone
        } else if (isCharacter('z')) {
            length = letterLength('z');
            buffer->append(calendar->getTimeZone()->getId());
            
        // timezone offset
        } else if (isCharacter('Z')) {
            String pattern;
            int    offset;
            int    newLength;
            
            length = letterLength('Z');
            offset = calendar->getTimeZone()->getOffset(calendar);
            
            if (offset < 0) {
                temp = String::valueOf((int) (offset / 36.0 * -1));
            } else {
                temp = String::valueOf((int) (offset / 36.0));
            }
            
            if (length > 1) {
                buffer->append("UTC");
            }
            
            if (offset < 0) {
                buffer->append('-');
            } else {
                buffer->append('+');
            }
            if (length == 1) {
                pattern = "0000";
            } else {
                pattern = "00#:00";
            }
            buffer->append(NumberFormat::newInstance(pattern)->format(temp));
        // text
        } else if (isCharacter('\'')) {
            _cursor++;
            if (isEOF() == false && isCharacter('\'')) {
                buffer->append('\'');
            } else {
                do {
                    buffer->append(_pattern->charAt(_cursor));
                    _cursor++;
                } while (isEOF() == false && isCharacter('\''));
                _cursor++;
            }
        } else {
            buffer->append(_pattern->charAt(_cursor));
            _cursor++;
        }
    }
    
    return buffer->toString();
}

Object CalendarFormatImpl::parse(String str) {
    return parseCalendar(str);
}

/**
 * HACK!!!
 *
 * Will be better implementation...
 */
Calendar CalendarFormatImpl::parseCalendar(String str) {
    int      day;
    int      month;
    int      year;
    int      hour;
    int      minute;
    int      second;
    
    day     = 1;
    month   = 1;
    year    = 1970;
    hour    = 0;
    minute  = 0;
    second  = 0;
    
    if (_pattern->length() != str->length() && (_pattern->length() + 1) != str->length()) {
        throw ParseException::newInstance("exception.parse.mismatch");
    }
    
    if (_pattern->equals("MM/dd/yyyy hh:mm:ss A")) {
        day    = Integer::parseInt(str->substring( 3,  5));
        month  = Integer::parseInt(str->substring( 0,  2));
        year   = Integer::parseInt(str->substring( 6, 10));
        hour   = Integer::parseInt(str->substring(11, 13));
        minute = Integer::parseInt(str->substring(14, 16));
        second = Integer::parseInt(str->substring(17, 19));
        
        if (str->substring(20, 22)->equalsIgnoreCase("PM")) {
            if (hour != 12) {
                hour += 12;
            }
        } else if (hour == 12) {
            hour = 0;
        }
    } else if (_pattern->equals("dd.MM.yyyy HH:mm:ss")) {
        day    = Integer::parseInt(str->substring( 0,  2));
        month  = Integer::parseInt(str->substring( 3,  5));
        year   = Integer::parseInt(str->substring( 6, 10));
        hour   = Integer::parseInt(str->substring(11, 13));
        minute = Integer::parseInt(str->substring(14, 16));
        second = Integer::parseInt(str->substring(17, 19));
    } else if (_pattern->equals("yyyyMMddHHmmss")) {
        day    = Integer::parseInt(str->substring( 6,  8));
        month  = Integer::parseInt(str->substring( 4,  6));
        year   = Integer::parseInt(str->substring( 0,  4));
        hour   = Integer::parseInt(str->substring( 8, 10));
        minute = Integer::parseInt(str->substring(10, 12));
        second = Integer::parseInt(str->substring(12, 14));
    } else if (_pattern->equals("MM/dd/yyyy")) {
        day    = Integer::parseInt(str->substring( 3,  5));
        month  = Integer::parseInt(str->substring( 0,  2));
        year   = Integer::parseInt(str->substring( 6, 10));
    } else if (_pattern->equals("dd.MM.yyyy")) {
        day    = Integer::parseInt(str->substring( 0,  2));
        month  = Integer::parseInt(str->substring( 3,  5));
        year   = Integer::parseInt(str->substring( 6, 10));
    } else if (_pattern->equals("yyyyMMdd")) {
        day    = Integer::parseInt(str->substring( 6,  8));
        month  = Integer::parseInt(str->substring( 4,  6));
        year   = Integer::parseInt(str->substring( 0,  4));
    } else if (_pattern->equals("hh:mm:ss A")) {
        hour   = Integer::parseInt(str->substring( 0,  2));
        minute = Integer::parseInt(str->substring( 3,  5));
        second = Integer::parseInt(str->substring( 6,  8));
        
        if (str->substring(10, 12)->equalsIgnoreCase("PM")) {
            if (hour != 12) {
                hour += 12;
            }
        } else if (hour == 12) {
            hour = 0;
        }
    } else if (_pattern->equals("HH:mm:ss")) {
        hour   = Integer::parseInt(str->substring( 0,  2));
        minute = Integer::parseInt(str->substring( 3,  5));
        second = Integer::parseInt(str->substring( 6,  8));
    } else if (_pattern->equals("hh:mm A")) {
        hour   = Integer::parseInt(str->substring( 0,  2));
        minute = Integer::parseInt(str->substring( 3,  5));
        
        if (str->substring(6, 8)->equalsIgnoreCase("PM")) {
            if (hour != 12) {
                hour += 12;
            }
        } else if (hour == 12) {
            hour = 0;
        }
    } else if (_pattern->equals("HH:mm")) {
        hour   = Integer::parseInt(str->substring( 0,  2));
        minute = Integer::parseInt(str->substring( 3,  5));
    }
    
    if (day  < 1 || day  > 31 || month  < 1 || month  > 12 || year   < 1960 || year   > 3000 ||
        hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0    || second > 59) {
            throw ParseException::newInstance("exception.parse.outofbound");
    }
    
    return Calendar::newInstance(day, month, year, hour, minute, second);
}
