#pragma once
#include <string>
namespace mylib {

	class MyString {
	private:
		std::string str;
	public:
		MyString(std::string);

		std::string get() const;

		/*conversion Functions allows implicit and explicit conversion*/
		operator int() const;

		/*explict conversion Functions */
		explicit operator double() const;
	};
}