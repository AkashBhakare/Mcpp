#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "department.h"
namespace mylib {
	class University
	{
	private:
		std::string name;
		size_t yoe;
		std::vector<std::unique_ptr<mylib::Department>> departments;
	public:
		University(std::string&& name, size_t yoe, Department&&);
		~University();
		std::string get_univ_info();
		void add_departments(std::string&& dname, std::string&& hod, size_t emp_count);
	};
	std::ostringstream& print(std::ostringstream&, std::unique_ptr<mylib::Department>&);
}
