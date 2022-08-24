// 101_Conversion_function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "my_string.h"
#include "Conversion_function.h"


int main()
{
    //  conversion_userdefined_to_primitive();
    conversion_constructor();
}


void sqr(int n) {
    std::cout << "square of " << n << " = " << n * n << '\n';
}

void conversion_userdefined_to_primitive()
{
    mylib::MyString object1{ "1234" };
    std::cout << "s1 : " << object1.get() << '\n';

    int ans = object1; // Implicit conversion

    std::cout << "object1 * 10 = " << (ans * 10) << '\n';
    std::cout << "object1 * 10 = " << (int)object1 * 10 << '\n'; // C Style Explicit conversion
    std::cout << "object1 * 10 = " << static_cast<int>(object1) * 10 << '\n';  // C++ Style Explicit conversion

    sqr(object1); // Implicit conversion


    mylib::MyString object2{ "123.45" };
    // double dans = object2 ; // Implicit conversion not allowed for explicit conversion function
    double dans = static_cast<double>(object2); // Implicit conversion
    std::cout << "1234.45 * 10 = " << dans * 10 << '\n';
    std::cout << "10 * 1234.45 = " << 10 * (double)object2 << '\n';  // C Style Explicit conversion
    std::cout << "1234.45 * 10 = " << static_cast<double>(object2) * 10 << '\n';  // C++ Style Explicit conversion

    // Implicit conversion not allowed for explicit conversion function
    //std::cout << "Square Root of " << object2.get() << " is = " << std::sqrt(object2) << '\n'; 

    std::cout << "Square Root of " << object2.get() << " is = " << std::sqrt(static_cast<double>(object2)) << '\n';
}

void conversion_constructor() {
    A obj1;
    std::cout << "Object1 : " << obj1.get() << '\n';

    A obj2{ 90 };
    std::cout << "Object2 : " << obj2.get() << '\n';

    A obj3(50);
    std::cout << "Object3 : " << obj3.get() << '\n';

    A obj4 = 44;
    std::cout << "Object4 : " << obj4.get() << '\n';

    /*Converting constructor in action*/
    obj4 = 555;
    std::cout << "Object4 : " << obj4.get() << '\n';

    /*What's happeing under the Hood ?*/
    obj4 = A(555);
    obj4 = obj1;

    foo(obj1);

    /*44 is first converted to object of type A by converting constructor*/
    foo(44); // Converting constructor is called 
    baz(44); // Copy initialization after calling converting constructor

    //B obj5 = 44;
    B obj6{ 66 };
    B obj7(77);
    bar(obj6);
    //bar(44);
    bar(static_cast<B>(44));
    bar(B(44));
}