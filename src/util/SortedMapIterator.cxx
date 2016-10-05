#include "jam/util/SortedMapIterator.hxx"
#include "jam/util/SortedMap.hxx"
#include "jam/lang/Class.hxx"

#include <iostream>

using namespace jam::util;
using namespace jam::lang;

const Class SortedMapIterator::klass = Class::newInstance("jam::util::SortedMapIterator");

/*** Reference ***/

SortedMapIterator::SortedMapIterator() : Iterator() {
    //
}

SortedMapIterator::SortedMapIterator(const Reference& ref) : Iterator(ref) {
    //
}

SortedMapIterator::SortedMapIterator(Implementation* impl) : Iterator(impl) {
    //
}

SortedMapIterator::~SortedMapIterator() {
    //
}

SortedMapIteratorImpl& SortedMapIterator::operator*() {
    return (SortedMapIteratorImpl&) Iterator::operator*();
}

SortedMapIteratorImpl* SortedMapIterator::operator->() {
    return (SortedMapIteratorImpl*) Iterator::operator->();
}

const SortedMapIterator& SortedMapIterator::operator=(const Reference& ref) {
    return (SortedMapIterator&) Iterator::operator=(ref);
}

const SortedMapIterator& SortedMapIterator::operator=(Implementation* impl) {
    return (SortedMapIterator&) Iterator::operator=(impl);
}

SortedMapIterator SortedMapIterator::newInstance(SortedMap map, int set) {
    return SortedMapIterator(new SortedMapIteratorImpl(map, set));
}

/*** Implementation ***/

SortedMapIteratorImpl::SortedMapIteratorImpl(SortedMap map, int set) {
    _map    = map;
    _set    = set;
    _size   = _map->_size;
    _index  = 0;
}

SortedMapIteratorImpl::~SortedMapIteratorImpl() {
    
}

SortedMapIteratorImpl::SortedMapIteratorImpl(const SortedMapIteratorImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* SortedMapIteratorImpl::debugClassName() {
    return "jam::util::SortedMapIterator";
}
#endif

Class SortedMapIteratorImpl::getClass() {
    return SortedMapIterator::klass;
}

boolean SortedMapIteratorImpl::hasNext() {
    return _index < _size;
}

Object SortedMapIteratorImpl::next() {
    SortedMapImpl::Entry* entry;
    
    if (_size != _map->_size) {
        // throw ConcurrentModificationException();
        printf("ConcurrentModificationException\n");
        return null;
    }
    
    if (_index >= _size) {
        // throw NoSuchElementException();
        printf("NoSuchElementException\n");
        return null;
    }
    
    entry = _map->_map[_index++];
    
    if (_set == SortedMapIterator::KEY_SET) {
        return entry->_key;
    }
    
    return entry->_value;
}

Object SortedMapIteratorImpl::remove() {
    return null;
}
