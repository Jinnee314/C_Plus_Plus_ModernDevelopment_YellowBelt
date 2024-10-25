#pragma once
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s);

template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, const std::map<K, V>& m);

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	out << "[";

	bool first = true;
	for (const auto& elem : vec)
	{
		if (!first)
		{
			out << ", ";
		}
		first = false;
		out << elem;
	}
	out << "]";

	return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s)
{
	out << "{";

	bool first = true;
	for (const auto& elem : s)
	{
		if (!first)
		{
			out << ", ";
		}
		first = false;
		out << elem;
	}
	out << "}";

	return out;
}

template<typename K, typename V>
std::ostream& operator <<(std::ostream& out, const std::map<K, V>& m)
{
	out << "{";

	bool first = true;
	for (const auto& [key, value] : m)
	{
		if (!first)
		{
			out << ", ";
		}
		first = false;
		out << key << ": " << value;
	}
	out << "}";

	return out;
}

namespace MyUnitTest
{
	template<typename T, typename U>
	void AssertEqual(const T & t, const U & u, const std::string & hint = {})
	{
		if (t != u)
		{
			std::ostringstream os;
			os << "Assertion failed:\n" << t << " != " << u << ";\nHint " << hint << "\n";
			throw std::runtime_error(os.str());
		}
	}

	void Assert(bool b, const std::string & hint = {})
	{
		AssertEqual(b, true, hint);
	}

	class TestRunner
	{
	private:
		uint32_t failCount = 0;
	public:

		~TestRunner()
		{
			if (failCount > 0)
			{
				std::cerr << failCount << " tests failed. Terminate\n";
				exit(1);
			}
		}

		template<class TestFunc>
		void RunTest(TestFunc func, const std::string& test_name) {
			try {
				func();
				std::cerr << test_name << " OK" << std::endl;
			}
			catch (std::exception& e) {
				++failCount;
				std::cerr << test_name << " fail: " << e.what() << std::endl;
			}
			catch (...) {
				++failCount;
				std::cerr << "Unknown exception caught" << std::endl;
			}
		}
	};
}