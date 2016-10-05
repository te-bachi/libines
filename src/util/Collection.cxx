#include "jam/util/Collection.hxx"

using namespace jam::util;

/*** Reference ***/

Collection::Collection() : Object() {
    //
}

Collection::Collection(const Reference& ref) : Object(ref) {
    //
}

Collection::Collection(Implementation* impl) : Object(impl) {
    //
}

Collection::~Collection() {
    //
}

CollectionImpl& Collection::operator*() {
    return (CollectionImpl&) Reference::operator*();
}

CollectionImpl* Collection::operator->() {
    return (CollectionImpl*) Reference::operator->();
}

const Collection& Collection::operator=(const Reference& ref) {
    return (Collection&) Reference::operator=(ref);
}

const Collection& Collection::operator=(Implementation* impl) {
    return (Collection&) Reference::operator=(impl);
}

/*** Implementation ***/

CollectionImpl::CollectionImpl() {
    //
}

CollectionImpl::~CollectionImpl() {
    //
}

CollectionImpl::CollectionImpl(const CollectionImpl& copy) {
    //
}
