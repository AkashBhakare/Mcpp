#pragma once
#include "point.h"
namespace mylib {
	class Point; // forward Declaration

	class Line
	{
	private:
		Point* point1;
		Point* point2;
	public:
		Line();
		~Line();
		Line(Point*, Point*);
		void draw_line() const;
	};

}