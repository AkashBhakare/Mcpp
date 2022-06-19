#pragma once

#include <string>

struct A
{
	void foo(void);
};

struct B :public A {
	//hides method "void foo(void)" inherited from A
	void foo(int x);

};


struct FirstClass {
	void doit(int task_id);

	// overloads the method "void doit(int task_id)"
	void doit(int task_id1, int task_id2);
};

struct SecondClass : public FirstClass {
	/*introduce the doit method of firstClass in the scope of SecondClass to avoid hiding*/
	using FirstClass::doit;

	void doit(std::string task);
};
