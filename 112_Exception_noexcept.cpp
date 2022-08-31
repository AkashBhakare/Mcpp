// 112_Exception_noexcept.cpp :

#include <iostream>
#include <cstdlib>
#include "iostream"
#include <stdexcept>
#include <string>

 /*
  * noexcept
  */
#define MAX 5

  //Allowed to throw anything (anytype)
void boom(void) {
    std::cout << "Inside baz()\n";
    int status = 0;
    if (status) {
        throw std::invalid_argument("INV");
    }
    else {
        throw std::out_of_range("ofr");
    }
    return;
}

/*
 Will throw either of the type of exception
 warning C5040: dynamic exception specifications are valid only in C++14 and earlier; treating as noexcept(false)
*/
void boo(void) throw(std::invalid_argument, std::out_of_range) {
    std::cout << "Inside baz()\n";
    int status = 0;
    if (status) {
        throw std::invalid_argument("INV");
    }
    else {
        throw std::out_of_range("ofr");
    }
    return;
}

//Will not throw any exception
void baz(void) throw() {
    std::cout << "Inside baz()\n";
    return;
}

//Will not throw any exception
void zoo(void) noexcept {
    std::cout << "Inside Foo()\n";
    //  throw std::invalid_argument("invalid");
}

//Will not throw any exception
void foo(void) noexcept(true) {
    std::cout << "Inside Foo()\n";
    //    throw std::runtime_error("Some Error");
}

// Allowed to throw any kind of exception
void bar(void) noexcept(false) {
    std::cout << "Inside Bar()\n";
    throw std::runtime_error("Some runtime Error");
}

int main()
{
    //    boom();
    try
    {
        // boo();
        // baz();
        // foo();
        bar();
        // zoo();
    }
    catch (const std::runtime_error& re) {
        std::cout << re.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

