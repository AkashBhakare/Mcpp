#include "myhead.h"
#include <iostream>
#include <cstdlib>


/*
* The handler is supposed to perform all the clean up operation before the program terminates
* Eg:
*	close the file
*	close the DB conections
*	flush the streams
*   relase resources that are previously acquired
*/
void my_terminate_handler(void)
{
	std::cout << "Terminating Error has occured!\n";
	std::cout << "Please contact the developer at support@impetusits.com\n";
	std::exit(EXIT_FAILURE);
	// Terminate handler should never return. It should always exit
}

/*Removed in C++ 17*/
void my_unexcepted_handler(void)
{
	std::cout << "Unexpected Error has occured!\n";
	std::cout << "Please contact the developer at support@impetusits.com\n";
	std::exit(EXIT_FAILURE);
}