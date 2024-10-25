#include "Triangle.hpp"
#include <cmath>
#include <execution>

Triangle::Triangle(uint32_t a, uint32_t b, uint32_t c)
	: Figure("TRIANGLE"), a(a), b(b), c(c) 
{
	if (a == 0 || b == 0 || c == 0)
	{
		throw std::invalid_argument("One or more sides are equal to zero.");
	}

	uint32_t sum = a + b + c;

	if (sum - a < a || sum - b < b || sum - c < c)
	{
		throw std::invalid_argument("One of the sides is greater than the sum of the other two.");
	}
	
}

std::string Triangle::Name() const
{
	return this->type;
}

double Triangle::Perimeter() const
{
	return a + b + c;
}

double Triangle::Area() const
{
	double p = (a + b + c) / 2.;
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}