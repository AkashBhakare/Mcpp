#include "multi_inherit.h"
#include <iostream>
#include <iomanip>
namespace mylib {

	mylib::Time::Time()
	{
		std::cout << "Time Ctor called\n";
	}

	mylib::Time::Time(int hour, int minute, int second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	mylib::Time::~Time()
	{
		std::cout << "Time Dtor called\n";
	}

	void mylib::Time::print_time()
	{
		std::cout << std::setw(9) << std::left << "Hour" << ":" << std::setw(3) << hour
			<< std::setw(9) << std::left << "Minute" << ":" << std::setw(3) << minute
			<< std::setw(9) << std::left << "Second" << ":" << std::setw(3) << second << "\n";
	}



	mylib::Calendar::Calendar()
	{
		std::cout << "Calander Ctor called\n";
	}

	mylib::Calendar::Calendar(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}


	mylib::Calendar::~Calendar()
	{
		std::cout << "Calander Dtor called\n";
	}

	void mylib::Calendar::print_date()
	{
		std::cout << std::setw(9) << std::left << "Day" << ":" << std::setw(3) << day
			<< std::setw(9) << std::left << "Month" << ":" << std::setw(3) << month
			<< std::setw(9) << std::left << "Year" << ":" << std::setw(3) << year << "\n";
	}

	mylib::ClockWithDate::~ClockWithDate()
	{
		std::cout << "Clock Destroyed\n";
	}

	mylib::ClockWithDate::ClockWithDate()
	{
		std::cout << "Clock Created\n";
	}

	mylib::ClockWithDate::ClockWithDate(int day, int month, int year, int hour, int minute, int second) :
		Calendar(day, month, year), Time(hour, minute, second)  //Base class initializer list
	{
		/*this->day = day;
		this->month = month;
		this->year = year;*/ // Error 
	}
}