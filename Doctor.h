#pragma once
#include <string>
#include "Person.h"
namespace mylib {

	class Doctor : public Person
	{
	private:
		std::string specialization;
		void update_specialization(std::string new_specialization);
	public:
		Doctor(std::string name, std::string specialization);
		~Doctor();
		std::string get_specialization() const;
		void set_specialization(std::string new_specialization);
		std::string operate();
		/*Override inherited method : change the get_name method implementation*/
		std::string get_name(void) const;
	};

}
