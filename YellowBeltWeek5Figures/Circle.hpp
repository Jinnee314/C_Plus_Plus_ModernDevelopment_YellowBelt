#pragma once
#include "Figure.hpp"

class Circle :
    public Figure
{
    uint32_t radius = 0;

public:

    Circle(uint32_t r);

    std::string Name() const override;

    double Perimeter() const override;

    double Area() const override;
};

