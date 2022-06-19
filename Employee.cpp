#include "Employee.h"
namespace company {
	Employee::Employee(int id, std::string name, std::string department_name)
	{
		this->empid = id;
		this->name = name;
		this->deptname = department_name;
	}

	int Employee::get_emp_id() const
	{
		return empid;
	}

	std::string Employee::get_name(void) const
	{
		return name;
	}

	std::string Employee::get_department_name(void) const
	{
		return deptname;
	}

	void Employee::set_emp_id(int new_id)
	{
		this->empid = new_id;
	}

	void Employee::set_name(std::string new_name)
	{
		this->name = new_name;
	}

	void Employee::set_dept_name(std::string new_dept_name)
	{
		this->deptname = new_dept_name;
	}
}