#include "Date.hpp"
#include <string>
#include <utility>

//Date::Date() : year(0), month(1), day(1)
//{}

Date::Date(const uint32_t year, const uint32_t month, const uint32_t day) : year(year), month(month), day(day)
{}

Date::Date(const Date& date) : year(date.year), month(date.month), day(date.day)
{}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	return out << std::string(4 - std::to_string(date.year).size(), '0') << date.year << "-"
		<< (date.month < 10 ? "0" : "") << date.month << "-"
		<< (date.day < 10 ? "0" : "") << date.day;
}

bool operator<(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) < std::tie(r.year, r.month, r.day);
}

bool operator<=(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) <= std::tie(r.year, r.month, r.day);
}

bool operator>(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) > std::tie(r.year, r.month, r.day);
}

bool operator>=(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) >= std::tie(r.year, r.month, r.day);
}

bool operator==(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) == std::tie(r.year, r.month, r.day);
}

bool operator!=(const Date& l, const Date& r)
{
	return std::tie(l.year, l.month, l.day) != std::tie(r.year, r.month, r.day);
}

Date ParseDate(std::istringstream& is)
{
	std::string data = "";

	is >> data;

	auto pos1 = data.find('-');
	auto pos2 = data.find('-', pos1 + 1);

	int year = static_cast<uint32_t>(std::stoi(data.substr(0, pos1)));
	int month = static_cast<uint32_t>(std::stoi(data.substr(pos1 + 1, pos2)));
	int day = static_cast<uint32_t>(std::stoi(data.substr(pos2 + 1)));

	return Date(year, month, day);
}