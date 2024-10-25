#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& vecStops)
{
    for (const auto& stop : vecStops)
    {
        buses[bus].push_back(stop);
        stops[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const
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

StopsForBusResponse BusManager::GetStopsForBus(const std::string& nameBus) const
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

AllBusesResponse BusManager::GetAllBuses() const
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