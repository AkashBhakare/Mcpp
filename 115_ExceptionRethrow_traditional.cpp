// 115_ExceptionRethrow_traditional.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <cstdlib>
#include <iostream>
#include <exception>


// throw, catch and rethrow std::exception

void doSomething(void) {
	bool exceptional_situation_occurs = true;
	// throw std::exception and catch it immediately
	try {
		std::cout << "  Function doSomething throws an std::exception\n";
		if (exceptional_situation_occurs) {
			throw std::invalid_argument("Some thing went wrong"); // generate std::exception
		}
	}// end try
	catch (const std::exception&) { // handle std::exception
		std::cout << "  Exception handled in function doSomething"
			<< "\n  Function doSomething rethrows std::exception";
		throw; // rethrow std::exception for further processing
	} // end catch
	catch (...) {
		std::cout << "Catch all\n";
	}
	std::cout << "This also should not print\n";
} // end function throwException


int main() {
	// throw std::exception
	try {
		std::cout << "\nmain invokes function doSomething\n";
		doSomething();
		std::cout << "This should not print\n";
	}// end try
	catch (const std::exception& e) // handle std::exception
	{
		std::cout << "\n\nException handled in main\n";
		std::cout << e.what() << std::endl;
	} // end catch

	std::cout << "Program control continues after catch in main\n";
	return 0;
} // end main

