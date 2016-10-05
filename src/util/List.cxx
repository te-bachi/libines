#include "jam/util/List.hxx"

using namespace jam::util;

/*** Reference ***/

List::List() : Collection() {
    //
}

List::List(const Reference& ref) : Collection(ref) {
    //
}

List::List(Implementation* impl) : Collection(impl) {
    //
}

List::~List() {
    //
}

ListImpl& List::operator*() {
    return (ListImpl&) Collection::operator*();
}

ListImpl* List::operator->() {
    return (ListImpl*) Collection::operator->();
}

const List& List::operator=(const Reference& ref) {
    return (List&) Collection::operator=(ref);
}

const List& List::operator=(Implementation* impl) {
    return (List&) Collection::operator=(impl);
}

const Object List::operator[](int index) {
    return operator->()->get(index);
}

/*** Implementation ***/

ListImpl::ListImpl() {
    //
}

ListImpl::~ListImpl() {
    //
}

ListImpl::ListImpl(const ListImpl& copy) {
    //
}
