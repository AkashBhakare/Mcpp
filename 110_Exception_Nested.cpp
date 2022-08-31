// 110_Exception_Nested.cpp :

#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <fstream>


// prints the explanatory string of an exception. If the exception is nested,
// recurses to print the explanatory of the exception it holds

void print_exception(const std::exception& e, int level = 0) {
    std::cerr << std::string(level, ' ') << "exception: " << e.what() << '\n';
    try {
        std::rethrow_if_nested(e);
    }
    catch (const std::exception& e) {
        print_exception(e, level + 1);
    }
    catch (...) {
    }
}

// open_file function that catches an exception and wraps it in a nested exception

void open_file(const std::string& filename) {
    try {
        std::ifstream inputfile{};
        inputfile.open(filename); //fails here
        inputfile.exceptions(std::ios_base::failbit);
    }
    catch (...) {
        std::throw_with_nested(std::runtime_error("Couldn't open " + filename));
    }
}

// run function that catches an exception and wraps it in a nested exception

void run() {
    try {
        open_file("nonexistent.file");
    }
    catch (...) {
        throw_with_nested(std::runtime_error("run() failed"));
    }
}

// runs the sample function above and prints the caught exception

int main() {
    try {
        run();
    }
    catch (const std::exception& e) {
        //std::cerr << "Error handled in Main : " << e.what() << '\n';
        print_exception(e);
    }
    return 0;
}