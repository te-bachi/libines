#include "jam/lang/ByteArray.hxx"
#include "jam/lang/Double.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Thread.hxx"
#include "jam/lang/Character.hxx"
#include "jam/lang/System.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/util/StringTokenizer.hxx"
#include "jam/util/StringPadding.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/LinkedList.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/ListIterator.hxx"
#include "jam/util/SortedMap.hxx"
#include "jam/util/sort/Comparator.hxx"
#include "jam/util/sort/StringComparator.hxx"
#include "jam/util/locale/Country.hxx"
#include "jam/util/locale/Language.hxx"
#include "jam/util/locale/Locale.hxx"
#include "jam/util/time/TimeZone.hxx"
#include "jam/util/time/Calendar.hxx"
#include "jam/util/time/Clock.hxx"
#include "jam/lang/IndexOutOfBoundsException.hxx"
#include "jam/lang/Exception.hxx"
#include "jam/text/CalendarFormat.hxx"
#include "jam/text/NumberFormat.hxx"
#include "jam/text/ParseException.hxx"
#include "jam/util/locale/MissingResourceException.hxx"
#include "jam/lang/StackTraceElement.hxx"
#include "jam/lang/RegisterElement.hxx"
#include "jam/lang/Pointer.hxx"
#include "jam/io/File.hxx"
#include "jam/io/FileNotFoundException.hxx"

#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace jam::lang;
using namespace jam::util;
using namespace jam::util::locale;
using namespace jam::util::time;
using namespace jam::text;
using namespace jam::io;

void test1() {
    Thread thread;
    
    thread = Thread::newInstance(Thread::PRIORITY_LOW);
    thread->start();
    printf("%s\n", thread->toString()->toChar());
    thread->join();
    
    thread = Thread::newInstance(Thread::PRIORITY_REALTIME);
    thread->start();
    printf("%s\n", thread->toString()->toChar());
    thread->join();
}

void test2() {
    ArrayList  list_1;
    ArrayList  list_2;
    ArrayList  list_3;
    ArrayList  list_4;
    String a;
    String b;
    String c;
    String d;
    String e;
    String f;
    
    a = "aabbcc";
    b = "bbccdd";
    c = "ccddee";
    d = "ddeeff";
    e = "eeffgg";
    f = "ffgghh";
    
    list_1 = ArrayList::newInstance(2);
    list_2 = ArrayList::newInstance(2);
    list_1->add(a);
    list_1->add(b);
    list_1->add(c);
    list_1->add(d);
    list_1->add(e);
    list_1->add(f);
    
    list_2->add((Collection) list_1);
    
    list_3 = list_2->subList(0, 2);
    list_4 = list_2->subList(3, 5);
    
    printf("%s\n", list_3->toString()->toChar());
    printf("%s\n", list_4->toString()->toChar());
    
    list_1->remove(a);
    list_1->remove(d);
    list_1->remove(f);
    
    list_2->remove((Collection) list_1);
    
    printf("%s\n", list_1->toString()->toChar());
    printf("%s\n", list_2->toString()->toChar());
    
}

void test3() {
    Country country_1;
    Country country_2;
    Country country_3;
    Country country_4;
    Language lang;
    
    Locale::init();
    
    country_1 = Country::SINGAPORE;
    country_2 = Country::getCountry(840);
    country_3 = Country::getCountry(String::newInstance("CH"));
    country_4 = Country::getCountry(String::newInstance("DEU"));
    lang      = Language::MALAY;
    
    printf("%d %s %s\n", country_1->getNumber(), country_1->getISO2()->toChar(), country_1->getISO3()->toChar());
    printf("%d %s %s\n", country_2->getNumber(), country_2->getISO2()->toChar(), country_2->getISO3()->toChar());
    printf("%d %s %s\n", country_3->getNumber(), country_3->getISO2()->toChar(), country_3->getISO3()->toChar());
    printf("%d %s %s\n", country_4->getNumber(), country_4->getISO2()->toChar(), country_4->getISO3()->toChar());
    printf("%s %s\n", lang->getISO2()->toChar(), lang->getISO3()->toChar());
}

void test4() {
    TimeZone tz_1;
    TimeZone tz_2;
    Calendar cal_1;
    Calendar cal_2;
    List     list_1;
    String   id;
    int      i;
    
    tz_1    = TimeZone::getTimeZone(String::newInstance("Europe/Zurich"));
    tz_2    = TimeZone::getTimeZone(String::newInstance("America/New York"));
    cal_1   = Calendar::newInstance(tz_1);
    cal_2   = Calendar::newInstance(tz_2);
    
    printf("%d.%d.%d %d:%d:%d\n", cal_1->getDay(), cal_1->getMonth(), cal_1->getYear(), cal_1->getHour(), cal_1->getMinute(), cal_1->getSecond());
    printf("%d.%d.%d %d:%d:%d\n", cal_2->getDay(), cal_2->getMonth(), cal_2->getYear(), cal_2->getHour(), cal_2->getMinute(), cal_2->getSecond());
    
    list_1 = TimeZone::getAvailableTimeZones();
    
    for (i = 0; i < list_1->size(); i++) {
        id = ((TimeZone) list_1->get(i))->getId();
        printf("--> %s\n", id->toChar());
    }
}

void test5() {
    String s1;
    String s2;
    
    s1 = "hallo welt";
    
    s2 = s1;
    
    printf("%s\n", s1->toChar());
    
    printf("Vor\n");
    throw Exception::newInstance(String::newInstance("das ist eine exception!"));
    printf("Nach\n");
}

