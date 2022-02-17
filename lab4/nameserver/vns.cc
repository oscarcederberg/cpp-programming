#include <algorithm>

#include "vns.h"

void VNS::insert(const HostName& name, const IPAddress& adress) {
    hosts.push_back({name, adress});
}

bool VNS::remove(const HostName& name) {
    size_t count = hosts.size();
    hosts.erase(std::remove_if(hosts.begin(), 
            hosts.end(),
            [&](const NameEntry& entry) { return entry.first == name; }),
        hosts.end());
    
    return count != hosts.size();
}

IPAddress VNS::lookup(const HostName& name) const {
    auto result = std::find_if(hosts.begin(), hosts.end(), 
        [&](const NameEntry& entry) { return entry.first == name; });

    if (result != hosts.end()) {
        return (*result).second;
    } else {
        return NON_EXISTING_ADDRESS;
    } 
}