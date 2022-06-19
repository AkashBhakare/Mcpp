#pragma once
#include <string>
namespace company {
	class Employee
	{
	private:
		int empid;
		std::string name;
		std::string deptname;
	public:
		Employee() = delete;
		Employee(const Employee&) = delete;
		Employee(Employee&&) = delete;
		Employee(int id, std::string name, std::string department_name);
		//getters
		int get_emp_id(void) const;
		std::string get_name(void)const;
		std::string get_department_name(void)const;
		//setters
		void set_emp_id(int new_id);
		void set_name(std::string new_name);
		void set_dept_name(std::string new_dept_name);
	};

}