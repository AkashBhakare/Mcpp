// 42_EnumerationUnscoped.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <string>
using namespace std::literals;

void enumBasic() {

	enum TrafficLight
	{
		green,
		yellow,
		red,
	};

	TrafficLight trafficlight = red;

	// Checking some stuff
	if (trafficlight == TrafficLight::green)
		std::cout << "Traffic light is green! You may proceed" << std::endl;
	if (trafficlight == TrafficLight::yellow)
		std::cout << "Traffic light is yellow! Go slow" << std::endl;
	if (trafficlight == TrafficLight::red)
		std::cout << "Traffic light is red! Please Stop" << std::endl;
	// not recommended. Always prefix the enumerator with the enumeration type
	if (trafficlight == red)
		std::cout << "Traffic light is red! Please Stop" << std::endl;

	/*constexpr int PINK{ 5 };
	trafficlight = PINK;*/
}

void enumScope() {
	//conventional enums export their enumerators to the surrounding scope, causing name clashes.
	enum TrafficLight
	{
		green,
		yellow = 5,
		red,
	};
	std::cout << "GREEN   : " << green << std::endl;

	enum Colors
	{
		cyan,
		pink,
		magenta,
		//yellow = 5, //'enumScope::YELLOW' : redefinition; previous definition was 'enumerator'
	};

	std::cout << "PINK    : " << pink << std::endl;
	std::cout << "MAGENTA : " << magenta << std::endl;

	//'enumScope::YELLOW' : redefinition; previous definition was 'enumerator'
	std::cout << "YELLOW  : " << yellow << std::endl;

	//std::cout << "YELLOW color : " << Colors::yellow << std::endl;
	std::cout << "YELLOW  TrafficLight: " << TrafficLight::yellow << std::endl;
}


//unscoped 
enum Color
{
	red, // color red is placed in the same scope as Color
	yellow,
};

enum Fruit
{
	banana, // fruit banana is placed in the same scope as Fruit
	apple,
};

//Error :	'red' : redefinition; previous definition was 'enumerator'	
//std::string red{ "My color"s };

int getFruitPrice(Fruit afruit) {
	if (afruit == apple)
		return 100;
	else
		if (afruit == banana)
			return 70;
}

void enumConversion() {
	/*conventional enums implicitly convert to int, causing errors when someone
	does not want an enumeration to act as an integer.*/

	//implicit conversion
	Color aColor{ red }; // Color and RED can be accessed in the same scope (no prefix needed)
	Fruit aFruit{ banana }; // Fruit and BANANA can be accessed in the same scope (no prefix needed)

	if (aColor == aFruit) // The compiler will compare aColor and aFruit as integers
		std::cout << "color and fruit are equal\n"; // and find they are equal!
	else
		std::cout << "color and fruit are not equal\n";

	std::cout << "color :" << aColor << std::endl;
	std::cout << "fruit :" << aFruit << std::endl;

	std::cout << "Price of Apple  : " << getFruitPrice(apple) << std::endl;
	/*
	std::cout << "Price of Apple  : " << getFruitPrice(aColor) << std::endl;

	//One enum type does not convert to a different enum type implicitly
	std::cout << "Price of BANANA : " << getFruitPrice(red) << std::endl;
	std::cout << "Price of BANANA : " << getFruitPrice(1) << std::endl;*/

	//But unscoped enums can implicitly convert to integer values, 
	aFruit = apple;
	//aFruit = BANANA;
	if (aFruit == banana)
		std::cout << "I Love Bananaa!" << std::endl;
	else
		if (aFruit == 1)  //implicit conversion while comparing
			std::cout << "a Apple a Day.. Keep the doctor away" << std::endl;
	/*
	* While the compiler will implicitly convert unscoped enumerators to an integer,
	it will not implicitly convert an integer to an unscoped enumerator.
	*/
	//a value of type "int" cannot be used to initialize an entity of type "Fruit"	
	//Fruit my_fruit{ 1 };
	//my_fruit = 1;

	//you can force the compiler to convert an integer to an unscoped enumerator using static_cast:
	Fruit my_fruit{ static_cast<Fruit>(1) };
	my_fruit = static_cast<Fruit>(0);

	// C++17 : if an unscoped enumeration has a specified base, 
	//then the compiler will allow you to initialize(but not assign) an unscoped enumeration using an integral value :
	enum ComputerType : int // we've specified a base
	{
		supercomputer,  // assigned 0
		mainframe,		// assigned 1
		minicomputer,   // assigned 2
		workstation,    // assigned 3
		personalcomputer,// assigned 4
	};

	ComputerType comp{ 2 }; // ok: can initialize with integer
	//comp = 3;       // compile error: can not assign with integer
	comp = static_cast<ComputerType>(3);

}



