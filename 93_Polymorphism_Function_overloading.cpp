// 93_Polymorphism_Function_overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "operation.h"
void print(int data);
void print(const int data);
void print(double data);
void print(const char* data);
void print(std::string);
void print(int array[], size_t array_size);
//void print(int * array, size_t array_size);
void print(size_t array_size, int array[]);

using namespace std::string_literals;
int main()
{
    int data = 55;
    print(data);
    print(10);
    print(12.34);
    print("Hello");
    print("Bye"s);

    int arr[] = { 1,3,5,6,7,9 };
    print(arr, 6);
    print(6, arr);

    std::cout << "Adding 2 integers : " << my_lib::Operation::add(12, 45) << '\n';
    my_lib::Operation object{};
    object.add(12, 45);
    std::cout << "Adding 3 integers : " << my_lib::Operation::add(12, 45, 10) << '\n';
    std::cout << "Adding 2 double   : " << my_lib::Operation::add(1.2F, 4.5F) << '\n';

    my_lib::Operation const c_object;
    c_object.dotask();

    my_lib::Operation nc_object;
    nc_object.dotask();
    return 0;
}

/* differs in the type of paramenter*/
void print(int data) {
    std::cout << "Printing integer : " << data << '\n';
}

//void print(const int data) {
//    std::cout << "Printing integer : " << data << '\n';
//}
//
//void print(volatile int data) {
//    std::cout << "Printing integer : " << data << '\n';
//}

void print(double data) {
    std::cout << "Printing double : " << data << '\n';
}

void print(const char* data) {
    std::cout << "Printing char * : " << data << '\n';
}

void print(std::string data) {
    std::cout << "Printing string literal : " << data << '\n';
}

/* differ in the order of paramenter type*/
void print(int array[], size_t array_size) {
    std::cout << "Printing Array -I: " << '\n';
    for (int idx = 0; idx < array_size; idx++) {
        std::cout << array[idx] << ',';
    }
    std::cout << '\n';
}

//void print(int* array, size_t array_size)
//{
//    std::cout << "Printing Array -I: " << '\n';
//    for (int idx = 0; idx < array_size; idx++) {
//        std::cout << *(array+idx) << ',';
//    }
//    std::cout << '\n';
//}

void print(size_t array_size, int  array[]) {
    std::cout << "Printing Array -II " << '\n';
    for (size_t idx = 0; idx < array_size; idx++) {
        std::cout << array[idx] << ", ";
    }
    std::cout << '\n';
}