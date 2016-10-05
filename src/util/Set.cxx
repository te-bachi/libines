#include "jam/util/Set.hxx"
#include "jam/util/Set.hxx"

using namespace jam::util;

/*** Reference ***/

Set::Set() : Collection() {
    //
}

Set::Set(const Reference& ref) : Collection(ref) {
    //
}

Set::Set(Implementation* impl) : Collection(impl) {
    //
}

Set::~Set() {
    //
}

SetImpl& Set::operator*() {
    return (SetImpl&) Collection::operator*();
}

SetImpl* Set::operator->() {
    return (SetImpl*) Collection::operator->();
}

const Set& Set::operator=(const Reference& ref) {
    return (Set&) Collection::operator=(ref);
}

const Set& Set::operator=(Implementation* impl) {
    return (Set&) Collection::operator=(impl);
}

/*** Implementation ***/
