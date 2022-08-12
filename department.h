#pragma once
#include <string>
namespace mylib {
	class Department
	{
	private:
		std::string name;
		std::string hod;
		size_t employee_count;
	public:
		Department(std::string&& name, std::string&& hod, size_t emp_count);
		~Department();
		std::string get_dept_info() const;
	};
}
