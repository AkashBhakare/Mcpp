// 70_Formatting.cpp : Manipulators introducted in Modern C++
// https://docs.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
// https://docs.moodle.org/dev/Table_of_locales
// https://docs.oracle.com/cd/E13214_01/wli/docs92/xref/xqisocodes.html
//https://docs.microsoft.com/en-us/windows/win32/intl/code-page-identifiers
// https://en.wikipedia.org/wiki/Code_page
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <ctime>


void money_demo() {
	// set the appropriate locale for stdin, stdout
	 // in this example, we use en_US.UTF-8 / en-US
	 // note: locale names are implementation specific
	std::locale en_us("en_US.UTF-8");
	std::cin.imbue(std::locale("en_US.UTF-8"));
	std::cout.imbue(std::locale("en_US.UTF-8"));


	// get the monetary values  amount1 and amount2;
	// since the locale is en_US.UTF-8, the monetary unit is a cent
	// note: using the lowest denomination monetary unit for all our 
	// computations minimises/eliminates rounding errors
	// ie. input of $12,345 or 1235 USD or just 12345
	// http://en.cppreference.com/w/cpp/io/manip/get_money
	long double amount1, amount2;
	std::cout << "enter amount1 and amount2: ";
	std::cin >> std::get_money(amount1) >> std::get_money(amount2);

	// to print out monetary values, we use std::put_money
	// converts the monetary value mon to its character representation as 
	// specified by the std::money_put facet of the locale currently imbued
	// http://en.cppreference.com/w/cpp/io/manip/put_money

	std::cout << std::showbase; // show the currency symbol on output
	std::cout << "\namount1: " << std::put_money(amount1) << "\namount2: " << std::put_money(amount2) << "\n\n";

}

void get_money_demo() {
	std::time_t rawtime;
	std::istringstream in("$1,234.56 2.22 USD  3.33");
	long double amt1;
	long double amt2;
	std::string str_amount;
	in.imbue(std::locale("en_US.UTF-8"));
	in >> std::get_money(amt1)
		>> std::get_money(amt2)
		>> std::get_money(str_amount, true);
	if (in) {
		std::cout << std::fixed << std::setprecision(2)
			<< std::quoted(in.str()) << " parsed as: "
			<< amt1 / 100 << ", "
			<< amt2 / 100 << ", "
			<< str_amount << '\n';
	}
	else {
		std::cout << "Parse failed";
	}

	std::string name = "Aakash";
	std::cout << "Name : " << name << std::endl;
	std::cout << "Name : " << std::quoted(name) << std::endl;
}

void get_money_french() {
	std::string str = "1,11 € 2,22 EUR 3,33 EUR";

	std::istringstream s1(str);
	s1.imbue(std::locale("fr_FR.utf8"));

	std::cout << std::fixed << std::setprecision(2);
	std::cout << '"' << str << "\" parsed with the I/O manipulator: ";

	long double amt;
	std::cout << std::showbase;
	s1.setf(std::ios::showbase);
	while (s1 >> std::get_money(amt))
		std::cout << amt / 100 << ' ';
	std::cout << '\n';

}
/*
quoted
(New in C++14) An iostream manipulator that enables convenient round - tripping of strings
into and out of streams using the >> and << operators.
*/
void show_quoted_v_nonquoted()
{
	// Results are identical regardless of input string type:
	// string inserted { R"(This is a "sentence".)" }; // raw string literal
	// string inserted { "This is a \"sentence\"." };  // regular string literal
	const char* inserted = "This is a \"sentence\".";  // const char*
	std::stringstream ss, ss_quoted;
	std::string extracted, extracted_quoted;

	ss << inserted;
	ss_quoted << std::quoted(inserted);

	std::cout << "ss.str() is storing       : " << ss.str() << std::endl;
	std::cout << "ss_quoted.str() is storing: " << ss_quoted.str() << std::endl << std::endl;

	// Round-trip the strings
	ss >> extracted;
	ss_quoted >> quoted(extracted_quoted);

	std::cout << "After round trip: " << std::endl;
	std::cout << "Non-quoted      : " << extracted << std::endl;
	std::cout << "Quoted          : " << extracted_quoted << std::endl;
}

