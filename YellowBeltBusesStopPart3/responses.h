#pragma once
#include <iostream>
#include <string>

struct BusesForStopResponse {
    std::string out;
};

std::ostream& operator<<(std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    std::string out;
};

std::ostream& operator<<(std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    std::string out;
};

std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r);