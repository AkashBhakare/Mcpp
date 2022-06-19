// 82_Inheritance.cpp : // change the access of a base class member that is inherited in the derived class
/*
You may increase the access of the following members:
A member inherited as private.
A member either inherited or declared as protected
You cannot increase the access of a member declared as private because a using declaration must have access to the member’s name.

*/

#include <iostream>
#include "usingdemo.h"

/*Non-Member frunction*/
void check_derived1_members() {
	Derived1 d1_obj{};
	//std::cout << d1_obj.b_pri_mem << "\n";
	//std::cout << d1_obj.b_pro_mem << "\n";
	std::cout << d1_obj.b_pub_mem << "\n";
}

/*Non-Member frunction*/
void check_derived2_members() {
	Derived2 d2_obj{};
	//std::cout << d2_obj.b_pri_mem << "\n";
	/*we have brought the member b_pro_mem of the Base class in public scope of Derived2 class */
	std::cout << d2_obj.b_pro_mem << "\n";
	std::cout << d2_obj.b_pub_mem << "\n";
}


/*Non-Member frunction*/
void check_derived3_members() {
	Derived3 d3_obj{};
	//std::cout << d3_obj.b_pri_mem << "\n";
	//std::cout << d3_obj.b_pro_mem << "\n";
	//std::cout << d3_obj.b_pub_mem << "\n";
}

/*Non-Member function*/
void check_derived4_members() {
	Derived4 d4_obj{};
	//std::cout << d4_obj.b_pri_mem << "\n";
	/*we have brought the protected and public members of the Base class in
	public scope of Derived4 class */
	std::cout << d4_obj.b_pro_mem << "\n";
	std::cout << d4_obj.b_pub_mem << "\n";
}


int main()
{
	std::cout << "Size of Base class     : " << sizeof(Base) << " bytes\n";
	std::cout << "Size of Derived1 class : " << sizeof(Derived1) << " bytes\n";
	std::cout << "Size of Derived2 class : " << sizeof(Derived2) << " bytes\n";
	check_derived1_members();
	check_derived2_members();
	/*check_derived3_members();
	check_derived4_members();*/

}