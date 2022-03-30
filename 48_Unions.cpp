// 48_Unions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>
#include <ctime>
#include <string>
#include "Unions.h"
using  std::string;


void union_basics() {
	union U {
		char ch;
		int i;
		float f;
		double d;
	};

	U variable;
	/*Size of union is large enough to accomodate the largest member*/
	std::cout << "Size of union : " << sizeof(variable) << " bytes\n";
	variable.i = 42;      //ok, now i is active
	std::cout << "u.i = " << variable.i << std::endl;

	variable.f = 3.14f;   // ok, now f is active
	std::cout << "u.f = " << variable.f << std::endl;

	std::cout << std::hex << "Address of variable   :" << &variable << std::endl;
	U* ptr = &variable;
	std::cout << std::hex << "Address of variable   :" << ptr << std::endl;
	std::cout << std::hex << "Address of variable.ch:" << reinterpret_cast<unsigned long long>(&variable.ch) << std::endl;
	std::cout << std::hex << "Address of variable.i :" << &variable.i << std::endl;
	std::cout << std::hex << "Address of variable.f :" << &variable.f << std::endl;
	std::cout << std::hex << "Address of variable.d :" << &variable.d << std::endl;


}

void union_initialization() {
	union NumericType
	{
		short       sValue;
		long        lValue;
		double      dValue;
	};

	union NumericType values { 10 };   // sValue = 10
	std::cout << "Short Value  : " << values.sValue << std::endl;
	std::cout << "Long Value   : " << values.lValue << std::endl;
	std::cout << "Double Value : " << values.dValue << std::endl;

	values.dValue = 3.1416;

	std::cout << "Short Value  : " << values.sValue << std::endl;
	std::cout << "Long Value   : " << values.lValue << std::endl;
	std::cout << "Double Value : " << values.dValue << std::endl;
}

void union_problems() {
	union Data {
		int i;
		double d;
	};

	Data variable;
	variable.d = 98.7654;
	std::cout << "variable.d : " << variable.d << "\n";

	/*undefined behaviour and there is no error message.*/
	std::cout << "variable.i : " << variable.i << "\n";

	variable.i = -4;
	std::cout << "variable.i : " << variable.i << "\n";
	/*undefined behaviour and there is no error message.*/
	std::cout << "variable.d : " << variable.d << "\n";


	return;
}



enum class WeatherDataType
{
	Temperature, Wind
};

struct TempData
{
	int stationId;
	time_t time;
	double current;
	double max;
	double min;
};

struct WindData
{
	int stationId;
	time_t time;
	int speed;
	short direction;
};

struct WeatherData
{
	WeatherDataType type;
	/*Union has no name, so it's called an anonymous union
	Names declared in an anonymous union are used directly,
	like nonmember variables.
	It implies that the names declared in an anonymous union must be
	unique in the surrounding scope.
	*/
	union
	{
		TempData temp;
		WindData wind;
	};
};

// Functions that are specific to data types
void process_temp_data(TempData t) {
	std::cout << "Processing the Temperature data\n";
	std::cout << "Current    : " << t.current << "\n";
	std::cout << "Station_id : " << t.stationId << "\n";
	std::cout << "Time       : " << t.time << "\n";
	std::cout << "max        : " << t.max << "\n";
	std::cout << "min        : " << t.min << "\n";
}

void process_wind_data(WindData w) {
	std::cout << "Processing the Wind data\n";
	std::cout << "Station_id : " << w.stationId << "\n";
	std::cout << "Time       : " << w.time << "\n";
	std::cout << "Direction  : " << w.direction << "\n";
	std::cout << "Speed      : " << w.speed << "\n";
}

void initialize(std::queue<WeatherData>& inputs)
{
	WeatherData first;
	first.type = WeatherDataType::Temperature;
	first.temp = { 101, 1418855664, 91.8, 108.5, 67.2 };
	inputs.push(first);

	WeatherData second;
	second.type = WeatherDataType::Wind;
	second.wind = { 204, 1418859354, 14, 27 };
	inputs.push(second);
}

void discriminated_union() {
	// Container for all the data records
	std::queue<WeatherData> inputs;
	initialize(inputs);
	while (not inputs.empty())
	{
		const WeatherData data = inputs.front();
		switch (data.type)
		{
		case WeatherDataType::Temperature:
			process_temp_data(data.temp);
			break;
		case WeatherDataType::Wind:
			process_wind_data(data.wind);
			break;
		default:
			break;
		}
		inputs.pop();

	}
}

