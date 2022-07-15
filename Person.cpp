#include "Person.h"
#include <string>
#include <iostream>
#include <stdexcept>

mylib::Person::Person(std::string name)
{
    std::cout << name << " is created\n";
    update_name(name);
}

std::string mylib::Person::get_name() const
{
    return name;
}

void mylib::Person::set_name(std::string new_name)
{
    update_name(new_name);
}

mylib::Person::~Person()
{
    std::cout << name << " is destroyed\n";
}

void mylib::Person::update_name(std::string new_name)
{
    if (not new_name.empty()) {
        name = new_name;
    }
    else {
        throw std::invalid_argument("Name cannot be empty!\n");
    }
}