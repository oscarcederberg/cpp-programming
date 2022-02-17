#include <algorithm>

#include <umns.h>

void UMNS::insert(const HostName& name, const IPAddress& adress) {
    hosts[name] = adress;
}

bool UMNS::remove(const HostName& name) {
    size_t count = hosts.erase(name);
    return count > 0;
}

IPAddress UMNS::lookup(const HostName& name) const {
    auto result = hosts.find(name);
    
    if (result != hosts.end()) {
        return (*result).second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}