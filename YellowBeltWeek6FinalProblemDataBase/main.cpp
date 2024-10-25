#include "database.hpp"
#include "date.hpp"
#include "condition_parser.hpp"
#include "node.hpp"
#include "Test.hpp"
#include "MyUnitTestFreimwork.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

string ParseEvent(istream& is) {
	// Реализуйте эту функцию
	std::string buff;
	std::getline(is, buff);
	auto pos = buff.find_first_not_of(' ');
	return buff.substr(pos);
}

void runTestParseEvent();
//Add 2017-06-01 1st of June
int main() {
	runTestParseEvent();
	TestAll();

	Database db;

	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "Add") {
			const auto date = ParseDate(is);
			const auto event = ParseEvent(is);
			db.Add(date, event);
		}
		else if (command == "Print") {
			db.Print(cout);
		}
		else if (command == "Del") {
			auto condition = ParseCondition(is);
			auto predicateFunc = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
				};
			int count = db.RemoveIf(predicateFunc);
			cout << "Removed " << count << " entries" << endl;
		}
		else if (command == "Find") {
			auto condition = ParseCondition(is);
			auto predicateFunc = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
				};

			const auto entries = db.FindIf(predicateFunc);
			for (const auto& entry : entries) {
				cout << entry << endl;
			}
			cout << "Found " << entries.size() << " entries" << endl;
		}
		else if (command == "Last") {
			try {
				cout << db.Last(ParseDate(is)) << endl;
			}
			catch (invalid_argument&) {
				cout << "No entries" << endl;
			}
		}
		else if (command == "END")
		{
			break;
		}
		else if (command.empty()) {
			continue;
		}
		else {
			std::cout << "Unknown command: " << command << "\nTry again.\n";
			//throw logic_error("Unknown command: " + command);
		}
	}

	return 0;
}

void TestParseEvent() {
	{
		istringstream is("event");
		MyUnitTest::AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
	}
	{
		istringstream is("   sport event ");
		MyUnitTest::AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
	}
	{
		istringstream is("  first event  \n  second event");
		vector<string> events;
		events.push_back(ParseEvent(is));
		events.push_back(ParseEvent(is));
		MyUnitTest::AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
	}
}

void runTestParseEvent()
{
	MyUnitTest::TestRunner tr;
	tr.RunTest(TestParseEvent, "TestParseEvent");
}