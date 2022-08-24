// 106_ExceptionUnwinding.cpp :
// Demonstrating stack unwinding.
// Local objects destruction sequence

#include <cstdlib>
#include <iostream>
#include <string>


#include <stdexcept>
using std::runtime_error;

class Person
{
private:
    std::string name;
public:
    Person(std::string name)
    {
        std::cout << "Created " << name << std::endl;
        this->name = name;
    }
    ~Person()
    {
        std::cout << "Destroying :" << name << std::endl;
        name.clear();
    }
};

// function3 throws run-time error

void function3() noexcept(false) {
    Person p("f3");
    std::cout << "In function 3" << std::endl;
    //    no try block, stack unwinding occur, return control to function2
    throw runtime_error("runtime_error in function3");
    std::cout << "Rest of he statements in function3\n";
} // end function3

// function2 invokes function3

void function2() noexcept(false) {
    Person p("f2");
    std::cout << "function3 is called inside function2" << std::endl;
    function3();
    // stack unwinding occur, return control to function1
    std::cout << "Rest of the statements in function2\n";
} // end function2

// function1 invokes function2

void function1() noexcept(false) {
    Person p("f1");
    std::cout << "function2 is called inside function1" << std::endl;
    function2();
    // stack unwinding occur, return control to main
    std::cout << "Rest of he statements in function1\n";
} // end function1

// demonstrate stack unwinding

int main() {
    // invoke function1
    try {
        //local objects
        Person p1("Geeta");
        Person p2("Sunita");
        Person* ptr = new Person("Raja"); //Free store : Heap
        std::cout << "function1 is called inside main" << std::endl;
        // call function1 which throws runtime_error
        function1();
        std::cout << "Rest of the instructions in main";
        std::cout << "This would skip if exception has occurred earlier" << std::endl;
        delete ptr; //may possibly never be reached : memory leak
    }// end try
    catch (runtime_error& error) // handle run-time error
    {
        std::cout << "Exception occurred: " << error.what() << std::endl;
        std::cout << "Exception handled in main" << std::endl;
    } // end catch
    std::cout << "Instruction after catch\n";
    return 0;
} // end main
