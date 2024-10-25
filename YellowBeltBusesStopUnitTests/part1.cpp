#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using MapBus = std::map<std::string, std::vector<std::string>>;
using MapStops = std::map<std::string, std::vector<std::string>>;

void newBus(MapBus& buses, MapStops& stops, std::stringstream& ss)
{
	std::string name;
	ss >> name;

	int32_t numStops = 0;
	ss >> numStops;

	std::string stop;
	for (int32_t i = 0; i < numStops; ++i)
	{
		ss >> stop;
		buses[name].push_back(stop);
		stops[stop].push_back(name);
	}
}

std::string busesForStop(const MapStops& stops, const std::string& stop)
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

	return ss.str();
}

std::string stopsForBuses(const MapBus& buses, const MapStops& stops, const std::string& nameBus)
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

	return ss.str();
}

std::string allBuses(const MapBus& buses)
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

	return ss.str();
}

int part1()
{
	int32_t count = 0;
	std::string enter;
	std::string buff;

	std::cout << "Enter:\n";
	std::getline(std::cin, buff);

	count = std::stoi(buff);

	for (int32_t i = 0; i < count; ++i)
	{
		std::getline(std::cin, buff);
		enter += buff + "\n";
	}

	std::cout << "\nOUT:\n";

	MapBus buses;
	MapStops stops;

	std::stringstream ss(enter);

	std::string command = "";
	std::string str = "";

	for (int32_t i = 0; i < count; ++i)
	{
		ss >> command;

		if (command == "NEW_BUS")
		{
			newBus(buses, stops, ss);
		}
		else if (command == "BUSES_FOR_STOP")
		{
			ss >> str;
			std::cout << busesForStop(stops, str);
		}
		else if (command == "STOPS_FOR_BUS")
		{
			ss >> str;
			std::cout << stopsForBuses(buses, stops, str);
		}
		else if (command == "ALL_BUSES")
		{
			std::cout << allBuses(buses);
		}

	}

	return 0;
}

