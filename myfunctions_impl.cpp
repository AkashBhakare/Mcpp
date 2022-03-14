#include "myfunctions.h"
#include <iostream>
#include <limits>
/*Takes no arguments and returns a integer*/
int get_integer(std::string msg) {
	int number{};
	do {
		std::cout << msg;
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.fail();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cerr << "The input incorrect!\n";
		}
		else {
			return number;
		}
	} while (true);
}

/*Take two integers as an argument and returns their addition as long long value*/
long long int addition(int n1, int n2) {
	return static_cast<long long int>(n1) + n2;
}

long long int square(int n) {
	return static_cast<long long int>(n) * n;
}


