// 81_Inheritance.cpp : // How to overload a inherited method in subclass

#include <iostream>
#include "A.h"
int main()
{
    A a_obj{};
    a_obj.foo();

    B b_obj{};
    b_obj.foo(99);
    //b_obj.foo();

    FirstClass f_obj{};
    f_obj.doit(101);
    f_obj.doit(10, 12);

    SecondClass s_obj{};
    s_obj.doit("One");
    s_obj.doit(102);
    s_obj.doit(101, 201);
}