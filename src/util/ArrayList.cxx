#include "jam/util/ArrayList.hxx"
#include "jam/util/ListIterator.hxx"
#include "jam/util/sort/Comparator.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/IndexOutOfBoundsException.hxx"

#include <iostream>

using namespace jam::util;
using namespace jam::lang;

const Class ArrayList::klass = new ClassImpl("jam::util::ArrayList");

const int ArrayListImpl::NOT_FOUND = -1;

/*** Reference ***/

ArrayList::ArrayList() : List() {
    //
}

ArrayList::ArrayList(const Reference& ref) : List(ref) {
    //
}

ArrayList::ArrayList(Implementation* impl) : List(impl) {
    //
}

ArrayList::~ArrayList() {
    //
}

ArrayListImpl& ArrayList::operator*() {
    return (ArrayListImpl&) List::operator*();
}

ArrayListImpl* ArrayList::operator->() {
    return (ArrayListImpl*) List::operator->();
}

const ArrayList& ArrayList::operator=(const Reference& ref) {
    return (ArrayList&) List::operator=(ref);
}

const ArrayList& ArrayList::operator=(Implementation* impl) {
    return (ArrayList&) List::operator=(impl);
}

ArrayList ArrayList::newInstance() {
    return ArrayList(new ArrayListImpl());
}

ArrayList ArrayList::newInstance(int size) {
    return ArrayList(new ArrayListImpl(size));
}

const Object ArrayList::operator[](int index) {
    return operator->()->get(index);
}

/*** Implementation ***/

ArrayListImpl::ArrayListImpl() {
    init(50);
}

ArrayListImpl::ArrayListImpl(int size) {
    init(size);
}

ArrayListImpl::~ArrayListImpl() {
    clear();
    delete[] _list;
}

ArrayListImpl::ArrayListImpl(const ArrayListImpl& copy) {
    //
}

ArrayListImpl::Entry::Entry(Object obj) {
    _obj = obj;
}

#ifdef __DEBUG__
const char* ArrayListImpl::debugClassName() {
    return "jam::util::ArrayList";
}
#endif

Object ArrayListImpl::clone() {
    ArrayList list;
    
    list = ArrayList::newInstance(size());
    list->add(Collection(this));
    
    return list;
}

String ArrayListImpl::toString() {
    StringBuffer sb;
    Entry*       entry;
    int          i;
    
    sb    = new StringBufferImpl(50);
    
    for (i = 0; i < _size; i++) {
        entry = _list[i];
        sb->append(i + 1);
        sb->append(" (");
        sb->append(String::valueOf((int) entry, Number::HEXADECIMAL, true));
        sb->append(")");
        sb->append(": ");
        sb->append(entry->_obj->toString());
        sb->append(" (");
        sb->append(String::valueOf((int) entry->_obj.getImplementation(), Number::HEXADECIMAL, true));
        sb->append(")\n");
    }
    
    return sb->toString();
}

Class ArrayListImpl::getClass() {
    return ArrayList::klass;
}

boolean ArrayListImpl::add(Object obj) {
    if (_size >= _capacity) {
        resize();
    }
    
    _list[_size] = new Entry(obj);
    _size++;
    
    return true;
}

boolean ArrayListImpl::add(Collection collection) {
    Iterator iter;
    
    iter = collection->iterator();
    
    while (iter->hasNext()) {
        add(iter->next());
    }
    
    return true;
}

void ArrayListImpl::clear() {
    int i;
    
    for (i = 0; i < _size; i++) {
        delete _list[i];
        _list[i] = 0;
    }
    
    _size = 0;
}

boolean ArrayListImpl::contains(Object obj) {
    
    if (findEntry(obj) != NOT_FOUND) {
        return true;
    }
    
    return false;
}

boolean ArrayListImpl::contains(Collection collection) {
    Iterator iter;
    Object   obj;
    int      index;
    
    iter    = collection->iterator();
    
    while (iter->hasNext()) {
        obj     = iter->next();
        index   = findEntry(obj);
        
        if (index == NOT_FOUND) {
            return false;
        }
    }
    
    return true;
}

