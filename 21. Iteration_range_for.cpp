// 21. Iteration_range_for.cpp : Range Based for Loop
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

void imperative_iteration() {
	std::string name{ "dhanashree" };
	for (size_t i{ 0 }; i < name.size(); ++i) {
		std::cout << name.at(i) << " = " << static_cast<char>(std::toupper(name.at(i))) << "\n";
	}
	/* for (size_t i{ 0 }; i < name.size(); ++i) {
		 std::cout <<  static_cast<char>(std::toupper(name.at(i)));
	 }*/
}


void declarative_iteration() {

	std::string name{ "dhanashree" };
	std::cout << "Iterating through String\n";
	for (char alpha : name) {
		std::cout << static_cast<char>(std::toupper(alpha));
	}
	std::cout << "\n";

	std::cout << "Iterating through Array of primitive\n";
	int score[5]{ 56,78,77,88,91 };
	for (int element : score) {
		std::cout << element << "\n";
	}

	std::cout << "Iterating through Container <vector> \n";
	std::vector<float> percentage{ 56.6f, 78.8f, 89.7f, 45.5f };
	for (float percent : percentage) {
		std::cout << percent << "\n";
	}

	/*type inference is also supported in range based for loop*/
	std::vector<double> dist{ 3.4,6.7,77.4,88.8 };
	std::cout << "Automatic type inferrence with vector<double>:\n";
	for (auto element : dist) {
		std::cout << element << "\n";
	}

	std::cout << "Automatic type inferrence with array of integer:\n";
	for (auto element : score) {
		std::cout << element << "\n";
	}

	std::cout << "Automatic type inferrence with string:\n";
	for (auto element : name) {
		std::cout << element << "\n";
	}
}

void print(std::string str) {
	std::cout << "Name : " << str << "\n";
}

void for_each_loop() {
	/*vector of string*/
	std::vector<std::string> names{ "Akash","Aryan","Nishant","Parag","Sakshi" };

	std::cout << "Using traditional for Loop : \n";
	for (size_t i{ 0 }; i < names.size(); ++i) {
		std::cout << "Name : " << names.at(i) << "\tLength : " << names.at(i).length() << "\n";
	}

	std::cout << "\nUsing Range based for Loop : \n";
	for (auto name: names) {
		std::cout << "Name : " << name << "\tLength : " << name.length() << "\n";
	}

	std::cout << "\nUsing  for_each Loop  : \n";
	std::for_each(names.begin(), names.end(), print);


	std::cout << "\nUsing  for_each with Lambda expression: \n";
	std::for_each(names.begin(), names.end(), [](std::string str) {std::cout << "Name : " << str << "\n"; });

	std::cout << "\nUsing  for_each with Lambda varaible: \n";
	auto consumer{ [](std::string str) {std::cout << "Name : " << str << "\n"; } };
	std::for_each(names.begin(), names.end(), consumer);

	std::cout << "Iterating through Array of primitive using for_each\n";
	int score[5]{ 56,78,77,88,91 };
	//std::for_each(score.begin(), score.end(), [](int mark) {});

	std::for_each(std::begin(score), std::end(score), [](int mark) {std::cout << (mark + 5) <<"\n"; });

	/*Using for_each for reverese traversal*/
	std::cout << "Iterating through Array of primitive using for_each in reverse order\n";
	int values[5]{10, 20,30,40,50};
	std::for_each(std::rbegin(values), std::rend(values), [](int data) {std::cout << data << "\n"; });
}

int main()
{
	//  imperative_iteration();
	//  declarative_iteration();
	for_each_loop();
}

