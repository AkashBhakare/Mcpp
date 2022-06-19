#pragma once

namespace mylib {

	class Time
	{
	private:
		int hour{ 10 };
		int minute{ 15 };
		int second{ 27 };
	public:
		Time();
		Time(int hour, int minute, int second);
		~Time();
		/*
		* Yet to be implemented
		*/
		void print_time();
	};


	class Calendar {
	private:
		int day{ 1 };
		int month{ 1 };
		int year{ 2022 };
	public:
		Calendar();
		Calendar(int day, int month, int year);
		~Calendar();
		/*
		*/
		void print_date();
	};


	class ClockWithDate : public Time, public Calendar {
	public:
		ClockWithDate();
		ClockWithDate(int day, int month, int year, int hour, int minute, int second);
		~ClockWithDate();
	};
}
