// 117_ExceptionRethrow.cpp : 
#include <iostream>
#include "header.h"
#include "error_handler.h"
int main()
{
    {
        std::exception_ptr eptr;
        try {
            /*           A a;
                       a.foo();*/
            B b;
            b.baz();
        }
        catch (...) {
            //        captures the current exception object and creates an 
            //        std::exception_ptr that holds either a copy or a reference 
            //        to that exception object
            eptr = std::current_exception(); // capture
        }
        ErrorState error = handle_exception(eptr);
        std::cout << "Error Code : " << static_cast<int>(error) << std::endl;
    } // destructor for std::out_of_range called here, when the eptr is destructed
}

