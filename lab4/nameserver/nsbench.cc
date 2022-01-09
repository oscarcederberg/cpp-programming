#include <benchmark/benchmark.h>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#define USE_HASH

#include "nameserverinterface.h"
#include "vns.h"
#include "mns.h"
#include "umns.h"
#ifdef USE_HASH
#include "hns.h"
#endif


using dns_record = std::pair<HostName, IPAddress>;
struct static_data {

    static_data();

    int seed;
    std::vector<dns_record> data;
	VNS vns;
	MNS mns;
	UMNS umns;
#ifdef USE_HASH
	/*
	 * The hash table implementation. The size of the hash table is
	 * a parameter to the constructor.
	 */
	HNS hns{17441};
#endif
} the_objects;

static_data::static_data()
{
        /*
        * data is a vector containing the name/address pairs. Used by the
        * do_lookup() function.
        */
        cout << "enter seed: " << std::ends;
        cin >> seed;

        std::ifstream in("nameserverdata.txt");
        if (!in) {
           // hack to run from a build directory under the source directory
           cout << "Could not open data file (nameserverdata.txt), trying in parent directory" << endl;
           in.open("../nameserverdata.txt");
        }
        
        if (!in) {
            cerr << "Could not open data file (nameserverdata.txt), exiting" << endl;
            exit(1);
        }

        /*
        * Read the input file, store in the data vector. At the same time,
        * insert the data into the name servers.
        */
        cout << "Reading ..." << std::flush;
        HostName name;
        IPAddress nbr;
        while (in >> name >> nbr) {
            data.push_back(dns_record(name, nbr));
            vns.insert(name, nbr);
            mns.insert(name, nbr);
            umns.insert(name, nbr);
#ifdef USE_HASH
            hns.insert(name, nbr);
#endif
        }
        cout << " read " << data.size() << " words." << endl;

}
class ns_bench : public benchmark::Fixture {

public:
    ns_bench() :re(the_objects.seed), dist(0, the_objects.data.size()-1) {cout << "Creating Fixture\n";}

private:
    void SetUp(const ::benchmark::State&) {
        re = std::default_random_engine(the_objects.seed);
    }

    void TearDown(const ::benchmark::State&){
        // the_vector.clear();
    }


public:
    std::default_random_engine re;
    std::uniform_int_distribution<unsigned int> dist;
};

void do_lookup(const NameServerInterface& ns,
               const std::vector<dns_record>& data,
               int j) {
    HostName name = data[j].first;
    if (name == "") {cout << j <<"-->empty name??? \n";}
    IPAddress address = ns.lookup(name);
    if (address == NON_EXISTING_ADDRESS) {
        cerr << "Error: " << name << " not found" << endl;
    } else if (address != data[j].second) {
        cerr << "Error: " << name << " returned wrong address, "
            << address << endl;
    }
}


BENCHMARK_DEFINE_F(ns_bench, VNSTest)(benchmark::State& st) {
    for (auto _ : st) {
        do_lookup(the_objects.vns, the_objects.data, dist(re));
    }
}

BENCHMARK_DEFINE_F(ns_bench, MNSTest)(benchmark::State& st) {
    for (auto _ : st) {
        do_lookup(the_objects.mns, the_objects.data, dist(re));
    }
}

BENCHMARK_DEFINE_F(ns_bench, UMNSTest)(benchmark::State& st) {
    for (auto _ : st) {
        do_lookup(the_objects.umns, the_objects.data, dist(re));
    }
}

#ifdef USE_HASH
BENCHMARK_DEFINE_F(ns_bench, HNSTest)(benchmark::State& st) {
    for (auto _ : st) {
        do_lookup(the_objects.hns, the_objects.data, dist(re));
    }
}
#endif
BENCHMARK_REGISTER_F(ns_bench, VNSTest);
BENCHMARK_REGISTER_F(ns_bench, MNSTest);
BENCHMARK_REGISTER_F(ns_bench, UMNSTest);
#ifdef USE_HASH
BENCHMARK_REGISTER_F(ns_bench, HNSTest);
#endif

BENCHMARK_MAIN();

