// 77_InheritanceAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <format>
#include "Employee.h"
#include "PermanantEmployee.h"

using namespace std::string_literals;
int main()
{
    company::Employee e1(1001, "Ramesh"s, "Sales"s);
    //  std::cout << e1;
    std::cout << "Name          :" << e1.get_name() << "\n";
    std::cout << "Id            :" << e1.get_emp_id() << "\n";
    std::cout << "Department    :" << e1.get_department_name() << "\n";

    e1.set_dept_name("Marketing"s);
    e1.set_name("Rameesh"s);
    e1.set_emp_id(2001);
    std::cout << std::format("{:11}:{}\n", "Name"s, e1.get_name());
    std::cout << std::format("{:11}:{}\n", "Department"s, e1.get_department_name());
    std::cout << std::format("{:11}:{}\n", "Id"s, e1.get_emp_id());
    std::cout << std::endl;
    company::PermanantEmployee pe1(2003, "Sakshi"s, "HR"s, 250000.0F, "PUN1234"s);
    std::cout << std::format("{:11}:{}\n", "Name"s, pe1.get_name());
    std::cout << std::format("{:11}:{}\n", "Department"s, pe1.get_department_name());
    std::cout << std::format("{:11}:{}\n", "Id"s, pe1.get_emp_id());
    std::cout << std::format("{:11}:{}\n", "Salary"s, pe1.get_salary());
    std::cout << std::format("{:11}:{}\n", "PF Number"s, pe1.get_pf_number());
}