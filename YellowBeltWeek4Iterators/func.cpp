#include "func.hpp"
#include <algorithm>
#include <iostream>

void PrintVectorPart(const std::vector<int>& numbers)
{
	auto posFirstNegative = std::find_if(numbers.begin(), numbers.end(),
		[](const int num)
		{
			return num < 0;
		});

	for (auto it = posFirstNegative; it != numbers.begin(); )
	{
		std::cout << *(--it) << " ";
	}
	std::cout << "\n";
}

void PrintPermutation(int n)
{
	if (n > 9 || n < 0)
	{
		throw std::invalid_argument("n not in [0,9]");
	}

	std::vector<int> per(n);
	for (int i = 0; i < n; ++i)
	{
		per[i] = n - i;
	}
	std::vector<int> end = per;

	do
	{
		std::for_each(per.begin(), per.end(),
			[](int a)
			{
				std::cout << a << " ";
			});
		std::cout << "\n";
		std::prev_permutation(per.begin(), per.end());
	} while (per != end);
}

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
			return lhs.age < rhs.age;
		}
	);
	return middle->age;
}

void PrintStats(std::vector<Person> persons)
{
	std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << "\n";

	auto posStartMale = std::partition(persons.begin(), persons.end(),
		[](Person person)
		{
			return person.gender == Gender::FEMALE;
		});

	auto posUnemployedWoman = std::partition(persons.begin(), posStartMale,
		[](Person person)
		{
			return person.is_employed;
		});

	auto posUnemployedMale = std::partition(posStartMale, persons.end(),
		[](Person person)
		{
			return person.is_employed;
		});

	std::cout << "Median age for females = "
		<< ComputeMedianAge(persons.begin(), posStartMale) << "\n";

	std::cout << "Median age for males = "
		<< ComputeMedianAge(posStartMale, persons.end()) << "\n";

	std::cout << "Median age for employed female = "
		<< ComputeMedianAge(persons.begin(), posUnemployedWoman) << "\n";

	std::cout << "Median age for unemployed females = "
		<< ComputeMedianAge(posUnemployedWoman, posStartMale) << "\n";

	std::cout << "Median age for employed males = "
		<< ComputeMedianAge(posStartMale, posUnemployedMale) << "\n";

	std::cout << "Median age for unemployed males = "
		<< ComputeMedianAge(posUnemployedMale, persons.end()) << "\n";
}

std::set<int>::const_iterator FindNearestElement
(
	const std::set<int>& numbers,
	int border
)
{
	auto maxNear = numbers.lower_bound(border);

	if (maxNear == numbers.begin())
	{
		return maxNear;
	}

	auto minNear = std::prev(maxNear);
	if (maxNear == numbers.end())
	{
		return minNear;
	}

	return border - *minNear <= *maxNear - border ? minNear : maxNear;
}

void PersonLastFirsName::ChangeFirstName(int year, const std::string& first_name)
{
	firstName[year] = first_name;
}

void PersonLastFirsName::ChangeLastName(int year, const std::string& last_name)
{
	lastName[year] = last_name;
}

std::string getNameByYear(const std::map<int, std::string> names, int year)
{
	if (names.empty() || year < names.begin()->first)
	{
		return "";
	}

	std::string res = "";

	auto pos = names.lower_bound(year);

	if (pos == names.end() || !names.contains(year))
	{
		return std::prev(pos)->second;
	}

	return pos->second;

}

std::string PersonLastFirsName::GetFullName(int year)
{
	std::string res;

	auto fName = std::move(getNameByYear(firstName, year));
	auto lName = std::move(getNameByYear(lastName, year));

	if (fName == "" && lName == "")
	{
		return "Incognito";
	}

	if (fName == "")
	{
		return lName + " with unknown first name";
	}

	if (lName == "")
	{
		return fName + " with unknown last name";
	}

	return fName + " " + lName;
}