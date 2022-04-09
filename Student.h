#pragma once
#include <string>
/*All members of a Structure are implicitely public*/
struct Student
{
	size_t roll_number;
	std::string name;
	float percentage;

	/*Returns the roll number of the student*/
	size_t get_roll_number();

	/*returns the Percentage marks secured by the student*/
	float get_percentage();

	/*Returns the name of the student*/
	std::string get_name();

};
