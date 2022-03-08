// 19. Iteration_do_while.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
/*Accept a single digit number and display it in words*/
void single_digit_words() {
	int digit{};
	std::cout << "Please enter a Single digit Number : ";
	std::cin >> digit;
	switch (std::abs(digit)) {
	case 0:
		std::cout << digit << " in words is Zero\n";
		break;
	case 1:
		std::cout << digit << " in words is One\n";
		break;
	case 2:
		std::cout << digit << " in words is Two\n";
		break;
	case 3:
		std::cout << digit << " in words is Three\n";
		break;
	case 4:
		std::cout << digit << " in words is Four\n";
		break;
	case 5:
		std::cout << digit << " in words is Five\n";
		break;
	case 6:
		std::cout << digit << " in words is Six\n";
		break;
	case 7:
		std::cout << digit << " in words is Seven\n";
		break;
	case 8:
		std::cout << digit << " in words is Eight\n";
		break;
	case 9:
		std::cout << digit << " in words is Nine\n";
		break;
	default:
		std::cout << digit << " is not a +ve Single digit between (0-9)\n";
	}

}

/*Accept a single digit number and display it in words*/
void single_digit_words2() {
	/*We want user to enter only a single digit positive number*/
	int digit{};
	do {
		std::cout << "Please enter a Single digit Number (0-9): ";
		std::cin >> digit;
	//	digit = std::abs(digit);
	} while (digit < 0 or digit > 9);

	switch (std::abs(digit)) {
	case 0:
		std::cout << digit << " in words is Zero\n";
		break;
	case 1:
		std::cout << digit << " in words is One\n";
		break;
	case 2:
		std::cout << digit << " in words is Two\n";
		break;
	case 3:
		std::cout << digit << " in words is Three\n";
		break;
	case 4:
		std::cout << digit << " in words is Four\n";
		break;
	case 5:
		std::cout << digit << " in words is Five\n";
		break;
	case 6:
		std::cout << digit << " in words is Six\n";
		break;
	case 7:
		std::cout << digit << " in words is Seven\n";
		break;
	case 8:
		std::cout << digit << " in words is Eight\n";
		break;
	case 9:
		std::cout << digit << " in words is Nine\n";
		break;
	}
	return;
}

/*Accept a single digit number and display it in words*/
void single_digit_words3() {
	/*We want user to enter only a single digit positive number*/
	int digit{};
	do {
		std::cout << "Please enter a Single digit Number (0-9): ";
		std::cin >> digit;
	} while (digit < 0 or digit > 9);

	std::vector<std::string> words{"Zero","One","Two","Three","four","Five","Six","Seven","Eight","Nine"};
	std::cout << "digit : " << words.at(digit) << "\n";
	return;
}


/*Toggle the case of entered alphabet*/
void toggle_alphabet_case() {
	char alpha{};
	do {
		std::cout << "Please enter an Alphabet : ";
		std::cin >> alpha;
	} while (not std::isalpha(alpha));

	if (std::isupper(alpha)) {
		std::cout << "Lowercase equivalent of " << alpha << " is " 
			<< static_cast<char>(std::tolower(alpha)) << "\n";
	}
	else {
		std::cout << "Uppercase equivalent of " << alpha << " is " 
			<< static_cast<char>(std::toupper(alpha)) << "\n";
	}
	return;
}

void login_demo() {

	std::map<std::string, std::string> user_credentails{ { "rohit","rohit123#" },
		{ "rashmi","rush123#" },
		{"siddhi","sid123#"},
		{"sparsh","spar123#"}
	};
	
	//if (_stricmp(user_credentails[user].c_str(),pword.c_str())) {
	std::string user{};
	std::string pword{};
	int constexpr max_chances{ 3 };
	int chance_count = 1;

	do {
		std::cout << "Please enter the username : ";
		std::cin >> user;
     	std::cout << "Please enter the Password : ";
		std::cin >> pword;
		if (user_credentails[user] == pword) {
			std::cout << "Welcome " << user << "!\n";
			break;
		}
		else {
			std::cout << "Incorrect credentails! Please try again\n";
			std::cout << "You have " << max_chances - chance_count << " more chances\n";
			++chance_count;
		}
	} while (chance_count <= max_chances);

	return;
}

/*Display sum and average of all numbers keyed in before zero*/
void sum_avg() {
	int number{};
	double avg{0};
	long long int sum{0};
	int counter{ 0 };
	do {
		std::cout << "Please enter a integer : ";
		std::cin >> number;
		sum += number;
		++counter;
	} while (number != 0);
	std::cout << "The Sum of numbers is : " << sum << "\n";
	if (counter != 1) {
		avg = static_cast<double>(sum) / (counter - 1);
	}
	std::cout << "The Average is : " << avg << "\n";

}

int main()
{
	//single_digit_words1();
	//single_digit_words2();
	//single_digit_words3();

	//toggle_alphabet_case();
	//login_demo();
	sum_avg();


}
