#include "jam/util/ListIterator.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util;
using namespace jam::lang;

const Class ListIterator::klass = new ClassImpl("jam::util::ListIterator");

/*** Reference ***/

ListIterator::ListIterator() : Iterator() {
    //
}

ListIterator::ListIterator(const Reference& ref) : Iterator(ref) {
    //
}

ListIterator::ListIterator(Implementation* impl) : Iterator(impl) {
    //
}

ListIterator::~ListIterator() {
    //
}

ListIteratorImpl& ListIterator::operator*() {
    return (ListIteratorImpl&) Iterator::operator*();
}

ListIteratorImpl* ListIterator::operator->() {
    return (ListIteratorImpl*) Iterator::operator->();
}

const ListIterator& ListIterator::operator=(const Reference& ref) {
    return (ListIterator&) Iterator::operator=(ref);
}

const ListIterator& ListIterator::operator=(Implementation* impl) {
    return (ListIterator&) Iterator::operator=(impl);
}

ListIterator ListIterator::newInstance(List list) {
    return ListIterator(new ListIteratorImpl(list));
}

/*** Implementation ***/

ListIteratorImpl::ListIteratorImpl(List list) {
    _list  = list;
    _index = 0;
}

ListIteratorImpl::~ListIteratorImpl() {
    
}

ListIteratorImpl::ListIteratorImpl(const ListIteratorImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ListIteratorImpl::debugClassName() {
    return "jam::util::ListIterator";
}
#endif

// TODO
Object ListIteratorImpl::clone() {
    return null;
}

// TODO
String ListIteratorImpl::toString() {
    return null;
}

Class ListIteratorImpl::getClass() {
    return ListIterator::klass;
}

boolean ListIteratorImpl::hasNext() {
    int size;
    
    size = _list->size();
    
    if (0 < size && _index >= 0 && _index < size) {
        return true;
    }
    return false;
}

Object ListIteratorImpl::next() {
    Object obj;
    
    obj = _list->get(_index);
    _index++;
    
    return obj;
}

boolean ListIteratorImpl::hasPrevious() {
    if (0 < _index && (_index - 1) < _list->size()) {
        return true;
    }
    return false;
}

Object ListIteratorImpl::previous() {
    Object obj;
    
    obj = _list->get(_index - 1);
    _index--;
    
    return obj;
}

Object ListIteratorImpl::remove() {
    return _list->remove(_index);
}
