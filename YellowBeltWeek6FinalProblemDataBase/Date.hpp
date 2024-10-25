#pragma once
#include <cstdint>
#include <sstream>
#include <iostream>

class Date
{
private:
	uint32_t year = 0;
	uint32_t month = 0;
	uint32_t day = 0;

public:
	//Date();

	Date(const uint32_t year, const uint32_t month, const uint32_t day);

	Date(const Date& date);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);

	friend bool operator<(const Date& l, const Date& r);

	friend bool operator<=(const Date& l, const Date& r);

	friend bool operator>(const Date& l, const Date& r);

	friend bool operator>=(const Date& l, const Date& r);

	friend bool operator==(const Date& l, const Date& r);

	friend bool operator!=(const Date& l, const Date& r);


};

Date ParseDate(std::istringstream& is);