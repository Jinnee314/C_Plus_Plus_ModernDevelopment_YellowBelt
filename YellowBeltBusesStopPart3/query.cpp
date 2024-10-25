#include "query.h"

std::istream& operator>>(std::istream& is, Query& q) 
{
    std::string queryType = "";
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