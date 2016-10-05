#include "jam/util/Map.hxx"

using namespace jam::util;

/*** Reference ***/

Map::Map() : Object() {
    //
}

Map::Map(const Reference& ref) : Object(ref) {
    //
}

Map::Map(Implementation* impl) : Object(impl) {
    //
}

Map::~Map() {
    //
}

MapImpl& Map::operator*() {
    return (MapImpl&) Reference::operator*();
}

MapImpl* Map::operator->() {
    return (MapImpl*) Reference::operator->();
}

const Map& Map::operator=(const Reference& ref) {
    return (Map&) Reference::operator=(ref);
}

const Map& Map::operator=(Implementation* impl) {
    return (Map&) Reference::operator=(impl);
}

/*** Implementation ***/

MapImpl::MapImpl() {
    
}

MapImpl::~MapImpl() {
    
}

MapImpl::MapImpl(const MapImpl& copy) {
    
}
