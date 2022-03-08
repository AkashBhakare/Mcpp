// 25. Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <valarray>
#include <cmath>
#include <numbers>
/*
data_type <array_name>[<size>]
*/
void defining_array() {
	/*Group of 5 varaibles of type integer*/
	int marks[5];

	std::cout << "Intitial contents of the array : \n";
	for (int index{ 0 }; index < 5; ++index) {
		std::cout << "Marks : " << marks[index] << "\n";
	}

	// assigning values to array
	marks[0] = 99;
	marks[1] = 89;
	marks[2] = 79;
	marks[3] = 69;
	marks[4] = 59;
	//marks[4]{ 59 };

	std::cout << "Contents of the array after assignment: \n";
	for (int element : marks) {
		std::cout << "Marks : " << element << "\n";
	}
}

void array_size() {

	char grades[5]; //syntatically correct but not appropriate

	constexpr int number_of_subjects{ 5 };
	char grade[number_of_subjects];
	std::cout << "Size of character array : " << sizeof(grade) << " bytes\n";

	double distances[10];
	std::cout << "Size of double array : " << sizeof(distances) << " bytes\n";
	std::cout << "Number of elements in the array : " << sizeof(distances) / sizeof(distances[0]) << "\n";


	size_t number_of_distances = sizeof(distances) / sizeof(distances[0]);
	for (size_t index{ 0 }; index < number_of_distances; ++index) {
		std::cout << "distance : " << distances[index] << "\n";
	}



}


void array_initialization() {
	/*We cannot define array without specifying size
	char vowels[];
	*/

	char vowels[5]{ 'a','e','i','o','u' };
	std::cout << "The characters in the array are as follows : \n";
	for (char vowel : vowels) {
		std::cout << "\t" << vowel << "\n";
	}

	/*Number of initializers determine the size of the array*/
	char consonants[]{ 'q','w','r','t','y','p' };
	std::cout << "The consonants  in the array are as follows : \n";
	for (char consonant : consonants) {
		std::cout << "\t" << consonant << "\n";
	}

	int marks[]{ 34,45,44,47,50 };
	std::cout << "The marks are as follows : \n";
	for (int mark : marks) {
		std::cout << "\t" << mark << "\n";
	}
	//total size of array must not exceed 0x7fffffff bytes	
	//double big_array[1000000000LL]{};
	std::cout << 0x7fffffff;

}

/*We can overcome the limitiation of need to specify the array size at compile time by allocating
memory for array at runtime on heap*/
void heap_based_array() {
	int number_students{};
	//	int marks[number_students]
	std::cout << "How many students marks do you want to store ? ";
	std::cin >> number_students;

	int* marks = new int[number_students];

	std::cout << "Please enter the marks of " << number_students << " students\n";
	for (int idx{ 0 }; idx < number_students; ++idx) {
		std::cout << "Student number : " << (idx + 1) << " : ";
		std::cin >> marks[idx];
	}

	std::cout << "Student marks are as follows\n";
	for (int idx{ 0 }; idx < number_students; ++idx) {
		std::cout << "Student number : " << (idx + 1) << " Marks :  " << marks[idx] << "\n";
	}

	delete[] marks; //compulsory
}

void std_size_demo() {

	int a[] = { -5, 10, 15 };
	std::cout << "Number of elements in the array is : " << std::size(a) << '\n';

	std::cout << "Traversing array in ascending order Using std::size() \n";
	//since C++17 : std::size() Returns the size of the given container  or  array 
	size_t size = std::size(a);
	std::cout << "type returned by size() : " << typeid(size).name() << '\n';
	for (size_t index{ 0 }; index < size; ++index) {
		std::cout << "element : " << a[index] << "\n";
	}

	/*std::cout << "Traversing array in descending order Using std::size() \n";
	auto index = std::size(a);
	for (--index ; index >= 0; --index) {
		std::cout << "element : " << a[index] << "\n";
	}*/

	std::cout << "Traversing array in descending order Using std::ssize() \n";
	// since C++20 the signed size (ssize) can avail
	auto idx = std::ssize(a);
	std::cout << "type of value returned by ssize() : " << typeid(idx).name() << '\n';
	for (--idx; idx != -1; --idx) {
		std::cout << a[idx] << (idx ? ", " : "\n");
	}
	std::cout << "index  = " << idx << '\n';
}

