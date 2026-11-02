#include "Fraction.h"

void Fraction::Reduction()
{
	int n{ numerator }, d{ denominator };
	int remains;
	do
	{
		remains = n % d;
		n = d;
		d = remains;
	} while (remains);
	numerator /= n;
	denominator /= n;
}

void Fraction::Add(Fraction other)
{
	this->numerator = this->numerator * other.denominator
					+ this->denominator * other.numerator;
	this->denominator *= other.denominator;
	Reduction();
}

void Fraction::Add(int other)
{
	Add(Fraction(other, 1));
}

void Fraction::Add(double other)
{
	Fraction f;
	int whole = (int)other;
	f.numerator = whole * 100 + round((other - whole) * 100);
	f.denominator = 100;
	Add(f);
	Reduction();
}


void Fraction::Del(Fraction other)
{
	this->Add(Fraction(-other.numerator, other.denominator));
}

void Fraction::Del(int other)
{
	this->Add(-other);
}

void Fraction::Del(double other)
{
	this->Add(-other);
}

void Fraction::Mult(Fraction other)
{
	this->numerator *= other.numerator;
	this->denominator *= other.denominator;
}

void Fraction::Div(Fraction other)
{
	Mult(Fraction(other.denominator, other.numerator));
}


Fraction Fraction::Plus(Fraction other)
{
	Fraction result{ *this };
	result.Add(other);
	return result;
}

Fraction Fraction::Minus(Fraction other)
{
	Fraction result{ *this };
	result.Del(other);
	return result;
}

Fraction Fraction::Multiply(Fraction other)
{
	Fraction result{ *this };
	result.Mult(other);
	return result;
}

Fraction Fraction::Divide(Fraction other)
{
	Fraction result{ *this };
	result.Div(other);
	return result;
}

Fraction Fraction::operator+(Fraction other)
{
	return Plus(other);
}

Fraction Fraction::operator+(int other)
{
	return *this + Fraction(other, 1);
}
