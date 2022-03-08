// 23. Iteration_nested.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>

/* find the factorial of all numbers in range of n1..n2 */
void find_factorial(int start, int end) {

    std::cout << "Factorial of integers in the range of " << start << " to " << end << " : \n";
    do {
        long double facto{ 1 };
        for (int i{ 2 }; i <= start; ++i) {
            facto = facto * i;
        }
        std::cout << "Factorial of " << start << " is " << facto << "\n";
        ++start;
    } while (start <= end);
}


/* find the factorial of all numbers in range of n1..n2 */
void find_factorial_improved(int start, int end) {

    std::cout << "\nFactorial of integers in the range of " << start << " to " << end << " : \n";
    long double facto{ 1 };
    
    for (int i{ 2 }; i <= start; ++i) {
        facto = facto * i;
    }
    do {
        std::cout << "Factorial of " << start << " is " << facto << "\n";
        facto = facto * ++start;
    } while (start <= end);
}

/*accept a number and diplay sum of its digits continue till the user wishes*/
void sum_of_digits() {
    char choice;
    do {
        std::cout << "Please enter a integer  : ";
        int number;
        std::cin >> number;
        int digit_sum{ 0 };
        while (number != 0) {
            int digit = number % 10;
            number = number / 10;
            digit_sum += digit;
        }
        std::cout << "The Sum of digits is  : " << digit_sum << "\n";
        std::cout << "Do you want ot continue ?\n";
        std::cout << "Press 'q' / 'Q' to Quit or Press enter key to continue : ";
        /*Ignores max 10 characters fron input stream or till \n is encountered*/
        std::cin.ignore(10,'\n');
        /*std::noskipws :  does not skip whitespace characters during input*/
        std::cin >> std::noskipws >> choice;
        std::cin >> std::skipws;
        std::cin.ignore(10, '\n');
    } while (std::toupper(choice) != 'Q');
}

/*
Accept number of rows and print 'n' rows from the following series

rows = 4
O/P :
        1
        1 2
        1 2 3
        1 2 3 4

*/

void pattern1() {
    int total_rows{};
    std::cout << "How many rows do you want to print ? ";
    std::cin >> total_rows;
    for (int rows{ 1 }; rows <= total_rows; ++rows) {
        for (int cols{ 1 }; cols <= rows; ++cols) {
            std::cout << " " << cols;
        }
        std::cout << std::endl;
    }

}


/*
Accept number of rows and print 'n' rows from the following series

rows = 4
O/P :
        4 3 2 1
        4 3 2
        4 3
        4

*/

void pattern2() {
    int total_rows{};
    std::cout << "How many rows do you want to print ? ";
    std::cin >> total_rows;
    for (int rows{ 1 }; rows <= total_rows; ++rows) {
        std::cout << std::endl;
        for (int cols{ total_rows }; cols >= rows; --cols) {
            std::cout << " " << cols;
        }
    }
    std::cout << std::endl;
}

int main()
{
    find_factorial(5, 9);
    find_factorial_improved(5, 9);
    sum_of_digits();

    pattern1();
    pattern2();


}
