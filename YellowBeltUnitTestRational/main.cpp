#include "MyUnitTestFreimwork.hpp"

#include <iostream>

class Rational {
	int numerator = 0;
	int denominator = 0;

public:
	Rational()
	{
		numerator = 0;
		denominator = 1;
	}

	Rational(int numerator, int denominator)
	{
		if (denominator == 0)
		{
			throw std::runtime_error("Copy Constructor: denominator == 0");
		}

		if (numerator == 0)
		{
			denominator = 1;
		}

		if (denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
		}

		this->numerator = numerator;
		this->denominator = denominator;

		Reduction();
	}

	void Reduction()
	{
		int copyNum = std::abs(this->numerator);
		int copyDen = this->denominator;

		while (copyNum != 0 && copyDen != 0) 
		{
			if (copyNum > copyDen) 
			{
				copyNum %= copyDen;
			}
			else 
			{
				copyDen %= copyNum;
			}
		}

		this->numerator /= copyNum + copyDen;
		this->denominator /= copyNum + copyDen;

	}


	int Numerator() const
	{
		return numerator;
	}
	int Denominator() const
	{
		return denominator;
	}
};

void TestDefaultConstructor()
{
	Rational rat;

	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(0, 1), "[0, 1]");
}

void TestCopyConstructor()
{
	Rational rat(-1, -2);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(1, 2), "[-1, -2]");

	rat = Rational(1, -2);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(-1, 2), "[1, -2]");

	rat = Rational(-1, 2);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(-1, 2), "[1, -2]");

	rat = Rational(1, 2);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(1, 2), "[1, 2]");

	rat = Rational(2, 4);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(1, 2), "Reduction [2, 4]");

	rat = Rational(10, 25);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(2, 5), "Reduction [10, 25]");

	rat = Rational(10, -25);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(-2, 5), "Reduction [10, -25]");

	rat = Rational(0, 5);
	MyUnitTest::AssertEqual(std::make_pair(rat.Numerator(), rat.Denominator()), std::make_pair(0, 1));
}

int main()
{
	MyUnitTest::TestRunner tr;

	tr.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
	tr.RunTest(TestCopyConstructor, "TestCopyConstructor");

	return 0;
}