void test6() {
    TimeZone tz;
    TimeZone tz_2;
    TimeZone utc;
    Calendar c_1;
    Calendar c_2;
    Calendar c_3;
    Calendar c_4;
    
    tz   = TimeZone::getLocation(String::newInstance("America/New York"));
    tz_2 = TimeZone::getLocation(String::newInstance("Europe/Zurich"));
    utc  = TimeZone::getLocation("UTC");
    
    // UTC
    c_1 = Calendar::newInstance(utc);
    // Local
    c_2 = Calendar::newInstance(tz);
    // UTC
    c_3 = Calendar::newInstance(c_1->getDay(),
                                c_1->getMonth(),
                                c_1->getYear(),
                                c_1->getHour(),
                                c_1->getMinute(),
                                c_1->getSecond());
    // Local
    c_4 = Calendar::newInstance(c_2->getDay(),
                                c_2->getMonth(),
                                c_2->getYear(),
                                c_2->getHour(),
                                c_2->getMinute(),
                                c_2->getSecond(),
                                tz);
    printf("UTC:      %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_1->getDay(), c_1->getMonth(), c_1->getYear(),
        c_1->getHour(), c_1->getMinute(), c_1->getSecond(),
        (long) c_1->getUnixtime());
    printf("New York: %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_2->getDay(), c_2->getMonth(), c_2->getYear(),
        c_2->getHour(), c_2->getMinute(), c_2->getSecond(),
        (long) c_2->getUnixtime());
    printf("UTC:      %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_3->getDay(), c_3->getMonth(), c_3->getYear(),
        c_3->getHour(), c_3->getMinute(), c_3->getSecond(),
        (long) c_3->getUnixtime());
    printf("New York: %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_4->getDay(), c_4->getMonth(), c_4->getYear(),
        c_4->getHour(), c_4->getMinute(), c_4->getSecond(),
        (long) c_4->getUnixtime());
    
    printf("Diff 1-3: %ld\n", (long) c_1->getUnixtime() - (long) c_3->getUnixtime());
    printf("Diff 2-4: %ld\n", (long) c_2->getUnixtime() - (long) c_4->getUnixtime());
    
    c_1->changeTimeZone(tz_2);
    c_2->changeTimeZone(tz_2);
    c_3->changeTimeZone(tz_2);
    c_4->changeTimeZone(tz_2);
    
    printf("Zürich:   %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_1->getDay(), c_1->getMonth(), c_1->getYear(),
        c_1->getHour(), c_1->getMinute(), c_1->getSecond(),
        (long) c_1->getUnixtime());
    printf("Zürich:   %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_2->getDay(), c_2->getMonth(), c_2->getYear(),
        c_2->getHour(), c_2->getMinute(), c_2->getSecond(),
        (long) c_2->getUnixtime());
    printf("Zürich:   %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_3->getDay(), c_3->getMonth(), c_3->getYear(),
        c_3->getHour(), c_3->getMinute(), c_3->getSecond(),
        (long) c_3->getUnixtime());
    printf("Zürich:   %02d.%02d.%04d %02d:%02d:%02d %10ld\n",
        c_4->getDay(), c_4->getMonth(), c_4->getYear(),
        c_4->getHour(), c_4->getMinute(), c_4->getSecond(),
        (long) c_4->getUnixtime());
}

void test7() {
    String tmp;
    
    tmp = "BANGLADESH          ";
    printf("<LONG>  \"%s\" (%d)\n", tmp->toChar(),              tmp->length());
    printf("<RIGHT> \"%s\" (%d)\n", tmp->trimRight()->toChar(), tmp->trimRight()->length());
    printf("<LEFT>  \"%s\" (%d)\n", tmp->trimLeft()->toChar(),  tmp->trimLeft()->length());
    printf("<BOTH>  \"%s\" (%d)\n", tmp->trim()->toChar(),      tmp->trim()->length());
    printf("--------------------\n");
    
    tmp = "          BANGLADESH";
    printf("<LONG>  \"%s\" (%d)\n", tmp->toChar(),              tmp->length());
    printf("<RIGHT> \"%s\" (%d)\n", tmp->trimRight()->toChar(), tmp->trimRight()->length());
    printf("<LEFT>  \"%s\" (%d)\n", tmp->trimLeft()->toChar(),  tmp->trimLeft()->length());
    printf("<BOTH>  \"%s\" (%d)\n", tmp->trim()->toChar(),      tmp->trim()->length());
    printf("--------------------\n");
    
    tmp = "          BANGLADESH          ";
    printf("<LONG>  \"%s\" (%d)\n", tmp->toChar(),              tmp->length());
    printf("<RIGHT> \"%s\" (%d)\n", tmp->trimRight()->toChar(), tmp->trimRight()->length());
    printf("<LEFT>  \"%s\" (%d)\n", tmp->trimLeft()->toChar(),  tmp->trimLeft()->length());
    printf("<BOTH>  \"%s\" (%d)\n", tmp->trim()->toChar(),      tmp->trim()->length());
}

void test8() {
    List         list;
    ListIterator iter;
    String       str;
    String       tmp;
    
    list = ArrayList::newInstance();
    str  = "hallo";
    
    list->add(str);
    
    iter = (ListIterator) list->iterator();
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
    
    while (iter->hasPrevious()) {
        tmp = (String) iter->previous();
        printf("(-) %s\n", tmp->toChar());
    }
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
    
    while (iter->hasPrevious()) {
        tmp = (String) iter->previous();
        printf("(-) %s\n", tmp->toChar());
    }
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
}

void test9() {
    List            list;
    ListIterator    iter;
    String          a;
    String          b;
    String          c;
    String          d;
    String          tmp;
    
    a = "aaa";
    b = "bbb";
    c = "ccc";
    d = "ddd";
    
    list = ArrayList::newInstance();
    list->add(a);
    list->add(b);
    list->add(c);
    list->add(d);
    
    iter = (ListIterator) list->iterator();
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
    
    while (iter->hasPrevious()) {
        tmp = (String) iter->previous();
        printf("(-) %s\n", tmp->toChar());
    }
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
    
    while (iter->hasPrevious()) {
        tmp = (String) iter->previous();
        printf("(-) %s\n", tmp->toChar());
    }
    
    while (iter->hasNext()) {
        tmp = (String) iter->next();
        printf("(+) %s\n", tmp->toChar());
    }
}

void test10() {
    Calendar calendar;
    TimeZone zone;
    List     zoneList;
    List     locationList;
    Iterator iter;
    String   id;
    String   location;
    
    calendar = Calendar::newInstance();
    zoneList = TimeZone::getAvailableTimeZones();
    iter     = zoneList->iterator();
    
    while (iter->hasNext()) {
        zone = (TimeZone) iter->next();
        calendar->changeTimeZone(zone);
        printf("%-3s %d %d %02d.%02d.%04d %02d:%02d:%02d\n",
            zone->getId()->toChar(), zone->useDaylightTime(), zone->inDaylightTime(calendar),
            calendar->getDay(), calendar->getMonth(), calendar->getYear(),
            calendar->getHour(), calendar->getMinute(), calendar->getSecond());
    }
    
    locationList = TimeZone::getAvailableLocations();
    iter         = locationList->iterator();
    
    while (iter->hasNext()) {
        location = (String) iter->next();
        printf("%s\n", location->toChar());
    }
}

