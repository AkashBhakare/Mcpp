// 75_formatting.cpp : 

#define FMT_HEADER_ONLY

//defines the core API which provides main formatting functions 
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>
#include <fmt/os.h>
#include <vector>
#include <fmt/ranges.h>
#include <string_view>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fmt/format.h>
//#include <fmt/time.h>
#include <fmt/color.h>
#include <fmt/printf.h>
#include <fstream>
using namespace std::literals::chrono_literals;

void fmt_code_demo() {
	std::cout << "What's your age ? ";
	int age;
	std::cin >> age;
	std::string message = fmt::format("You are {} years old", age);
	std::cout << message << std::endl;

	auto out = std::vector<char>();
	fmt::format_to(std::back_inserter(out), "{}", 'A');
	fmt::format_to(std::back_inserter(out), "{}", 'X');
	fmt::format_to(std::back_inserter(out), "{}", 'Q');
	for (char ch : out) {
		std::cout << ch << ", ";
	}
	std::cout << std::endl;

	std::string buffer;
	fmt::format_to(std::back_inserter(buffer), "You are {} years old. ", age);
	fmt::format_to(std::back_inserter(buffer), "You born before {} year. ", age);
	std::cout << buffer << std::endl;
}

void fmt_print_intro() {
	int ans = 42;
	// Formats args according to specifications in fmt and writes the output to stdout.
	fmt::print("The answer is {}.\n", ans);
	//formats args according to specifications in fmt and returns a formatted string
	std::string message = fmt::format("The answer is {}", ans);

	fmt::print(fmt::emphasis::bold | fg(fmt::color::red), "Elapsed time: {0:.2f} seconds\n", 1.23345);

	fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "Hello, {}!\n", "world");
	fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
		fmt::emphasis::underline, "Hello, {}!\n", "мир");

	fmt::print(fg(fmt::color::red) | bg(fmt::color::white) | fmt::emphasis::italic,
		"Hello, {}!\n", "Good Morning!");

	fmt::print("Default format: {} {}\n", 42s, 100ms);
	fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);


	std::vector<int> v = { 1, 2, 3 };
	fmt::print("{}\n", v);

}

void defining_parameter_order(bool ascending) {
	std::string_view format_spec = ascending ? "{0}, {1}, {2}\n" : "{2}, {1}, {0}\n";

	auto one = "one";
	auto two = "two";
	auto three = "three";

	fmt::print(format_spec, one, two, three);
}

//Write a file from a single thread
//#include <fmt/os.h>
#define  _CRT_SECURE_NO_WARNINGS
void write_to_destination() {
	int ans = 42;
	fmt::print(stdout, "Sent to stdout {}\n", ans);
	fmt::print(stderr, "Sent to stderr {}\n", ans);
	std::FILE* fp;
	fopen_s(&fp, "d:\\data.txt", "w");
	fmt::print(fp, "Sent to file {} {}\n", "data.txt", ans);
	std::fclose(fp);
	//auto out = fmt::output_file("d:\\guide.txt");
	//out.print("Don't {}", "Panic");
}

//'fopen': This function or variable may be unsafe.Consider using fopen_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.formatting - 10	D : \TC\Cpp\CppBasics\formatting - 10\formatting - 10.cpp	85


void alignment_demo() {
	// Alignment
	fmt::print("{:*<30}\n", "left aligned");
	fmt::print("{:=>30}\n", "right aligned");
	fmt::print("{:-^30}\n", "centered");
}


void named_args() {
	//fmt::args() : 
	// Returns a named argument to be used in a formatting function. 
	// It should only be used in a call to a formatting function
	// Named arguments
	std::string name_of_person;
	std::cout << "What's your name ? ";
	std::cin >> name_of_person;
	std::cout << "What's your age ? ";
	int age_of_person;
	std::cin >> age_of_person;
	fmt::print("Hello {name} you are {age} years old\n",
		fmt::arg("age", age_of_person), fmt::arg("name", name_of_person));
	//fmt::print("{second} {first}\n", "second"_a = "The answer is", "first"_a = 42);

}
int main() {
	fmt_code_demo();
	fmt_print_intro();
	write_to_destination();
	named_args();

	defining_parameter_order(true);
	defining_parameter_order(false);
	alignment_demo();


}


