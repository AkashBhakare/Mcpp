// Polymorphism_Overloading_binary_op.cpp : 

#include <iostream>
#include "RationalNumber.h"
#include "Overloading_binary_op.h"
int main()
{
    overloading_plus_minus();
	whats_under_the_hood();
	overloading_inserter_extractor();
	return 0;
}

void overloading_plus_minus()
{
	mylib::RationalNumber r1(3, 4);
	std::cout << "R1 : " << r1.get_string_representation() << std::endl;
	mylib::RationalNumber r2;
	std::cout << "R2 : " << r2.get_string_representation() << std::endl;

	mylib::RationalNumber r3(1, 5);
	std::cout << "R2 : " << r3.get_string_representation() << std::endl;

	r2 = r1;		/* r2.operator=(r1) */
	std::cout << "R2 : " << r2.get_string_representation() << std::endl;


	/* r1.operator+(r3);  since operator + is a member function */
	mylib::RationalNumber r4 = r1 + r3;
	std::cout << r1.get_string_representation() << " + "
		<< r3.get_string_representation() << " = "
		<< r4.get_string_representation() << std::endl;

	/* operator+(r1,r3);  since operator - is a non-member function */
	r4 = r1 - r3;
	std::cout << r1.get_string_representation() << " - "
		<< r3.get_string_representation() << " = "
		<< r4.get_string_representation() << std::endl;
	return;
}

void whats_under_the_hood() {

	int rollNo = 67;
	/* inserting C style string (const char*) literal into output stream using operator <<
	   cout << "Hi";
	   operator << (cout, "Hi");    if the operator function is Non member function
	*/
	std::cout << "Roll Number = ";

	/* inserting integer into output stream using operator <<
		cout << rollNo;
		cout.operator << (rollNo);    The operator function is member function
	*/
	std::cout << rollNo;

	/*
		cin >> rollNo;
		cin.operator>>(rollNo);
	*/
	std::cin >> rollNo;

	/* inserting character literal into output stream using operator <<
	   cout << '\n';
	   operator << (cout, '\n');   Tthe operator function is Non member function
	*/
	std::cout << '\n';

	float percentage = 78.98F;
	std::cout << "Percentage : ";


	/* inserting integer into output stream using operator <<
		cout << percentage;
		cout.operator << (percentage);  The operator function is member function
	*/
	std::cout << percentage;
	std::cout << '\n';



	struct Point {
		int x = 4;
		int y = 3;
	};

	Point point;
	//std::cout << point;
	mylib::RationalNumber r{ 4 / 5 };
	//std::cout << r;

}

void overloading_inserter_extractor()
{
	mylib::RationalNumber r1{ 3,7 };

	std::cout << r1.get_string_representation() << '\n';

	std::cout << "R1 : ";
	/*
		cout << r1;
		operator << (cout, r1);
	*/
	std::cout << r1;

	std::cout << "R1 : " << r1 << std::endl;

	std::cout << "Accept Relational number : \n";
	/*
	  cin >> r1;
	  operator >> (cin, r1);
	*/
	std::cin >> r1;
	std::cout << "R1 : " << r1 << std::endl;

}