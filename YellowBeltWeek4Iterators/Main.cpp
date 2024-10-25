#include <iostream>
#include "func.hpp"
#include "Test.hpp"
#include <deque>

void arithmeticExpressions()
{
	std::cout << "Enter number: ";
	int num = 0;
	std::cin >> num;

	std::cout << "Enter number operations: ";
	int numOp = 0;
	std::cin >> numOp;

	if (numOp <= 0)
	{
		std::cout << num << "\n";
		return;
	}

	std::string res(numOp, '(');
	res += std::to_string(num);

	std::string buff = "";
	std::getline(std::cin, buff);
	for(int i = 0; i < numOp; ++i)
	{
		std::getline(std::cin, buff);
		res += ") " + buff;
	}

	std::cout << res << "\n";
}

void arithmeticExpressions2()
{
	std::cout << "Enter number: ";
	int num = 0;
	std::cin >> num;

	std::cout << "Enter number operations: ";
	int numOp = 0;
	std::cin >> numOp;

	if (numOp <= 0)
	{
		std::cout << num << "\n";
		return;
	}

	std::deque<std::string> express;
	express.push_back(std::to_string(num));

	std::string buff = "";
	std::getline(std::cin, buff);
	for (size_t i = 0; i < numOp; ++i)
	{
		std::getline(std::cin, buff);

		if (i > 0)
		{
			if (buff[0] == '*' || buff[0] == '/')
			{
				if (express.back()[1] == '+' || express.back()[1] == '-') 
				{
					express.push_front("(");
					express.push_back(")");
				}
			}
		}

		express.push_back(" " + buff);
	}

	for (const auto& e : express)
	{
		std::cout << e;
	}
}

int main()
{
	arithmeticExpressions2();

	//std::vector<std::string> vec{ "c", "cccc", "cca", "ca", "a", "ccb", "cce", "ccaaaa", "caaaaaaaaaaaaaaa", "z", "zzz"};
	//std::sort(vec.begin(), vec.end());
	//std::cout << vec << "\n";
	//std::string prefix = "cc";
	//auto startR = std::lower_bound(vec.begin(), vec.end(), prefix);
	//std::cout << *startR << "\n";
	//++prefix.back();
	//auto endR = std::lower_bound(vec.begin(), vec.end(), prefix);
	//std::cout << *endR << "\n";
	//std::for_each(startR, endR,
	//	[](std::string str)
	//	{
	//		std::cout << str << " ";
	//	});
	

	//runTest();
	
	/*std::vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;*/

	//MergeSort2
	/*std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort2(begin(v), end(v));
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;*/

	//MergeSort3
	/*std::vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort3(begin(v), end(v));
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	return 0;*/

	//FindStartsWith
	/*const std::vector<std::string> sorted_strings = { "moscow", "motovilikha", "murmansk", "vologda" };

	const auto m_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "m");
	for (auto it = m_result.first; it != m_result.second; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << std::endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	std::cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << std::endl;*/

	return 0;
}