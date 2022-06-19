// 79_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Early or Static
// Name- mangling


#include <iostream>
#include "SimpleCalculator.h"

int main()
{
    SimpleCalculator calculator{};

    std::cout << "Add two integers : " << calculator.add(10, 20) << "\n";
    std::cout << "Add four integers : " << calculator.add(10, 20, 30, 50) << "\n";

    int in1{ 10 };
    int in2{ 20 };

    std::cout << "Add two integers : " << calculator.add(in1, in2) << "\n";
    float f1{ 3.4F };
    float f2{ 5.7f };
    std::cout << "Add two floats : " << calculator.add(f1, f2) << "\n";

    double d1{ 3.41 };
    double d2{ 5.64 };
    // std::cout << "Add two double : " << calculator.add(d1, d2) << "\n";
    std::cout << "Mulltiply two double : " << calculator.multi(d1, d2) << "\n";
    std::cout << "Multiply two integers : " << calculator.multi(in1, in2) << "\n";
    std::cout << "Multiply two floats : " << calculator.multi(f1, f2) << "\n"; 

    std::cout << "Divide two double : " << divide(d1, d2) << "\n";
    std::cout << "Divide two integers : " << divide(in1, in2) << "\n";
    std::cout << "Divide two floats : " << divide(f1, f2) << "\n";
}