#pragma once
#include "Date.hpp"
#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

bool operator<
(
	const std::pair<Date, std::string>& l,
	const std::pair<Date, std::string>& r
);

bool operator==
(
	const std::pair<Date, std::string>& l,
	const std::pair<Date, std::string>& r
);

std::ostream& operator<<(std::ostream& out, const std::pair<Date, std::string>& val);

std::ostream& operator<<(std::ostream& out, const std::pair<Date, std::vector<std::string>>& val);

class Database
{
private:
	std::map<Date, std::vector<std::string>> database;

public:
	void Add(const Date& date, const std::string& event);

	void Print(std::ostream& out);

	template <class predFunc>
	int RemoveIf(predFunc predicate) {
		uint32_t count = 0;
		auto it = database.begin();
		while ( it != database.end())
		{
			auto posEnd = std::remove_if(it->second.begin(), it->second.end(),
				[&](const std::string str) { return predicate(it->first, str); });

			if (posEnd == it->second.begin())
			{
				count += static_cast<uint32_t>(it->second.size());
				it = database.erase(it);
			}
			else
			{
				if (posEnd != it->second.end())
				{
					count += static_cast<uint32_t>(std::distance(posEnd, it->second.end()));
					it->second.erase(posEnd, it->second.end());
				}
				++it;
			}

		}

		return count;
	}

	template<class predFunc>
	std::vector<std::pair<Date, std::string>> FindIf(predFunc predicate)
	{
		std::vector< std::pair<Date, std::string>> res;

		auto it = database.begin();
		for (it; it != database.end(); ++it)
		{
			for (const auto& e : it->second)
			{
				if (predicate(it->first, e))
				{
					res.push_back(std::move(std::make_pair(it->first, e)));
				}
			}
		}

		return res;
	}

	std::pair<Date, std::string> Last(const Date& date);
};

