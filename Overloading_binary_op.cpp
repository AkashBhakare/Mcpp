// Polymorphism_Overloading_binary_op.cpp : 

#include <iostream>
#include "RationalNumber.h"
int main()
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
	return 0;
}
