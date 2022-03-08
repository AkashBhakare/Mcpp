// Constants.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <math.h>
#include <iomanip>
#include <thread>
#include <chrono>
void constant_basics();
void constant_use_case1();
void constant_use_case2();
void const_constexpr_diff();
void constexpr_define_diff();
void bar();


void baz(const int data) {
	// data = 88;
}


int foo() {
	int a{ 0 };
	std::cout << "enter a integer : ";
	std::cin >> a;
	return a;
}

int main()
{
	//constant_basics();

	//constant_use_case1();
	constant_use_case2();
	//const_constexpr_diff();
	//constexpr_define_diff();
	//std::this_thread::sleep_for(std::chrono::seconds(4));
	return EXIT_SUCCESS;
}

// const T var_name{ initializer };
// T const var_name{ initializer };

void constant_basics() {

	const int ci1{ 1 };  //Initialization required
	std::cout << "ci1 : " << ci1 << std::endl;
	//ci1 = 33;		//error : Assignment is not possible to constant variable
	
	int const ci2{ 2 };

	//const int ci3; // Error: no value

	float const pi{ 3.14159f };
	std::cout << "pi  : " << pi << std::endl;

	const char cc{ 'a' };
	std::cout << "cc  : " << cc << std::endl;

	const int result = foo(); // initialization can be differed till run time

	const bool cmp{ ci1 < result };
	std::cout << "cmp : " << std::boolalpha << cmp << std::endl;

	int a{ 10 };
	int b;
	std::cout << "Enter two integers ";
	std::cin >> a >> b;
	const bool flag = (a < b);

	std::cout << "flag :" << std::boolalpha << flag << std::endl;


	//A constexpr variable accepts only compile - time values
	constexpr short scale{ 4 };
	//constexpr short int scale = 4;
	std::cout << "scale : " << scale << std::endl;
	constexpr bool is_signed = true;
	std::cout << "is_signed : " << is_signed << std::endl;

	std::cout << "is_signed : "
		<< std::boolalpha << is_signed << std::endl;

	std::cout << "is_signed : " << std::boolalpha << is_signed << std::endl;

	constexpr int max{ 8 * 1024 }; //compile time constant
	std::cout << "max : " << max << std::endl;
	constexpr int min{ 10 };
	constexpr bool flag1{ min < max }; //compile time evaluation

	//constexpr int product1{ a * b }; //the initializer has to be evaluated at compile time
	const int product2{ a * b }; //runtime constant
	std::cout << "product : " << product2 << std::endl;
	//product = 34;
	//constexpr int product1 = (a * b); //Error

	baz(10);
}

void constant_use_case1() {
	int age{};
	std::cout << "What's your age (years) ? ";
	std::cin >> age;

	if (age >= 18) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

	if (age >= 18) {
		std::cout << "You are eligible for Driving licanse!" << std::endl;
	}
	else {
		std::cout << "You are not eligible  for Driving licanse!" << std::endl;
	}

	//Avoid “magic constants”; use symbolic constants
	constexpr int MIN_AGE_FOR_VOTING{ 16 };
	constexpr int MIN_AGE_FOR_DRIVING{ 18 };

	std::cout << "What's your age (years) ? ";
	std::cin >> age;

	if (age >= MIN_AGE_FOR_VOTING) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

	if (age >= MIN_AGE_FOR_DRIVING) {
		std::cout << "You are eligible for Driving licanse!" << std::endl;
	}
	else {
		std::cout << "You are not eligible  for Driving licanse!" << std::endl;
	}

}


void constant_use_case2() {
	std::cout << "What's the rate of the product(Rs) :";
	float price;
	std::cin >> price;
	std::cout << "How many such products have you purchased ? :";
	float qty_purchased;
	std::cin >> qty_purchased;
	//Avoid “magic constants”; use symbolic constants
	float bill_amount = (price * qty_purchased * 0.05F);
	bill_amount = bill_amount - (bill_amount * 0.02f);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;

	constexpr float DISCOUNT_RATE = 0.05f;
	constexpr float LOYALTY_DISCOUNT_RATE = 0.02f;

	bill_amount = (price * qty_purchased) * DISCOUNT_RATE;
	bill_amount = bill_amount - (bill_amount * LOYALTY_DISCOUNT_RATE);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;
}

void const_constexpr_diff() {
	const double      C_PI = 3.142;
	constexpr double CE_PI = 3.142;
	std::cout << "Value of const     PI : " << C_PI << std::endl;
	std::cout << "Value of constexpr PI : " << CE_PI << std::endl;

	const double     C_PI_2 = C_PI / 2;   // evaluates at runtime
	constexpr double CE_PI_2 = CE_PI / 2;   // evaluation happens at compile time
	std::cout << "Value of const     PI/2 : " << C_PI_2 << std::endl;
	std::cout << "Value of constexpr PI/2 : " << CE_PI_2 << std::endl;

	const double     C_PI_4 = CE_PI / 4;
	std::cout << "Value of const     PI/4 : " << C_PI_4 << std::endl;

	constexpr double CE_PI_4 = C_PI / 4;
	const double x = CE_PI;
}



void constexpr_define_diff() {
	constexpr int max = 77;
#define MIN 2
	constexpr int max1 = MIN;
	std::cout << "max = " << max << std::endl;
	std::cout << "MIN = " << MIN << std::endl;

}

void bar() {
	//std::cout << "max = " << max << std::endl; //undefined
	std::cout << "MIN = " << MIN << std::endl;
}