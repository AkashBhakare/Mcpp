// 72_Formatting.cpp : Custom manipulators without arguments

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::ostream& endl_tab(std::ostream& out) {
	out << "\n\t";
	return out;
}


std::ostream& currency(std::ostream& out) {
	out.setf(std::ios::showpoint);
	out.setf(std::ios::fixed, std::ios::floatfield);
	out.precision(2);
	out << "Rs ";
	return out;
}

std::istream& pw(std::istream& in) {
	in.width(5);
	return in;
}

std::ostream& line(std::ostream& out) {
	out << "\n--------------------------------------------------------------------------\n";
	return out;
}

//int foo(char);
//int(*fp)(char);
//
//std::ostream& f(std::ostream&);
//std::ostream& (*fp1)(std::ostream&);
/*
 basic_ostream&  operator<<( basic_ostream& (* _Pfn)(basic_ostream&) ) { // call basic_ostream manipulator
		return _Pfn(*this);
	}
*/

void understand_working_of_manipulators() {
	std::cout << 10;
	std::cout << std::endl;
	std::cout.operator << (10);
	std::cout << line; // line(cout)
	std::cout << std::endl;

	std::ostream& (*fp)(std::ostream&);
	/*Name of function without parenthesis in C/C++ refers to its address*/
	fp = line;
	//Method-I
	line(std::cout);
	fp(std::cout);
	//Method-II
	std::cout << fp;
	std::cout << line;
	//	std::cout << line << std::setw(40) << "Manipulators" << line << std::endl;
}

/*Manipulator with Parameter*/
class PrintLine {

private:
	size_t _width;
public:
	PrintLine(size_t width = 0) :_width(width) {};
	size_t get_width() {
		return _width;
	}

};


std::ostream& operator << (std::ostream& out, PrintLine&& line) {
	//std::string s1(10, '$');
	size_t width = line.get_width();
	if (width) {
		std::string line_to_print(width, '-');	//construct a line by calling ctor of string class
		out << std::endl << line_to_print << std::endl;	//insert the line into the stream
	}
	else {
		out << width;
	}
	return out;		//return the reference to stream
}


std::ios_base& operator << (std::ios_base& out, const std::_Smanip<int>& _Manip) {
	// extract by calling function with input stream and argument

	(*_Manip._Pfun)(out, _Manip._Manarg);
	return out;
}

static void stars(std::ios_base& out, int count) {
	out.setf('*');
	std::cout << "******";
}
//static void __cdecl swfun(ios_base& iostr, streamsize wide) { // set width
//	iostr.width(wide);
//}

const std::_Smanip<int>& print_star(int count) {
	return std::_Smanip<int>(&stars, count);
	//return (std::_Smanip<int> (stars, count));

}


/*

std::cout << 10;
cout.operator<<(int);

std::cout << 34.5F;
cout.operator <<(float);
//member func

a+b;
a.operator+(b);


//Non-member
a+b;
operater+(a,b);


std::cout << PrintLine(100);

cout.operator<<(PrintLine);


cout.operator <<(PrintLine)
*/

void using_manipulator_with_parameter() {
	std::cout << 10; // cout.operator(int)
	std::cout << PrintLine(); // operator <<(cout,Printline);
	std::cout << PrintLine(100) << std::setw(50) << "Impetus" << PrintLine(100);
	std::cout << PrintLine();


}

int add(int n1, int n2) {
	return n1 + n2;
}


int multiply(int n1, int n2) {
	return n1 * n2;
}

long double factorial(int n) {
	long double facto = 1;
	for (int counter = 1; counter <= n; ++counter) {
		facto = facto * counter;
	}
	return facto;
}

void demo_ptr_to_function() {

	std::cout << "Addition of 4,5 : " << add(4, 5) << std::endl;
	std::cout << "Multiplication of 4,5 : " << multiply(4, 5) << std::endl;

	int (*fp1)(int, int);

	fp1 = add;
	std::cout << "Addition of 4,5 : " << fp1(4, 5) << std::endl;
	fp1 = multiply;
	std::cout << "Multiplication of 4,5 : " << fp1(4, 5) << std::endl;

	long double (*fp2)(int);

	//fp2 = add;
	fp2 = factorial;
	std::cout << "Factorail of 5 = " << factorial(5) << std::endl;
	std::cout << "Factorail of 5 = " << fp2(5) << std::endl;
}

void using_manipulators_without_parameter() {
	std::cout << std::endl << "Hello" << std::endl << "World!" << std::endl;
	std::cout << endl_tab << "Hello" << endl_tab << "World!" << endl_tab;
	endl_tab(std::cout);
	std::endl(std::cout);
	std::cout << std::endl;

	double amount{ 1234 };
	std::cout << "Amount : " << amount << std::endl;
	amount = 1234.56678;
	std::cout << "Amount : " << amount << std::endl;

	amount = 1234;
	std::cout << "Amount : " << currency << amount << std::endl;
	amount = 1234.56678;
	std::cout << "Amount : " << currency << amount << std::endl;

	std::string passphrase;
	std::cout << "Enter Password (not more that 5 characters ) :";
	std::cin >> pw >> passphrase;
	std::cout << "Password is : " << passphrase << std::endl;

	std::ostringstream ocout{};
	ocout << std::endl << "Hello" << std::endl << "World" << std::endl;
	ocout << endl_tab << "Hello" << endl_tab << "World" << std::endl;
	std::cout << "osting : " << ocout.str();
}

int main()
{

	std::cout << print_star(5);
	demo_ptr_to_function();
	understand_working_of_manipulators();

	using_manipulators_without_parameter();

	using_manipulator_with_parameter();

}