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

/*Definition of Non-Member function*/
void mylib::print_point(const Point& pref)
{
	std::cout << "X : " << pref.x << "\tY : " << pref.y << '\n';
}

int mylib::A::foo()
{
	B bobj;
	std::cout << "B::data : " << bobj.data << "\n";
	return 0;
}

int mylib::A::bar()
{
	B bobj;
	//std::cout << "B::data : " << bobj.data << "\n";
	return 0;
}