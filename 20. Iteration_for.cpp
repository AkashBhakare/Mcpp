// 20. Iteration_for.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
/*Print integers in the range of 1 to 10 Ascending order*/
void print_1_to_10() {

	std::cout << "Integers in the range of 1 to 10 are as follows :\n";

	for (int i{ 1 }; i <= 10; ++i) {
		std::cout << "\t" << i << "\n";
	}
}

/*Print integers in the range of 1 to 10 in descending order */
void print_10_to_1() {

	std::cout << "Integers in the range of 10 to 1 in descending order are as follows :\n";

	for (int i{ 10 }; i > 0; --i) {
		std::cout << "\t" << i << "\n";
	}
	return;
}

/*Print integers in the range of 1 to n Ascending order*/
void print_1_to_n() {
	int limit{};
	std::cout << "Please enter an Integer : ";
	std::cin >> limit;

	limit = std::abs(limit);
	std::cout << "Integers in the range of 1 to " << limit << " are as follows : \n";
	for (int i{ 1 }; i <= limit; ++i) {
		std::cout << "\t" << i << "\n";
	}

	return;
}

/*Print all odd integers in the range of 1 to n */
// 2n+1
void print_odd_in_1_to_n() {
	int limit{};
	std::cout << "Please enter an Integer : ";
	std::cin >> limit;
	std::cout << "Odd Integers in the range of 1 to " << limit << " are as follows : \n";

	for (int i{ 1 }; i <= limit; ++i) {
		if (i % 2 != 0) {
			std::cout << "\t" << i << "\n";
		}
	}

	return;
}

/*Print all odd integers in the range of 1 to n */
// (n/2)+1 
void print_odd_in_1_to_n_better() {
	int limit{};
	std::cout << "Please enter an Integer : ";
	std::cin >> limit;
	std::cout << "Odd Integers in the range of 1 to " << limit << " are as follows : \n";

	for (int i{ 1 }; i <= limit; i+=2) {
		std::cout << "\t" << i << "\n";
	}

	return;
}

/*Calculate Factorial v.1*/
//n+1
void print_factorial_1() {
	int number{};
	std::cout << "Please enter integer to calculate its Factorial : ";
	std::cin >> number;
	int facto{1};
	for (int i{ 1 }; i <= number; ++i) {
		facto = facto * i;
	}
	std::cout << "The Factorial of " << number << " is " << facto << "\n";
	return;
}

/*Calculate Factorial v.2*/
// n
void print_factorial_2() {
	int number{};
	std::cout << "Please enter integer to calculate its Factorial : ";
	std::cin >> number;
	int facto{ 1 };
	for (int i{ 2 }; i <= number; ++i) {
		facto = facto * i;
	}
	std::cout << "The Factorial of " << number << " is " << facto << "\n";
	return;
}


/*Calculate Factorial v.3*/
// n
void print_factorial_correct_1() {
	int number{};
	std::cout << "Please enter integer to calculate its Factorial : ";
	std::cin >> number;
	
	long double facto{ 1.0L};

	for (int i{ 2 }; i <= number; ++i) {
		facto = facto * i;
	}
	
	std::cout << "The Factorial of " << number << " is " << std::fixed << std::setprecision(0) << facto << "\n";
	return;
}


/*Calculate Factorial v.4*/
/*more than one variables can be intitialized in the for loop*/
void print_factorial_correct_2() {
	int number{};
	long double facto{};
	int x = 5, y=6;
	std::cout << "Please enter integer to calculate its Factorial : ";
	std::cin >> number;
	
	// Case:1 : Incorrect
	/*inititalize counter creates two new local variables viz i & facto which are local to for loop*/
	for (int i{ 2 }, facto=1 ; i <= number; ++i) {
		facto = facto * i;
	}
	std::cout << "The Factorial of " << number << " is " << std::fixed << std::setprecision(0) << facto << "\n";
	
	//Case: 2 Correct
	int i{};
	for (i = 2 , facto = 1.0; i <= number; ++i) {
		facto = facto * i;
	}
	std::cout << "The Factorial of " << number << " is " << std::fixed << std::setprecision(0) << facto << "\n";

	return;
}

/*Print Sum of add nos in the range of 1 to n*/
void print_sum_odd_nos() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;
	long long int sum{};

	//Case : 1
	for (int i{ 1 }; i <= number; i += 2) {
		sum += i;
	}
	std::cout << "Sum of odd numbers = " << sum << "\n";

	sum = 0;
	//Case : 2 : we can have any sort of statement in the initialize counter
	for (number = (number%2==0)?(number -1):number ; number > 0; number -= 2 ) {
		sum += number;
	}
	std::cout << "Sum of odd numbers = " << sum << "\n";
}

/*Print in descending order from n to 1*/
void print_descending_1() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;
	for (int i{ number }; i > 0; --i) {
		std::cout << "\t" << i << "\n";
	}
}


/*Print in descending order from n to 1*/

/*initialize counter in the for loop can be null(empty)*/
void print_descending_2() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;

	for ( ; number > 0; --number) {
		std::cout << "\t" << number << "\n";
	}
}

/*Print in descending order from n to 1*/

/*initialize counter & reevaluation_parameter in the for loop can be null(empty)*/
void print_descending_3() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;

	for (; number > 0; ) {
		std::cout << "\t" << number-- << "\n";
	}
}


/*initialize counter & reevaluation_parameter in the for loop can be null(empty)*/
void print_descending_4() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;
	/*Any non-zero value represents true
	As long as the valueof the variable number is not zero the condition evaluates to true*/
	for (; number ; ) {
		std::cout << "\t" << number-- << "\n";
	}
}

/*initialize counter & reevaluation_parameter in the for loop can be null(empty)*/
void print_descending_5() {
	int number{};
	std::cout << "Please enter integer : ";
	std::cin >> number;
	/*Any non-zero value represents true
	Infinit loop since teh condition is missing*/
	for (; ; ) {
		std::cout << "\t" << number-- << "\n";
		if (number == 0) {
			break;
		}
	}
}


int main()
{
	// print_1_to_10();
	// print_10_to_1();
	// print_1_to_n();
	// print_odd_in_1_to_n();
	// print_odd_in_1_to_n_better();
	// print_factorial_1();
	// print_factorial_2();
	// print_factorial_correct_1();
	// print_factorial_correct_2();
	// print_sum_odd_nos();
	// print_descending_1();
	// print_descending_2();
	// print_descending_3();
	// print_descending_4();
	print_descending_5();
	return 0;
}
