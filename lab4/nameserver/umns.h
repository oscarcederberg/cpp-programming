#ifndef UMNS_H
#define UMNS_H

#include <unordered_map>

#include "nameserverinterface.h"

class UMNS : public NameServerInterface {
public:
    UMNS(){}
    void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
    std::unordered_map<HostName, IPAddress> hosts;
};

#endif