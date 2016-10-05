#include "jam/util/log/LogManager.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/log/Log.hxx"

using namespace jam::util::log;
using namespace jam::util;
using namespace jam::lang;

HashMap LogManager::repository = new HashMapImpl();

LogManager::LogManager() {
    //
}

LogManager::LogManager(const LogManager& ref) {
    //
}

LogManager::~LogManager() {
    //
}

Log LogManager::getLog(String name) {
    Log log;
    
    log = repository->get(name);
    
    if (log.hasReferences() == false) {
        log = new LogImpl(name, Log::OFF);
        repository->put(name, log);
    }
    
    return log;
}
