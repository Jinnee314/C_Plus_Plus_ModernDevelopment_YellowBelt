#pragma once
#include <map>
#include <vector>
#include <sstream>
#include "responses.h"


using MapBus = std::map<std::string, std::vector<std::string>>;
using MapStops = std::map<std::string, std::vector<std::string>>;

class BusManager {
private:
    MapBus buses;
    MapStops stops;

public:
    void AddBus(const std::string& bus, const std::vector<std::string>& vecStops);

    BusesForStopResponse GetBusesForStop(const std::string& stop) const;

    StopsForBusResponse GetStopsForBus(const std::string& nameBus) const;

    AllBusesResponse GetAllBuses() const;
};