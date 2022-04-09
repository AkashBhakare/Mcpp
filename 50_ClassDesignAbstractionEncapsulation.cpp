// 50_ClassDesignAbstractionEncapsulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Student.h"
#include "Player.h"
using namespace std::literals;

void problem_with_ignoring_abstraction() {
	Student s1{ 10,"Radha"s,77.56F };
	std::cout << "Name        : " << s1.get_name() << '\n';
	std::cout << "Roll Number : " << s1.get_roll_number() << '\n';
	std::cout << "Percentage  : " << s1.get_percentage() << '\n';

	/*direct access may result into curruption of data*/
	s1.name = "!@#$^565";
	s1.roll_number = 100000001;
	s1.percentage = -56.56F;

	std::cout << "Name        : " << s1.name << '\n';
	std::cout << "Roll Number : " << s1.roll_number << '\n';
	std::cout << "Percentage  : " << s1.percentage << '\n';

}

void abstraction_encapsulation() {
	//Player p{ "Firoz"s,2019,21 };
	Player p1;
	/* All class Members are implicitely private;
	thus they cannot be accessed in a non-member function*/
	/*
	std::cout << "Name          : " << p1.name << '\n';
	std::cout << "Year of debut : " << p1.debut << '\n';
	std::cout << "Age           : " << p1.age << '\n';
	*/

	std::cout << "Name          : " << p1.get_name() << '\n';
	std::cout << "Year of debut : " << p1.get_year_of_debut() << '\n';
	std::cout << "Age           : " << p1.get_age() << '\n';

	p1.set_age(21);
	p1.set_name("Sunny"s);
	p1.set_year_of_debut(1994);

	std::cout << "Name          : " << p1.get_name() << '\n';
	std::cout << "Year of debut : " << p1.get_year_of_debut() << '\n';
	std::cout << "Age           : " << p1.get_age() << '\n';

	p1.set_age(31);
	p1.set_name("Jay"s);
	p1.set_year_of_debut(2020);

	std::cout << "Name          : " << p1.get_name() << '\n';
	std::cout << "Year of debut : " << p1.get_year_of_debut() << '\n';
	std::cout << "Age           : " << p1.get_age() << '\n';

}

int main()
{
	//problem_with_ignoring_abstraction();
	abstraction_encapsulation();
}