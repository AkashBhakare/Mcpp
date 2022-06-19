// 83_Inheritance.cpp : // Basic of Multiple inheritance
// Order of invoking Ctor and Dtor

#include <iostream>
#include "multi_inherit.h"
int main()
{
    /* {
         mylib::Time time{};
         std::cout << "Size of Time class object : " << sizeof(mylib::Time) << " bytes\n";
         time.print_time();
         mylib::Calendar calander{};
         std::cout << "Size of Calander class object : " << sizeof(mylib::Calendar) << " bytes\n";
         calander.print_date();
     }*/


     /*
       Order of calling constructors for derived class object is from Base to Derived.
       When we have multiple base classes the order of invoking constructors of base class
       is same as order of inheritance

       Order of calling destructors for derived class object is from  Derived.to Base
       When we have multiple base classes the order of invoking destructors of base class
       is the reverse of order of inheritance
     */

    {
        mylib::ClockWithDate aclock{};  //Derived class object without parameters
        std::cout << "Size of Clock class object : " << sizeof(mylib::ClockWithDate) << " bytes\n";
        aclock.print_date(); //invoking the method inherited from base class Calender
        aclock.print_time(); //invoking the method inherited from base class Time
    }


    /*{
        mylib::Time time{9,43,21};
        std::cout << "The time is\n";
        time.print_time();
        mylib::Calendar calander{29,12,2021};
        std::cout << "The Date is\n";
        calander.print_date();
    }*/

    //{
    //    mylib::ClockWithDate aclock{ 29,12,2021,9,43,21}; //Derived class object with parameters
    //   
    //    aclock.print_date();
    //    aclock.print_time();
    //}
}