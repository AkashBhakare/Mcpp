#include "point.h"
#include <iostream>

mylib::Point::Point() {
	x = 1;
	y = 1;
}

mylib::Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int mylib::Point::get_x(void) const {
	return x;
}

int mylib::Point::get_y(void) const {
	return y;
}

void mylib::print_point(const Point& pref)
{
	std::cout << "X : " << pref.x << "\tY : " << pref.y << '\n';
}

mylib::Line::Line(Point&& s, Point&& e) :start(s), end(e)
{
}

void mylib::Line::draw_line(void)
{
	std::cout << "Drawing line from : " << start.get_x();
}
