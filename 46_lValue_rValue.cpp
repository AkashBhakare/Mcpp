// 46_lValue_rValue.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
You can overloada function to take a  lvaluev reference and an rvalue reference.
By overloading a function to take a const lvalue reference or an rvalue reference.
you can write code that distinguishes between non-modifiable object (lvalues) and
modifiable temporary values (rvalues). you can pass an object to a function that takes
an rvalue reference unless the object is marked as const . the following example show
the function f, which is overloaded to take an lvalue reference and an rvalue reference.
the main function calls f with both lvalues amd an rvalues.

*/

#include <iostream>

//A cllass that contains a memory resource.
struct MemoryBlock
{
	int data{ 99 };
};

/*const reference can recive const and non-const lvalues but cannot modify*/
void f(const MemoryBlock&)
{
	std::cout << "In f(const MemoryBlock&). This version cannot modify the parameter." << std::endl;
}

void f(MemoryBlock&&)
{
	std::cout << "in f(MemoryBlock&&). This version can modify the parameter." << std::endl;
}

int main()
{
	/*The compiler treats a named rvalue reference as an lvalue and an unnamed rvalue reference as an rvalues*/
	MemoryBlock block;  //non-const object (lvalue)
	f(block);      //passes a local variable (an lvalue) as its argument.
	f(MemoryBlock());  //passes a non-const temporary object as its argument

	const MemoryBlock Cblock;
	f(block);  //constant object l-value
	/*you can pass an object to a function that takes an rvalue reference unless the object is marked as*/
	f((const MemoryBlock()));  //passes a const tempory object as its arguments
	return EXIT_SUCCESS;
}
