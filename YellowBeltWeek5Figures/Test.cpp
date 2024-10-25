#include "Test.hpp"
#include <cmath>

void tTrianConstr()
{
	Triangle t2(0, 0, 0);
	Triangle t3(3, 4, 5);
	Triangle t4(2, 3, 10);
	Triangle t5(2, 3, 5);
}

void tTrianFunc()
{
	Triangle t1(3, 4, 5);

	MyUnitTest::Assert(t1.Name() == "TRIANGLE", "Name t1");
	MyUnitTest::Assert(t1.Perimeter() == 12, "Perimeter t1");
	MyUnitTest::Assert(t1.Area() == 6, "Area t1");

	Triangle t2(5, 7, 9);

	MyUnitTest::Assert(t2.Name() == "TRIANGLE", "Name t2");
	MyUnitTest::Assert(t2.Perimeter() == 21, "Perimeter t2");
	MyUnitTest::Assert(t2.Area() == std::sqrt(10.5 * (10.5 - 5) * (10.5 - 7) * (10.5 - 9)), "Area t2");
}

void tRectConstr()
{
	Rect r2(0,  0);
	Rect r3(3,  4);
}

void tRectFunc()
{
	Rect r1(3, 4);

	MyUnitTest::Assert(r1.Name() == "RECT", "Name r1");
	MyUnitTest::Assert(r1.Perimeter() == 14, "Perimeter r1");
	MyUnitTest::Assert(r1.Area() == 12, "Area r1");

	Rect r2(1000, 200);

	MyUnitTest::Assert(r2.Name() == "RECT",	"Name r2");
	MyUnitTest::Assert(r2.Perimeter() == 2400, "Perimeter r2");
	MyUnitTest::Assert(r2.Area() == 200'000, "Area r2");
}

void tCircleConstr()
{
	Circle c2(4);
	Circle c3(0);
}

void tCircleFunc()
{
	Circle c1(8);

	MyUnitTest::Assert(c1.Name() == "CIRCLE", "Name c1");
	MyUnitTest::Assert(c1.Perimeter() == 16 * 3.14, "Perimeter c1");
	MyUnitTest::Assert(c1.Area() == 64 * 3.14, "Area c1");

	Circle c2(400);

	MyUnitTest::Assert(c2.Name() == "CIRCLE", "Name c2");
	MyUnitTest::Assert(c2.Perimeter() == 800 * 3.14, "Perimeter c2");
	MyUnitTest::Assert(c2.Area() == 160'000 * 3.14, "Area c2");
}


void runTests()
{
	MyUnitTest::TestRunner tr;

	//tr.RunTest(tTrianConstr,	"tTrianConstr");
	tr.RunTest(tTrianFunc,		"tTrianFunc");
	//tr.RunTest(tRectConstr,		"tRectConstr");
	tr.RunTest(tRectFunc,		"tRectFunc");
	//tr.RunTest(tCircleConstr,	"tCircleConstr");
	tr.RunTest(tCircleFunc,		"tCircleFunc");
}