boolean ArrayListImpl::isEmpty() {
    return (_size == 0 ? true : false);
}

Iterator ArrayListImpl::iterator() {
    return ListIterator::newInstance((List) this);
}

Object ArrayListImpl::get(int index) {
    if (index < 0 || index >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    return _list[index]->_obj;
}

boolean ArrayListImpl::remove(Object obj) {
    int index;
    
    index = findEntry(obj);
    
    if (index == NOT_FOUND) {
        return false;
    }
    
    removeEntry(index);
    return true;
}

boolean ArrayListImpl::remove(Collection collection) {
    Iterator iter;
    Object   obj;
    int      index;
    
    if (contains(collection) == false) {
        return false;
    }
    
    iter = collection->iterator();
    
    while (iter->hasNext()) {
        obj   = iter->next();
        index = findEntry(obj);
        removeEntry(index);
    }
    
    return true;
}

Object ArrayListImpl::remove(int index) {
    Entry* entry;
    Object obj;
    
    if (index < 0 || index >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    entry = _list[index];
    obj   = entry->_obj;
    removeEntry(index);
    
    return obj;
}

List ArrayListImpl::subList(int fromIndex, int toIndex) {
    ArrayList   list;
    Entry*      entry;
    int         i;
    
    if ((fromIndex < 0 || fromIndex >= _size) || (toIndex < 0 || toIndex > _size)) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    list    = ArrayList::newInstance();
    
    for (i = fromIndex; i <= toIndex; i++) {
        entry = _list[i];
        list->add(entry->_obj);
    }
    
    return list;
}

// TODO
Collection ArrayListImpl::sort(Comparator comparator) {
    ArrayList other;
    Object    obj1;
    Object    obj2;
    int       i;
    int       k;
    
    other = (ArrayList) clone();
    
    for (i = 0; i < (other->_size - 1); i++) {
        for (k = 0; k < (other->_size - 1); k++) {
            obj1 = other->_list[k]->_obj;
            obj2 = other->_list[k + 1]->_obj;
            
            if (comparator->compare(obj1, obj2) == -1) {
                other->_list[k]->_obj     = obj2;
                other->_list[k + 1]->_obj = obj1;
            }
        }
    }
    
    return other;
}

void ArrayListImpl::swap(int i1, int i2) {
    Entry* e1;
    Entry* e2;
    
    if (i1 < 0 || i1 >= _size || i2 < 0 || i2 >= _size) {
        throw IndexOutOfBoundsException::newInstance();
    }
    
    
    e1 = _list[i1];
    e2 = _list[i2];
    
    _list[i1] = e2;
    _list[i2] = e1;
}

int ArrayListImpl::size() {
    return _size;
}

int ArrayListImpl::indexOf(Object obj) {
    return findEntry(obj);
}

void ArrayListImpl::init(int size) {
    _list     = new Entry*[size];
    _size     = 0;
    _capacity = size;
    initList();
}

void ArrayListImpl::initList() {
    int i;
    
    for (i = 0; i < _capacity; i++) {
        _list[i] = 0;
    }
}

void ArrayListImpl::resize() {
    Entry** oldList;
    int     oldCapacity;
    int     i;
    
    oldCapacity = _capacity;
    oldList     = _list;
    
    _capacity   = oldCapacity * 2;
    _list       = new Entry*[_capacity];
    initList();
    
    for (i = 0; i < _size; i++) {
        _list[i] = oldList[i];
    }
    
    delete[] oldList;
}

int ArrayListImpl::findEntry(Object obj) {
    Entry*  entry;
    int     i;
    
    for (i = 0; i < _size; i++) {
        entry = _list[i];
        if (entry->_obj->equals(obj)) { // maybee entry->_obj == obj 
            return i;
        }
    }
    
    return NOT_FOUND;
}

void ArrayListImpl::removeEntry(int index) {
    Entry* entry;
    int    i;
    
    entry = _list[index];
    
    for (i = index; i < (_size - 1); i++) {
        _list[i] = _list[i + 1];
    }
    
    _size--;
    delete entry;
}
