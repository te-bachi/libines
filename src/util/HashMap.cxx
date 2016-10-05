#include "jam/util/HashMap.hxx"
#include "jam/util/Set.hxx"
#include "jam/util/Map.hxx"
#include "jam/util/HashMapIterator.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Number.hxx"

using namespace jam::util;
using namespace jam::lang;

const Class HashMap::klass = Class::newInstance("jam::util::HashMap");

/*** Reference ***/

HashMap::HashMap() : Map() {
    //
}

HashMap::HashMap(const Reference& ref) : Map(ref) {
    //
}

HashMap::HashMap(Implementation* impl) : Map(impl) {
    //
}

HashMap::~HashMap() {
    //
}

HashMapImpl& HashMap::operator*() {
    return (HashMapImpl&) Map::operator*();
}

HashMapImpl* HashMap::operator->() {
    return (HashMapImpl*) Map::operator->();
}

const HashMap& HashMap::operator=(const Reference& ref) {
    return (HashMap&) Map::operator=(ref);
}

const HashMap& HashMap::operator=(Implementation* impl) {
    return (HashMap&) Map::operator=(impl);
}

HashMap HashMap::newInstance() {
    return HashMap(new HashMapImpl());
}

HashMap HashMap::newInstance(int initialCapacity) {
    return HashMap(new HashMapImpl(initialCapacity));
}

HashMap HashMap::newInstance(int initialCapacity, float loadFactor) {
    return HashMap(new HashMapImpl(initialCapacity, loadFactor));
}

/*** Implementation ***/

HashMapImpl::HashMapImpl() {
    init(11, 0.75);
}

HashMapImpl::HashMapImpl(int initialCapacity) {
    init(initialCapacity, 0.75);
}

HashMapImpl::HashMapImpl(int initialCapacity, float loadFactor) {
    init(initialCapacity, loadFactor);
}

HashMapImpl::~HashMapImpl() {
    clear();
    delete[] _map;
}

