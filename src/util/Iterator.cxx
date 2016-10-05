#include "jam/util/Iterator.hxx"

using namespace jam::util;

/*** Reference ***/

Iterator::Iterator() : Object() {
    //
}

Iterator::Iterator(const Reference& ref) : Object(ref) {
    //
}

Iterator::Iterator(Implementation* impl) : Object(impl) {
    //
}

Iterator::~Iterator() {
    //
}

IteratorImpl& Iterator::operator*() {
    return (IteratorImpl&) Reference::operator*();
}

IteratorImpl* Iterator::operator->() {
    return (IteratorImpl*) Reference::operator->();
}

const Iterator& Iterator::operator=(const Reference& ref) {
    return (Iterator&) Reference::operator=(ref);
}

const Iterator& Iterator::operator=(Implementation* impl) {
    return (Iterator&) Reference::operator=(impl);
}

/*** Implementation ***/

IteratorImpl::IteratorImpl() {
    //
}

IteratorImpl::~IteratorImpl() {
    //
}

IteratorImpl::IteratorImpl(const IteratorImpl& copy) {
    //
}