/*array name decays ot a pointer*/

//void passing_array(int score[6]) {
//void passing_array(int score[]) {
void passing_array(int* score) {
	std::cout << "The contents of the array are as follows : \n";
	std::cout << "The size of the array is : " << sizeof(score) << " bytes\n";
	size_t size = sizeof(score) / sizeof(score[0]);
	std::cout << "The number of elements in the array is : " << size << '\n';
	for (size_t counter{ 0 }; counter < size; ++counter) {
		std::cout << score[counter] << '\n';
	}
}

void passing_array_correctly(int score[], size_t number_of_elements) {
	std::cout << "The content of the array is : \n";
	for (size_t counter{ 0 }; counter < number_of_elements; ++counter) {
		std::cout << score[counter] << '\n';
	}
}

//https://en.cppreference.com/w/cpp/numeric/constants
void working_with_arrays() {
	int a[]{ 10,20,30 };
	int b[]{ 3,4,5 };
	//std::cout << "Addition of arrays a+b: " << a + b << '\n';
	//std::cout << "Mulpiply of arrays a*b: " << a * b << '\n';
	//a = a + 5;
	int c[3];
	for (size_t idx{ 0 }; idx<std::size(a);++idx) {
		c[idx] = a[idx] + b[idx];
	}

	std::cout << "The result ofter addition of array : \n";
	for (int element : c) {
		std::cout << element << ',';
	}
	std::cout << "\n";

	float degrees[]{ 180,115,90 };
	std::cout << "Sine of the values are :\n";
	for (float deg : degrees) {
		std::cout << "Sine of " << deg << " degree : " << std::sin(deg * (std::numbers::pi/ 180)) <<'\n';
	}

}

int square(int val) {
	return val * val;
}

void valarray_demo() {
	std::valarray < float > v = { 1, 2, 3 };
	std::valarray < float >	w = { 7, 8, 9};
	auto s = v * w;
	std::cout << "Result of multiplying two valarray : \n";
	for (float element : s) {
		std::cout << element << ' ';
	}
	std::cout << '\n';
	std::valarray < float > addition1 = v + w;	//okay
	auto addition2 = v + w;						//recommended
	std::cout << "Result of addition two valarray : \n";
	for (float element : addition2) {
		std::cout << element << ' ';
	}
	std::cout << '\n';

	auto x = v + 5;
	std::cout << "Result of addition of 5 to valarray : \n";
	for (float element : x) {
		std::cout << element<< ' ';
	}
	std::cout << '\n';

	auto y = v * 5;
	std::cout << "Result of multiplying of 5 to valarray : \n";
	for (float element : y) {
		std::cout << element << ' ';
	}
	std::cout << '\n';

	std::valarray<float> degree{ 180,115,90 };
	std::cout << "Sine of the values are :\n";
	auto sin_deg = std::sin(degree*(std::numbers::pi/180));
	for (float deg : sin_deg) {
		std::cout << "Sine of " << deg << " degree \n";
	}

	std::valarray<int> v1{ 1,2,3 };
	std::valarray<int> v2{ 5,6,7 ,8};
	auto v3 = v1 + v2;
	std::cout << "After adding two valarrays of unequal size and taking square : \n";
	auto v4 = v3.apply(square);
	for (auto element : v4) {
		std::cout << element << "\n";
	}
}

int main()
{
	//defining_array();
	//array_size();
	// std_size_demo();
	//array_initialization();
	//heap_based_array();

	//int score[]{ 67,89,77,56,45,88 };
	//passing_array(score);
	//passing_array_correctly(score, (sizeof(score) / sizeof(score[0])));
	//passing_array_correctly(score, std::size(score)); //C++17

	//working_with_arrays();
	valarray_demo();
}