void enumNeed()
{
	std::cout << "Std Code of my city : " << 84 << std::endl;
	constexpr unsigned HYDERABAD_STD_CODE{ 84 };
	//HYDERABAD_STD_CODE = 48;
	std::cout << "Std Code of my city : " << HYDERABAD_STD_CODE << std::endl;
	static constexpr unsigned AKURDI{ 411035 };
	static constexpr unsigned CHINCHWAD{ 411018 };
	static constexpr unsigned PUNE{ 411004 };
	//static constexpr unsigned PUNE{ 22 };
	int pincode = AKURDI;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = CHINCHWAD;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = PUNE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = -565656;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = HYDERABAD_STD_CODE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
}

void enumDeclaration() {
	/*Create a type that can be assigned values only in the specified range*/
	enum Pincode {  //Declaration of enum type
		akurdi = 411035,
		nigdi = 411044,
		bhosari = 411027,
		chinchwad = 411018
	};

	enum Pincode my_city_pincode { akurdi };

	Pincode citycode; //defining a variable of enum type
	std::cout << "Size of enum type PINCODE :" << sizeof(citycode) << " bytes " << std::endl;
	citycode = akurdi;
	std::cout << "Pincode Code : " << citycode << std::endl;
	citycode = bhosari;
	std::cout << "Pincode Code : " << citycode << std::endl;
	/* CityCode can be assigned values specified in the enumeration only*/
	/*constexpr unsigned hyderabad_std_code{ 84 };
	citycode = hyderabad_std_code;
	citycode = 411005;
	citycode = 411035;*/
	return;
}

enum Size
{
	small,
	medium,
	large,
	extra_large,
};


// Using if-else for this is inefficient
void printSize(Size size)
{
	if (size == small) std::cout << "small";
	else if (size == medium) std::cout << "medium";
	else if (size == large) std::cout << "large";
	else if (size == extra_large) std::cout << "extra_large";
	else std::cout << "???";
}

std::string getSize(Size size)
{
	switch (size)
	{
	case small: return "small";
	case large:   return "large";
	case medium:  return "medium";
	case extra_large:  return "extra large";
	default:    return "???";
	}
}

constexpr std::string_view getSize_better(Size size)
{
	switch (size)
	{
	case small: return "small";
	case large:   return "large";
	case medium:  return "medium";
	case extra_large:  return "extra large";
	default:    return "???";
	}
}

// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Size size)
{
	switch (size)
	{
	case small:
		out << "small"s;
		break;
	case large:
		out << "large"s;
		break;
	case medium:
		out << "medium"s;
		break;
	case extra_large:
		out << "extra large"s;
		break;
	default:
		out << "???"s;
	}
	return out;
}

void printing_enum() {
	Size size{ medium };
	printSize(size);
	std::cout << '\n';
	std::cout << "The size is : " << getSize(size) << '\n';
	std::cout << "The size is : " << getSize_better(size) << '\n';
	std::cout << "The size is : ";
	std::cout << size;
}

int main()
{
	//enumNeed();
	//enumDeclaration();
	//enumBasic();
	//enumScope();
	//enumConversion();
	printing_enum();

	std::this_thread::sleep_for(std::chrono::seconds(5));
}