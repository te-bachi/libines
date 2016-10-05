#include "jam/util/log/Layout.hxx"
#include "jam/lang/Class.hxx"

using namespace jam::util::log;
using namespace jam::lang;

/*** Reference ***/

Layout::Layout() : Reference() {
    //
}

Layout::Layout(const Reference& ref) : Reference(ref) {
    //
}

Layout::Layout(Implementation* impl) : Reference(impl) {
    //
}

Layout::~Layout() {
    //
}

LayoutImpl& Layout::operator*() {
    return (LayoutImpl&) Reference::operator*();
}

LayoutImpl* Layout::operator->() {
    return (LayoutImpl*) Reference::operator->();
}

const Layout& Layout::operator=(const Reference& ref) {
    return (Layout&) Reference::operator=(ref);
}

const Layout& Layout::operator=(Implementation* impl) {
    return (Layout&) Reference::operator=(impl);
}

/*** Implementation ***/

LayoutImpl::LayoutImpl() {
    //
}

LayoutImpl::~LayoutImpl() {
    //
}

LayoutImpl::LayoutImpl(const LayoutImpl& copy) {
    //
}
