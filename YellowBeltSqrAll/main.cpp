#include <iostream>
#include <vector>
#include <map>

template<typename First, typename Second>
std::map<First, Second> Sqr(const std::map<First, Second>& m);

template<typename T>
std::vector<T> Sqr(const std::vector<T>& v);

template<typename T>
T Sqr(T x);

template<typename First, typename Second>
std::pair<First, Second> operator * (const std::pair<First, Second>& left, const std::pair<First, Second>& right)
{
	return std::make_pair(left.first * right.first, left.second * right.second);
}

template<typename T>
T Sqr(T x)
{
	return x * x;
}

template<typename First, typename Second>
std::map<First, Second> Sqr(const std::map<First, Second>& m)
{
	std::map<First, Second> res;

	for (const auto& [key, value] : m)
	{
		res[key] = value * value;
	}

	return res;
}

template<typename T>
std::vector<T> Sqr(const std::vector<T>& v)
{
	std::vector<T> res(v);

	for (auto& elem : res)
	{
		elem = Sqr(elem);
	}

	return res;
}


int main()
{
	std::vector<int> v = { 1, 2, 3 };
	std::cout << "vector:";
	for (int x : Sqr(v)) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;

	std::map<int, std::pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}

	std::vector<std::map<int, std::pair<int, int>>> giga = {
		{
			{4, {2, 2},},
			{7, {4, 3}}
		},
		{
			{7, {4, 3}},
			{2, {11, 32}}
		}
	};

	std::cout << "\n";

	for (const auto& elem : Sqr(giga))
	{
		for (const auto& [key, value] : elem)
		{
			std::cout << key << "{" << value.first << "," << value.second << "}" << "\n";
		}
		std::cout << "\n";
	}

	return 0;
}