void test11() {
    ArrayList list_a;
    ArrayList list_b;
    Iterator  iter;
    String    str;
    Clock     clock_a;
    Clock     clock_b;
    
    list_a = ArrayList::newInstance();
    
    clock_a = System::getTime();
    list_a->add(String::newInstance("ccc"));
    list_a->add(String::newInstance("AAA"));
    list_a->add(String::newInstance("1a3"));
    list_a->add(String::newInstance("ddd"));
    list_a->add(String::newInstance("CCC"));
    list_a->add(String::newInstance("bbb"));
    list_a->add(String::newInstance("123"));
    list_a->add(String::newInstance("aaA"));
    list_a->add(String::newInstance("eee"));
    list_a->add(String::newInstance("aaaA"));
    list_a->add(String::newInstance("fff"));
    list_a->add(String::newInstance("aAA"));
    list_a->add(String::newInstance("!?%"));
    list_a->add(String::newInstance("aaaaa"));
    list_a->add(String::newInstance("aaa"));
    list_a->add(String::newInstance("aaaa"));
    list_a->add(String::newInstance("234"));
    list_a->add(String::newInstance("BBB"));
    
    list_b = (ArrayList) list_a->sort(StringComparator::newInstance(StringComparator::IGNORE_CASE));
    clock_b = System::getTime();
    
    iter   = list_b->iterator();
    
    while (iter->hasNext()) {
        str = (String) iter->next();
        printf("==> %3s <==\n", str->toChar());
    }
    
    printf("Time:   %ld\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
}

void test12() {
    char h1, a1, l1, l2, o1, w1, e1, l3, t1, x1;
    h1 = Character::toUpperCase('h');
    a1 = Character::toLowerCase('a');
    l1 = Character::toLowerCase('L');
    l2 = Character::toLowerCase('l');
    o1 = Character::toLowerCase('o');
    
    w1 = Character::toUpperCase('w');
    e1 = Character::toLowerCase('E');
    l3 = Character::toLowerCase('l');
    t1 = Character::toLowerCase('T');
    x1 = Character::toLowerCase('!');
    
    printf("%c%c%c%c%c %c%c%c%c%c\n",h1, a1, l1, l2, o1, w1, e1, l3, t1, x1);
}

void test13() {
    String tmp;
    
    tmp = "";
    
    tmp  = tmp + "Andreas Bachmann\n" + "Im Baechli 51\n" + "8303 Bassersdorf";
    
    printf("\n%#010x %#010x\n%s\n\n", (unsigned int) &tmp, (unsigned int) tmp.getImplementation(), tmp->toChar());
}

void test14() {
    ByteArray array;
    int       i;
    byte      counter;
    
    array   = ByteArray::newInstance(5);
    counter = 'a';
    
    printf("length: %d\n", array->length());
    
    for (i = 0; i < array->length(); i++) {
        array[i] = counter++;
    }
    for (i = 0; i < array->length(); i++) {
        printf("%c (%d)\n", array[i], array[i]);
    }
}

void test15() {
    String a;
    String b;
    String c;
    String d;
    
    a = "";
    b = "         ";
    c = "        a";
    d = "d        ";
    
    printf("==> %d: \"%s\"\n", a->isEmpty(), a->toChar());
    printf("==> %d: \"%s\"\n", b->isEmpty(), b->toChar());
    printf("==> %d: \"%s\"\n", c->isEmpty(), c->toChar());
    printf("==> %d: \"%s\"\n", d->isEmpty(), d->toChar());
}

void test16() {
    String a;
    String b;
    const char*  c;
    char*  d;
    int    i;
    
    c = "hallo welt!";
    d = new char[20];
    strcpy(d, "hallo welt!");
    
    a = String::newInstance(c);
    b = String::newInstance(d, false);
    
    for (i = 0; i < 11; i++) {
        printf("%#010x %c\n", &(c[i]), c[i]);
    }
    printf("\n");
    
    for (i = 0; i < 11; i++) {
        printf("%#010x %c\n", &(d[i]), d[i]);
    }
    printf("\n");
    
    
    printf("==> %s\n", a->toChar());
    printf("==> %s\n", b->toChar());
    
}

void test17() {
    String a;
    int    b;
    
    b = 1600;
    a = String::valueOf(b);
    
    printf("==> %s\n", a->toChar());
}

void test18() {
    String a;
    
    a = "11a22b33c44d55e66f77g88h99";
    
    printf("==> %d\n", a->isDigit());
    a = a->digitFormat();
    printf("==> %d\n", a->isDigit());
    printf("==> %s\n", a->toChar());
    printf("==> %s\n", a->currencyFormat()->toChar());
}

void test19() {
    String s;
    double d;
    
    s = "-7346.634";
    d = Double::parseDouble(s);
    
    printf("==> %lf\n", d);
    
    d *= -1.0;
    s = String::valueOf(d, 3);
    printf("==> %s\n", s->toChar());
}

void test20() {
    Calendar       calendar;
    TimeZone       tz;
    CalendarFormat usFormat;
    CalendarFormat europeanFormat;
    String         usDate;
    String         europeanDate;
    
    tz             = TimeZone::getLocation(String::newInstance("Europe/Zurich"));
    calendar       = Calendar::newInstance(tz);
    usFormat       = CalendarFormat::newInstance(String::newInstance("MM/dd/yyyy ZZ hh:mm:ss a "));
    europeanFormat = CalendarFormat::newInstance(String::newInstance("dd.MM.yyyy ZZ HH:mm:ss"));
    usDate         = usFormat->format(calendar);
    europeanDate   = europeanFormat->format(calendar);
    
    printf("US: %s\n", usDate->toChar());
    printf("EU: %s\n", europeanDate->toChar());
}

void test21() {
    Calendar       cal1;
    Calendar       cal2;
    Calendar       cal3;
    Calendar       cal4;
    Calendar       cal5;
    Calendar       cal6;
    CalendarFormat form1;
    CalendarFormat form2;
    CalendarFormat form3;
    CalendarFormat form4;
    
    cal1    = Calendar::newInstance(1, 25, 2006, 23, 59, 59);
    cal2    = Calendar::newInstance(1, 25, 2006, 0, 0, 0);
    cal3    = Calendar::newInstance(1, 25, 2006, 0, 0, 1);
    cal4    = Calendar::newInstance(1, 25, 2006, 11, 59, 59);
    cal5    = Calendar::newInstance(1, 25, 2006, 12, 0, 0);
    cal6    = Calendar::newInstance(1, 25, 2006, 12, 0, 1);
    
    form1   = CalendarFormat::newInstance(String::newInstance("HH:mm:ss  "));
    form2   = CalendarFormat::newInstance(String::newInstance("kk:mm:ss  "));
    form3   = CalendarFormat::newInstance(String::newInstance("KK:mm:ss a"));
    form4   = CalendarFormat::newInstance(String::newInstance("hh:mm:ss a"));
    
    printf("\n=== M I D N I G H T ===\n\n");
    
    printf("00h - 23h: %s\n",   form1->format(cal1)->toChar());
    printf("           %s\n",   form1->format(cal2)->toChar());
    printf("           %s\n\n", form1->format(cal3)->toChar());
    
    printf("01h - 24h: %s\n",   form2->format(cal1)->toChar());
    printf("           %s\n",   form2->format(cal2)->toChar());
    printf("           %s\n\n", form2->format(cal3)->toChar());
    
    printf("00h - 11h: %s\n",   form3->format(cal1)->toChar());
    printf("           %s\n",   form3->format(cal2)->toChar());
    printf("           %s\n\n", form3->format(cal3)->toChar());
    
    printf("01h - 12h: %s\n",   form4->format(cal1)->toChar());
    printf("           %s\n",   form4->format(cal2)->toChar());
    printf("           %s\n\n", form4->format(cal3)->toChar());
    
    printf("\n=== N O O N ===\n\n");
    
    printf("00h - 23h: %s\n",   form1->format(cal4)->toChar());
    printf("           %s\n",   form1->format(cal5)->toChar());
    printf("           %s\n\n", form1->format(cal6)->toChar());
    
    printf("01h - 24h: %s\n",   form2->format(cal4)->toChar());
    printf("           %s\n",   form2->format(cal5)->toChar());
    printf("           %s\n\n", form2->format(cal6)->toChar());
    
    printf("00h - 11h: %s\n",   form3->format(cal4)->toChar());
    printf("           %s\n",   form3->format(cal5)->toChar());
    printf("           %s\n\n", form3->format(cal6)->toChar());
    
    printf("01h - 12h: %s\n",   form4->format(cal4)->toChar());
    printf("           %s\n",   form4->format(cal5)->toChar());
    printf("           %s\n\n", form4->format(cal6)->toChar());
}

void test22() {
    Country  country;
    Language language;
    Iterator iter1;
    Iterator iter2;
    
    iter1 = Language::getAvailableLanguages()->iterator();
    while (iter1->hasNext()) {
        language = (Language) iter1->next();
        iter2    = Country::getAvailableCountries()->iterator();
        try {
            printf("%s\n", language->getDisplayName(language)->toChar());
            while (iter2->hasNext()) {
                country = (Country) iter2->next();
                printf("  %s\n", country->getDisplayName(language)->toChar());
            }            
        } catch (MissingResourceException e) {
            printf("Missing Resource\n");
        }
        printf("\n");
    }
}

void test23() {
    Language language;
    Locale   locale;
    Iterator iter1;
    Iterator iter2;
    
    iter1 = Language::getAvailableLanguages()->iterator();
    while (iter1->hasNext()) {
        language = (Language) iter1->next();
        iter2 = Locale::getAvailableLocales()->iterator();
        try {
            while (iter2->hasNext()) {
                locale = (Locale) iter2->next();
                printf(" [%s] %s\n", locale->toString()->toChar(), locale->getDisplayName(language)->toChar());
            }
        } catch (MissingResourceException e) {
            printf("Missing Resource\n");
        }
        printf("\n");
    }
}

void test24() {
    List   list;
    String a;
    String b;
    String c;
    String result;
    int    i;
    
    list = ArrayList::newInstance(3);
    a    = "aaa";
    b    = "bbb";
    c    = "ccc";
    
    list->add(a);
    list->add(b);
    list->add(c);
    
    for (i = 0; i < list->size(); i++) {
        result = list[i];
        printf("==> %s\n", result->toChar());
    }
}

void test25() {
    TimeZone       zone;
    Calendar       calendar;
    CalendarFormat format;
    Locale         locale;
    Iterator       iter;
    int            i;
    int            k;
    
    //zone     = TimeZone::getLocation(String::newInstance("Asia/Hong Kong"));
    zone     = TimeZone::getLocation(String::newInstance("America/New York"));
    calendar = Calendar::newInstance(zone);
    
    iter = Locale::getAvailableLocales()->iterator();
    while (iter->hasNext()) {
        locale = (Locale) iter->next();
        printf("%s\n", locale->getDisplayName()->toChar());
        format = CalendarFormat::newInstance(locale, CalendarFormat::DATE_SHORT | CalendarFormat::TIME_SHORT);
        printf("  %s\n", format->format(calendar)->toChar());
        format = CalendarFormat::newInstance(locale, CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
        printf("  %s\n", format->format(calendar)->toChar());
        format = CalendarFormat::newInstance(locale, CalendarFormat::DATE_LONG | CalendarFormat::TIME_LONG);
        printf("  %s\n", format->format(calendar)->toChar());
        format = CalendarFormat::newInstance(locale, CalendarFormat::DATE_FULL | CalendarFormat::TIME_FULL);
        printf("  %s\n", format->format(calendar)->toChar());
        printf("\n");
    }
    
}

void test26() {
    Locale       locale;
    NumberFormat format;
    Iterator     iter;
    long         number1;
    double       number2;
    double       number3;
    double       number4;
    double       number5;
    int          k;
    
    number1 = 1234567;
    number2 = 1234567.0;
    number3 = 1234567.12;
    number4 = 1234567.1;
    number5 = 1234567.1234;
    
    format = NumberFormat::newInstance("##0.00");
    printf("no special formating: %s\n", format->format(number5)->toChar());
    
    iter = Locale::getAvailableLocales()->iterator();
    while (iter->hasNext()) {
        locale = (Locale) iter->next();
        printf("%s\n", locale->getDisplayName()->toChar());
        for (k = 0; k < NumberFormat::STYLE_LENGTH; k++) {
            switch (k) {
                case NumberFormat::DECIMAL:  printf("  Decimal\n");  break;
                case NumberFormat::INTEGER:  printf("  Integer\n");  break;
                case NumberFormat::CURRENCY: printf("  Currency\n"); break;
                case NumberFormat::PERCENT:  printf("  Percent\n");  break;
            }
            format = NumberFormat::newInstance(k, locale);
            printf("  %s\n", format->format(number1)->toChar());
            printf("  %s\n", format->format(number2)->toChar());
            printf("  %s\n", format->format(number3)->toChar());
            printf("  %s\n", format->format(number4)->toChar());
            printf("  %s\n", format->format(number5)->toChar());
            printf("\n");
        }
        printf("\n");
    }
}

void test27() {
    List test;
    
    printf("--- ArrayList::newInstance()\n");
    test = ArrayList::newInstance();
    printf("--- LinkedList::newInstance()\n");
    test = LinkedList::newInstance();
    printf("--- List::put()\n");
    test->add(Pointer::newInstance(0));
    printf("--- null\n");
    test = null;
    printf("--- ArrayList::newInstance()\n");
    test = ArrayList::newInstance();
    printf("--- List::put()\n");
    test->add(Pointer::newInstance(0));
    printf("--- End\n");
}

void test28() {
    Map      map;
    Clock    clock_a;
    Clock    clock_b;
    String   retval;
    
    map = SortedMap::newInstance(StringComparator::newInstance(StringComparator::IGNORE_CASE));
    
    clock_a = System::getTime();
    map->put(String::newInstance("ccc"),   String::newInstance("value"));
    map->put(String::newInstance("AAA"),   String::newInstance("value"));
    map->put(String::newInstance("1a3"),   String::newInstance("value"));
    map->put(String::newInstance("ddd"),   String::newInstance("value"));
    map->put(String::newInstance("CCC"),   String::newInstance("value"));
    map->put(String::newInstance("bbb"),   String::newInstance("value"));
    map->put(String::newInstance("123"),   String::newInstance("value"));
    map->put(String::newInstance("aaA"),   String::newInstance("value"));
    map->put(String::newInstance("eee"),   String::newInstance("value"));
    map->put(String::newInstance("aaaA"),  String::newInstance("value"));
    map->put(String::newInstance("fff"),   String::newInstance("value"));
    map->put(String::newInstance("aAA"),   String::newInstance("value"));
    map->put(String::newInstance("!?%"),   String::newInstance("value"));
    map->put(String::newInstance("aaaaa"), String::newInstance("value"));
    map->put(String::newInstance("aaa"),   String::newInstance("value"));
    map->put(String::newInstance("aaaa"),  String::newInstance("value"));
    map->put(String::newInstance("234"),   String::newInstance("value"));
    map->put(String::newInstance("BBB"),   String::newInstance("value"));
    clock_b = System::getTime();
    
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
    
    clock_a = System::getTime();
    retval = (String) map->get(String::newInstance("aaaaa"));
    clock_b = System::getTime();
    printf("Get:    %s\n", retval->toChar());
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
    
    clock_a = System::getTime();
    retval = (String) map->remove(String::newInstance("aaaaa"));
    clock_b = System::getTime();
    printf("Remove: %s\n", retval->toChar());
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
}

void test29() {
    Map      map;
    Clock    clock_a;
    Clock    clock_b;
    String   retval;
    
    map = HashMap::newInstance();
    
    clock_a = System::getTime();
    map->put(String::newInstance("ccc"),   String::newInstance("value"));
    map->put(String::newInstance("AAA"),   String::newInstance("value"));
    map->put(String::newInstance("1a3"),   String::newInstance("value"));
    map->put(String::newInstance("ddd"),   String::newInstance("value"));
    map->put(String::newInstance("CCC"),   String::newInstance("value"));
    map->put(String::newInstance("bbb"),   String::newInstance("value"));
    map->put(String::newInstance("123"),   String::newInstance("value"));
    map->put(String::newInstance("aaA"),   String::newInstance("value"));
    map->put(String::newInstance("eee"),   String::newInstance("value"));
    map->put(String::newInstance("aaaA"),  String::newInstance("value"));
    map->put(String::newInstance("fff"),   String::newInstance("value"));
    map->put(String::newInstance("aAA"),   String::newInstance("value"));
    map->put(String::newInstance("!?%"),   String::newInstance("value"));
    map->put(String::newInstance("aaaaa"), String::newInstance("value"));
    map->put(String::newInstance("aaa"),   String::newInstance("value"));
    map->put(String::newInstance("aaaa"),  String::newInstance("value"));
    map->put(String::newInstance("234"),   String::newInstance("value"));
    map->put(String::newInstance("BBB"),   String::newInstance("value"));
    clock_b = System::getTime();
    
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
    
    clock_a = System::getTime();
    retval = (String) map->get(String::newInstance("aaaaa"));
    clock_b = System::getTime();
    printf("Get:    %s\n", retval->toChar());
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
    
    clock_a = System::getTime();
    retval = (String) map->remove(String::newInstance("aaaaa"));
    clock_b = System::getTime();
    printf("Remove: %s\n", retval->toChar());
    printf("Time:   %d ns\n\n", (clock_b->getNanosecond() - clock_a->getNanosecond()));
}

void test30b(Object abc) {
    String str;
    
    str = (String) abc;
    
    printf("--> %s\n", str->toChar());
}

void test30() {
    List     list;
    Iterator iter;
    String   str;
    String   x;
    
    list = ArrayList::newInstance();
    
    str  = "hallo";
    list->add(str);
    str  = "welt";
    list->add(str);
    str  = "abc";
    list->add(str);
    
    str  = null;
    list->add(str);
    
    str  = "xyz";
    list->add(str);
    str  = "Andreas";
    list->add(str);
    
    x    = str;
    
    str  = "Bachmann";
    list->add(str);
    str  = "Zuerich";
    list->add(str);
    
    str  = null;
    list->add(str);
    
    str  = "Bassersdorf";
    list->add(str);
    str  = "Ich";
    list->add(str);
    
    test30b((String) "hallo welt");
    
    iter = list->iterator();
    while (iter->hasNext()) {
        str = (String) iter->next();
        if (str == x) {
            printf("==> %s\n", str->toChar());
        } else if (str != null) {
            printf("--> %s\n", str->toChar());
        }
    }
}

void test31() {
    String str;
    
    //     0123456789012345678901234567
    str = "Hallo Welt Andreas Bachmann";
    printf("'%s'\n", str->substring( 0,  5)->toChar());
    printf("'%s'\n", str->substring( 6, 10)->toChar());
    printf("'%s'\n", str->substring(11, 18)->toChar());
    printf("'%s'\n", str->substring(19, 27)->toChar());
}

void test32() {
    Calendar        c;
    CalendarFormat  chFormat;
    CalendarFormat  usFormat;
    CalendarFormat  genFormat;
    CalendarFormat  dateFormat;
    String          chCalendar;
    String          usCalendar;
    String          genCalendar;
    String          dateCalendar;
    
    // Now
    c            = Calendar::newInstance(TimeZone::getLocation("Europe/Zurich"));
    chFormat     = CalendarFormat::newInstance(Locale::getLocale("de_CH"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    usFormat     = CalendarFormat::newInstance(Locale::getLocale("en_US"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    genFormat    = CalendarFormat::newInstance("yyyyMMddHHmmss");
    dateFormat   = CalendarFormat::newInstance("yyyyMMdd");
    chCalendar   = chFormat->format(c);
    usCalendar   = usFormat->format(c);
    genCalendar  = genFormat->format(c);
    dateCalendar = dateFormat->format(c);
    
    try {
        c           = chFormat->parseCalendar(chCalendar);
        printf("CH:   %s\n", chCalendar->toChar());
        printf("ISO:  %02d.%02d.%04d %02d:%02d:%02d\n\n", c->getDay(), c->getMonth(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = usFormat->parseCalendar(usCalendar);
        printf("US:   %s\n", usCalendar->toChar());
        printf("ISO:  %02d/%02d/%04d %02d:%02d:%02d\n\n", c->getMonth(), c->getDay(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = genFormat->parseCalendar(genCalendar);
        printf("GEN:  %s\n", genCalendar->toChar());
        printf("ISO:  %04d%02d%02d%02d%02d%02d\n\n", c->getYear(), c->getMonth(), c->getDay(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = chFormat->parseCalendar(dateCalendar);
    } catch (ParseException e ) {
        printf("[ERROR] %s\n\n", e->getMessage()->toChar());
    }
    
    // Noon
    c            = Calendar::newInstance(6, 7, 2006, 12, 0, 0);
    chFormat     = CalendarFormat::newInstance(Locale::getLocale("de_CH"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    usFormat     = CalendarFormat::newInstance(Locale::getLocale("en_US"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    genFormat    = CalendarFormat::newInstance("yyyyMMddHHmmss");
    dateFormat   = CalendarFormat::newInstance("yyyyMMdd");
    chCalendar   = chFormat->format(c);
    usCalendar   = usFormat->format(c);
    genCalendar  = genFormat->format(c);
    dateCalendar = dateFormat->format(c);
    
    try {
        c           = chFormat->parseCalendar(chCalendar);
        printf("CH:   %s\n", chCalendar->toChar());
        printf("ISO:  %02d.%02d.%04d %02d:%02d:%02d\n\n", c->getDay(), c->getMonth(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = usFormat->parseCalendar(usCalendar);
        printf("US:   %s\n", usCalendar->toChar());
        printf("ISO:  %02d/%02d/%04d %02d:%02d:%02d\n\n", c->getMonth(), c->getDay(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = genFormat->parseCalendar(genCalendar);
        printf("GEN:  %s\n", genCalendar->toChar());
        printf("ISO:  %04d%02d%02d%02d%02d%02d\n\n", c->getYear(), c->getMonth(), c->getDay(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = chFormat->parseCalendar(dateCalendar);
    } catch (ParseException e ) {
        printf("[ERROR] %s\n\n", e->getMessage()->toChar());
    }
    
    // Midnight
    c            = Calendar::newInstance(6, 7, 2006, 0, 0, 0);
    chFormat     = CalendarFormat::newInstance(Locale::getLocale("de_CH"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    usFormat     = CalendarFormat::newInstance(Locale::getLocale("en_US"), CalendarFormat::DATE_MEDIUM | CalendarFormat::TIME_MEDIUM);
    genFormat    = CalendarFormat::newInstance("yyyyMMddHHmmss");
    dateFormat   = CalendarFormat::newInstance("yyyyMMdd");
    chCalendar   = chFormat->format(c);
    usCalendar   = usFormat->format(c);
    genCalendar  = genFormat->format(c);
    dateCalendar = dateFormat->format(c);
    
    try {
        c           = chFormat->parseCalendar(chCalendar);
        printf("CH:   %s\n", chCalendar->toChar());
        printf("      %02d.%02d.%04d %02d:%02d:%02d\n\n", c->getDay(), c->getMonth(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = usFormat->parseCalendar(usCalendar);
        printf("US:   %s\n", usCalendar->toChar());
        printf("      %02d/%02d/%04d %02d:%02d:%02d\n\n", c->getMonth(), c->getDay(), c->getYear(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = genFormat->parseCalendar(genCalendar);
        printf("GEN:  %s\n", genCalendar->toChar());
        printf("      %04d%02d%02d%02d%02d%02d\n\n", c->getYear(), c->getMonth(), c->getDay(), c->getHour(), c->getMinute(), c->getSecond());
        
        c           = chFormat->parseCalendar(dateCalendar);
    } catch (ParseException e ) {
        printf("[ERROR] %s\n\n", e->getMessage()->toChar());
    }
}

void test33() {
    NumberFormat format;
    double       number;
    double       result;
    String       str;
    
    number = 1234567.1234;
    
    format = NumberFormat::newInstance(NumberFormat::CURRENCY, Locale::getLocale("en_US"));
    str    = format->format(number);
    result = format->parseDouble(str);
    
    printf("Original: %.4f\n", number);
    printf("String:   %s\n", str->toChar());
    printf("Result:   %.2f\n", result);
}

void test34() {
    Map      map;
    Clock    clock_a;
    Clock    clock_b;
    Iterator iter;
    
    map = SortedMap::newInstance(StringComparator::newInstance(StringComparator::IGNORE_CASE));
    
    clock_a = System::getTime();
    map->put(String::newInstance("ccc"),   String::newInstance("value"));
    map->put(String::newInstance("2'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("2,000,000.00"), String::newInstance("value"));
    map->put(String::newInstance("AAA"),   String::newInstance("value"));
    //map->put(String::newInstance("1a3"),   String::newInstance("value"));
    map->put(String::newInstance("ddd"),   String::newInstance("value"));
    map->put(String::newInstance("CCC"),   String::newInstance("value"));
    map->put(String::newInstance("bbb"),   String::newInstance("value"));
    map->put(String::newInstance("123.00"),   String::newInstance("value"));
    map->put(String::newInstance("1.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaA"),   String::newInstance("value"));
    map->put(String::newInstance("3'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000,000.00"),   String::newInstance("value"));
    map->put(String::newInstance("aaaA"),  String::newInstance("value"));
    map->put(String::newInstance("fff"),   String::newInstance("value"));
    map->put(String::newInstance("2.00"),     String::newInstance("value"));
    map->put(String::newInstance("aAA"),   String::newInstance("value"));
    map->put(String::newInstance("!?%"),   String::newInstance("value"));
    map->put(String::newInstance("aaaaa"), String::newInstance("value"));
    map->put(String::newInstance("3.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaa"),   String::newInstance("value"));
    map->put(String::newInstance("3'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000.00"), String::newInstance("value"));
    map->put(String::newInstance("aaaa"),  String::newInstance("value"));
    map->put(String::newInstance("234.00"),   String::newInstance("value"));
    map->put(String::newInstance("BBB"),   String::newInstance("value"));
    clock_b = System::getTime();
    
    printf("%s", map->toString()->toChar());
    
    iter = map->keyIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    printf("\n");
    
    iter = map->valueIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    
}

void test35() {
    String test;
    
    test = "abcdefaghijcdeka";
    
    printf("==> '%s'\n", test->toChar());
    printf("first     'a':   %d\n", test->indexOf('a'));
    printf("last      'a':   %d\n", test->lastIndexOf('a'));
    printf("2nd index 'a':   %d\n", test->indexOf('a', 1));
    printf("first     'cde': %d\n", test->indexOf("cde"));
    printf("2nd index 'cde': %d\n", test->indexOf("cde", 3));
    
}

void test36() {
    StringPadding padding;
    String        str;
    
    // 1
    padding = StringPadding::newInstance(35, '*');
    str     = padding->doPadding("Hallo");
    
    printf("==> %s (%d)\n", str->toChar(), str->length());
    
    // 2
    padding = StringPadding::newInstance(35, '*', true);
    str     = padding->doPadding("Hallo");
    
    printf("==> %s (%d)\n", str->toChar(), str->length());
    
    // 3
    padding = StringPadding::newInstance(35, '*');
    str     = padding->doPadding("12345678901234567890123456789012345");
    
    printf("==> %s (%d)\n", str->toChar(), str->length());
    
    // 4
    padding = StringPadding::newInstance(35, '*', true);
    str     = padding->doPadding("12345678901234567890123456789012345");
    
    printf("==> %s (%d)\n", str->toChar(), str->length());
}

void test37() {
    String          str;
    StringTokenizer tokenizer;
    
    str       = "abc";
    tokenizer = StringTokenizer::newInstance(str, "***");
    
    while (tokenizer->hasMoreTokens()) {
        printf("==> '%s'\n", tokenizer->nextToken()->toChar());
    }
    
    printf("---\n");
    
    str       = "abc***xyz***ab*cd**def***hallo";
    tokenizer = StringTokenizer::newInstance(str, "***");
    
    while (tokenizer->hasMoreTokens()) {
        printf("==> '%s'\n", tokenizer->nextToken()->toChar());
    }
    
    printf("---\n");
    
    str       = "***abc***xyz***ab*cd**def***hallo***";
    tokenizer = StringTokenizer::newInstance(str, "***");
    
    while (tokenizer->hasMoreTokens()) {
        printf("==> '%s'\n", tokenizer->nextToken()->toChar());
    }
    
    printf("---\n");
    
    str       = " ***abc***xyz***ab*cd**def***hallo*** ";
    tokenizer = StringTokenizer::newInstance(str, "***");
    
    while (tokenizer->hasMoreTokens()) {
        printf("==> '%s'\n", tokenizer->nextToken()->toChar());
    }
}

void test38() {
    Clock c1;
    Clock c2;
    long  diff;
    
    c1   = System::getTime();
    sleep(1);
    c2   = System::getTime();
    diff = Clock::diff(c1, c2);
    printf("==> %ld\n", diff);
}

void test39() {
    List list_a;
    List list_b;
    
    list_a = ArrayList::newInstance();
    
    list_a->add(String::newInstance("aaa")); // 0
    list_a->add(String::newInstance("bbb")); // 1
    list_a->add(String::newInstance("ccc")); // 2
    list_a->add(String::newInstance("xxx")); // 3
    list_a->add(String::newInstance("yyy")); // 4
    list_a->add(String::newInstance("zzz")); // 5
    printf("*** List A ************************************\n%s\n", list_a->toString()->toChar());
    list_a->swap(0, 1);
    printf("%s\n", list_a->toString()->toChar());
    list_a->swap(4, 5);
    printf("%s\n", list_a->toString()->toChar());
    list_a->swap(2, 3);
    printf("%s\n", list_a->toString()->toChar());
    
    list_b = LinkedList::newInstance();
    
    list_b->add(String::newInstance("aaa")); // 0
    list_b->add(String::newInstance("bbb")); // 1
    list_b->add(String::newInstance("ccc")); // 2
    list_b->add(String::newInstance("xxx")); // 3
    list_b->add(String::newInstance("yyy")); // 4
    list_b->add(String::newInstance("zzz")); // 5
    printf("*** List B ************************************\n%s\n", list_b->toString()->toChar());
    list_b->swap(0, 1);
    printf("%s\n", list_b->toString()->toChar());
    list_b->swap(4, 5);
    printf("%s\n", list_b->toString()->toChar());
    list_b->swap(2, 3);
    printf("%s\n", list_b->toString()->toChar());
    
}

void test40() {
    Map      map;
    Iterator iter;
    
    map = SortedMap::newInstance(StringComparator::newInstance(), 200);
    
    map->put(String::newInstance("ccc"),   String::newInstance("value"));
    map->put(String::newInstance("2'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("2,000,000.00"), String::newInstance("value"));
    map->put(String::newInstance("AAA"),   String::newInstance("value"));
    map->put(String::newInstance("ddd"),   String::newInstance("value"));
    map->put(String::newInstance("CCC"),   String::newInstance("value"));
    map->put(String::newInstance("bbb"),   String::newInstance("value"));
    map->put(String::newInstance("123.00"),   String::newInstance("value"));
    map->put(String::newInstance("1.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaA"),   String::newInstance("value"));
    map->put(String::newInstance("3'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000,000.00"),   String::newInstance("value"));
    map->put(String::newInstance("aaaA"),  String::newInstance("value"));
    map->put(String::newInstance("fff"),   String::newInstance("value"));
    map->put(String::newInstance("2.00"),     String::newInstance("value"));
    map->put(String::newInstance("aAA"),   String::newInstance("value"));
    map->put(String::newInstance("!?%"),   String::newInstance("value"));
    map->put(String::newInstance("aaaaa"), String::newInstance("value"));
    map->put(String::newInstance("3.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaa"),   String::newInstance("value"));
    map->put(String::newInstance("3'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000.00"), String::newInstance("value"));
    map->put(String::newInstance("aaaa"),  String::newInstance("value"));
    map->put(String::newInstance("234.00"),   String::newInstance("value"));
    map->put(String::newInstance("BBB"),   String::newInstance("value"));
    
    iter = map->keyIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    printf("\n");
    
    iter = map->valueIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    
    map->clear();
    
    map->put(String::newInstance("ccc"),   String::newInstance("value"));
    map->put(String::newInstance("2'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("2,000,000.00"), String::newInstance("value"));
    map->put(String::newInstance("AAA"),   String::newInstance("value"));
    map->put(String::newInstance("ddd"),   String::newInstance("value"));
    map->put(String::newInstance("CCC"),   String::newInstance("value"));
    map->put(String::newInstance("bbb"),   String::newInstance("value"));
    map->put(String::newInstance("123.00"),   String::newInstance("value"));
    map->put(String::newInstance("1.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaA"),   String::newInstance("value"));
    map->put(String::newInstance("3'000'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000,000.00"),   String::newInstance("value"));
    map->put(String::newInstance("aaaA"),  String::newInstance("value"));
    map->put(String::newInstance("fff"),   String::newInstance("value"));
    map->put(String::newInstance("2.00"),     String::newInstance("value"));
    map->put(String::newInstance("aAA"),   String::newInstance("value"));
    map->put(String::newInstance("!?%"),   String::newInstance("value"));
    map->put(String::newInstance("aaaaa"), String::newInstance("value"));
    map->put(String::newInstance("3.00"),     String::newInstance("value"));
    map->put(String::newInstance("aaa"),   String::newInstance("value"));
    map->put(String::newInstance("3'000.00"), String::newInstance("value"));
    map->put(String::newInstance("3,000.00"), String::newInstance("value"));
    map->put(String::newInstance("aaaa"),  String::newInstance("value"));
    map->put(String::newInstance("234.00"),   String::newInstance("value"));
    map->put(String::newInstance("BBB"),   String::newInstance("value"));
    
    iter = map->keyIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    printf("\n");
    
    iter = map->valueIterator();
    while (iter->hasNext()) {
        printf("==> %s\n", iter->next()->toString()->toChar());
    }
    
}

void test41() {
    Thread thread;
    Clock  begin;
    Clock  end;
    
    thread = Thread::newInstance();
    begin  = System::getTime();
    
    thread->start();
    thread->sleep(2, 500);
    thread->join();
    
    end = System::getTime();
    
    printf("thread sleep = %ld\n", Clock::diff(begin, end));
}

void test42() {
    File test;
    
    test = File::newInstance("test.txt");
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    test->createFile();
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    test->remove();
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    
    try {
        test->remove();
    } catch (FileNotFoundException e) {
        printf("ERROR: %s\n", e->getMessage()->toChar());
    }
    
    test = File::newInstance("test_dir");
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    test->createDirectory();
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    test->remove();
    printf("File does%s exist\n", test->exists() ? "" : " NOT");
    
    try {
        test->remove();
    } catch (FileNotFoundException e) {
        printf("ERROR: %s\n", e->getMessage()->toChar());
    }
    
    
    
}

int main(int argc, char** argv) {
    try {
        printf("********************************************************************************\n");
        printf("Test 1\n");
        test1();
        printf("********************************************************************************\n");
        printf("Test 2\n");
        test2();
        printf("********************************************************************************\n");
        printf("Test 3\n");
        test3();
        printf("********************************************************************************\n");
        printf("Test 4\n");
        test4();
        printf("********************************************************************************\n");
        printf("Test 5\n");
        try {
            test5();
        } catch (Exception e) {
            printf("Exception %s\n\n", e->getMessage()->toChar());
            printf("%s\n", e->printFullInfos()->toChar());
        }
        printf("********************************************************************************\n");
        printf("Test 6\n");
        test6();
        printf("********************************************************************************\n");
        printf("Test 7\n");
        test7();
        printf("********************************************************************************\n");
        printf("Test 8\n");
        test8();
        printf("********************************************************************************\n");
        printf("Test 9\n");
        test9();
        printf("********************************************************************************\n");
        printf("Test 10\n");
        test10();
        printf("********************************************************************************\n");
        printf("Test 11\n");
        test11();
        printf("********************************************************************************\n");
        printf("Test 12\n");
        test12();
        printf("********************************************************************************\n");
        printf("Test 13\n");
        test13();
        printf("********************************************************************************\n");
        printf("Test 14\n");
        test14();
        printf("********************************************************************************\n");
        printf("Test 15\n");
        test15();
        printf("********************************************************************************\n");
        printf("Test 16\n");
        test16();
        printf("********************************************************************************\n");
        printf("Test 17\n");
        test17();
        printf("********************************************************************************\n");
        printf("Test 18\n");
        test18();
        printf("********************************************************************************\n");
        printf("Test 19\n");
        test19();
        printf("********************************************************************************\n");
        printf("Test 20\n");
        test20();
        printf("********************************************************************************\n");
        printf("Test 21\n");
        test21();
        printf("********************************************************************************\n");
        printf("Test 22\n");
        test22();
        printf("********************************************************************************\n");
        printf("Test 23\n");
        test23();
        printf("********************************************************************************\n");
        printf("Test 24\n");
        test24();
        printf("********************************************************************************\n");
        printf("Test 25\n");
        test25();
        printf("********************************************************************************\n");
        printf("Test 26\n");
        test26();
        printf("********************************************************************************\n");
        printf("Test 27\n");
        test27();
        printf("********************************************************************************\n");
        printf("Test 28\n");
        test28();
        printf("********************************************************************************\n");
        printf("Test 29\n");
        test29();
        printf("********************************************************************************\n");
        printf("Test 30\n");
        test30();
        printf("********************************************************************************\n");
        printf("Test 31\n");
        test31();
        printf("********************************************************************************\n");
        printf("Test 32\n");
        test32();
        printf("********************************************************************************\n");
        printf("Test 33\n");
        test33();
        printf("********************************************************************************\n");
        printf("Test 34\n");
        test34();
        printf("********************************************************************************\n");
        printf("Test 35\n");
        test35();
        printf("********************************************************************************\n");
        printf("Test 36\n");
        test36();
        printf("********************************************************************************\n");
        printf("Test 37\n");
        test37();
        printf("********************************************************************************\n");
        printf("Test 38\n");
        test38();
        printf("********************************************************************************\n");
        printf("Test 39\n");
        test39();
        printf("********************************************************************************\n");
        printf("Test 40\n");
        test40();
        printf("********************************************************************************\n");
        printf("Test 41\n");
        test41();
        printf("********************************************************************************\n");
        /*
        printf("Test 42\n");
        test42();
        printf("********************************************************************************\n");
        */
    } catch (Exception e) {
        printf("%s\n", e->printFullInfos()->toChar());
    }
    return 0;
}
