#include "jam/lang/Implementation.hxx"

using namespace jam::lang;

Implementation::Implementation() {
    _refCounter = new int(0);
}

Implementation::~Implementation() {
    delete _refCounter;
}

Implementation::Implementation(const Implementation& impl) {
    //
}

void Implementation::initRefCounter() {
    (*_refCounter) = 1;
}

boolean Implementation::checkRefCounter() {
    return ((*_refCounter) > 0);
}

void Implementation::addRefCounter() {
    (*_refCounter)++;
}

void Implementation::releaseRefCounter() {
    (*_refCounter)--;
}

int Implementation::getRefCounter() {
    return (*_refCounter);
}
