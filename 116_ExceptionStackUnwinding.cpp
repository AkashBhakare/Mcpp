// 116_ExceptionStackUnwinding.cpp : 
#include <string>
#include <iostream>
#include <stdexcept>

struct MyException : std::exception {};

struct Dummy
{
	//ctor
	Dummy(std::string s) : my_name(s) {
		print_msg("Created Dummy:");
	}

	//ctor
	Dummy(const Dummy& other) : my_name(other.my_name) {
		print_msg("Copy created Dummy:");
	}

	//dtor
	~Dummy() {
		print_msg("Destroyed Dummy:");
	}

	//member function (method)
	void print_msg(std::string s) {
		std::cout << s << my_name << std::endl;
	}

	//data member
	std::string my_name;
	int level;
};

void C(Dummy d, int i)
{
	std::cout << "Entering FunctionC" << std::endl;
	d.my_name = " C";
	throw MyException();

	std::cout << "Exiting FunctionC" << std::endl;
}

void B(Dummy d, int i)
{
	std::cout << "Entering FunctionB" << std::endl;
	//try {
	d.my_name = "B";
	C(d, i + 1);
	/*}
	catch (const MyException& error) {
		std::cout << error.what() <<std::endl;
	}*/
	std::cout << "Exiting FunctionB" << std::endl;
}

void A(Dummy d, int i)
{
	std::cout << "Entering FunctionA" << std::endl;
	d.my_name = " A";
	//  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
	B(d, i + 1);
	//   delete pd;
	std::cout << "Exiting FunctionA" << std::endl;
}

int main()
{
	std::cout << "Entering main" << std::endl;
	try
	{
		Dummy d(" M");
		A(d, 1);
	}
	catch (MyException& e)
	{
		std::cout << "Caught an exception of type: " << typeid(e).name() << std::endl;
	}

	std::cout << "Exiting main." << std::endl;
	char c;
	std::cin >> c;
}

/* Output:
	Entering main
	Created Dummy: M
	Copy created Dummy: M
	Entering FunctionA
	Copy created Dummy: A
	Entering FunctionB
	Copy created Dummy: B
	Entering FunctionC
	Destroyed Dummy: C
	Destroyed Dummy: B
	Destroyed Dummy: A
	Destroyed Dummy: M
	Caught an exception of type: class MyException
	Exiting main.

*/