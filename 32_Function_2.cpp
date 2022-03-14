// 32_Function_2.cpp : Main()

#include <iostream>
#include <cstdlib>
#include "myfunctions.h"

int main(void)
{
    int i1n = get_integer("Enter the first integer : ");
    int i2n = get_integer("Enter the second integer : ");
    auto result = addition(i1n, i2n);
    std::cout << i1n << " + " << i2n << " = " << result << '\n';

    i1n = get_integer("Enter an integer : ");
    result = square(i1n);
    std::cout << "Square of " << i1n << " = " << result << '\n';
    return EXIT_SUCCESS;
}

