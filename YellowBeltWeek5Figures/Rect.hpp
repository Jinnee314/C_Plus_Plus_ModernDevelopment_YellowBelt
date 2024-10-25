#pragma once
#include "Figure.hpp"

class Rect :
	public Figure
{
	uint32_t w = 0, h = 0;

public:
	Rect(uint32_t w, uint32_t h);

	std::string Name() const override;

	double Perimeter() const override;

	double Area() const override;
};