HashMapImpl::HashMapImpl(const HashMapImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* HashMapImpl::debugClassName() {
    return "jam::util::HashMap";
}
#endif

// TODO
Object HashMapImpl::clone() {
    return null;
}

String HashMapImpl::toString() {
    StringBuffer sb;
    Entry*       entry;
    int          i;
    
    sb = new StringBufferImpl(50);
    
    for (i = 0; i < _capacity; i++) {
        entry = _map[i];
        
        sb->append(String::valueOf(i, Number::HEXADECIMAL, false));
        sb->append(" {\n");
        
        if (entry != 0) {
            do {
                sb->append("    ");
                sb->append(String::valueOf((int) entry->_previous, Number::HEXADECIMAL, true));
                sb->append("\n    ");
                sb->append(String::valueOf((int) entry, Number::HEXADECIMAL, true));
                sb->append(": ");
                sb->append(entry->_key->toString());
                sb->append(" [hash=");
                sb->append(String::valueOf(entry->_key->hashCode(), Number::HEXADECIMAL, true));
                sb->append("] (");
                sb->append(String::valueOf((int) entry->_key.getImplementation(), Number::HEXADECIMAL, true));
                sb->append(") = ");
                sb->append(entry->_value->toString());
                sb->append(" (");
                sb->append(String::valueOf((int) entry->_value.getImplementation(), Number::HEXADECIMAL, true));
                sb->append(") \n    ");
                sb->append(String::valueOf((int) entry->_next, Number::HEXADECIMAL, true));
                sb->append("\n\n");
                
                entry = entry->_next;
            } while (entry != 0);
        } else {
            sb->append("    null\n");
        }
        sb->append("}\n");
    }
    return sb->toString();
}

Class HashMapImpl::getClass() {
    return HashMap::klass;
}

void HashMapImpl::init(int initialCapacity, float loadFactor) {
    _size       = 0;
    _capacity   = initialCapacity;
    _loadFactor = loadFactor;
    _threshold  = (int) (initialCapacity * loadFactor);
    _map        = new Entry*[_capacity];
    initMap();
}

void HashMapImpl::initMap() {
    int i;
    
    for (i = 0; i < _capacity; i++) {
        _map[i] = 0;
    }
}

HashMapImpl::Entry::Entry(Object key, Object value) {
    _key      = key;
    _value    = value;
    _next     = 0;
    _previous = 0;
}

HashMapImpl::Entry::Entry(Object key, Object value, Entry* entry) {
    _key      = key;
    _value    = value;
    _next     = entry;
    _previous = 0;
}

void HashMapImpl::rehash() {
    Entry** oldMap;
    Entry*  entry;
    Entry*  tmpEntry;
    int     oldCapacity;
    int     i;
    int     index;
    
    oldMap      = _map;
    oldCapacity = _capacity;
    
    _capacity     = (oldCapacity * 2) + 1;
    _threshold  = (int) (_capacity * _loadFactor);
    _map        = new Entry*[_capacity];
    initMap();
    
    for (i = 0; i < oldCapacity; i++) {
        entry = oldMap[i];
        
        if (entry != 0) {
            do {
                tmpEntry = entry;
                // the last entry of a index
                while (tmpEntry->_next != 0) {
                    tmpEntry = tmpEntry->_next;
                }
                index = (tmpEntry->_key->hashCode() & 0x7FFFFFFF) % _capacity;
                if (tmpEntry->_previous != 0) {
                    tmpEntry->_previous->_next = 0;
                    tmpEntry->_previous        = 0;
                }
                tmpEntry->_next = 0;
                
                if (_map[index] != 0) {
                    tmpEntry->_next          = _map[index];
                    _map[index]->_previous  = tmpEntry;
                }
                _map[index] = tmpEntry;
            } while (tmpEntry != entry);
        }
    }
    
    delete[] oldMap;
}

Object HashMapImpl::put(Object key, Object value) {
    Entry*  entry;
    Object  oldValue;
    int     hash;
    int     index;
    
    hash  = key->hashCode();
    index = (hash & 0x7FFFFFFF) % _capacity;
    
    // Detect dublicate keys
    entry = findEntry(key);
    if (entry != 0) {
        oldValue      = entry->_value;
        entry->_value = value;
        return oldValue;
    }
    
    // Rehash the table if the threshold is exceeded
    if (_size > _threshold) {
        rehash();
        index = (hash & 0x7FFFFFFF) % _capacity;
    }
    
    if (_map[index] == 0) {
        entry = new Entry(key, value);
    } else {
        entry = new Entry(key, value, _map[index]);
        _map[index]->_previous = entry;
    }
    
    _map[index] = entry;
    _size++;
    
    return null;
}

// TODO
void HashMapImpl::putAll(Map t) {
    
}

// TODO
boolean HashMapImpl::containsKey(Object key) {
    return null;
}

// TODO
boolean HashMapImpl::containsValue(Object value) {
    return null;
}

Iterator HashMapImpl::keyIterator() {
    return HashMapIterator::newInstance(HashMap(this), HashMapIterator::KEY_SET);
}

Iterator HashMapImpl::valueIterator() {
    return HashMapIterator::newInstance(HashMap(this), HashMapIterator::VALUE_SET);
}

Object HashMapImpl::get(Object key) {
    Entry*  entry;
    
    entry = findEntry(key);
    
    if (entry != 0) {
        return entry->_value;
    }
    
    return null;
}

Object HashMapImpl::remove(Object key) {
    Object  obj;
    Entry*  entry;
    int     hash;
    int     index;
    
    hash    = key->hashCode();
    index   = (hash & 0x7FFFFFFF) % _capacity;
    
    for (entry = _map[index]; entry != 0; entry = entry->_next) {
            if (hash == entry->_key->hashCode() && key->equals(entry->_key)) {
                if (entry->_previous == 0) {
                    // only one
                    if (entry->_next == 0) {
                        _map[index]             = 0;
                    // start
                    } else {
                        _map[index]             = entry->_next;
                        entry->_next->_previous = 0;
                    }
                } else {
                    // end
                    if (entry->_next == 0) {
                        entry->_previous->_next = 0;
                    // middle
                    } else {
                        entry->_previous->_next = entry->_next;
                        entry->_next->_previous = entry->_previous;
                    }
                }
                _size--;
                obj = entry->_value;
                delete entry;
                
                return obj;
            }
    }
    
    return null;
}

HashMapImpl::Entry* HashMapImpl::findEntry(Object key) {
    Entry*  entry;
    int     hash;
    int     index;
    
    hash  = key->hashCode();
    index = (hash & 0x7FFFFFFF) % _capacity;
    
    for (entry = _map[index]; entry != 0; entry = entry->_next) {
            if (hash == entry->_key->hashCode() && key->equals(entry->_key)) {
                return entry;
            }
    }
    
    return 0;
}

boolean HashMapImpl::isEmpty() {
    boolean isEmpty;
    int     i;
    
    isEmpty = true;
    
    for (i = _capacity; i >= 0; i--) {
        if (_map[i] != 0) {
            isEmpty = false;
            break;
        }
    }
    
    return isEmpty;
}

int HashMapImpl::size() {
    return _size;
}

void HashMapImpl::clear() {
    Entry* entry;
    Entry* previous;
    int    i;
    
    for (i = 0; i < _capacity; i++) {
        entry = _map[i];
        if (entry != 0) {
            
            while (entry->_next != 0) {
                while (entry->_next != 0) {
                    previous = entry;
                    entry    = entry->_next;
                }
                delete entry;
                
                previous->_next = 0;
                entry           = _map[i];
            }
            delete entry;
            _map[i] = 0;
        }
    }
    
    _size = 0;
}
