// 45_Lvalue_Rvalue.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cstdlib>
#include <stdexcept>


/*
* The key to understanding rvalue references is the concept of an anonymous variable.
* An anonymous variable has no name and this is the distinguishing feature for the
* compiler to associate it automatically with an rvalue reference if it has a choice.
*/

struct X {
	int data{ 10 };
	X() {
		std::cout << "X is constructed\n";
	}
	X(const X& x) {
		std::cout << "X is copy constructed\n";
	}
	~X() {
		std::cout << "X is destroyed\n";
	}
};


void receive(int& value) // note: lvalue reference
{
	std::cout << "int value parameter\n";
}

void receive(int&& value) // note: rvalue reference
{
	std::cout << "int R-value parameter\n";
	//Internally, it actually uses a temporary variable to store the received value
	value++; // Okay
	std::cout << "Value : " << value << std::endl;
}

/*
* the compiler selects the overloaded function using the rvalue reference if the
* function is passed an anonymous value
*/
//void receive(const int& value) // note: rvalue reference
//{
//	std::cout << "int const L-value parameter\n";
//	//Internally, it actually uses a temporary variable to store the received value
//	//value++; // Error
//	std::cout << "Value : " << value << std::endl;
//}

/*
* When confronted with the choice between a value parameter and a reference parameter
* (either lvalue or rvalue) it cannot make a decision and reports an ambiguity.
*/

//void receive(int value) // note: call by value
//{
//
//	std::cout << "value parameter\n";
//}

//void receive(X value) // note: call by value
//{
//	value.data = 888;
//	std::cout << "value parameter : data : "<<value.data <<"\n";
//}

//void receive(X& value) // note: lvalue reference
//{
//	std::cout << "int l-value parameter\n";
//}

void receive(X&& value) // note: rvalue reference
{
	std::cout << "int R-value parameter\n";
}




X XVal()
{
	return X{};
}

int intVal() //r_value
{
	return 5;
}

int multiply_10_by(int factor) { //r-value
	int i = 10;  //local variable : l-value
	i = i * factor;
	return i; //actually returns a temporary copy of i which R-Value
}

void 	working_with_primitive_types() {
	/*  Although intVal’s return value can be assigned to an int variable it requires copying,
		which might become prohibitive when a function does not return an int but instead some
		large object. */

	int ivar = intVal(); // Copies return value into ivar
	std::cout << "ivar : " << ivar << std::endl;
	ivar = multiply_10_by(4);
	std::cout << "ivar : " << ivar << std::endl;
	// std::cout << i;  local to multiply_10_by
	/*
	* A reference or pointer cannot be used either to collect the anonymous return value as
	* the return value won’t survive beyond that
	*/
	int& ir1 = ivar;
	//int& ir2 = intVal(); // fails: refers to a temporary;  cannot convert from 'int' to 'int &'
	//int& ir3 = multiply_10_by(5);
	//int* ip1 = &intVal(); // fails: no lvalue available; '&' requires l-value
	//int* ip2 = &multiply_10_by(5);  // fails: no lvalue available; '&' requires l-value

	//const int* ptr = &intVal(); //cannot seek for address of R-value
	int const& ic1 = intVal(); // OK: immutable temporary
	//it is not possible to modify the temporary returned by intVal.
	//ic1 = 77;
	int const& ic2 = 77; // OK: immutable temporary
	std::cout << "ic1 : " << ic1 << "\tic2 : " << ic2 << std::endl;

	/*
	* The program’s output shows the compiler selecting receive(int &&value)
	* in all cases where it receives an anonymous int as its argument
	*/

	// Literal 18 has no name and thus receive(int&& value) is called
	receive(18);

	// Value is a variable threfore has a name and thus receive(int& value) is called
	int value = 5;
	receive(value);

	// inVal() retruns a temporary variable
	receive(intVal());
	return;
}

void working_with_class_types() {
	/*
	* Although return value can be assigned to an variable it requires copying, which might
	become prohibitive when a function does not return an basic type but instead some
	large object.
	*/

	//receive(X{});
	//X x{};
	//receive(x);
	receive(XVal());
}


int main()
{

	working_with_primitive_types();
	//working_with_class_types();

	return EXIT_SUCCESS;
}