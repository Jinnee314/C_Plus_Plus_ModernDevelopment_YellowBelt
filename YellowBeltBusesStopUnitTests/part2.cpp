#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator>>(istream& is, Query& q) {
    string queryType = "";
    is >> queryType;

    if (queryType == "NEW_BUS")
    {
        q.type = QueryType::NewBus;
        size_t countStops = 0;

        is >> q.bus >> countStops;

        q.stops.resize(countStops);

        for (size_t i = 0; i < countStops; ++i)
        {
            is >> q.stops[i];
        }
    }
    else if (queryType == "BUSES_FOR_STOP")
    {
        q.type = QueryType::BusesForStop;

        is >> q.stop;
    }
    else if (queryType == "STOPS_FOR_BUS")
    {
        q.type = QueryType::StopsForBus;

        is >> q.bus;
    }
    else if (queryType == "ALL_BUSES")
    {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse {
    string out;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
    os << r.out;
    return os;
}

struct StopsForBusResponse {
    string out;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
    os << r.out;
    return os;
}

struct AllBusesResponse {
    string out;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r) {
    os << r.out;
    return os;
}

using MapBus = std::map<std::string, std::vector<std::string>>;
using MapStops = std::map<std::string, std::vector<std::string>>;

class BusManager {
private:
    MapBus buses;
    MapStops stops;

public:
    void AddBus(const string& bus, const vector<string>& vecStops) 
    {
        for (const auto& stop : vecStops)
        {
            buses[bus].push_back(stop);
            stops[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const 
    {
        std::stringstream ss;

        bool first = true;

        if (!stops.contains(stop))
        {
            ss << "No stop.\n";
        }
        else
        {
            for (const auto& elem : stops.at(stop))
            {
                if (!first)
                {
                    ss << " ";
                }
                first = false;
                ss << elem;
            }

            ss << "\n";
        }

        BusesForStopResponse r;
        r.out = ss.str();
        return r;
    }

    StopsForBusResponse GetStopsForBus(const string& nameBus) const 
    {
        std::stringstream ss;

        if (buses.contains(nameBus))
        {
            for (const auto& stop : buses.at(nameBus))
            {
                ss << "Stop " << stop << ":";
                if (stops.at(stop).size() == 1)
                {
                    ss << " no interchange\n";
                }
                else
                {
                    for (const auto& bus : stops.at(stop))
                    {
                        if (bus != nameBus)
                        {
                            ss << " " << bus;
                        }
                    }

                    ss << "\n";
                }
            }
        }
        else
        {
            ss << "No bus.\n";
        }

        StopsForBusResponse r;
        r.out = ss.str();
        return r;
    }

    AllBusesResponse GetAllBuses() const 
    {
        std::stringstream ss;

        if (buses.empty())
        {
            ss << "No buses.\n";
        }
        else
        {
            for (const auto& [bus, vecStop] : buses)
            {
                ss << "Bus " << bus << ":";

                for (const auto& stop : vecStop)
                {
                    ss << " " << stop;
                }
                ss << "\n";
            }
        }

        AllBusesResponse r;
        r.out = ss.str();
        return r;
    }
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}
