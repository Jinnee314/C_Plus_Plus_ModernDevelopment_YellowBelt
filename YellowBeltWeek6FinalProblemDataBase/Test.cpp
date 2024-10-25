#include "Test.hpp"
#include "condition_parser.hpp"
#include "MyUnitTestFreimwork.hpp"
#include "Database.hpp"

#include <sstream>

using namespace std;
using namespace MyUnitTest;

void TestParseCondition() {
	{
		istringstream is("date != 2017-11-18");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, ""), "Parse condition 1");
		Assert(!root->Evaluate({ 2017, 11, 18 }, ""), "Parse condition 2");
	}
	{
		istringstream is(R"(event == "sport event")");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, "sport event"), "Parse condition 3");
		Assert(!root->Evaluate({ 2017, 1, 1 }, "holiday"), "Parse condition 4");
	}
	{
		istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, ""), "Parse condition 5");
		Assert(root->Evaluate({ 2017, 3, 1 }, ""), "Parse condition 6");
		Assert(root->Evaluate({ 2017, 6, 30 }, ""), "Parse condition 7");
		Assert(!root->Evaluate({ 2017, 7, 1 }, ""), "Parse condition 8");
		Assert(!root->Evaluate({ 2016, 12, 31 }, ""), "Parse condition 9");
	}
	{
		istringstream is(R"(event != "sport event" AND event != "Wednesday")");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, "holiday"), "Parse condition 10");
		Assert(!root->Evaluate({ 2017, 1, 1 }, "sport event"), "Parse condition 11");
		Assert(!root->Evaluate({ 2017, 1, 1 }, "Wednesday"), "Parse condition 12");
	}
	{
		istringstream is(R"(event == "holiday AND date == 2017-11-18")");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(!root->Evaluate({ 2017, 11, 18 }, "holiday"), "Parse condition 13");
		Assert(!root->Evaluate({ 2017, 11, 18 }, "work day"), "Parse condition 14");
		Assert(root->Evaluate({ 1, 1, 1 }, "holiday AND date == 2017-11-18"), "Parse condition 15");
	}
	{
		istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, "holiday"), "Parse condition 16");
		Assert(!root->Evaluate({ 2017, 1, 2 }, "holiday"), "Parse condition 17");
	}
	{
		istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(!root->Evaluate({ 2016, 1, 1 }, "holiday"), "Parse condition 18");
		Assert(root->Evaluate({ 2017, 1, 2 }, "holiday"), "Parse condition 19");
		Assert(root->Evaluate({ 2017, 1, 2 }, "workday"), "Parse condition 20");
		Assert(!root->Evaluate({ 2018, 1, 2 }, "workday"), "Parse condition 21");
	}
	{
		istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2016, 1, 1 }, "event"), "Parse condition 22");
		Assert(root->Evaluate({ 2017, 1, 2 }, "holiday"), "Parse condition 23");
		Assert(root->Evaluate({ 2017, 1, 2 }, "workday"), "Parse condition 24");
		Assert(!root->Evaluate({ 2018, 1, 2 }, "workday"), "Parse condition 25");
	}
	{
		istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 2017, 1, 1 }, "holiday"), "Parse condition 26");
		Assert(!root->Evaluate({ 2017, 1, 2 }, "holiday"), "Parse condition 27");
	}
	{
		istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
		shared_ptr<Node> root = ParseCondition(is);
		Assert(root->Evaluate({ 1, 1, 1 }, "2017-01-01"), "Parse condition 28");
		Assert(!root->Evaluate({ 2016, 1, 1 }, "event"), "Parse condition 29");
		Assert(root->Evaluate({ 2016, 1, 2 }, "event"), "Parse condition 30");
	}
}

void TestParseDate()
{
	{
		istringstream is("2017-01-01");
		Date d(ParseDate(is));
		Assert(d == Date(2017, 1, 1), "ParseDate 2017-01-01");
	}
	{
		istringstream is("2017-08-15");
		Date d(ParseDate(is));
		Assert(d == Date(2017, 8, 15), "ParseDate 2017-08-15");
	}
	{
		istringstream is("1-1-1");
		Date d(ParseDate(is));
		Assert(d == Date(1, 1, 1), "ParseDate 1-1-1");
	}
}

void TestOutDate()
{
	{
		istringstream is("2017-01-01");
		Date d(ParseDate(is));
		ostringstream out;
		out << d;
		Assert(out.str() == "2017-01-01", "Out Date 2017-01-01");
	}
	{
		istringstream is("1-1-1");
		Date d(ParseDate(is));
		ostringstream out;
		out << d;
		auto res = out.str();
		AssertEqual(res, "0001-01-01", "Out Date 1-1-1");
	}
	{
		istringstream is("11-10-7");
		Date d(ParseDate(is));
		ostringstream out;
		out << d;
		Assert(out.str() == "0011-10-07", "Out Date 11-10-7");
	}
	{
		istringstream is("111-6-20");
		Date d(ParseDate(is));
		ostringstream out;
		out << d;
		Assert(out.str() == "0111-06-20", "Out Date 111-6-20");
	}
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestParseDate, "TestParseDate");
	tr.RunTest(TestOutDate, "TestOutDate");
	tr.RunTest(TestParseCondition, "TestParseCondition");
}
