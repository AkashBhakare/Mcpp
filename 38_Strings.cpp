// 38_Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <format>
#include <string_view>
#include <algorithm>
#include <xutility>
#include <cctype>
#include <string>
using namespace std::literals;

/*
* Standard series of ASCII charaters (a.k.a C string) are delimited by double qoutes, supporting
* escape sequence like  \n, \\, and \" , and ending in 0-bytes. such of ASCII - charaters are 
* commonly know as null-terminated bytes strings
*/

void ntbs() {
    char str[15] = "\"IMP\"ETUS\"";  //char str[10] = "IMPETUS";
    //char str[25] = "First line\nSecond line";
    size_t idx = 0;
    //Traditional style
    while (str[idx] != '\0') {
        std::cout << str[idx];
        ++idx;
    }
    std::cout << "\n";
    //since cpp20
    for (auto const& element : str) {
        std::cout << element << ".";
    }
    std::cout << "\n";
    for (auto& element : str) {
        std::cout << element << ".";
        element = 'Q';
    }
    std::cout << "\n";
    for (idx = 0; auto const& element : str) {
        std::cout << idx++ << ":" << element << '\n';
    }
    const char* ptr = str;
    std::cout << "Using Pointer : " << ptr << "\n";
    return;
}

//since cpp11
void raw_strings() {
    //The problem
    std::string dir = "B:\ModernCpp\CppBasics\Scope.txt";
    std::string special_str = "newline\n";

    std::cout << dir << std::endl;
    std::cout << special_str << std::endl;
    std::cout << std::endl;

    //Possible solutions : using \\in strings
    dir = "B:\\ModernCpp\\CppBasics\\Scope.txt";
    special_str = "newline\\n";

    std::cout << dir << std::endl;
    std::cout << special_str << std::endl;
    std::cout << std::endl;

/*
Using R for raw strings:
From c++11 on - wards, we can write the code more easily and fancy with the help of
R in - front of the string and partenthesis in the string which treats special characters as literal.
used to avoid escaping of my character anything between the delimiters becomes part of the strings.
*/
    dir = R"(B:\ModernCpp\CppBasics\Scope.txt)";
    special_str = R"(newline\n)";

    std::cout << dir << std::endl;
    std::cout << special_str << std::endl;
    std::cout << std::endl;

    /*
    Tag is a sequence of up to 16 characters (and an empty tag is both OK and common).
    The characters after 'tag(and before the first following occurrence of )tag' are
    used literally as the contents of the string literal
    */
    special_str = R"tag(whatever you want to say)tag";
    std::cout << special_str << std::endl;
    std::cout << std::endl;

    std::string pattern = "(? : \"(\\\\\" | [^ \"]) * \" | \'(\\\\' | [^ \'])*";
    std::cout << "Regular Expression : " << pattern << std::endl;
    special_str = "\\\\\"";
    std::cout << special_str << std::endl;

    pattern = R"regex((?<=\.) {2,}(?=[A-Z]))regex";
    std::cout << "Regular Expression : " << pattern << std::endl;
    pattern = R"regex(? : "(?:\\" | [^ "])*" | \'(?:\\' | [^ '])*')regex";
    std::cout << "Regular Expression : " << pattern << std::endl;

    return;

}
void string_inititalization() {
	//An object of type string contains a sequence of characters of type char, which can be empty
	std::string empty;
	std::cout << "Empty String : " << empty << std::endl;

	//You can initialize a string object with a string literal when you define it :
	std::string proverb{ "A bad workman always blames his tools" };
	std::cout << "Proverb : " << proverb << std::endl;

	/*  You can convert a std::string object to a C - style string using two similar methods.
		The first is by	calling its c_str() member function(short for C - string) :
		This conversion results in a C - string of type const char* .Because it’s const,
		this pointer cannot be used to	modify the characters of the string, only to access them.
	*/
	const char* proverb_c_str = proverb.c_str();
	std::cout << "Proverb_c_str : " << proverb_c_str << std::endl;
	//proverb_c_str[0] = 'a'; //Error
	/*
		Your second option is the string’s data() function, which starting from C++17 evaluates
		to a non - const char* pointer1 	(prior to C++17, data() resulted in a 	const char* pointer as well) :
	*/
	char* proberb_data = proverb.data();
	std::cout << "Proverb_data : " << proberb_data << std::endl;
	proberb_data[0] = 'a';
	std::cout << "Proverb_data : " << proberb_data << std::endl;

	/*
	* You can use an initial sequence from a  string literal, for instance: */
	std::string part_literal{ "Least said soonest mended.", 5 }; // "Least
	std::cout << "part_literal : " << part_literal << std::endl;

	/*you can initialize a string with any 	number of instances of a given character.*/

	std::string sleeping(6, 'z');
	std::cout << "sleeping : " << sleeping << std::endl;

	/*
	use an existing string object to provide the initial value.
	Given that you’ve defined proverb previously, you can define another object based on that:*/
	std::string sentence{ proverb };
	std::cout << "sentence : " << sentence << std::endl;
	/*
	* You can use a pair of index values to identify part of an existing string and use that to initialize
	a new string object. */
	std::string phrase{ proverb, 2, 13 }; // Initialize with 13 characters starting at index 2
	std::cout << "phrase : " << phrase << std::endl;

	/*Using std::initializer_list  (9) from cpp docs*/
	std::string init_str{ 'T','a','t','a' };
	std::cout << "init_str : " << init_str << std::endl;

	//from cpp docs
	std::vector<char> coll{ 'a','b','c','d','e' };
	std::string from_container{ coll.begin(),coll.end() };
	std::cout << "from_container : " << from_container << std::endl;

}

