#include "jam/util/sort/Comparator.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util::sort;
using namespace jam::lang;

const Class Comparator::klass = Class::newInstance("jam::util::sort::Comparator");

/*** Reference ***/

Comparator::Comparator() : Object() {
    //
}

Comparator::Comparator(const Reference& ref) : Object(ref) {
    //
}

Comparator::Comparator(Implementation* impl) : Object(impl) {
    //
}

Comparator::~Comparator() {
    //
}

ComparatorImpl& Comparator::operator*() {
    return (ComparatorImpl&) Object::operator*();
}

ComparatorImpl* Comparator::operator->() {
    return (ComparatorImpl*) Object::operator->();
}

const Comparator& Comparator::operator=(const Reference& ref) {
    return (Comparator&) Object::operator=(ref);
}

const Comparator& Comparator::operator=(Implementation* impl) {
    return (Comparator&) Object::operator=(impl);
}

/*** Implementation ***/

ComparatorImpl::ComparatorImpl() {
    
}

ComparatorImpl::~ComparatorImpl() {
    
}

ComparatorImpl::ComparatorImpl(const ComparatorImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ComparatorImpl::debugClassName() {
    return "jam::util::sort::Comparator";
}
#endif

Class ComparatorImpl::getClass() {
    return Comparator::klass;
}
