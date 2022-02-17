#include <algorithm>

#include "mns.h"

void MNS::insert(const HostName& name, const IPAddress& adress) {
    hosts[name] = adress;
}

bool MNS::remove(const HostName& name) {
    size_t count = hosts.erase(name);
    return count > 0;
}

IPAddress MNS::lookup(const HostName& name) const {
    auto result = hosts.find(name);
    
    if (result != hosts.end()) {
        return (*result).second;
    } else {
        return NON_EXISTING_ADDRESS;
    } 
}