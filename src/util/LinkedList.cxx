#include "jam/util/LinkedList.hxx"
#include "jam/util/Collection.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/util/List.hxx"
#include "jam/util/ListIterator.hxx"
#include "jam/util/sort/Comparator.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Number.hxx"
#include "jam/lang/IndexOutOfBoundsException.hxx"

using namespace jam::util;
using namespace jam::lang;

const Class LinkedList::klass = new ClassImpl("jam::util::LinkedList");

/*** Reference ***/

LinkedList::LinkedList() : List() {
    //
}

LinkedList::LinkedList(const Reference& ref) : List(ref) {
    //
}

LinkedList::LinkedList(Implementation* impl) : List(impl) {
    //
}

LinkedList::~LinkedList() {
    //
}

LinkedListImpl& LinkedList::operator*() {
    return (LinkedListImpl&) List::operator*();
}

LinkedListImpl* LinkedList::operator->() {
    return (LinkedListImpl*) List::operator->();
}

const LinkedList& LinkedList::operator=(const Reference& ref) {
    return (LinkedList&) List::operator=(ref);
}

const LinkedList& LinkedList::operator=(Implementation* impl) {
    return (LinkedList&) List::operator=(impl);
}

LinkedList LinkedList::newInstance() {
    return LinkedList(new LinkedListImpl());
}

const Object LinkedList::operator[](int index) {
    return operator->()->get(index);
}

/*** Implementation ***/

LinkedListImpl::LinkedListImpl() {
    _head = 0;
    _tail = 0;
    _size = 0;
}

LinkedListImpl::~LinkedListImpl() {
    clear();
}

