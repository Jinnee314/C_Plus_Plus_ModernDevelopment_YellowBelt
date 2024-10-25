#pragma once
#include <string>

class Figure
{
protected:
	std::string type = "figure";

public:
	Figure(const std::string& type);

	virtual std::string Name() const = 0;

	virtual double Perimeter() const = 0;

	virtual double Area() const = 0;
};

