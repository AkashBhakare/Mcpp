#include "university.h"
#include <sstream>
#include <memory>
#include <utility> 

#include <algorithm>
mylib::University::University(std::string&& name, size_t yoe, Department&& dept)
{
	this->name = std::move(name);
	this->yoe = yoe;
	departments.emplace_back(std::make_unique<Department>(std::move(dept)));
}

mylib::University::~University()
{
	std::cout << "University has closeded down! :< \n";
}

std::string mylib::University::get_univ_info()
{
	std::ostringstream info{};
	info << "Name : " << name << '\n';
	info << "Year of Establishment : " << yoe << '\n';
	info << "Details of Departments : \n";
	for (size_t i{ 0 }; i < departments.size(); ++i) {
		info << "\t" << departments[i]->get_dept_info();
	}
	return info.str();
}

void mylib::University::add_departments(std::string&& dname, std::string&& hod, size_t emp_count)
{
	departments.emplace_back(std::make_unique<Department>(std::move(dname), std::move(hod), emp_count));
}