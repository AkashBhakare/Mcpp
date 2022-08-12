#include <iostream>
#include <string>
#include <sstream>
#include "department.h"

mylib::Department::Department(std::string&& _name, std::string&& _hod, size_t _emp_count) :
	name(std::move(_name)), hod(std::move(_hod)), employee_count(_emp_count)
{
	std::cout << "Department : " << name << " has started\n";
}

mylib::Department::~Department()
{
	std::cout << "Department : " << name << " has been closed\n";
}

std::string mylib::Department::get_dept_info() const
{
	std::ostringstream info{};
	info << "Name : " << name << "\tHOD : " << hod << "\tEmployee count " << employee_count << '\n';
	return info.str();
}