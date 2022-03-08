// 2.Variables_Data_types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
void valid_identifiers() {
    //Identifier should be meaningful
    int m;      // poor 
    int age;    // Good

    //First letter of an identifier must be alphabetic character or a underscore or Dollor
    //int 1unit;  // Error
    int unit1; //OK
    int _unit1; //ok

    //Embedded spaces are not allowed.
    //int product rate; //Error
    int product_rate;
    int productRate;

    //Must be composed of alphabetic characters, or digits or underscores or $.
    //int interest%;
    //int interest-rate;
    //int domain@in;
    //[A-Z][a-z][0-9]$
    int $rate;
    int product1;

    //Identifier should not be same as that of any keyword
    /*int asm;
    int case;*/

    int case_no;

    //‘Cpp ‘ is case sensitive
    int limit{ 3 };
    int Limit{ 4 };
    int LIMIT{ 5 };

    return;
}

/*Function returning nothing and not requiring any parameter*/
void void_type(void) {
    
    //void var; //It is an incomplete type;type with an empty set of values.

    int age;
    int* ptr_i = &age;

    //Generic pointer
    void* ptr;
    ptr = &age;
    char grade;
    ptr = &grade;
    float per;
    ptr = &per;
    
    //ptr_i = &per;

    void (*fp)(void) = valid_identifiers;
    return;
}



void foo(int * p) {
    std::cout << "foo(int*)\n";
}

void foo(double* p) {
    std::cout << "foo(double*)\n";
}

void foo(std::nullptr_t p) {
    std::cout << "foo(nullptr_t)\n";
}

/*
* nullptr_t:
*   size : equal to size of native pointer
*   introducted in C11
*   it is not a pointer
*   it's value is null pointer ( nullptr )
* 
*/
void null_ptr_type_demo() {
    //Dangling pointers
    int* ptr_i;
    char* ptr_c;

    float* ptr_f = NULL; //poor

    double* ptr_d = nullptr; //Good ;  nullptr is a literal of type std::nullptr_t
    std::nullptr_t nothing{};
    std::cout << "Size of nullptr_t type variable " << sizeof(nothing) << " bytes\n";
    int* ptr_ii = nothing;

    int a{ 10 };
    ptr_i = &a;
    foo(ptr_i);

    double d{ 0.0 };
    ptr_d = &d;
    foo(ptr_d);

   //foo(0);
   // foo(NULL);

    foo(nullptr);

    //ptr_c = nullptr;
    //foo(ptr_c);
}

int main()
{
    //valid_identifiers();
    //void_type();
    null_ptr_type_demo();

    return EXIT_SUCCESS;
}
