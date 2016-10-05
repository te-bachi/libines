#include "jam/util/SortedMap.hxx"
#include "jam/util/Set.hxx"
#include "jam/util/Map.hxx"
#include "jam/util/SortedMapIterator.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Number.hxx"

using namespace jam::util;
using namespace jam::lang;

const Class SortedMap::klass = Class::newInstance("jam::util::SortedMap");

/*** Reference ***/

SortedMap::SortedMap() : Map() {
    //
}

SortedMap::SortedMap(const Reference& ref) : Map(ref) {
    //
}

SortedMap::SortedMap(Implementation* impl) : Map(impl) {
    //
}

SortedMap::~SortedMap() {
    //
}

SortedMapImpl& SortedMap::operator*() {
    return (SortedMapImpl&) Map::operator*();
}

SortedMapImpl* SortedMap::operator->() {
    return (SortedMapImpl*) Map::operator->();
}

const SortedMap& SortedMap::operator=(const Reference& ref) {
    return (SortedMap&) Map::operator=(ref);
}

const SortedMap& SortedMap::operator=(Implementation* impl) {
    return (SortedMap&) Map::operator=(impl);
}

SortedMap SortedMap::newInstance(Comparator comparator) {
    return SortedMap(new SortedMapImpl(comparator));
}

SortedMap SortedMap::newInstance(Comparator comparator, int initialCapacity) {
    return SortedMap(new SortedMapImpl(comparator, initialCapacity));
}

/*** Implementation ***/

SortedMapImpl::SortedMapImpl(Comparator comparator) {
    init(comparator, 20);
}

SortedMapImpl::SortedMapImpl(Comparator comparator, int initialCapacity) {
    init(comparator, initialCapacity);
}

SortedMapImpl::~SortedMapImpl() {
    clear();
    delete[] _map;
}

SortedMapImpl::SortedMapImpl(const SortedMapImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* SortedMapImpl::debugClassName() {
    return "jam::util::SortedMap";
}
#endif

// TODO
Object SortedMapImpl::clone() {
    return null;
}

String SortedMapImpl::toString() {
    StringBuffer sb;
    Entry*       entry;
    int          i;
    
    sb = new StringBufferImpl(50);
    
    for (i = 0; i < _size; i++) {
        entry = _map[i];
        
        sb->append(String::valueOf((int) entry, Number::HEXADECIMAL, true));
        sb->append(": ");
        sb->append(entry->_key->toString());
        sb->append(" (");
        sb->append(String::valueOf((int) entry->_key.getImplementation(), Number::HEXADECIMAL, true));
        sb->append(") = ");
        sb->append(entry->_value->toString());
        sb->append(" (");
        sb->append(String::valueOf((int) entry->_key.getImplementation(), Number::HEXADECIMAL, true));
        sb->append(")\n");
    }
    return sb->toString();
}

Class SortedMapImpl::getClass() {
    return SortedMap::klass;
}

void SortedMapImpl::init(Comparator comparator, int initialCapacity) {
    _size       = 0;
    _capacity   = initialCapacity;
    _map        = new Entry*[_capacity];
    _comparator = comparator;
    
    initMap();
}

void SortedMapImpl::initMap() {
    int i;
    
    for (i = 0; i < _capacity; i++) {
        _map[i] = 0;
    }
}

void SortedMapImpl::increaseMap() {
    Entry** oldMap;
    int     oldCapacity;
    int     i;
    
    oldMap      = _map;
    oldCapacity = _capacity;
    
    _capacity   = (oldCapacity * 2) + 1;
    _map        = new Entry*[_capacity];
    
    // entryies
    for (i = 0; i < _size; i++) {
        _map[i] = oldMap[i];
    }
    
    // fill with null
    for (; i < _capacity; i++) {
        _map[i] = 0;
    }
    
    delete[] oldMap;
}

Object SortedMapImpl::put(Object key, Object value) {
    Entry*  entry;
    int     index;
    int     i;
    boolean hasFound;
    
    if (_size >= _capacity) {
        increaseMap();
    }
    
    index = findIndex(key);
    
    for (i = (_size - 1); i >= index; i--) {
        _map[i + 1] = _map[i];
    }
    
    entry         = new Entry();
    entry->_key   = key;
    entry->_value = value;
    _map[index]   = entry;
    _size++;
    
    return null;
}

void SortedMapImpl::putAll(Map map) {
    Iterator iter;
    Object   key;
    
    iter = map->keyIterator();
    while (iter->hasNext()) {
        key = iter->next();
        put(key, map->get(key));
    }
}

boolean SortedMapImpl::containsKey(Object key) {
    if (findEntry(key) == NULL) {
        return false;
    }
    
    return true;
}

boolean SortedMapImpl::containsValue(Object value) {
    Entry *entry;
    int    i;
    
    for (i = 0; i < _size; i++) {
        entry = _map[i];
        
        if (entry->_value->equals(value)) {
            return true;
        }
    }
    
    return false;
}

Iterator SortedMapImpl::keyIterator() {
    return SortedMapIterator::newInstance(SortedMap(this), SortedMapIterator::KEY_SET);
}

Iterator SortedMapImpl::valueIterator() {
    return SortedMapIterator::newInstance(SortedMap(this), SortedMapIterator::VALUE_SET);
}

Object SortedMapImpl::get(Object key) {
    Entry* entry;
    
    if ((entry = findEntry(key)) != NULL) {
        return entry->_value;
    }
    
    return null;
}

Object SortedMapImpl::remove(Object key) {
    Object obj;
    Entry* entry;
    int    index;
    int    i;
    
    index = findIndex(key);
    entry = _map[index];
    
    if (_comparator->compare(key, entry->_key) == 0) {
        obj = entry->_value;
        delete entry;
        
        for (i = index; i < _size; i++) {
            _map[i] = _map[i + 1];
        }
        
        _size--;
        
        return obj;
    }
    
    return null;
}

boolean SortedMapImpl::isEmpty() {
    return _size > 0;
}

int SortedMapImpl::size() {
    return _size;
}

void SortedMapImpl::clear() {
    Entry* entry;
    int    i;
    
    for (i = 0; i < _size; i++) {
        entry = _map[i];
        delete entry;
    }
    
    _size = 0;
}

SortedMapImpl::Entry* SortedMapImpl::findEntry(Object key) {
    Entry* entry;
    int    index;
    
    index = findIndex(key);
    entry = _map[index];
    
    if (_comparator->compare(key, entry->_key) == 0) {
        return entry;
    }
    
    return NULL;
}

int SortedMapImpl::findIndex(Object key) {
    Entry*  entry;
    int     left;
    int     right;
    int     middle;
    boolean hasFound;
    
    hasFound = false;
    left     = 0;
    right    = _size - 1;
    middle   = 0;
    
    while (left <= right) {
        middle = (left + right) / 2;
        entry  = _map[middle];
        
        switch (_comparator->compare(key, entry->_key)) {
            case -1:
                left     = middle + 1;
                break;
                
            case 1:
                right    = middle - 1;
                break;
                
            case 0:
                hasFound = true;
                right    = -1;
                break;
        }
    }
    
    if (hasFound == false) {
        middle = left;
    }
    
    return middle;
}
