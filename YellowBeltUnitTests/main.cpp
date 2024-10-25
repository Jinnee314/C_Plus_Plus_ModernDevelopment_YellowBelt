#include "MyUnitTestFreimwork.hpp"

#include <iostream>
#include <map>
#include <set>
#include <vector>

std::map<int, int> createMap(int countKey)
{
	std::map<int, int> res;

	for (int i = 0; i < countKey; ++i)
	{
		res[i] = -i;
	}

	return res;
}

void TestCreateMap()
{
	std::map<int, int> proof = {
		{0,0},
		{1,-1},
		{2,-2},
		{3,-3}
	};

	MyUnitTest::AssertEqual(createMap(3), proof, "Check createMap");

	std::cout << "All ok\n";
}

int main()
{
	MyUnitTest::TestRunner tr;

	tr.RunTest(TestCreateMap, "TestCreateMap");

	return 0;
}