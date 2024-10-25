#include "MyUnitTestFreimwork.hpp"
#include <iostream>

bool IsPalindrome(const std::string& str)
{
	if (str == "" || str.size() == 1)
	{
		return true;
	}

	for (size_t i = 0; i <= str.size() / 2; ++i)
	{
		if (str.at(i) != str.at(str.size() - 1 - i))
		{
			return false;
		}
	}

	return true;
}

void SetTests()
{
	MyUnitTest::AssertEqual(IsPalindrome(""), true, "\"\"");

	MyUnitTest::AssertEqual(IsPalindrome("not"), false, "not");
	
	MyUnitTest::AssertEqual(IsPalindrome("n"), true, "n");

	MyUnitTest::AssertEqual(IsPalindrome("n n"), true, "n n");

	MyUnitTest::AssertEqual(IsPalindrome("n  n"), true, "n  n");

	MyUnitTest::AssertEqual(IsPalindrome("level"), true, "level");

	MyUnitTest::AssertEqual(IsPalindrome("nototo"), false, "nototo");

	MyUnitTest::AssertEqual(IsPalindrome("notonn"), false, "notonn");

	MyUnitTest::AssertEqual(IsPalindrome("noon"), true, "noon");

	MyUnitTest::AssertEqual(IsPalindrome("n N"), false, "n N");

	MyUnitTest::AssertEqual(IsPalindrome("levEl"), false, "levEl");

	MyUnitTest::AssertEqual(IsPalindrome("levelAlevel"), true, "levelAlevel");

	MyUnitTest::AssertEqual(IsPalindrome(" n n"), false, " n n");

	MyUnitTest::AssertEqual(IsPalindrome(" n n "), true, " n n ");

	MyUnitTest::AssertEqual(IsPalindrome("                                 n"), false, "                                 n");

	MyUnitTest::AssertEqual(IsPalindrome("                                 "), true, "                                 ");

	MyUnitTest::AssertEqual(IsPalindrome("lev vel"), true, "lev vel");

	MyUnitTest::AssertEqual(IsPalindrome("lev Vel"), false, "lev Vel");
}

void RunTest()
{
	MyUnitTest::TestRunner tr;

	tr.RunTest(SetTests, "SetTests");
}

int main()
{
	RunTest();

	return 0;
}