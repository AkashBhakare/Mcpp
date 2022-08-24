#include <iostream>
#include <sstream>
#include <numeric>
#include "RationalNumber.h"

mylib::RationalNumber::RationalNumber(int numerator)
{
	this->numerator = numerator;
}

mylib::RationalNumber::RationalNumber(int numerator, int denominator)
{
	this->numerator = numerator;
	this->demoninator = denominator;
}

mylib::RationalNumber::RationalNumber(const RationalNumber& initializer)
{
	this->numerator = initializer.numerator;
	this->demoninator = initializer.demoninator;
}

mylib::RationalNumber::RationalNumber(RationalNumber&& initializer)
{
	this->numerator = std::move(initializer.numerator);
	this->demoninator = std::move(initializer.demoninator);
}

const mylib::RationalNumber& mylib::RationalNumber::operator=(const RationalNumber& rhs)
{
	this->numerator = rhs.numerator;
	this->demoninator = rhs.demoninator;
	return (*this);
}

std::string mylib::RationalNumber::get_string_representation() const
{
	std::ostringstream out_str;
	out_str << numerator << "/" << demoninator;
	return out_str.str();
}

mylib::RationalNumber mylib::RationalNumber::operator+(const RationalNumber& rhs) const
{
	int denominator = std::lcm(this->demoninator, rhs.demoninator);
	int numerator = (this->numerator * rhs.demoninator) + (rhs.numerator * this->demoninator);
	return RationalNumber(numerator, denominator);
}

mylib::RationalNumber mylib::operator-(const RationalNumber& lhs, const RationalNumber& rhs)
{
	int denominator = std::lcm(lhs.demoninator, rhs.demoninator);
	int numerator = (lhs.numerator * rhs.demoninator) - (rhs.numerator * lhs.demoninator);
	return RationalNumber(numerator, denominator); /*returning copy of Local obejct*/
}


std::ostream& mylib::operator<<(std::ostream& output_stream, const RationalNumber& rational)
{
	output_stream << rational.numerator << '/' << rational.demoninator;
	return output_stream;
}

std::istream& mylib::operator >> (std::istream& input_stream, RationalNumber& rational)
{
	std::cout << "Enter the Numerator of a Rational Number : ";
	input_stream >> rational.numerator;
	std::cout << "Enter the Denominator of a Rational Number : ";
	input_stream >> rational.demoninator;

	return input_stream;
}