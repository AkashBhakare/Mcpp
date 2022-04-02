// 39_Reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void reference_basics() {
    int rollno;
    int* iptr;
    //int& ref; //'ref': reference must be initialized

    rollno = 77;
    iptr = &rollno;
    std::cout << "Using variable name : " << rollno << '\n';
    //std::cout << "Using reference : "     <<  ref    << '\n';
    rollno = 66;
    std::cout << "After updating the variable\n";
    std::cout << "Using variable name : " << rollno << '\n';
    //std::cout << "Using reference : " << ref << '\n';

    rollno = 66;
    std::cout << "After updating the variable\n";
    std::cout << "Using variable name : " << rollno << '\n';
    //std::cout << "Using reference : " << ref << '\n';

    std::cout << "Address of variable : " << &rollno << '\n';
    //std::cout << "Address of reference : " << &ref << '\n';

    /*A pointer to integer can store address of any integer variable*/
    iptr = &rollno;
    std::cout << "Using pointer pointing to rollno : " << *iptr << '\n';
    int length = 89;

    /*A pointer can point to different variable at different times the address stored in the pointer can change*/
    iptr = &length;
    std::cout << "Using pointer pointing to length : " << *iptr << '\n';
    /*Reference cannot be modified in they cannot refer to different variable
    reference variable refer to the same variable through out*/
    //&ref = length; //expression must be a modifiable lvalue
}

void swap_using_pointer(int* iptr1, int* iptr2) {
    int temp{};
    temp = *iptr1;
    *iptr1 = *iptr2;
    *iptr2 = temp;
    std::cout << "Calling routine => var1: " << *iptr1 << ", var2:" << *iptr2 << '\n';
    return;

}

void call_by_reference() {
    int var1{ 10 };
    int var2{ 20 };
    std::cout << "Calling routine => var1: " << var1 << ", var2:" << var2 << '\n';
    swap_using_pointer(&var1, &var2);
    std::cout << "Calling routine => var1: " << var1 << ", var2:" << var2 << '\n';


    var1 = 10;
    var2 = 20;
    std::cout << "Calling routine => var1: " << var1 << ", var2:" << var2 << '\n';
    swap_using_pointer(&var1, &var2);
    std::cout << "Calling routine => var1: " << var1 << ", var2:" << var2 << '\n';


}

void extern_reference_demo() {
    //std::cout << "Reference decalred extern : " << gref << '\n';
}

void function_returning_refrence_to_local_variable() {
    int local_variable{ 55 };
    local_variable++;
    return local_variable;
}

int main()
{
    //reference_basics();
    //call_by_reference();
    //extern_reference_demo();
    function_returning_refrence_to_local_variable();
}
