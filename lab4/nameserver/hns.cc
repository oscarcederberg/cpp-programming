#include <algorithm>

#include "hns.h"

HNS::HNS(size_t size) {
    hosts.resize(size);
}

void HNS::insert(const HostName& name, const IPAddress& adress) {
    size_t hash = std::hash<HostName>{}(name) % hosts.size();
    hosts.at(hash).push_back({name, adress});
}

bool HNS::remove(const HostName& name) {
    size_t hash = std::hash<HostName>{}(name) % hosts.size();
    size_t count = hosts.at(hash).size();
    hosts.at(hash).erase(std::remove_if(hosts.at(hash).begin(), 
            hosts.at(hash).end(),
            [&](const NameEntry& entry) { return entry.first == name; }),
        hosts.at(hash).end());
    
    return count != hosts.at(hash).size();
}

IPAddress HNS::lookup(const HostName& name) const {
    size_t hash = std::hash<HostName>{}(name) % hosts.size();
    auto result = std::find_if(hosts.at(hash).begin(), hosts.at(hash).end(),
        [&](const NameEntry& entry) { return entry.first == name; });
    
    if (result != hosts.at(hash).end()) {
        return (*result).second;
    } else {
        return NON_EXISTING_ADDRESS;
    }
}