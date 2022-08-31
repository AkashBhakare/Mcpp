// 111_ExceptionHandlingStregy.cpp :

#include <cstdlib>
#include <iostream>
#include <exception>
#include <climits>
#include <limits>
#include <limits>
#define MAXTIMES 3
int getInt(void) noexcept(false); //May throw
long long int getSquare(int) noexcept(true); //Will not throw
int getInteger() noexcept(true);
void propogate_to_caller();
void handle_locally();
void myhandler(void);

int main() {
    std::terminate_handler original = std::set_terminate(myhandler);
    //    propogate_to_caller();
    handle_locally();
    std::set_terminate(original);
    return EXIT_SUCCESS;
}

void propogate_to_caller() {
    std::cin.exceptions(std::ios::failbit);
    int attempt = MAXTIMES;
    int value;
    do {
        try {
            value = getInt();
            std::cout << "You Entered " << value;
            std::cout << " & it's Square = " << getSquare(value) << "\n";
            break;
        }
        catch (const std::ios::failure& ref) {
            //std::cout << "Input Stream State " << std::cin.rdstate() << std::endl;
            std::cout << "\tPlease enter only integer in digits with or without leading sign (+-)!\n" << std::endl;
            std::cin.clear(); //clears the error state flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the faulty line
            --attempt;
            std::cout << "\tYou are left with " << attempt << " chances.\n" << std::endl;

        }
    } while (attempt != 0);
    std::cout << "That's all !\n";
}
void handle_locally() {
    int attempt = MAXTIMES;
    int value;
    value = getInteger();
    std::cout << "You Entered " << value;
    std::cout << " & it's Square = " << getSquare(value) << "\n";
    std::cout << "That's all !\n";
}
int getInt() noexcept(false) {
    std::cin.exceptions(std::ios::failbit);
    int value{};
    std::cout << "Please enter a integer: ";
    std::cin >> value; /*Propogating the exception to caller*/
    return value;
}
long long int getSquare(int val) noexcept (true) {
    return (long long)val * val;
}
int getInteger() noexcept(true) {
    std::cin.exceptions(std::ios::failbit);
    int value;
    while (true) {
        std::cout << "Please enter a integer: ";
        try {
            std::cin >> value;
            return value;
        }
        catch (const std::ios::failure& ref) {
            std::cout << "Invalid input entered! Enter only digits\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void myhandler(void) {
    std::cerr << "Some unexpected error has been encountered!\n";
    exit(EXIT_FAILURE);
}