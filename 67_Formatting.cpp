// 67_Formatting.cpp : 
// Explore manipulators for formatting


#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdexcept>
//#include <strstream> //The class ostrstream implements output operations on array-backed streams.
#include <iomanip>
#include <limits>
#include <cstring>

using std::ios;  // bring std::ios in the current scope

void boolalphademo() {

	bool flag{ true };
	std::cout << "Flag : " << flag << std::endl;
	flag = false;
	std::cout << "Flag : " << flag << std::endl;
	/* turns the flag on*/
	std::cout << "Flag : " << std::setiosflags(ios::boolalpha) << flag << std::endl;
	flag = true;
	std::cout << "Flag : " << flag << std::endl;
	flag = false;
	std::cout << "Flag : " << flag << std::endl;

	/* turns the flag off */
	std::cout << "Flag : " << std::resetiosflags(ios::boolalpha) << flag << std::endl;
	flag = false;
	std::cout << "Flag : " << flag << std::endl;

	/* turns the flag on using manipulator*/
	std::cout << std::boolalpha;
	int age{ 17 };
	std::cout << "Is he/she eligible to vote ? " << (age >= 18) << std::endl;

	age = 21;
	std::cout << "Is he/she eligible to vote ? " << (age >= 18) << std::endl;

	/* turns the flag off using manipulator*/
	std::cout << std::noboolalpha; //default behaviour

	flag = true;
	std::cout << "Flag : " << flag << std::endl;
	flag = false;
	std::cout << "Flag : " << flag << std::endl;

	flag = true;
	std::cout << "Flag : " << std::boolalpha << flag << std::endl;
	flag = false;
	std::cout << "Flag : " << flag << std::endl;
	std::cout << std::noboolalpha;

}

void ends_demo() {
	//This manipulator is typically used with std::ostrstream, 
	//when the associated output buffer needs to be null - terminated to be processed as a C string.
	//Unlike std::endl, this manipulator does not flush the stream.
	//char a[10] = {'A','\n','B','\0'}; //array containing C style string
	//char b[10] = { 'A','\n','B' };  //just a character array initialized with character literls
	//std::printf("string : %s\n", a);
	//
	//std::ostrstream oss;
	//oss << "Sample text: " << 42 << std::ends;
	//std::printf("%s\n", oss.str());
	//oss.freeze(false); // enable memory deallocation

	//std::ostringstream ostr;
	//ostr << "Sample text: " << 42;
	//std::cout << ostr.str();
}

void base_demo_cout() {
	int i = 100;

	//base
	std::cout << "Value of i is (dec) : " << i << std::endl;
	std::cout << "Value of i is (dec) : " << std::dec << i << std::endl;

	std::cout << "Value of i is (hex) : " << std::hex << i << std::endl;

	std::cout << "Value of i is (oct) : " << std::oct << i << std::endl;

	std::cout << "Value of i is (dec) : " << std::dec << i << std::endl;

	//showbase

	std::cout << "Showbase " << std::endl;

	std::cout << "Value of i is (dec) : " << std::dec << std::showbase << i << std::endl;

	std::cout << "Value of i is (oct) : " << std::oct << std::showbase << i << std::endl;

	std::cout << "Value of i is (hex) : " << std::hex << std::showbase << i << std::endl;

	// uppercase
	i = 2000;
	std::cout << "Uppercase " << std::endl;
	std::cout << "Value of i is (hex) : " << i << std::endl;
	std::cout << "Value of i is (hex) : " << std::uppercase << i << std::endl;
	std::cout << "Value of i is (hex) : " << std::noshowbase << i << std::endl;

}

void reset_input_stream()
{
	// If an invalid input occurred:
	std::cin.sync(); // Clears the buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear(); // Reset error flags

}

void base_demo_cin() {
	int ivar{};
	std::cout << "Enter an Integer in decimal format : ";
	std::cin >> std::dec >> ivar;  //default behaviour
	std::cout << "Integer in decimal format : " << std::dec << ivar << std::endl;
	reset_input_stream();

	std::cout << "Enter an Integer in Octal format : ";
	std::cin >> std::oct >> ivar;
	reset_input_stream();
	std::cout << "Integer in Octal format   : " << std::showbase << std::oct << ivar << std::endl;
	std::cout << "Integer in decimal format : " << std::dec << ivar << std::endl;

	std::cout << "Enter an Integer in Hexadecimal format : ";
	std::cin >> std::hex >> ivar;
	reset_input_stream();
	std::cout << "Integer in Hexadecimal format : " << std::showbase << std::hex << ivar << std::endl;
	std::cout << "Integer in decimal format     : " << std::dec << ivar << std::endl;

}


