// 36_Function_Passing_Arguments.cpp : 
//Passing Arguments during Function Calls

#include <iostream>
#include <cmath>
#include <limits>


long double factorial(int n1, int  n2);
long double factorial(int value);
int get_integer(std::string msg);
void call_by_value1();
void call_by_value2();
void swap1(int, int);

void call_reference_need();
float get_float(std::string msg);
int maximum(float);
int minimum(float f);

void call_by_reference1();

int maxmin(float f, int* p_max, int* p_min);

void call_by_reference2();
void swap2(int*, int*);
using namespace std::literals;

int main()
{
   call_by_value1();
   call_by_value2();
   call_reference_need();
   call_by_reference1();
   call_by_reference2();
}

void call_by_value1() {

}


int get_integer(std::string msg) {
	int number{};
	do {
		std::cout << msg;
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cerr << "The input was incorrect!\n";
		}
		else {
			return number;
		}
	}while (true);
}

/*Takes two integers as an arguments and returns their addtion as lon long value*/
long double addition(int n1, int  n2) {
	return static_cast<long long int>(n1) + n2;
}



long double factorial(int number) {

}

void swap1(int in1, int in2) {
	int itemp{};
	itemp = in1;
	in2 = in2;
	in2 = itemp;
	std::cout << "(in called routine - swap in1 : " << in1 << "\tin2 : " << in2 << '\n';
	return;
}

void call_by_value2() {
	int in1{ 10 };
	int in2{ 20 };
	std::cout << "(Before : in called routine - swap in1 : " << in1 << "\tin2 : " << in2 << '\n';
	swap1(in1, in2);
	std::cout << "(After : in called routine - swap in1 : " << in1 << "\tin2 : " << in2 << '\n';
}

/*Function couldnt return more than one value*/
void call_reference_need() {
	float f = get_float("Enter a floating point value :"s);
	std::cout << "The Largest integer not greater than " << f << " is " << maximum(f) << '\n';
	std::cout << "The Minimum integer not smaller than " << f << " is " << minimum(f) << '\n';

}

/*Takes no argument and return a integer*/
float fet_float(std::string msg) {

}

int maximum(float f) {

}

int minimum(float f) {

}

void call_by_reference1() {
	int max{ 122 };
	int min{ 3 };
	float f = get_float("Enter a floating point value : "s);
	maxmin(f, &max, &min);
	std::cout << "The Largest integer not greater than " << f << " is " << max << '\n';
	std::cout << "The Minimum integer not smaller than " << f << " is " << min << '\n';

}
int maxmin(float f, int* p_max, int* p_min) {
	std::cout << "Address : " << p_max << "\tValue : " << *p_max << '\n';
	std::cout << "Address : " << p_min << "\tValue : " << *p_min << '\n';
	*p_max = std::floor(f);
	*p_min = std::ceil(f);
}

void swap2(int* ptr1, int* ptr2) {
	int itemp{};
	itemp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = itemp;
	std::cout << "(in called routine - swap *ptr1 : " << *ptr1 << "\t*ptr2 : " << *ptr2 << '\n';
	return;
}

void call_by_reference2() {
	int in1{ 10 };
	int in2{ 20 };
	std::cout << "(Before : in called routine - swap in1 : " << in1 << "\tin2 : " << in2 << '\n';
	swap2(&in1, &in2);
	std::cout << "(After : in called routine - swap in1 : " << in1 << "\tin2 : " << in2 << '\n';
}













