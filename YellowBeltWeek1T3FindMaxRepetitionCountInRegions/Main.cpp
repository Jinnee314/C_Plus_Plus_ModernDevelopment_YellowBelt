#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstdint>
#include <tuple>
#include <algorithm>

enum class Lang {
	DE, FR, IT
};

struct Region {
	std::string std_name;
	std::string parent_std_name;
	std::map<Lang, std::string> names;
	int64_t population;
};

bool operator<(const Region& l, const Region& r)
{
    return std::tie(l.std_name, l.parent_std_name, l.names, l.population) < std::tie(r.std_name, r.parent_std_name, r.names, r.population);
}

bool operator==(const Region& l, const Region& r)
{
    return std::tie(l.std_name, l.parent_std_name, l.names, l.population) == std::tie(r.std_name, r.parent_std_name, r.names, r.population);
}

uint32_t FindMaxRepetitionCount(const std::vector<Region>& regions)
{
    size_t sizeVec = regions.size();
    if (sizeVec == 0)
    {
        return 0;
    }

    std::vector<Region> copy(regions);

    std::sort(copy.begin(), copy.end());

    uint32_t maxRepetitionNum = 1, repetitionNum = 1;

    for (size_t i = 1; i < sizeVec; ++i)
    {
        if (copy[i - 1] == copy[i])
        {
            ++repetitionNum;
        }
        else
        {
            if (maxRepetitionNum < repetitionNum)
            {
                maxRepetitionNum = repetitionNum;
            }
            repetitionNum = 1;
        }
    }

    return maxRepetitionNum;
}

int main() {
    std::cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
        }) << std::endl;

    std::cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
        }) << std::endl;

    return 0;
}