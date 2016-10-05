#include "jam/util/HashMapIterator.hxx"
#include "jam/util/HashMap.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util;
using namespace jam::lang;

const Class HashMapIterator::klass = Class::newInstance("jam::util::HashMapIterator");

/*** Reference ***/

HashMapIterator::HashMapIterator() : Iterator() {
    //
}

HashMapIterator::HashMapIterator(const Reference& ref) : Iterator(ref) {
    //
}

HashMapIterator::HashMapIterator(Implementation* impl) : Iterator(impl) {
    //
}

HashMapIterator::~HashMapIterator() {
    //
}

HashMapIteratorImpl& HashMapIterator::operator*() {
    return (HashMapIteratorImpl&) Iterator::operator*();
}

HashMapIteratorImpl* HashMapIterator::operator->() {
    return (HashMapIteratorImpl*) Iterator::operator->();
}

const HashMapIterator& HashMapIterator::operator=(const Reference& ref) {
    return (HashMapIterator&) Iterator::operator=(ref);
}

const HashMapIterator& HashMapIterator::operator=(Implementation* impl) {
    return (HashMapIterator&) Iterator::operator=(impl);
}

HashMapIterator HashMapIterator::newInstance(HashMap map, Set set) {
    return HashMapIterator(new HashMapIteratorImpl(map, set));
}

/*** Implementation ***/

HashMapIteratorImpl::HashMapIteratorImpl(HashMap map, HashMapIterator::Set set) {
    _map        = map;
    _set        = set;
    
    _current    = 0;
    _next       = 0;
    _size       = _map->_size;
    
    // pre-read to the first entry
    if (_size != 0) {
        for (_index = 0; _index < _map->_capacity && _next == 0; _index++) {
            _next = _map->_map[_index];
        }
    }
}

HashMapIteratorImpl::~HashMapIteratorImpl() {
    
}

HashMapIteratorImpl::HashMapIteratorImpl(const HashMapIteratorImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* HashMapIteratorImpl::debugClassName() {
    return "jam::util::HashMapIterator";
}
#endif

Class HashMapIteratorImpl::getClass() {
    return HashMapIterator::klass;
}

boolean HashMapIteratorImpl::hasNext() {
    return _next != 0;
}

Object HashMapIteratorImpl::next() {
    
    if (_size != _map->_size) {
        // throw ConcurrentModificationException();
    }
    
    if (_next == 0) {
        // throw NoSuchElementException();
    }
    
    _current = _next;
    _next    = _current->_next;
    
    while (_index < _map->_capacity && _next == 0) {
        _next = _map->_map[_index++];
    }
    
    if (_set == HashMapIterator::KEY_SET) {
        return _current->_key;
    }
    
    return _current->_value;
}

Object HashMapIteratorImpl::remove() {
    return null;
}
