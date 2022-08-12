#pragma once
#include "line.h"
namespace mylib {

	class Line; //Foward declaration 

	class Point
	{
		//Non-member frunction is declared as friend
		friend void print_point(const Point&);
		//Member function declared as friend
		//friend void Line::draw_line(void);
	private:
		int x;
		int y;
	public:
		Point();
		Point(int x, int y);
		int get_x(void) const;
		int get_y(void) const;
	};

	//Non-Member free standing function 
	void print_point(const Point&);

	class Line
	{
	private:
		Point& start;
		Point& end;

	public:
		Line(Point&& start, Point&& end);
		void draw_line(void);
	};
}
