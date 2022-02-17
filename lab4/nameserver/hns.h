#ifndef HNS_H
#define HNS_H

#include <vector>

#include "nameserverinterface.h"

class HNS : public NameServerInterface {
public:
    HNS(size_t size);
    void insert(const HostName&, const IPAddress&);
	bool remove(const HostName&);
	IPAddress lookup(const HostName&) const;
private:
    std::vector<std::vector<NameEntry>> hosts;
};

#endif