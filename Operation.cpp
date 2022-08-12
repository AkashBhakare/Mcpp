#include "operation.h"
#include <iostream>
long long int my_lib::Operation::add(int n1, int n2)
{
    return static_cast<long long int>(n1) + n2;
}

long long int my_lib::Operation::add(int n1, int n2, int n3)
{
    return static_cast<long long int>(n1) + n2 + n3;
}

long double my_lib::Operation::add(float n1, float n2)
{
    return static_cast<long double>(n1) + n2;
}

long long int my_lib::Operation::multiply(int n1, int n2)
{
    return static_cast<long double>(n1) * n2;
}

void my_lib::Operation::dotask() const
{
    std::cout << "Constant Function called\n";
}

void my_lib::Operation::dotask()
{
    std::cout << "Non-Constant Function called\n";
}