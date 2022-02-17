#ifndef VNS_H
#define VNS_H

#include <vector>
#include <utility>

#include "nameserverinterface.h"

class VNS : public NameServerInterface {
public:
    VNS(){}
    void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
    std::vector<NameEntry> hosts;
};

#endif