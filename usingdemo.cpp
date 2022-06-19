#include "usingdemo.h"
#include <iostream>

void Derived1::check_member_access()
{
	//std::cout << b_pri_mem << "\n";
	std::cout << b_pro_mem << "\n";
	std::cout << b_pub_mem << "\n";
}

void Derived2::check_member_access()
{
	//std::cout << b_pri_mem << "\n";
	std::cout << b_pro_mem << "\n";
	std::cout << b_pub_mem << "\n";
}


void Derived3::check_member_access()
{
	//std::cout << b_pri_mem << "\n";
	std::cout << b_pro_mem << "\n";
	std::cout << b_pub_mem << "\n";
}

void Derived4::check_member_access()
{
	//std::cout << b_pri_mem << "\n";
	std::cout << b_pro_mem << "\n";
	std::cout << b_pub_mem << "\n";
}