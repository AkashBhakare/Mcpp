// 105_Ex2BadAlloc.cpp : 

// Demonstrating standard new throwing 
// bad_alloc when memory cannot be allocated.
#include <iostream>
#include <new> // standard operator new

void useTheBlockOfMemory(double*);

void bad_alloc_demo();
void bad_array_length_demo();

int main() {
    bad_alloc_demo();
    bad_array_length_demo();
    return 0;
} // end main

void bad_alloc_demo() {
    /*Array of 100 pointer to double*/
    double* array_ptr[100];
    try {
        for (int i = 0; i < 100; i++) {
            array_ptr[i] = new double[50000000];
            std::cout << "Allocated 50000000 doubles in ptr[ " << i << " ]\n";
            useTheBlockOfMemory(array_ptr[i]);
        } // end for
    }// end try
    catch (const std::bad_alloc& memoryAllocationException) {
        std::cout << "Exception occurred: "
            << memoryAllocationException.what() << std::endl;
        std::cout << "Insufficient memory!\n";
    } // end catch

}

void bad_array_length_demo() {
    double* array_ptr = nullptr;
    std::cout << "Continue with the rest of processing!\n";
    int size;
    std::cout << "Please enter the size of the array :";

    try {
        std::cin >> size;
        array_ptr = new double[size];
        std::cout << "Allocated " << size << " doubles array\n";
        useTheBlockOfMemory(array_ptr);

    }
    catch (const std::bad_array_new_length& ref_bad_length) {
        std::cout << "Exception occurred: "
            << ref_bad_length.what() << std::endl;

    }
    catch (const std::bad_alloc& memoryAllocationException) {
        std::cout << "Exception occurred: "
            << memoryAllocationException.what() << std::endl;
        std::cout << "Insufficient memory!\n";
    }
}

void useTheBlockOfMemory(double* p) {
    std::cout << "Used the memory for the operations\n";
    return;
}