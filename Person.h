#pragma once
#include <string>

namespace mylib {
	class Person
	{
	private:
		std::string name;
		void update_name(std::string new_name);
	public:
		Person(std::string name);
		virtual ~Person();
		virtual std::string get_name(void) const;
		void set_name(std::string new_name);

	};

}
