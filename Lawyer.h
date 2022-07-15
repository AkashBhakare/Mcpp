#pragma once
#include "Person.h"
namespace mylib {
	class Lawyer : public Person
	{
	private:
		std::string practice;
		void update_practice(std::string new_practice);
	public:
		Lawyer(std::string name, std::string practice);
		std::string get_practice() const;
		void set_practice(std::string new_specialization);
		/*Override inherited method : change the get_name method implementation*/
		std::string get_name(void) const;
	};

}