void left_right_justification_demo() {
	//justification
	int i{ 1234 };
	std::cout << i << std::endl;
	std::cout << std::right << i << std::endl;
	std::cout << std::left << i << std::endl;

	std::cout << std::cout.width() << std::endl; //returns the current width

	std::cout << std::setw(10) << i << "*" << "*" << std::endl;


	std::cout << std::right << std::setw(10) << i << std::endl;

	std::cout << std::setw(10) << "hello" << std::endl;

	std::cout << std::left << std::setw(10) << "hello" << "*";

	std::cout << std::right;
}


void cin_width_demo() {

	std::string data;

	//std::cout << "Please enter a String :";
	//std::cin >> std::noskipws;
 //  do {
	//	std::cin >> std::setw(10) >> data;
	//	std::cout << data << std::endl;
	//}while(data != "\0");

	//std::cout.flush();
	//char arr[100];
	//std::cin.getline(arr,11);
	//std::cout << arr << "\tSize : "<< std::strlen(arr) << std::endl;


	std::string input{ "IamveryhappytodayIwillgivemybesttoday" };
	std::istringstream mystream{ input };
	size_t width{ 1 };
	while (!mystream.eof()) {
		mystream >> std::setw(width++) >> data;
		std::cout << data << std::endl;

	}

}

void filldemo() {
	int i = 99;
	std::cout << std::setw(10) << std::setfill('*') << i << std::endl;

	std::cout << std::left << std::setw(10) << std::setfill('#') << i << std::endl;

	std::cout << std::setw(10) << i << std::endl;

	i = -14;
	std::cout << std::right << std::setw(10) << std::setfill('*') << i << std::endl;

	std::cout << std::left << std::setw(10) << std::setfill('#') << i << std::endl;

}

void internal_justification() {
	int i{ -55 };
	std::cout << std::setw(10) << std::internal << i << std::endl;
	std::cout << std::setfill('#');
	std::cout << std::setw(10) << std::internal << i << std::endl;
}


void showpos_demo() {
	int i{ -55 };
	std::cout << std::setfill('*');

	std::cout << std::internal << std::setw(10) << i << std::endl;

	i = +55;
	std::cout << std::internal << std::setw(10) << i << std::endl;


	i = +55;
	std::cout << std::internal << std::setw(10) << std::showpos << i << std::endl;
	std::cout << std::left << std::setw(10) << std::showpos << i << std::endl;
	std::cout << std::right << std::setw(10) << std::showpos << i << std::endl;

	i = -55;
	std::cout << std::internal << std::setw(10) << std::showpos << i << std::endl;
	std::cout << std::left << std::setw(10) << std::showpos << i << std::endl;
	std::cout << std::right << std::setw(10) << std::showpos << i << std::endl;
	return;
}

void floating_point_precision() {
	float f1{ 36 };
	std::cout << "Real number 36    : " << f1 << std::endl;
	float f2{ 36.0 };
	std::cout << "Real number 36.0  : " << f2 << std::endl;
	float f3{ 36.0f };
	std::cout << "Real number 36.0f : " << f3 << std::endl;

	std::cout << std::showpoint;

	std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
	std::cout << "Real number 36    : " << f1 << std::endl;
	std::cout << "Real number 36.0  : " << f2 << std::endl;
	std::cout << "Real number 36.0f : " << f3 << std::endl;

	std::cout << std::setprecision(5);
	std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
	std::cout << "Real number 36    : " << f1 << std::endl;
	std::cout << "Real number 36.0  : " << f2 << std::endl;
	std::cout << "Real number 36.0f : " << f3 << std::endl;

	std::cout << std::setprecision(10);
	std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
	std::cout << "Real number 36    : " << f1 << std::endl;
	std::cout << "Real number 36.0  : " << f2 << std::endl;
	std::cout << "Real number 36.0f : " << f3 << std::endl;

	std::cout << std::setprecision(6);  //revert to default

}


void floating_point_formatting() {

	std::cout << std::noshowpoint;

	std::cout << std::setprecision(6);

	float f1{ 36 };
	std::cout << "Real number 36    : " << f1 << std::endl;

	std::cout << "Real number 36    : " << std::fixed << f1 << std::endl;

	std::cout << std::setprecision(4);

	std::cout << "Real number 36    : " << f1 << std::endl;

	f1 = 30000000;

	std::cout << "Real number 30000000    : " << f1 << std::endl;

	std::cout << std::setprecision(2);

	std::cout << "Real number 30000000    : " << std::scientific << f1 << std::endl;
	std::cout << "Real number 30000000    : " << std::uppercase << f1 << std::endl;
}


int main()
{
	//boolalphademo();
	//ends_demo();
	//base_demo_cout();
	//base_demo_cin();
	//left_right_justification_demo();
	//cin_width_demo();
	//filldemo();
	//internal_justification();
	//showpos_demo();
	//floating_point_precision();
	floating_point_formatting();

}