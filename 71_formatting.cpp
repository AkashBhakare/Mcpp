// 71_formatting.cpp :std::formatting support in C++ 20
// std::std::format
//

#include <iostream>
#include <format>
#include <string>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <chrono>
#include <type_traits>

void placeholder_basics() {
	//placeholder is substituted with the corresponding argument 
	std::cout << std::format("{} {} {}\n", "Planet", "Temperature", "Pressure");
	//we can specify the index of the argument to be used to replace the placeholder
	std::cout << std::format("{0:} {1:}  {2:}\n", "Planet", "Temperature", "Pressure");
	//the index can be used repeatedly
	std::cout << std::format("{0:} {1:}  {2:}  {0:} {1:} \n", "Planet", "Temperature", "Pressure");
	//order of index does not not matter
	std::cout << std::format("{2:} {1:}  {0:}\n\n", "Planet", "Temperature", "Pressure");
}


void alignment_demo() {
	// planetary temperature and pressure
	constexpr double     VENUS_TEMP = 464;    // celsius
	constexpr double     EARTH_TEMP = 15;
	constexpr double      MARS_TEMP = -62;

	constexpr double VENUS_PRESSURE = 92000;    // millibars
	constexpr double EARTH_PRESSURE = 1000;
	constexpr double  MARS_PRESSURE = 1;

	std::cout << std::flush;
	// Headers
	// Print a 3-column table
	// Left column is 7 chars wide; char* -> left-justified by default
	// Other columns are 11 chars wide, right-justified

	// {0:7}   : allocate width of 7 column for the 0th argumment
	// {1:>11} : allocate width of 11 columns for the 1th argumnet; '>' indicates right alignment
	std::cout << std::format("|{:7}| |{:>11}|  |{:>11}|\n", "Planet", "Temperature", "Pressure");

	std::cout << std::format("{:<7} {:>11}  {:>11}\n\n", "", "(celsius)", "(millibars)");

	// Data
	// {1:11.1f} {index : width.precision format_specifier_float(fixed)}
	std::cout << std::format("{:7} {:11.1f}  {:11.0}\n", "Venus", VENUS_TEMP, VENUS_PRESSURE);
	std::cout << std::format("{:7} {:11.1f}  {:11.0e}\n", "Earth", EARTH_TEMP, EARTH_PRESSURE);
	std::cout << std::format("{:7} {:11.1f}  {:11.0E}\n", "Mars", MARS_TEMP, MARS_PRESSURE);

	/*std::cout << std::format("{:7} {:11.1f}  {:11.2e}\n", "Venus", VENUS_TEMP, VENUS_PRESSURE);
	std::cout << std::format("{:7} {:11.1f}  {:11.2e}\n", "Earth", EARTH_TEMP, EARTH_PRESSURE);
	std::cout << std::format("{:7} {:11.1f}  {:11.2e}\n", "Mars", MARS_TEMP, MARS_PRESSURE);*/

}

void base_demo() {
	// Print the same integer using base 2, 8, 16, and 10
	std::cout << "Here's 15 written in...\n";
	std::cout << std::format("{0:>8}{1:>8}{2:>8}{3:>8}\n", "binary", "octal", "hex", "decimal");
	//(if you don't specify, you get decimal)
	std::cout << std::format("{0:>8b}{0:>8o}{0:>8X}{0:>8}\n\n", 15);
	// We used argument #0 four times; no law against that...

	// Print the same item with different types of padding
	std::cout << "Here's 15 padded with x's, .'s, and *'s: ";
	std::cout << std::format("{0:x>4} {0:.>4} {0:*>4}\n\n", 15);

	// Print a floating point number with different std::formats
	std::cout << "And here's 0.01234 in scientific, fixed, general, ";
	std::cout << "and default std::format,\n";
	std::cout << "showing how they interpret a precision of 2.\n";
	std::cout << std::format("{0:>10.2e} {0:>10.2f} {0:>10.2g} {0:>10.2}\n\n", 0.01234);

	// You can also print to a string with std::format_to:
	std::string str;
	std::format_to(back_inserter(str), "The language of choice is {}.\n", "C++");
	std::cout << str;
}

void alignment_fill() {
	// Default alignment: right for numbers, left otherwise
	std::cout << std::format("{:7}|{:7}|{:7}|{:7}|{:7}|\n", 1, -.2, "str", 'c', true);

	// Left and right alignment : numbers left aligned and rest right aligned
	std::cout << std::format("{:<7}|{:<7}|{:>7}|{:>7}|{:>7}|\n", 1, -.2, "str", 'c', true);

	// Left and right alignment + custom fill character
	std::cout << std::format("{:*<7}|{:*<7}|{:*>7}|{:*>7}|{:*>7}|\n", 1, -.2, "str", 'c', true);

	// Centered alignment + 0 formatting option for numbers
	std::cout << std::format("{:^7}|{:^7}|{:^7}|{:^7}|{:^7}|\n", 1, -.2, "str", 'c', true);
	std::cout << std::format("{:*^7}|{:*^7}|{:*^7}|{:*^7}|{:*^7}|\n", 1, -.2, "str", 'c', true);
	std::cout << std::format("{:#^7}|{:#^7}|{:#^7}|{:#^7}|{:#^7}|\n", 1, -.2, "str", 'c', true);
}

#include <numbers>
//https://en.cppreference.com/w/cpp/numeric/constants