void string_initialization_with_docs()
{
	{
		// string::string()
		std::string s;
		assert(s.empty() && (s.length() == 0) && (s.size() == 0));
	}

	{
		// string::string(size_type count, charT ch)
		std::string s(4, '=');
		std::cout << s << '\n'; // "===="
	}

	{
		std::string const other("Exemplary");
		// string::string(string const& other, size_type pos, size_type count)
		std::string s(other, 0, other.length() - 1);
		std::cout << s << '\n'; // "Exemplar"
	}

	{
		// string::string(charT const* s, size_type count)
		std::string s("C-style string", 7);
		std::cout << s << '\n'; // "C-style"
	}

	{
		// string::string(charT const* s)
		std::string s("C-style\0string");
		std::cout << s << '\n'; // "C-style"
	}

	{
		char mutable_c_str[] = "another C-style string";
		// string::string(InputIt first, InputIt last)
		std::string s(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);
		std::cout << s << '\n'; // "C-style string"
	}

	{
		std::string const other("Exemplar");
		std::string s(other);
		std::cout << s << '\n'; // "Exemplar"
	}

	{
		// string::string(string&& str)
		std::string s(std::string("C++ by ") + std::string("example"));
		std::cout << s << '\n'; // "C++ by example"
	}

	{
		// string(std::initializer_list<charT> ilist)
		std::string s({ 'C', '-', 's', 't', 'y', 'l', 'e' });
		std::cout << s << '\n'; // "C-style"
	}

	{
		// overload resolution selects string(InputIt first, InputIt last) [with InputIt = int]
		// which behaves as if string(size_type count, charT ch) is called
		std::string s(3, std::toupper('a'));
		std::cout << s << '\n'; // "AAA"
	}
}


void string_assignment() {
	std::string adjective{ "hornswoggling" }; // Defines adjective
	std::string word{ "rubbish" }; // Defines word
	std::cout << "adjective :" << adjective << "\tword : " << word << std::endl;
	word = adjective; // Modifies word
	adjective = "twotiming"; // Modifies adjective
	std::cout << "adjective :" << adjective << "\tword : " << word << std::endl;
}

void string_concatenation() {
	std::string first; // Stores the first name
	std::string second; // Stores the second name
	std::cout << "Enter your first name: ";
	std::cin >> first; // Read first name
	std::cout << "Enter your second name: ";
	std::cin >> second; // Read second name
	std::string sentence{ "Your full name is " }; // Create basic sentence
	sentence += first + " " + second + "."; // Augment with names
	std::cout << sentence << std::endl; // Output the sentence
	std::cout << "The string contains " // Output its length
		<< sentence.length() << " characters." << std::endl;
}

