#include "Rect.hpp"
#include <execution>

Rect::Rect(uint32_t w, uint32_t h)
	: Figure("RECT"), w(w), h(h)
{
	if (h == 0 || w == 0)
	{
		throw std::invalid_argument("One or more sides are equal to zero.");
	}
}

std::string Rect::Name() const
{
	return this->type;
}

double Rect::Perimeter() const
{
	return 2 * (h + w);
}

double Rect::Area() const
{
	
	return h * w;
}