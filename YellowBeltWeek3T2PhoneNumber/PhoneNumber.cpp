#include "PhoneNumber.hpp"

PhoneNumber::PhoneNumber(const string& international_number)
{
	if (international_number.size() < 6)
	{
		throw std::invalid_argument("Too few characters");
	}

	if (international_number[0] != '+')
	{
		throw std::invalid_argument("There is no plus sign.");
	}

	if (std::count(international_number.begin(), international_number.end(), '-') < 2)
	{
		throw std::invalid_argument("Less than two hyphens.");
	}

	auto posFirstDash = international_number.find("-");

	if (posFirstDash == 1)
	{
		throw std::invalid_argument("There is no country code.");
	}	

	countryCode_ = international_number.substr(1, posFirstDash - 1);

	if (posFirstDash + 1 == international_number.size())
	{
		throw std::invalid_argument("There is no city code and local number.");
	}

	auto posSecondDash = international_number.find("-", posFirstDash + 1);

	if (posSecondDash == posFirstDash + 1)
	{
		throw std::invalid_argument("There is no city code.");
	}

	cityCode_ = international_number.substr(posFirstDash + 1, posSecondDash - posFirstDash - 1);

	if (posSecondDash + 1 == international_number.size())
	{
		throw std::invalid_argument("There is no local number.");
	}

	localNumber_ = international_number.substr(posSecondDash + 1);
}

string PhoneNumber::GetCountryCode() const
{
	return countryCode_;
}

string PhoneNumber::GetCityCode() const
{
	return cityCode_;
}

string PhoneNumber::GetLocalNumber() const
{
	return localNumber_;
}

string PhoneNumber::GetInternationalNumber() const
{
	return "+" + countryCode_ + "-" + cityCode_ + "-" + localNumber_;
}