// 96_Friend_Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "point.h"
#include "line.h"
int main()
{
    mylib::Point p1(12, 3);
    std::cout << "X : " << p1.get_x() << "\tY : " << p1.get_y() << '\n';
    mylib::print_point(p1);

    mylib::Line line1;
    line1.draw_line();
    mylib::Line line2(new mylib::Point(23, 40), new mylib::Point(50, 50));
    line2.draw_line();

    mylib::A aobj;
    aobj.foo();
}