void show_custom_delimiter()
{
	std::string inserted{ R"("This" "is" "a" "heavily-quoted" "sentence".)" };
	// string inserted{ "\"This\" \"is\" \"a\" \"heavily-quoted\" \"sentence\"" };
	// const char* inserted{ "\"This\" \"is\" \"a\" \"heavily-quoted\" \"sentence\"" };
	std::stringstream ss, ss_quoted;
	std::string extracted;

	ss_quoted << quoted(inserted, '*');
	ss << inserted;
	std::cout << "ss_quoted.str() is storing: " << ss_quoted.str() << std::endl;
	std::cout << "ss.str() is storing       : " << ss.str() << std::endl << std::endl;

	// Use the same quoted arguments as on insertion.
	ss_quoted >> quoted(extracted, '*');

	std::cout << "After round trip: " << std::endl;
	std::cout << "Quoted          : " << extracted << std::endl;

	extracted = {};
	ss >> extracted;
	std::cout << "Non-quoted      : " << extracted << std::endl << std::endl;
}

/*
get_money(valRef) Reads a monetary value into valRef, using the local currency symbol for the facet

get_money(valRef,intl) Reads a monetary value into valRef, using the currency symbol according to intl  for the facet

put_money(val) Writes a monetary value val, using the local currency symbol for the facet

put_money(val,intl) Writes a monetary value val, using the currency symbol according to intl for the facet
*/
void get_put_money() {


	try {

#ifdef _MSC_VER
		// use German locale:
		std::locale loc("deu_deu.1252");
		//std::locale loc("English_United States.1252");

		//code page for devangri (chcp 65001)
		// std::locale loc("Hindi.65001");
		//https://docs.moodle.org/dev/Table_of_locales
#else
		//	locale loc("de_DE");
		//	std::locale loc("en_US");
		locale loc("hi_IN.UTF-8");
#endif
		// use German/US locale and ensure that the currency is written:
		std::cin.imbue(loc);  //Replaces the current locale.
		std::cout.imbue(loc); //Replaces the current locale.
		std::cout << std::showbase;
		// read monetary value into long double (use international symbol)
		long double amt;
		std::cout << "monetary value: ";
		std::cin >> std::get_money(amt, true); //parses the character input as a monetary value
		if (std::cin) {
			// write monetary value (use local symbol)
			// converts the monetary value mon to its character representation 
			std::cout << std::put_money(amt, false) << std::endl;
			//use chcp 1252 for German
		}
		else {
			std::cerr << "invalid format" << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;

	}
}

//https://www.cplusplus.com/reference/ctime/strftime/

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS

void time_demo_c_style() {
	//	__time64_t rawtime;
//	struct tm* timeinfo;
//	char buffer[80];
//	
//	_time64(&rawtime);
//	timeinfo = _localtime64(&rawtime);
//
//	strftime(buffer, 80, "Now it's %I:%M%p.", timeinfo);
//	puts(buffer);
}

void time_dempo_unix_gcc()
{
	//std::time_t rawtime;
	//struct tm* timeinfo;
	//char buffer[80];
	////Returns the current calendar time encoded as a std::time_t object,
	//time(&rawtime);
	////Converts given time since epoch as std::time_t value into calendar time, expressed in local time
	//timeinfo = localtime(&rawtime);
	////Converts the dateand time information from a given calendar time time to a null - terminated multibyte character string str
	//strftime(buffer, 80, "Now it's %c", timeinfo);
	////https://en.cppreference.com/w/cpp/chrono/c/strftime
	//puts(buffer);
}

int main()
{
	//	get_put_money();
	//time_demo_c_style();
	//money_demo();
		//show_quoted_v_nonquoted();
	  // get_money_demo();
	 //   get_money_french();
}