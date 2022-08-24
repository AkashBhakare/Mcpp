#include "my_string.h"

mylib::MyString::operator int() const
{
	return std::stoi(str);
}

mylib::MyString::operator double() const
{
	return std::stod(str);
}

mylib::MyString::MyString(std::string parameter) :str(parameter)
{}

std::string mylib::MyString::get() const {
	return str;
}
