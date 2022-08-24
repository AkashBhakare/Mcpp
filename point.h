#pragma once
#include "line.h"
#include <iostream>
namespace mylib {

	class Line; //Forward Declaration

	class Point
	{
		//Non-member frunction is declared as friend
		friend void print_point(const Point&);
		//Class Line has been declared as friend to Point
		friend class Line;
	private:
		int x;
		int y;
	public:
		Point();
		explicit Point(int x, int y);
		int get_x(void) const;
		int get_y(void) const;
	}; //End of class declaration

	//Non-Member free standing function 
	void print_point(const Point&);


	class A {
	public:
		int foo(); //define later
		int bar();
	};


	class B {
		int data = 100;
		//Member function of class A is made friend of Class B
		friend int A::foo();
	};

}
