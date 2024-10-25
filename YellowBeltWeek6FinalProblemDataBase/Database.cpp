#include "Database.hpp"
#include <stdexcept>
#include <unordered_set>

bool operator<
	(
		const std::pair<Date, std::string>& l,
		const std::pair<Date, std::string>& r
		)
{
	return l.first == r.first ? false : l.first < r.first;
}

bool operator==
(
	const std::pair<Date, std::string>& l,
	const std::pair<Date, std::string>& r
	)
{

	return l.first == r.first && l.second == r.second;
}

std::ostream& operator<<(std::ostream& out, const std::pair<Date,std::string>& val)
{
	out << val.first << " " << val.second;
	
	return out;
}

std::ostream& operator<<(std::ostream& out, const std::pair<Date, std::vector<std::string>>& val)
{
	for (const auto& el : val.second)
	{
		out << val.first << " " << el << "\n";
	}
	return out;
}

void Database::Add(const Date& date, const std::string& event)
{
	if (database.contains(date))
	{
		auto pos = std::find(database.at(date).begin(), database.at(date).end(), event);
		if (pos == database.at(date).end())
		{
			database.at(date).push_back(event);
		}
	}
	else
	{
		database[date].push_back(event);
	}
}

void Database::Print(std::ostream& out)
{
	for (const auto& el : database)
	{
		out << el;
	}
}

std::pair<Date, std::string> Database::Last(const Date& date)
{
	auto it = database.upper_bound(date);

	if (it == database.begin())
	{
		throw std::invalid_argument("No entries");
	}

	it = std::prev(it);
	return std::make_pair(it->first, it->second.back());
}