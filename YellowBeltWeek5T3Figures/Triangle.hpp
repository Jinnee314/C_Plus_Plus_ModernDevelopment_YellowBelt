#pragma once
#include "Figure.hpp"

class Triangle :
    public Figure
{
    uint32_t a = 0, b = 0, c = 0;

public:
    Triangle(uint32_t a, uint32_t b, uint32_t c);

    std::string Name() const override;

    double Perimeter() const override;

    double Area() const override;
};

