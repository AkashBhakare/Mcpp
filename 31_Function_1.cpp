// 31_Function_1.cpp : Introduction

#include <iostream>


//Poor Diagram
//int main()
//{
//    int number{};
//    std::cout << "Please Enter A integer : ";
//    std::cin >> number;
//    long double facto{ 1 };
//    for (int i{ 1 }; i <= number; ++i) {
//        facto *= i;
//    }
//    std::cout << "Factorial of " << number << " is " << facto << "\n";
//
//}

//int main() {
//	int number = get_integer(); //Function Call
//	auto factorial = calculate_factorial(number); //Function Call
//	//std::cout << "Factorial of " << number << " is " << factorial << "\n";
//	print_result(number, factorial); //Function call
//	return 0;
//}

////Function Declaration (Prototype)
//int get_positive_integer(void);
//
////Take a single integer as parameter and returns its factorial
//long double calculate_factorial(int);
//
//void print_result(int number, long double factorial);
//
////Function Definations
//int main() {  
//	int number = get_positive_integer(); //Function Call
//	auto factorial = calculate_factorial(number); //Function Call
//	//std::cout << "Factorial of " << number << " is " << factorial << "\n";
//	print_result(number, factorial); //Function call
//	return 0;
//}
//
////Function Definations
//int get_positive_integer() {
//	int number{};
//	do {
//		std::cout << "please enter a integer :";
//		std::cin >> number;
//		if (std::cin.fail()) {
//			std::cout << "Input format is invalid. please enter only digits\n";
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
//		}
//		else {
//			if (number < 0) {
//				std::cout << "please enter positive numbers \n";
//			}
//			else {
//				break;
//			}
//		}
//	} while (true);
//	return number;
//}
//
////Function Definations
//long double calculate_factorial(int number) {
//	long double facto{ 1 };
//	for (int i{ 1 }; i <= number; ++i) {
//		facto *= i;
//	}
//	return facto;
//}
//
////Function Definations
//void print_result(int number, long double factorial) {
//	std::cout << "Factorial of " << number << " is " << factorial << "\n";
//	
//}

//Function Declaration (Prototype)
int get_positive_integer(void);

//Take a single integer as parameter and returns its factorial
long double calculate_factorial(int);

void print_result(int number, long double factorial);

//Function Definations
int main() {
	int number = get_positive_integer(); //Function Call
	auto factorial = calculate_factorial(number); //Function Call
	//std::cout << "Factorial of " << number << " is " << factorial << "\n";
	print_result(number, factorial); //Function call
	return 0;
}

//Function Definations
int get_positive_integer() {
	int number{};
	do {
		std::cout << "please enter a integer :";
		std::cin >> number;
		if (std::cin.fail()) {
			/*std::cout << "Input format is invalid. please enter only digits\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');*/
			throw std::invalid_argument("Input Format is invalid. please enter only digit\n");
		}
		else {
			if (number < 0) {
				std::cout << "please enter positive numbers \n";
			}
			else {
				break;
			}
		}
	} while (true);
	return number;
}

//Function Definations
long double calculate_factorial(int number) {
	long double facto{ 1 };
	for (int i{ 1 }; i <= number; ++i) {
		facto *= i;
	}
	return facto;
}

//Function Definations
void print_result(int number, long double factorial) {
	std::cout << "Factorial of " << number << " is " << factorial << "\n";

}