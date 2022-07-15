#include <iostream>
#include <stdexcept>
#include "Doctor.h"


void mylib::Doctor::update_specialization(std::string new_specialization)
{
    if (not new_specialization.empty()) {
        specialization = new_specialization;
    }
    else {
        throw std::invalid_argument("Specialization cannot be empty string\n");
    }
}

mylib::Doctor::Doctor(std::string name, std::string new_specialization) :Person(name)
{
    std::cout << "Doctor created\n";
    update_specialization(new_specialization);
}

mylib::Doctor::~Doctor()
{
    std::cout << "Doctor destroyed\n";
}

std::string mylib::Doctor::get_specialization() const
{
    return specialization;
}

void mylib::Doctor::set_specialization(std::string new_specialization)
{
    update_specialization(new_specialization);
}

std::string mylib::Doctor::operate()
{
    return "Operating the patient\n";
}

std::string mylib::Doctor::get_name() const
{
    return "Dr. " + Person::get_name();
}