LinkedListImpl::LinkedListImpl(const LinkedListImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* LinkedListImpl::debugClassName() {
    return "jam::util::LinkedList";
}
#endif

// TODO
Object LinkedListImpl::clone() {
    return null;
}

String LinkedListImpl::toString() {
    StringBuffer sb;
    Entry*       entry;
    int          i;
    
    sb    = new StringBufferImpl(50);
    entry = _head;
    
    for (i = 0; i < _size; i++) {
        sb->append(i + 1);
        sb->append(" (");
        sb->append(String::valueOf((int) entry, Number::HEXADECIMAL, true));
        sb->append(")");
        sb->append(": ");
        sb->append(entry->_obj->toString());
        sb->append(" (");
        sb->append(String::valueOf((int) entry->_obj.getImplementation(), Number::HEXADECIMAL, true));
        sb->append(")\n");
        
        entry = entry->_next;
    }
    
    return sb->toString();
}

Class LinkedListImpl::getClass() {
    return LinkedList::klass;
}

LinkedListImpl::Entry::Entry(Object obj, Entry *next, Entry *previous) {
    _obj      = obj;
    _next     = next;
    _previous = previous;
}

boolean LinkedListImpl::add(Object obj) {
    addLast(obj);
    
    return true;
}

boolean LinkedListImpl::add(Collection collection) {
    Iterator iter;
    
    iter = collection->iterator();
    
    while (iter->hasNext()) {
        addLast(iter->next());
    }
    
    return true;
}

void LinkedListImpl::addFirst(Object obj) {
    Entry* newEntry;
    Entry* currentEntry;
    
    newEntry = new Entry(obj, _head, 0);
    
    if (_tail == 0) {
        _tail = newEntry;
    } else {
        currentEntry            = _head;
        currentEntry->_previous = newEntry;
        newEntry->_next         = currentEntry;
    }
    
    _head = newEntry;
    _size++;
}

void LinkedListImpl::addLast(Object obj) {
    Entry* newEntry;
    Entry* currentEntry;
    
    newEntry = new Entry(obj, 0, _tail);
    
    if (_head == 0) {
        _head = newEntry;
    } else {
        currentEntry        = _tail;
        currentEntry->_next = newEntry;
        newEntry->_previous = currentEntry;
    }
    
    _tail = newEntry;
    _size++;
}

boolean LinkedListImpl::contains(Object obj) {
    if (findEntry(obj) == 0) {
        return false;
    }
    
    return true;
}

boolean LinkedListImpl::contains(Collection collection) {
    Iterator iter;
    Object   obj;
    Entry*   entry;
    
    iter    = collection->iterator();
    
    while (iter->hasNext()) {
        obj     = iter->next();
        entry   = findEntry(obj);
        
        if (entry == 0) {
            return false;
        }
    }
    
    return true;
}

Object LinkedListImpl::get(int index) {
    Entry*       entry;
    
    entry = findEntry(index);
    
    return entry->_obj;
}

Object LinkedListImpl::getFirst() {
    return _head->_obj;
}

Object LinkedListImpl::getLast() {
    return _tail->_obj;
}

boolean LinkedListImpl::remove(Object obj) {
    Entry*  entry;
    
    entry = findEntry(obj);
    if (entry == 0) {
        return false;
    }
    
    removeEntry(entry);
    
    return true;
}

boolean LinkedListImpl::remove(Collection collection) {
    Iterator iter;
    Object   obj;
    Entry*   entry;
    
    if (contains(collection) == false) {
        return false;
    }
    
    iter = collection->iterator();
    
    while (iter->hasNext()) {
        obj   = iter->next();
        entry = findEntry(obj);
        removeEntry(entry);
    }
    
    return true;
}

Object LinkedListImpl::remove(int index) {
    Object  obj;
    Entry*  entry;
    
    if (index < 0 || index >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    entry = findEntry(index);
    obj   = entry->_obj;
    removeEntry(entry);
    
    return obj;
}

Object LinkedListImpl::removeFirst() {
    Object obj;
    
    obj = _head->_obj;
    removeEntry(_head);
    
    return obj;
}

Object LinkedListImpl::removeLast() {
    Object obj;
    
    obj = _tail->_obj;
    removeEntry(_tail);
    
    return obj;
}

boolean LinkedListImpl::isEmpty() {
    return (_head == 0 ? true : false);
}

Iterator LinkedListImpl::iterator() {
    return ListIterator::newInstance((List) this);
}

int LinkedListImpl::size() {
    return _size;
}

void LinkedListImpl::clear() {
    Entry* entry;
    int    i;
    
    entry = _tail;
    
    for (i = 0; i < _size; i++) {
        if (entry->_previous == 0) {
            delete entry;
        } else {
            entry = entry->_previous;
            delete entry->_next;
        }
    }
    
    _head = 0;
    _tail = 0;
    _size = 0;
}

List LinkedListImpl::subList(int fromIndex, int toIndex) {
    LinkedList  list;
    Entry*      entry;
    int         size;
    int         i;
    
    if ((fromIndex < 0 || fromIndex >= _size) || (toIndex < 0 || toIndex > _size)) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    list    = LinkedList::newInstance();
    size    = toIndex - fromIndex;
    entry   = findEntry(fromIndex);
    
    for (i = 0; i < size; i++) {
        list->add(entry->_obj);
        entry = entry->_next;
    }
    
    return list;
}

//TODO
Collection LinkedListImpl::sort(Comparator comparator) {
    return null;
}

void LinkedListImpl::swap(int i1, int i2) {
    Entry* e1;
    Entry* e1Prev;
    Entry* e1Next;
    Entry* e2;
    Entry* e2Prev;
    Entry* e2Next;
    
    if (i1 < 0 || i1 >= _size || i2 < 0 || i2 >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    
    e1            = findEntry(i1);
    e1Prev        = e1->_previous;
    e1Next        = e1->_next;
    
    e2            = findEntry(i2);
    e2Prev        = e2->_previous;
    e2Next        = e2->_next;
    
    e1->_previous = e2Prev;
    e1->_next     = e2Next;
    
    e2->_previous = e1Prev;
    e2->_next     = e1Next;
    
    if (e1Prev == e2)   e1Prev            = e1;
    if (e1Next == e2)   e1Next            = e1;
    if (e2Prev == e1)   e2Prev            = e2;
    if (e2Next == e1)   e2Next            = e2;
    if (e1Prev != NULL) e1Prev->_next     = e2;
    if (e1Next != NULL) e1Next->_previous = e2;
    if (e2Prev != NULL) e2Prev->_next     = e1;
    if (e2Next != NULL) e2Next->_previous = e1;
    if (_head == e1)    _head             = e2;
    if (_tail == e2)    _tail             = e1;
}

LinkedListImpl::Entry* LinkedListImpl::findEntry(int index) {
    Entry*  entry;
    int     i;
    
    if (index < 0 || index >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    if (index < (_size / 2)) {
        entry = _head;
        
        for (i = 0; i < index; i++) {
            entry = entry->_next;
        }
    } else {
        entry = _tail;
        
        for (i = (_size - 1); i > index; i--) {
            entry = entry->_previous;
        }
    }
    
    return entry;
}

LinkedListImpl::Entry* LinkedListImpl::findEntry(Object obj) {
    Entry*  entry;
    int     i;
    
    entry = _head;
    
    for (i = 0; i < _size; i++) {
        if (entry->_obj->equals(obj)) {
            return entry;
        }
        entry = entry->_next;
    }
    
    return 0;
}

void LinkedListImpl::removeEntry(Entry* entry) {
    if (entry->_previous == 0) {
        // only one
        if (entry->_next == 0) {
            _head                   = 0;
            _tail                   = 0;
        // start
        } else {
            _head                   = entry->_next;
            entry->_next->_previous = 0;
        }
    } else {
        // end
        if (entry->_next == 0) {
            _tail                   = entry->_previous;
            entry->_previous->_next = 0;
        // middle
        } else {
            entry->_previous->_next = entry->_next;
            entry->_next->_previous = entry->_previous;
        }
    }
    
    _size--;
    delete entry;
}
