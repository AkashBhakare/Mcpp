// 43_EnumerationScoped.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <typeinfo>
#include <string>
using namespace std::literals;

void enumBasics() {
	// "enum class" defines this as a scoped enumeration instead of a standard enumeration
	enum class Color
	{
		red, // red is inside the scope of Color
		blue
	};

	enum class Fruit
	{
		banana, // banana is inside the scope of Fruit
		apple
	};
	std::string red{ "My color"s };
	//Color aColor = red;
	// note: red is not directly accessible any more, we have to use Color::red
	Color color1{ Color::red };
	// note: banana is not directly accessible any more, we have to use Fruit::banana
	Fruit fruit1{ Fruit::banana };

	// compile error here, as the compiler doesn't know how to compare different types Color and Fruit
	/*if (color1 == fruit1)
		std::cout << "color and fruit are equal\n";
	else
		std::cout << "color and fruit are not equal\n";*/


		/*you can still compare enumerators from within the same enum class*/

	Color color2{ Color::red };
	/* comparing two enum type variables*/
	if (color1 == color2)
		std::cout << "Colors are same\n";
	else
		std::cout << "Colors are different\n";

	/*Comparing enum varaible with enumerator of its own type*/
	if (color2 == Color::red) // this is okay
		std::cout << "The color is red!\n";
	else if (color2 == Color::blue)
		std::cout << "The color is blue!\n";

	/*Implicit conversion restricited*/
	//if (color2 == 1) {
	//	//..
	//}

	return;

}

/*
* you have to use a scope qualifier to access the enumerator (e.g. Color::red).
  This helps keep name pollution and the potential for name conflicts down.
*/
void enumScope() {

	enum class TrafficLight
	{
		green,
		yellow,
		red,
	};

	enum class Colors
	{
		cyan,
		pink,
		magenta,
		yellow,
	};

	//Colors acolor{ yellow };

	//have to use a scope qualifier to access the enumerator
	Colors acolor{ Colors::yellow };
	TrafficLight light{ TrafficLight::yellow };

}

/*
* the compiler will no longer implicitly convert enumerator values to integers.
  This is mostly a good thing. However, there are occasionally cases where it
  is useful to be able to do so. In these cases, you can explicitly convert an
  enum class enumerator to an integer by using a static_cast to int:
*/
void enumConversion() {

	enum class Color
	{
		red,
		blue
	};

	// Implicit (Automatic ) conversion of scoped enum is restricited
   /*
	std::cout << "COLOR RED    : " << red << std::endl;
	std::cout << "COLOR RED    : " << Color::red << std::endl;*/

	// Explict conversion of scoped enum is allowed
	std::cout << "COLOR red    : " << static_cast<int>(Color::red) << std::endl;
	std::cout << "COLOR blue   : " << static_cast<int>(Color::blue) << std::endl;

	Color acolor{ Color::red };
	acolor = Color::blue;

	//std::cout << acolor; // won't work, because there's no implicit conversion to int
	std::cout << "COLOR acolor : " << static_cast<int>(acolor); // will print 1
	return;
}

/*
* Being able to specify the underlying type allows simpler interoperability
  and guaranteed sizes of enumerations:
  Enumerated types are considered part of the integer family of types, and it’s up to the compiler to
  determine how much memory to allocate for an enum variable. .
  The C++ standard says the enum size needs to be large enough to represent all of the enumerator values.
  Most often, it will make enum variables the same size as a standard int.
  However, it is possible to specify a different underlying type. For example,
  if you are working in some bandwidth-sensitive context (e.g. sending data over a network)
  you may want to specify a smaller type:
*/
void enumCompactRepresentation() {
	// by default, the underlying type is int
	enum class TrafficLight { red, yellow, green, };
	std::cout << "Type :" << typeid(TrafficLight::green).name() << std::endl;
	std::cout << "Value :" << static_cast<int>(TrafficLight::yellow) << std::endl;
	std::cout << "TrafficLights Size :" << sizeof(TrafficLight) << " bytes" << std::endl;

	enum class Colors : std::int8_t { red = 1, green = 2, blue = 3 };
	std::cout << "Colors Size :" << sizeof(Colors) << " bytes" << std::endl;

	enum class Color : char { red, blue };  // compact representation
	std::cout << "Type :" << typeid(Color::red).name() << std::endl;
	std::cout << "Value :" << static_cast<int>(Color::blue) << std::endl;
	std::cout << "Color Size :" << sizeof(Color) << " bytes" << std::endl;

	// now we can be specific
	enum class FriendContact : unsigned long long {
		yash = 9876543217LL,
		geeta = 98777766543LL
	};
	std::cout << "FriendContact Size :" << sizeof(FriendContact) << " bytes" << std::endl;

	enum  FriendPhone : unsigned long long {
		aryan = 9876543217LL,
		akash = 98777766543LL
	};


	//underlying type of enum type must be an integral type
	//enum EE : float {

	//};


}

enum class Color
{
	red = 10,
	blue = 50,
	green = 5,
	cyan,
	pink,
};

int operator +(const Color& c1, const Color& c2) {
	int result = static_cast<int>(c1) + static_cast<int>(c2);
	return result;
}

int operator -(const Color& c1, const Color& c2) {
	int result = static_cast<int>(c1) - static_cast<int>(c2);
	return result;
}


int operator -(const Color& c1) {
	int result = -static_cast<int>(c1);
	return result;
}
enum class TrafficLight
{
	green,
	yellow,
	red,
};

void enum_operations() {
	Color color1{ Color::red };
	Color color2{ Color::cyan };
	/*	binary '*': 'Color' does not define this operator or a conversion to
		a type acceptable to the predefined operator	*/
		//auto result = color1 * color2;

	auto add_color = color1 + color2;
	std::cout << "Type :" << typeid(add_color).name() << std::endl;
	std::cout << "Result : " << add_color << '\n';
	std::cout << "Negation : " << -color1;
}


int main()
{
	//enumBasics();
	//enumScope();
	//enumConversion();
	//enumCompactRepresentation();
	enum_operations();
	std::this_thread::sleep_for(std::chrono::seconds(5));
}