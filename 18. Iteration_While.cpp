// 18. Iteration_While.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

void why_loop() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	return;
}

void loop_basic1() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "How many time should we greet '" << name << "' ";
	int limit;
	std::cin >> limit;

	int counter{ 1 };
	while (counter <= limit) {
		std::cout << counter << ". Hello " << name << "\n";
		++counter;
	}

	return;
}


/* Any non-zero integral value evaluates to true and only zero evalutes to false*/
void loop_basic2() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "How many time should we greet '" << name << "' ";
	int limit;
	std::cin >> limit;

	while (limit) {
		std::cout << "Hello " << name << "\n";
		--limit;
	}


	return;
}

// Divide the number by all numbers in the range of (1 to n) and check the number of factors
// complexity 2n+1
void check_prime1() {
	std::cout << "Please enter a integer : ";
	int number{};

	std::cin >> number;
	int factor_count{ 0 };
	int divisor{ 1 };

	while (divisor <= number) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 2) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}

}

//complixity : (n-1)+(n-2) : 2n-3
void check_prime2() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	int factor_count{ 0 };

	int divisor{ 2 };
	while (divisor < number) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}

}

/*
* Divide the number 'n' with all inthers in the range of 2 to n/2 and then check the number of factors
*/
//complixity : (n/2)+(n/2)-1 : n-1
void check_prime3() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	int factor_count{ 0 };
	
	int divisor{ 2 };
	int limit{ number / 2 };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}
	return;
}


/*Divide the number by all integers in the range of 2 to sqrt(n)*/
//sqrt(n)+1
void check_prime4() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;

	int factor_count{ 0 };

	int divisor{ 2 };
	int limit{ static_cast<int>(sqrt(number)) };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}
	return;
}


/*Divide the number by all integers in the range of 2 to sqrt(n)*/
void check_prime5() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	
	int divisor{ 2 };
	int limit{ static_cast<int>(std::sqrt(number)) };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			break; // terminate the loop when a factor is found
		}
		++divisor;
	}

	if (divisor <= limit) {
		std::cout << number << " is a NOT Prime Number\n";
	}
	else {
		std::cout << number << " is a Prime Number\n";
	}
	return;
}

/*Divide the number by all integers in the range of 2 to sqrt(n)*/
void check_prime6() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;

	int divisor{ 2 };
	int limit{ static_cast<int>(std::sqrt(number)) };
	if (number != 2) {
		if (number % divisor != 0) {
			divisor = 3;
			while (divisor <= limit) {
				if (number % divisor == 0) {
					break; // terminate the loop when a factor is found
				}
				divisor+=2;
			}
		}
	}
	if (divisor <= limit) {
		std::cout << number << " is a NOT Prime Number\n";
	}
	else {
		std::cout << number << " is a Prime Number\n";
	}
	return;
}

int main()
{
	// why_loop();
	// loop_basic1();
	// loop_basic2();
	// check_prime1();
	// check_prime2();
	// check_prime3();
	// check_prime4();
	// check_prime5();
	// check_prime6();
}
