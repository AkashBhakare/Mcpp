// 103_Ex1DivByZero.cpp 
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <exception>

/*
 * example to demonstrate exception
 * handling is avoiding divide-by-zero
 */
float safeDivide(int num, int den) {
    if (den == 0) {
        /*It reports errors that arise because an argument value has not been accepted.*/
        throw std::invalid_argument("Divide by zero Error");
    }
    return static_cast<float>(num) / den;
}

int main() {
    try {
        std::cout << safeDivide(5, 2) << std::endl;
        std::cout << safeDivide(10, 3) << std::endl;
        std::cout << safeDivide(13, 0) << std::endl;
        std::cout << safeDivide(13, 3) << std::endl;
    }
    catch (const std::invalid_argument& ref_invalid_arg) {
        std::cout << "Caught exception : " << ref_invalid_arg.what() << std::endl;
    }
    std::cout << "Completing the rest of the task!" << std::endl;
    return 0;
}