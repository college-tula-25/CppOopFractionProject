#pragma once
#include <iostream>

class FractionException
{
	std::string message;
public:
	FractionException(std::string message)
		: message{ message }{}
	std::string Message()
	{
		return message;
	}
};


class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction() : Fraction(0, 1){}

	Fraction(int numerator, int denominator)
		: numerator{ numerator },
		denominator{ denominator }
	{
		if (!denominator)
			throw FractionException("Divide by zero");
	}

	void Numerator(int numerator)
	{
		this->numerator = numerator;
	}

	int Numerator() const
	{
		return numerator;
	}

	void Denominator(int denominator)
	{
		if (!denominator)
			throw FractionException("Divide by zero");

		this->denominator = denominator;
	}

	int Denominator() const
	{
		return denominator;
	}

	void Print() const
	{
		std::cout << "[" << numerator << "/" << denominator << "]";
	}
};