void formatting_numbers() {
	const double pi = std::numbers::pi;
	std::cout << std::format("Default: {:.2}, fixed: {:.2f}, scientific: {:.2e}, general: {:.2g}\n", pi, pi, pi, pi);
	std::cout << std::format("Default: {}, binary: {:b}, hex.: {:x}, oct: {:o}\n", 314, 314, 314, 314);
	std::cout << std::format("Default: {0:}, binary: {0:b}, hex.: {0:x}, oct: {0:o}\n", 314);
	std::cout << std::format("Default: {0:}, binary: {0:b}, hex.: {0:x}, oct: {0:o}, decimal: {0:d}\n", 'c');
	std::cout << std::format("Alternative hex.: {:#x}, binary: {:#b}, HEX.: {:#X}, oct: {:#o},\n", 314, 314, 314, 314);
	// {0:# ^ #10x} : index : fillchar alignment basespecifier widthspecifier conversion_char
	std::cout << std::format("Alternative hex.: {:#^#10x}, binary: {:#b}, HEX.: {:#X}, oct: {:#o},\n", 314, 314, 314, 314);

	std::cout << std::format("Forced sign: {:+}, space sign: {: }\n", 314, 314);
	std::cout << std::format("Forced sign: {:+}, sign: {:+}\n", 314, -314);
	std::cout << std::format("All together: {0:*<+10.4f}, {1:+#09x}\n", pi, 314); //pad with 0
	std::cout << std::format("All together: {0:*<+10.4f}, {1:+#9x}\n", pi, 314);  //no padding
}

void finding_limits() {
	std::cout
		<< std::format("The range for type short is from {} to {}\n",
			std::numeric_limits<short>::min(), std::numeric_limits<short>::max())
		<< std::format("The range for type unsigned int is from {} to {}\n",
			std::numeric_limits<unsigned int>::min(),
			std::numeric_limits<unsigned int>::max())
		<< std::format("The range for type long is from {} to {}\n",
			std::numeric_limits<long>::min(), std::numeric_limits<long>::max())
		<< std::format("The positive range for type float is from {} to {}\n",
			std::numeric_limits<float>::min(), std::numeric_limits<float>::max())
		<< std::format("The full range for type float is from {} to {}\n",
			std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max())
		<< std::format("The positive range for type double is from {} to {}\n",
			std::numeric_limits<double>::min(),
			std::numeric_limits<double>::max())
		<< std::format("The positive range for type long double is from {} to {}\n",
			std::numeric_limits<long double>::min(),
			std::numeric_limits<long double>::max());
}

void indexing_rules() {
	//A format string cannot contain a mixture of automaticand manual indexing.— end note]
	try {
		std::string s0 = std::format("{} to {}", "a", "b"); // OK, automatic indexing
		std::cout << "s0 :" << s0 << std::endl;
		std::string s1 = std::format("{1} to {0}", "a", "b"); // OK, manual indexing
		std::cout << "s1 :" << s1 << std::endl;
		// not a format string (mixing automatic and manual indexing),  throws format_error
		// std::string s2 = std::format("{0} to {}", "a", "b"); 
		// not a format string (mixing automatic and manual indexing),  throws format_error
		// std::string s3 = std::format("{} to {1}", "a", "b"); 
	}
	catch (const std::format_error& err) {
		std::cerr << err.what() << std::endl;
	}
}

void sign_demo() {

	std::string s0 = std::format("{0:},{0:+},{0:-},{0: }", 1); // value of s0 is "1,+1,1, 1"
	std::cout << "s0 : " << s0 << std::endl;
	std::string s1 = std::format("{0:},{0:+},{0:-},{0: }", -1); // value of s1 is "-1,-1,-1,-1"
	std::cout << "s1 : " << s1 << std::endl;
	std::string s2 = std::format("{0:},{0:+},{0:-},{0:}", std::numeric_limits<double>::infinity()); // value of s2 is "inf,+inf,inf, inf"
	std::cout << "s2 : " << s2 << std::endl;
	//std::nan("1")
	std::string s3 = std::format("{0:},{0:+},{0:-},{0: }", std::sqrt(-1)); // value of s3 is "nan,+nan,nan, nan"
	std::cout << "s3 : " << s3 << std::endl;

	std::format_to(std::back_inserter(s3), "{0:},{0:+},{0:-},{0: }", std::sqrt(-1));
	std::cout << "s3 : " << s3 << std::endl;
	std::string s4;
	std::format_to(std::back_inserter(s4), "{0:},{0:+},{0:-},{0: }", std::sqrt(-1));
	std::cout << "s4 : " << s4 << std::endl;

}


int main()
{

	placeholder_basics();
	alignment_demo();
	alignment_fill();
	formatting_numbers();
	indexing_rules();
	sign_demo();
	base_demo();
	finding_limits();

}

/*
d or i	Signed decimal integer
u	Unsigned decimal integer	235
o	Unsigned octal	610
x	Unsigned hexadecimal integer	7fa
X	Unsigned hexadecimal integer (uppercase)	7FA
f	Decimal floating point, lowercase	392.65
F	Decimal floating point, uppercase	392.65
e	Scientific notation (mantissa/exponent), lowercase	3.9265e+2
E	Scientific notation (mantissa/exponent), uppercase	3.9265E+2
g	Use the shortest representation: %e or %f	392.65
G	Use the shortest representation: %E or %F	392.65
a	Hexadecimal floating point, lowercase	-0xc.90fep-2
A	Hexadecimal floating point, uppercase	-0XC.90FEP-2
c	Character	a
s	String of characters	sample
p	Pointer address	b8000000
n	Nothing printed.
The corresponding argument must be a pointer to a signed int.
The number of characters written so far is stored in the pointed location.
%	A % followed by another % character will write a single % to the stream.	%


*/