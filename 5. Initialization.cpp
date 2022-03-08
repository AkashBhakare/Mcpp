// 5. Initialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void basic() {
    int x; //Defined a variable
    x = 99; //Assignment
    std::cout << "x : " << x << std::endl;
    
    /*Storing a value into a variable at the toime of creation of variable
    Initialization can happen only once*/
    int y = 66; // Defining & initializing
    std::cout << "y : " << y << std::endl;
}

void initialization_basics()
{
    //narrowing implicit conversion resulting in loss of data
    long aadhar_card = 1234567890123;  //2147483647
    /* if we compile this code in 32bit platform it would generate
    warning and will also result in narrowing conversion with
    loss of data*/
    std::cout << "Aadhar Card Numer :" << aadhar_card << std::endl;
    std::cout << "Size of long : " << sizeof(aadhar_card) << " bytes" << std::endl;

    long other_aadhar_card(1234567890123);
    std::cout << "Other Aadhar Card Number :" << aadhar_card << std::endl;

    //Values in braces cannot be narrowed :
  /*  long new_aadhar_card{ 1234567890123 };
    std::cout << "New Aadhar Card Number :" << new_aadhar_card << std::endl;*/


    /*The compiler’s narrowing protection allows us to verify that
    values do not lose precision in initializations.
    Whereas an ordinary initialization of an int by a
    floating - point number is allowed due to implicit conversion*/
    int in1 = 3.14; // compiles despite narrowing (our risk)
    std::cout << "in1 : " << in1 << std::endl;

   // int in2 { 3.14 }; // Narrowing ERROR: fractional part lost

     /*Assigning negative values to unsigned variables or constants
     is tolerated with traditional initialization but denounced
     in the new form:*/
    unsigned uin1 = -5; // Compiles despite narrowing (our risk)
    std::cout << "uin1 : " << uin1 << std::endl;

   // unsigned uin2 { -3 }; // Narrowing ERROR: no negative values
    unsigned uin3 = { 3 }; // Okay
    std::cout << "uin3 : " << uin3 << std::endl;

    /* When a float is initialized from a double variable or
    constant(not a literal), we have to consider all possible
    double values and whether they are all convertible to float
    in a loss - free manner.*/
    float f1 = 3.14; // okay
    std::cout << "f1 : " << f1 << std::endl;

    double d = 3.14;
    std::cout << "d : " << d << std::endl;
    f1 = d + 1;
    std::cout << "f1 : " << f1 << std::endl;

    //float f2  { d };
    //1.7976931348623158e+308 
    float f3 = LDBL_MAX;    //allowed with narrowing conversion
    std::cout << "LDBL_MAX : " << LDBL_MAX << "\tf3 :" << f3 << std::endl;
    //conversion from 'double' to 'float' requires a narrowing conversion
    /*float f4 { LDBL_MAX };
    float f5{ 1.7976931348623158e+308 };*/

    /*The types signed intand unsigned int have the same size,
    but not all values of each type are representable in the other*/
    unsigned u3{ 3 };    //Okay
    signed int i2{ 2 };  //okay
    int i3{ 2 };
    // narrowing ERROR: no negative values
    /*unsigned u4 { i2 };
    unsigned u5{ i3 };

    int i4 { u3 };      */ // narrowing ERROR: not all large values
}


void default_values_of_builtin_type() {
    char        c{}; // c = 0
    std::cout << "char : " << c << std::endl;
    int         i{}; // i = 0
    std::cout << "int : " << i << std::endl;
    float       f{}; // f = 0.0f
    std::cout << "float : " << f << std::endl;
    double      d{}; // d = 0.0
    std::cout << "double : " << d << std::endl;
    bool        b{}; // b = false
    std::cout << "bool : " << std::boolalpha << b << std::endl;
    std::string s{}; // s = ""
    std::cout << "string : " << s << std::endl;
    int* p{}; // p = nullptr
    std::cout << "pointer : " << p << std::endl;
}


void init_with_specific_values()
{
    char        c{ 'x' };   // c = 'x'
    std::cout << "char : " << c << std::endl;

    int         i{ 99 };    // i = 99
    std::cout << "int : " << i << std::endl;

    float       f{ 3.14f }; // f = 3.14f
    std::cout << "float : " << f << std::endl;

    double      d{ 1.23 };  // d = 1.23
    std::cout << "double : " << d << std::endl;

    bool        b{ true };  // b = true
    std::cout << "bool : " << std::boolalpha << b << std::endl;

    std::string s{ "cat" }; // s = "cat"
    std::cout << "string : " << s << std::endl;

    int* p{ &i };    // p = &i
    std::cout << "pointer : " << p << std::endl;


    return;
}


void  confusing_declarations() {
    int i1n = (int)0; // same as i4n
    std::cout << "i1n : " << i1n << std::endl;
    int i2n = 2;
    std::cout << "i2n : " << i2n << std::endl;
    int i3n(3);
    std::cout << "i3n : " << i3n << std::endl;
    int i4n = int();        // No-Arg Default constructor
    std::cout << "i4n : " << i4n << std::endl;
    int i5n = int(5);       // Parameterized constructor
    std::cout << "i5n : " << i5n << std::endl;
    
    int i6n{ 5 };  //most recommended - non narrowing or uniform
    std::cout << "i6n : " << i6n << std::endl;
    return;
}

int main()
{
    //basic();
    //initialization_basics();
    // default_values_of_builtin_type();
    init_with_specific_values();
    //confusing_declarations();
}
