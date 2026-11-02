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

	void Reduction();
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

	void Print(char end = ' ') const
	{
		std::cout << "[" << numerator << "/" << denominator << "]" << end;
	}

	void Add(Fraction other);
	void Add(int other);
	void Add(double other);

	void Del(Fraction other);
	void Del(int other);
	void Del(double other);

	void Mult(Fraction other);

	void Div(Fraction other);

	Fraction Plus(Fraction other);
	Fraction Minus(Fraction other);
	Fraction Multiply(Fraction other);
	Fraction Divide(Fraction other);

	Fraction operator+(Fraction other);
	Fraction operator+(int other);

};

