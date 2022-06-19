#pragma once
#include "Employee.h"
namespace company {
	class PermanantEmployee : public Employee
	{
	private:
		float salary;
		std::string provident_fund_number;
	public:
		PermanantEmployee() = delete;
		PermanantEmployee(const PermanantEmployee&) = delete;
		PermanantEmployee(PermanantEmployee&&) = delete;

		PermanantEmployee(int empid, std::string name, std::string deptname,
			float salary, std::string provident_fund_number);
		//getters
		float get_salary(void)const;
		std::string get_pf_number(void)const;

		//setters
		void set_salary(float new_salary);
	};

}
