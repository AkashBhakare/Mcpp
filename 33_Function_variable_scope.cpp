// 33_Function_variable_scope.cpp : 
//variable scope
//Local variable varsus Global variable
//Actual and formal arguments

#include <iostream>
#include <cstdlib>

float divide(int numerator, int denominator);
int get_integer(std::string);

using namespace std::literals;

int gbl_var1;
int gbl_var2{ 7 };


int main() {
	std::cout << gbl_var1++ << " " << gbl_var2++ << '\n';
	//What is passed while giving a function call is called as argument(actual argument)
	int number1{};
	/*Actual argumet can be literal*/
	number1 = get_integer("Please enter the Numerator : "s);

	int number2{};
	std::string message{ "Please enter the Denominator : "s };
	/*Actual argument can be a object (variable)*/
	number2 = get_integer(message);
	float result = divide(number1, number2);
	std::cout << number1 << " / " << number2 << " = " << result << '\n';
	return EXIT_SUCCESS;
}

float divide(int numerator, int denominator) {
	double gbl_var2{ 44.4 };
	std::cout << gbl_var1 << " Glbal " << ::gbl_var2 << " Local " << gbl_var2 << '\n';
	return static_cast<float>(numerator) / denominator;
}

//variable that will receive the data passed to the  function is called paramenter (formal)
int get_integer(std::string msg) { //formal argument has to be a variable
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