#include "A.h"
#include <iostream>

void A::foo(void)
{
	std::cout << "A::foo \n";
}

void B::foo(int x)
{
	std::cout << "B::foo " << x << "\n";
}

void FirstClass::doit(int task_id)
{
	std::cout << "Doing task id : " << task_id << "\n";
}


void FirstClass::doit(int task_id1, int task_id2)
{
	std::cout << "Doing 2 task  : " << task_id1 << " & " << task_id2 << "\n";
}

void SecondClass::doit(std::string task)
{
	std::cout << "Doing task name : " << task << "\n";
}