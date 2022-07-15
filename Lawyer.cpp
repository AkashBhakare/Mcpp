#include "Lawyer.h"
#include "Person.h"
void mylib::Lawyer::update_practice(std::string new_practice)
{
}

mylib::Lawyer::Lawyer(std::string name, std::string practice) :Person(name)
{
	this->practice = practice;
}

std::string mylib::Lawyer::get_practice() const
{
	return practice;
}

void mylib::Lawyer::set_practice(std::string practice)
{
	update_practice(practice);
}


std::string mylib::Lawyer::get_name() const
{
	return "Adv. " + Person::get_name();
}