/*Fails to read string containing whitespace charaters
operator >> could extract single word*/
void reading_string_problem() {


	std::string name;
	std::string city;

	std::cout << "Please enter your name: ";
	std::cin >> name;
	std::cout << "Enter the city you live in: ";
	std::cin >> city;

	std::cout << "Hello, " << name << std::endl;
	std::cout << "You live in " << city << std::endl;
	return;

}

/*Accept strings containing embedded spaces
getline() extrating single line*/
void reading_string_solution() {
	std::string name;
	std::string city;

	std::cout << "Please enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Enter the city you live in: ";
	std::getline(std::cin, city);

	std::cout << "Hello, " << name << std::endl;
	std::cout << "You live in " << city << std::endl;
	return;

}

/*Extracting multiple lines*/
void read_multiple_lines() {
	std::string address{};
	std::cout << "Please enter your address :";
	//getline(std::cin, address,'\n');  Default delimiter
	getline(std::cin, address, '.');
	std::cout << "Address :" << address << std::endl;
}

void read_character() {
	std::cout << "Enter your Employee Id : ";
	int empid;
	std::cin >> empid;
	std::cout << "Your ID is :" << empid << std::endl;

	//To clear the input stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//std::cout << "Max Limit : " << std::numeric_limits<std::streamsize>::max() << std::endl;

	std::cout << "Enter your Grade (A/B/C/D) :";
	char grade;
	std::cin >> grade;

	std::cout << "Your grade is : " << grade << std::endl;

	std::cout << "\nPress any Key to continue....\n";
	char temp;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// operator >> extracts only non-whitespace character and ignores whitespace character
	//std::cin >> temp; 
	//std::get() doesnot ignore whitespace charater
	temp = std::cin.get();
	//std::cout << "temp : "<< static_cast<int>(temp) << std::endl;

	std::cout << "Enter your Department Code (X/Y/Z) :";
	char dept_code;
	std::cin >> dept_code;
	std::cout << "Your Department code is : " << dept_code << std::endl;
}

void problem_read_data() {
	int roll_no;
	std::cout << "Enter roll Number : ";
	std::cin >> roll_no;
	std::cout << "Enter Percentage Marks : ";
	float per;
	std::cin >> per;
	std::cout << "Roll No :" << roll_no << "\tPercentage :" << per << std::endl;
}

void problem_read_data_solved() {
	std::string data{};
	try {
		std::cout << "Enter roll Number : ";
		std::getline(std::cin, data);
		//converts string ot integer
		//int roll_no = std::stoi(data.substr(0, 3));
		size_t count{};
		int roll_no = std::stoi(data, &count, 10);
		std::cout << "Processed : " << count << " digits\n";
		//int roll_no = std::stoi(data,nullptr,16);   //data string has hex value
		//int roll_no = std::stoi(data, nullptr, 8);  //if the input string is octal

		std::cout << "Enter Percentage Marks : ";
		std::getline(std::cin, data);

		//converts string to float
		float per = std::stof(data);
		std::cout << "Roll No :" << roll_no << "\tPercentage :" << per << std::endl;
	}
	catch (std::invalid_argument& error) {
		std::cout << "The format of data is invalid" << std::endl;
	}
}

int main()
{
	//ntbs();
	//raw_strings();
	//string_inititalization();
	//string_initialization_with_docs();
	//string_assignment();
	//string_concatenation();
	//reading_string_problem();
	//reading_string_solution();
	//read_multiple_lines();
	//read_character();
	//problem_read_data();
	//problem_read_data_solved();

	//g++
	//std::u8string word{ u8"字符串" };
	//std::cout << s.length;
	//std::u8string quote{ u8"character is the real foundation of success." };// char8_t characters
	std::u16string question{ u"whither atrophy?" }; // char16_t characters
	std::u32string sentence{ U"this sentance contains three errars." }; // char32_t characters

	return EXIT_SUCCESS;
}
