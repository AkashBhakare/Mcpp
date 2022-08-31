// 109_Exception_Setterminate.cpp :

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
#include "myhead.h"
void foo() noexcept(true)
{
	bool is_error_condition = true;
	std::cout << "Entered foo\n";
	if (is_error_condition) {
		throw std::invalid_argument("Invalid excapetion"); //Promise Broken
	}
	std::cout << "Exiting foo\n";
	return;
}

void baz()noexcept(false) {
	std::cout << "Inside baz\n";
	std::string name{};
	std::cout << "First character : " << name.at(1);
	return;
}

void exploring_terminate_handler() {

	//User Defined pointer to function that takes no arguments and returns void
	void (*fp)(void);
	fp = my_terminate_handler;
	std::cout << "Address of myhandler : " << fp << std::endl;

	//Predefined pointer to function that takes no arguments and returns void
	std::terminate_handler newhandler = my_terminate_handler;
	std::cout << "Address of myhandler : " << newhandler << std::endl;

	// The argument to set_terminate() becomes the function called by terminate().
	// set_terminate returns the old/previous handler 
	std::terminate_handler old_handler = std::set_terminate(newhandler);
	std::cout << "Previous Terminate handler is:" << old_handler << std::endl;
	//return the current handler
	std::cout << "Current Terminate handler is :" << std::get_terminate() << std::endl;
}

int main() {
	//exploring_terminate_handler();

	//set the terminate handler
	std::terminate_handler old_handler = std::set_terminate(my_terminate_handler);
	//std::set_unexpected(my_unexcepted_handler); // Removed in C++17
	try {
		std::cout << "calling foo1 from main()\n";
		foo();
		std::cout << "back to main\n";
	}
	catch (const std::exception& errmsg)
	{
		std::cerr << "Error :" << errmsg.what() << "\n";
		std::cerr.flush();
	}

	std::cout << "inside main, but after try-catch!\n\n";
	std::cout << "Resetting the original exception handler\n";
	std::set_terminate(old_handler); //reset the handler to original handler
	std::cout << "Calling baz from main()\n";
	baz();

	return 0;
}
