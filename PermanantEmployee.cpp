#include "PermanantEmployee.h"
namespace company {
	PermanantEmployee::PermanantEmployee(int empid, std::string name, std::string deptname,
		float salary, std::string pf_number) :
		Employee(empid, name, deptname)
	{
		this->salary = salary;
		this->provident_fund_number = pf_number;
	}

	float PermanantEmployee::get_salary(void) const
	{
		return salary;
	}

	std::string PermanantEmployee::get_pf_number(void) const
	{
		return provident_fund_number;
	}

	void PermanantEmployee::set_salary(float new_salary)
	{
		this->salary = new_salary;
	}
}