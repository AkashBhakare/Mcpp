// 95_Friend_Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "point.h"
int main()
{
    mylib::Point p1(12, 3);
    std::cout << "X : " << p1.get_x() << "\tY : " << p1.get_y() << '\n';
    mylib::print_point(p1);
    mylib::Line line1(mylib::Point(12, 4), mylib::Point(50, 50));
    line1.draw_line();
}