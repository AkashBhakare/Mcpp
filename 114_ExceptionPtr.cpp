// ExceptionPtr.cpp : 
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

void case_I(void);
void case_II(void);

void handle_eptr(std::exception_ptr eptr);

int main()
{
	case_I();
	case_II();

	return 0;
}


void case_I()
{
	std::exception_ptr eptr{};
	while (true) {
		try {
			std::string dummy{ "dummy" };
			size_t index{};
			std::cout << "Please enter the index : ";
			std::cin >> index;
			std::cout << "The character at index is :" << dummy.at(index - 1) << '\n'; // this generates an std::out_of_range
			break;
		}
		catch (...) {
			//   captures the current exception object and creates an 
			//   std::exception_ptr that holds either a copy or a reference 
			//   to that exception object
			eptr = std::current_exception(); // capture
		}

		handle_eptr(eptr);
	}

} // destructor for std::out_of_range called here, when the eptr is destructed



void case_II()
{
	std::exception_ptr eptr;
	try {
		std::string dummy{};
		std::cout << dummy.at(1); // this generates an std::out_of_range
	}
	catch (const std::out_of_range& error) {
		//Creates an exception_ptr object that holds a copy of an exception.
		//Calling the make_exception_ptr function is equivalent to throwing a C++ exception, 
		//catching it in a catch block, and then calling the current_exception function to return 
		//an exception_ptr object that references the exception
		eptr = std::make_exception_ptr(error); // capture
	}
	handle_eptr(eptr);
}// destructor for std::out_of_range called here, when the eptr is destructed

void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
	try {
		if (eptr) {
			//  Throws the previously captured exception object, 
			//  referred to by the exception pointer
			std::rethrow_exception(eptr);
		}
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Handled Out of range exception\n";
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception \"" << e.what() << "\"\n";

	}
}