struct Point {
	Point() :x_(0), y_(0) {}
	Point(int x, int y) : x_(x), y_(y) {}
	~Point() { x_ = 0; y_ = 0; }
	int x_;
	int y_;
};

class widget {
public:
	widget(Point p) : type_(widget_type::POINT), p_(p) {}

	widget(int x, int y) : type_(widget_type::POINT), p_(x, y) {}

	widget(int i) : type_(widget_type::NUMBER), i_(i) {}

	widget(const char* s) : type_(widget_type::TEXT), s_(s) {}

	widget(const widget& w) { *this = w; }
	~widget() {};
	widget& operator=(const widget& w)
	{
		switch (w.type_)
		{
		case widget_type::POINT:
			new (&p_) Point(w.p_);  //Placement new: creating a new object on stack at the same location : address of union
			break;
		case widget_type::NUMBER:
			if (type_ == widget_type::POINT) {
				p_.~Point();
			}
			i_ = w.i_;
			break;
		case widget_type::TEXT:
			if (type_ == widget_type::POINT) {
				p_.~Point();
			}
			s_ = w.s_;
			break;
		}
		type_ = w.type_;
		return *this;
	}
private:
	//Annonymous Emun and a varaible of that type called type_
	enum class widget_type { POINT, NUMBER, TEXT } type_;
	//Annonymous union
	union {
		Point p_;
		int i_;
		const char* s_;
	};
};

void unrestricted_unions1() {
	widget w1(10, 20);
	Point p(100, 200);
	widget w2(p);
	widget w3("Mywidget");
	widget w4(9);
	widget w5(w1);
	w5 = w2;  // w5.operator=(w2)  w2:point
	w5 = w4;  // w5.operator=(w4)  w4 : int
	w4 = w1;
}

struct Value { // two alternative representations represented as a union

	enum class Tag { number, text };
	Tag type; // discriminant

	union { // representation (note: anonymous union)
		int i;
		std::string s; // string has default constructor, copy operations, and destructor
	};

	struct Bad_entry { }; // used for exceptions
	Value();
	~Value();
	Value& operator=(const Value&);   // necessary because of the string variant
	Value(const Value&);

	int number() const;
	std::string text() const;

	void set_number(int n);
	void set_text(const std::string&);

};

int Value::number() const
{
	if (type != Tag::number) {
		throw Bad_entry{};
	}
	return i;
}

std::string Value::text() const
{
	if (type != Tag::text) {
		throw Bad_entry{};
	}
	return s;
}

void Value::set_number(int n)
{
	if (type == Tag::text) {
		s.~string();      // explicitly destroy string
		type = Tag::number;
	}
	i = n;
}

void Value::set_text(const std::string& ss)
{
	if (type == Tag::text)
		s = ss;
	else {
		new(&s) std::string{ ss };   // placement new: explicitly construct string
		type = Tag::text;
	}
}

Value& Value::operator=(const Value& other)   // necessary because of the string variant
{
	if (type == Tag::text and other.type == Tag::text) {
		s = other.s;    // usual string assignment
		return *this;
	}

	if (type == Tag::text) {
		s.~string(); // explicit destroy
	}

	switch (other.type) {
	case Tag::number:
		i = other.i;
		break;
	case Tag::text:
		new(&s) string(other.s);   // placement new: explicit construct
	}

	type = other.type;
	return *this;
}

Value::Value(const Value& other)
{
	type = other.type;
	if (other.type == Tag::text) {
		new(&s) string(other.s);
	}
	else {
		i = other.i;
	}
}

Value::Value()
{
	type = Tag::number;
	i = 0;
}

Value::~Value()
{
	if (type == Tag::text) {
		s.~string(); // explicit destroy
	}
}

void unrestricted_unions2() {
	Value v1;
	v1.type = Value::Tag::number;
	v1.set_number(99);
	Value v2;
	v2.type = Value::Tag::text;
	v2.set_text("Happy");
	v2.set_number(33);
	v1.set_text("Bye");
	//v2 = v1;
	v1 = v2; //overloaded operator=()
	Value v3{ v2 }; //copy constructor
}



int main()
{
	//union_basics();
	//union_initialization();
	// union_problems();

	//discriminated_union();

	unrestricted_unions1();
	unrestricted_unions2();
	return 0;
}