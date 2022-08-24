// 97_Polymorphism_Unary_Operator_overloading_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Point.h"

void print_point(const mylib::Point& point) {
    std::cout << "\nX : " << point.get_x() << "  Y : " << point.get_y() << "\n";
}
int main()
{
    mylib::Point point1;
    print_point(point1);

    mylib::Point point2(45, 60);
    print_point(point2);

    mylib::Point point3(point2);
    print_point(point3);

    /*
     -point2;

     if the operator function is a member function
     point2.opeartor-(){}

     if the operator function is a non-member function
     opeartor-(point2){}

    */
    mylib::Point point4 = -point2;
    print_point(point4);
    print_point(point2);

    /*
        int a = 10;
        int b = a;

        b = a;
        b.operator=(a);
        operator=(b,a);

        point4 = point2;
        if the operator function is a member function
        point4.operator=(point2);

        if the operator function is a non-member function
        operator=(point4,point2);


     */
    mylib::Point point5(5, 6);
    point1 = point4 = -point5;
    print_point(point4);
    print_point(point1);
    print_point(point5);

}