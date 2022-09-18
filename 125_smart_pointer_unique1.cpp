// 125_smart_pointer_unique1.cpp :

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>


struct Resource {
    int array[1000];

    Resource() {
        std::cout << "Resource is created\n";
    }

    ~Resource() {
        std::cout << "Resource is destroyed\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Resource& obj) {
        os << "Operating on Resource";
        return os;
    }

};

void foo() noexcept(false) {
    Resource* ptr = new Resource();
    //Some operations
    std::cout << *ptr << std::endl;

    bool exceptional_condition{ true };
    if (exceptional_condition) {
        throw  std::logic_error("Logic error occurred bcoz...");
    }
    delete ptr;
    return;
}

void bar()  noexcept(false) {
    // create an object explicitly using Raw Pointer
    Resource* ptr = nullptr;
    try {
        ptr = new Resource();
        // perform some operations
        std::cout << *ptr << std::endl;
        bool exceptional_condition{ false };

        if (exceptional_condition) {
            throw  std::logic_error("Logic error occurred bcoz...");
        }
        delete ptr; // this will come in action if no exception is raised
    }
    catch (...) {
        delete ptr; // - clean up when exception is raised
        throw; // - rethrow the exception
    }
    std::cout << "Continue with rest of the operation on bar" << std::endl;

}

void baz() {
    try {
        // create and initialize an unique_ptr
        std::unique_ptr<Resource> ptr{ new Resource() };
        // perform some operations
        std::cout << *ptr << std::endl;

        bool exceptional_condition{ true };

        if (exceptional_condition) {
            throw  std::logic_error("Logic error occurred bcoz...");
        }
    }
    catch (std::logic_error& e) {
        std::cout << "Baz : " << e.what() << std::endl;

    }
    std::cout << "Moving out of baz\n";
    return;
}

int main(int argc, char** argv) {
    try {
        //foo();
        //bar();
        baz();
    }
    catch (std::logic_error& e) {
        std::cerr << "Main : " << e.what() << "\n";
    }
    catch (std::exception& e) {
        std::cerr << "Main : " << e.what() << "\n";
    }

    return 0;
}
