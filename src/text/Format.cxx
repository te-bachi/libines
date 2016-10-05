#include "jam/text/Format.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::text;
using namespace jam::lang;

const Class Format::klass = Class::newInstance("jam::text::Format");

/*** Reference ***/

Format::Format() : Object() {
    //
}

Format::Format(const Reference& ref) : Object(ref) {
    //
}

Format::Format(Implementation* impl) : Object(impl) {
    //
}

Format::~Format() {
    //
}

FormatImpl& Format::operator*() {
    return (FormatImpl&) Object::operator*();
}

FormatImpl* Format::operator->() {
    return (FormatImpl*) Object::operator->();
}

const Format& Format::operator=(const Reference& ref) {
    return (Format&) Object::operator=(ref);
}

const Format& Format::operator=(Implementation* impl) {
    return (Format&) Object::operator=(impl);
}

/*** Implementation ***/

FormatImpl::FormatImpl() {
    
}

FormatImpl::~FormatImpl() {
    
}

FormatImpl::FormatImpl(const FormatImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* FormatImpl::debugClassName() {
    return "jam::text::Format";
}
#endif

Class FormatImpl::getClass() {
    return Format::klass;
}