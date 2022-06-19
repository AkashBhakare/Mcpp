// 76_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cstdlib>
#include "iostream"
using namespace std;

/*
 *  All the datamembers of the superclass are inherited in the subclass irrespective of the access spcifiers for inheritance
 */
class Parent {
    int a;
}; //end of base class

class Child : protected  Parent {
    int b;
}; //end of derived class

//class derived from derived class

class GrandChild : protected Child {
    int c;
};

void size_of_class() {
    std::cout << "Parent class object size      : " << sizeof(Parent) << " bytes" << std::endl;
    std::cout << "Child class object size       : " << sizeof(Child) << " bytes" << std::endl;
    std::cout << "GrandChild class object size  : " << sizeof(GrandChild) << " bytes" << std::endl;
}


/*Role of access specifiers for inheritance*/

class Base {
private:
    int a{ 1 };
protected:
    int b{ 2 };
public:
    int c{ 3 };

    void get_private_member() {
        std::cout << "Private member a :" << a << "\n";
    }
};


class Derived : public Base {
private:
    int i{ 10 };
protected:
    int j{ 20 };
public:
    int k{ 30 };
    void access_attributes_in_member_function() {
        //Inherited Members inherited from Base class      
     //   std::cout << a << "\n";
        std::cout << "b : " << b << "\n";
        std::cout << "c : " << c << "\n";
        get_private_member();
        //Members defined in the Derived class
        std::cout << "i : " << i << "\n";
        std::cout << "j : " << j << "\n";
        std::cout << "k : " << k << "\n";
    }


};
//
//class Sub_derived :public Derived {
//    void foo() {
//        get_private_member();
//        std::cout << b << "\n";
//        std::cout << c << "\n";
//
//       // std::cout << i << "\n";
//        std::cout << j << "\n";
//        std::cout << k << "\n";
//    }
//};

void access_attributes_in_non_member_function() {
    Derived derived;
    //  std::cout << derived.a << "\n";
    //  std::cout << derived.b << "\n";*
    std::cout << derived.c << "\n";
    //   std::cout << derived.j << "\n";
    std::cout << derived.k << "\n";
    derived.get_private_member();

    derived.access_attributes_in_member_function();
}

void role_of_access_specifier_for_inheritance() {
    std::cout << "Size of Base      : " << sizeof(Base) << " byte\n";
    std::cout << "Size of Derived   : " << sizeof(Derived) << " byte\n";
    Derived d;
    d.access_attributes_in_member_function();
    //  access_attributes_in_non_member_function();

}



class Super {
public:
    Super() {
        std::cout << "Super default Ctor\n";
    }
    Super(std::string data) {
        std::cout << "Super parameterized Ctor\n";
    }
    ~Super() {
        std::cout << "Super Dtor\n";
    }
};

class Sub :public Super {
public:
    Sub() {
        std::cout << "Sub default Ctor\n";
    }

    Sub(std::string value) :Super(value) {
        std::cout << "Sub parameterized Ctor\n";
    }
    ~Sub() {
        std::cout << "Sub Dtor\n";

    }
};

void  invoking_ctor_dtor() {
    // Sub subclass_object;
    Sub another_obect("Other");
}

//non member function
int main(void) {
    // size_of_class();
   // role_of_access_specifier_for_inheritance();
    invoking_ctor_dtor();

    return 0;
}