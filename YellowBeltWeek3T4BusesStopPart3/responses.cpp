#include "responses.h"

std::ostream& operator<<(std::ostream& os, const BusesForStopResponse& r) {
    os << r.out;
    return os;
}

std::ostream& operator<<(std::ostream& os, const StopsForBusResponse& r) {
    os << r.out;
    return os;
}

std::ostream& operator<<(std::ostream& os, const AllBusesResponse& r) {
    os << r.out;
    return os;
}