#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

// INTERFACE

enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;  // �������
	Gender gender;  // ���
	bool is_employed;  // ����� �� ������
};

void PrintVectorPart(const std::vector<int>& numbers);

/*
	�������� ��������� ������� FindGreaterElements, 
	����������� ��������� elements �������� ���� T 
	� ��� ���� ������ border ���� T � ������������ ������ �� ���� ��������� ���������,
	������� border, � ������������ �������.
*/
template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border);

template <typename T>
void RemoveDuplicates(std::vector<T>& elements);

void PrintPermutation(int n);

void PrintStats(std::vector<Person> persons);

/*
	�������� ��������� ������� MergeSort, ����������� ��� ��������� ���������� 
	���� RandomIt � ����������� �������� ��� �������� � ������� ���������� ��������.
	��������� �� 2 �����
*/
template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end);

/*
	�������� ��������� ������� MergeSort, ����������� ��� ��������� ����������
	���� RandomIt � ����������� �������� ��� �������� � ������� ���������� ��������.
	��������� �� 3 �����
*/
template <typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end);

std::set<int>::const_iterator FindNearestElement
(
	const std::set<int>& numbers,
	int border
);
// set<int>::const_iterator �
// ��� ���������� ��� ������������ ��������� ����� �����

class PersonLastFirsName
{
	std::map<int, std::string> firstName;
	std::map<int, std::string> lastName;
public:
	// �������� ���� ��������� ����� �� first_name � ��� year
	void ChangeFirstName(int year, const std::string& first_name);

	// �������� ���� ��������� ������� �� last_name � ��� year
	void ChangeLastName(int year, const std::string& last_name);

	// �������� ��� � ������� �� ��������� �� ����� ���� year
	// � ������� ��������� ������
	std::string GetFullName(int year);
};

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith
(
	RandomIt range_begin, RandomIt range_end,
	char prefix
);

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith
(
	RandomIt range_begin, RandomIt range_end,
	const std::string& prefix
);

// IMPLEMENTATION

template <typename T>
void RemoveDuplicates(std::vector<T>& elements)
{
	std::sort(elements.begin(), elements.end());

	auto end = std::unique(elements.begin(), elements.end());
	elements.erase(end, elements.end());
}

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border)
{
	std::vector<T> res;
	std::copy_if(elements.begin(), elements.end(),
		std::back_inserter(res),
		[border](const auto& elem)
		{
			return elem > border;
		});

	return res;
}

template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end)
{
	if (range_end - range_begin < 2)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto middle = elements.begin() + elements.size() / 2;

	MergeSort2(elements.begin(), middle);
	MergeSort2(middle, elements.end());

	std::merge(elements.begin(), middle, middle, elements.end(), range_begin);
}

template <typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end)
{
	if (range_end - range_begin < 3)
	{
		return;
	}

	std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto secondThird = elements.begin() + elements.size() / 3;
	auto thirdThird = secondThird + elements.size() / 3;

	MergeSort3(elements.begin(), secondThird);
	MergeSort3(secondThird, thirdThird);
	MergeSort3(thirdThird, elements.end());

	std::vector<typename RandomIt::value_type> temp;
	std::merge(elements.begin(), secondThird, secondThird, thirdThird, std::back_inserter(temp));
	std::merge(temp.begin(), temp.end(), thirdThird, elements.end(), range_begin);
}

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith
(
	RandomIt range_begin, RandomIt range_end,
	char prefix
)
{
	std::string pref{ prefix };
	auto range = std::equal_range(range_begin, range_end, pref,
		[](const typename RandomIt::value_type& str1, const typename RandomIt::value_type& str2)
		{
			return str1[0] < str2[0];
		});

	return range;
}

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith
(
	RandomIt range_begin, RandomIt range_end,
	const std::string& prefix
)
{
	auto start = std::lower_bound(range_begin, range_end, prefix);
	std::string copy = prefix;
	++copy.back();
	auto end = std::lower_bound(range_begin, range_end, copy);

	return std::make_pair(start, end);
}
