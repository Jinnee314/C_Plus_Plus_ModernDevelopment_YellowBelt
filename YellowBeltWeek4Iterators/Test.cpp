#include "Test.hpp"
#include "func.hpp"
#include <set>
#include <string>
#include <map>

void testFindGreaterElements()
{
	std::set<int> testVec{ 1,3,5,7,9,11,13 };

	std::set<std::string> testSet{ "sdf", "qqq", "aac", "aab", "bbs" };
	

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 5), std::vector<int>{ 7, 9, 11, 13 }, "testVec. 5");

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 6), std::vector<int>{ 7, 9, 11, 13 }, "testVec. 6");

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 1), std::vector<int>{ 3, 5, 7, 9, 11, 13 }, "testVec. 1");

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 0), std::vector<int>{ 1, 3, 5, 7, 9, 11, 13 }, "testVec. 0");

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 13), std::vector<int>{}, "testVec. 13");

	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 14), std::vector<int>{}, "testVec. 14");

	testVec.clear();
	MyUnitTest::AssertEqual(FindGreaterElements(testVec, 6), std::vector<int>{}, "testVec empty. 6");

	std::string bs = "aaa";
	MyUnitTest::AssertEqual(FindGreaterElements(testSet, bs), std::vector<std::string>{"aab", "aac", "bbs", "qqq", "sdf"  }, "testSet. aaa");

	bs = "aac";
	MyUnitTest::AssertEqual(FindGreaterElements(testSet, bs), std::vector<std::string>{"bbs", "qqq", "sdf" }, "testSet. aac");

	bs = "zzz";
	MyUnitTest::AssertEqual(FindGreaterElements(testSet, bs), std::vector<std::string>{ }, "testSet. zzz");

	bs = "ddd";
	MyUnitTest::AssertEqual(FindGreaterElements(testSet, bs), std::vector<std::string>{ "qqq", "sdf" }, "testSet. ddd");
}

template <class T>
bool checkDuplication(const std::vector<T> vec)
{
	std::map<T, int> check;

	for (const auto& e : vec)
	{
		++check[e];
	}

	auto pos = std::find_if(check.begin(), check.end(),
		[](std::pair<T, int> p)
		{
			return p.second > 1;
		});

	return pos == check.end();
}

void testRemoveDuplicates()
{
	std::vector<int> test1{ 1,2,3,4,5,1,2,3,4,5,2,3,4,10,4,2,4 };
	RemoveDuplicates(test1);
	MyUnitTest::Assert(checkDuplication(test1), "checkDuplication test 1");

	std::vector<std::string> test2{ "str", "sss", "we", "w", "we", "sss", "str" };
	RemoveDuplicates(test2);
	MyUnitTest::Assert(checkDuplication(test2), "checkDuplication test 2");
}

void testFindNearestElement()
{
	const std::set<int> testNum{ 1,3,5,6,9,11,13 };

	MyUnitTest::AssertEqual(*FindNearestElement(testNum, 8), 9, "testNum. 8");

	MyUnitTest::Assert(*FindNearestElement(testNum, 10) == 9 || *FindNearestElement(testNum, 10) == 11, "testNum. Two var");

	MyUnitTest::AssertEqual(*FindNearestElement(testNum, 0), 1, "testNum. 0");
	
	MyUnitTest::AssertEqual(*FindNearestElement(testNum, 14), 13, "testNum. 14");
}

void TestChangeFirstNameLastName()
{
	PersonLastFirsName p;

	p.ChangeFirstName(2000, "Polina");
	p.ChangeLastName(2005, "Puchkina");

	MyUnitTest::AssertEqual(p.GetFullName(1999), "Incognito", "Incognito");
	MyUnitTest::AssertEqual(p.GetFullName(2000), "Polina with unknown last name", "Polina 2000");
	MyUnitTest::AssertEqual(p.GetFullName(2002), "Polina with unknown last name", "Polina 2002");
	MyUnitTest::AssertEqual(p.GetFullName(2006), "Polina Puchkina", "Polina Puchkina");

	p.ChangeFirstName(2003, "Alina");
	MyUnitTest::AssertEqual(p.GetFullName(2002), "Polina with unknown last name", "Polina");
	MyUnitTest::AssertEqual(p.GetFullName(2004), "Alina with unknown last name", "Alina");
	MyUnitTest::AssertEqual(p.GetFullName(2006), "Alina Puchkina", "Alina Puchkina");

	p.ChangeFirstName(2003, "Kate");
	MyUnitTest::AssertEqual(p.GetFullName(2004), "Kate with unknown last name", "Kate");
	MyUnitTest::AssertEqual(p.GetFullName(2006), "Kate Puchkina", "Kate Puchkina");

	p.ChangeLastName(2003, "Kort");
	MyUnitTest::AssertEqual(p.GetFullName(2000), "Polina with unknown last name", "Polina");
	MyUnitTest::AssertEqual(p.GetFullName(2004), "Kate Kort", "Kate Kort");
	MyUnitTest::AssertEqual(p.GetFullName(2006), "Kate Puchkina", "Kate Puchkina");
}

void runTest()
{
	MyUnitTest::TestRunner tr;

	//tr.RunTest(testFindGreaterElements, "testFindGreaterElements");
	//tr.RunTest(testRemoveDuplicates, "testRemoveDuplicates");
	//tr.RunTest(testFindNearestElement, "testFindNearestElement");
	tr.RunTest(TestChangeFirstNameLastName, "TestChangeFirstNameLastName");
}