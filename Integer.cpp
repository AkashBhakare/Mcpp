#include <iostream>
#include <limits>
#include "Integer.h"

mylib::Integer::Integer(int value) :data(value)
{}

mylib::Integer::Integer(const Integer& other) : data(other.data)
{}

mylib::Integer::Integer(Integer&& other) : data(std::move(other.data))
{}

int mylib::Integer::get_value(void) const
{
	return data;
}

int mylib::Integer::get_max_value() const
{
	return std::numeric_limits<int>::max();
}

int mylib::Integer::get_min_value() const
{
	return std::numeric_limits<int>::min();
}

void mylib::Integer::set_value(long long int value)
{
	if (value >= get_min_value() and value <= get_max_value()) {
		data = value;
	}
}

/*Operator ++ prefix*/
mylib::Integer mylib::Integer::operator++()
{
	data = data + 1;
	return (*this);
}

mylib::Integer mylib::Integer::operator=(const Integer& rhs)
{
	data = rhs.data;
	return (*this);
}

/*Operator -- prefix*/
mylib::Integer mylib::operator--(Integer& operand)
{
	operand.data = operand.data - 1;
	return operand;
}

mylib::Integer mylib::Integer::operator++(int)
{
	Integer original(*this);
	this->data++;
	return original;
}