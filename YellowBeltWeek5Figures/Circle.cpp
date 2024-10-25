#include "Circle.hpp"
#include <execution>

Circle::Circle(uint32_t r)
	: Figure("CIRCLE"), radius(r) 
{
	if (r == 0)
	{
		throw std::invalid_argument("Side is equal to zero.");
	}
}

std::string Circle::Name() const
{
	return this->type;
}

double Circle::Perimeter() const
{
	return 2 * 3.14 * radius;
}

double Circle::Area() const
{	
	return 3.14 * radius * radius;
}