// 17. Selection_Switch.cpp : 
//Switch case construct
#include <iostream>



/*
* Accept a  number and check whether it is single digit number`
*/

//int main() {
//	cout << "Please enter a Single digit integer :";
//	int inum{};
//	cin >> inum;
//
//	//Not recommended for just one or two conditions
//	switch( (inum / 10)  ){
//	case 0:
//		cout << "it's a singles digit number" << endl;
//		break;
//	default:
//		cout << "It's not a single digit number" << endl;
//	}
//
//	//better alternative construct
//	if (inum / 10 == 0) {
//		cout << "it's a singles digit number" << endl;
//	}
//	else {
//		cout << "It's not a single digit number" << endl;
//	}
//
//	if (inum % 10 == inum) {
//		cout << "it's a singles digit number" << endl;
//	}
//	else {
//		cout << "It's not a single digit number" << endl;
//	}
//	return 0;
//}

#include <cmath>
/*
* fabs
* labs
* abs
* llabs
*/
/*
* Accept a single digit  integer and print it in words
*/
//int main() {
//	std::cout << "Please enter a Single digit integer :";
//	int inum{};
//	std::cin >> inum;
//
//	//checking whether the number is single digit
//	if (inum / 10 == 0) {
//		//print the number in words
//		std::cout << "Original Number :" << inum << " Absolute Value : " << abs(inum) << std::endl;
//		switch (abs(inum))
//		{
//		case 0:
//			std::cout << "The number is ZERO" << endl;
//			break;
//		case 1:
//			std::cout << "The number is ONE" << endl;
//			break;
//		case 2:
//			std::cout << "The number is TWO" << endl;
//			break;
//		case 3:
//			std::cout << "The number is THREE " << endl;
//			break;
//		case 4:
//			std::cout << "The number is FOUR" << endl;
//			break;
//		case 5:
//			std::cout << "The number is  FIVE" << endl;
//			break;
//		case 6:
//			std::cout << "The number is SIX" << endl;
//			break;
//		case 7:
//			std::cout << "The number is  SEVEN" << endl;
//		case 8:
//			std::cout << "The number is  EIGHT" << endl;
//			break;
//		case 9:
//			std::cout << "The number is  NINE" << endl;
//			break;
//		}
//	}
//	else {
//		std::cerr << "It's not a single digit number" << endl;
//	}
//
//	
//	return 0;
//}



/*
* Accept the month and display the sesaon
*/
//int main(void)
//{
//    int month{};
//
//    /* Read in a month value */
//    std::cout << "Enter month (1-12): ";
//    std::cin >> month;
//
//    /* Tell what season it falls into */
//    switch (month)
//    { //case constants can appear in any order
//    case 12:
//        [[fallthrough]];
//    case 1:
//        [[fallthrough]];
//    case 2:
//        std::cout << "It's a winter season\n";
//        break;
//
//    case 3:
//        [[fallthrough]];
//    case 4:
//        [[fallthrough]];
//    case 5:
//        std::cout << "It's a  Summer season\n";
//        break;
//
//    case 6:
//        [[fallthrough]];
//    case 7:
//        [[fallthrough]];
//    case 8:
//        [[fallthrough]];
//    case 9:
//        std::cout << "It's a  Rainy season\n";
//        break;
//
//    case 10:
//        [[fallthrough]];
//    case 11:
//        std::cout << "It's a  Spring season\n";
//        break;
//  
//    default:
//        std::cerr << "month number you have given is incorrect\n";
//    }
//
//    return(0);
//}

//#include <cctype>
//int main()
//{
//	char alphabet{};
//	std::cout << "Please enter an alphabet :";
//	std::cin >> alphabet;
//
//	if (isalpha(alphabet)) {
//		switch (toupper(alphabet)) {
//		case 'A':
//			[[fallthrough]];
//		case 'E':
//			[[fallthrough]];
//		case 'I':
//			[[fallthrough]];
//		case 'O':
//			[[fallthrough]];
//		case 'U':
//			std::cout << "'" << alphabet << "' is a vowel" << std::endl;
//			break;
//		default:
//			std::cout << "'" << alphabet << "' is a Consonant" << std::endl;
//
//		}
//	}
//	else {
//		std::cerr << "Entered character '" << alphabet << "' is not a alphabet\n";
//	}
//	return 0;
//
//}

/* Returns a alphabet */
char get_alphabet() {
	char alphabet{};
start: //Label
	std::cout << "Please enter an alphabet :";
	std::cin >> alphabet;
	if (not isalpha(alphabet)) {
		std::cerr << "Entered character '" << alphabet << "' is not a alphabet\n";
		goto start;
	}

	return alphabet;
}

#include <cctype>
int main()
{
	switch (char alphabet = get_alphabet() ; toupper(alphabet)) {
	case 'A':
		[[fallthrough]];
	case 'E':
		[[fallthrough]];
	case 'I':
		[[fallthrough]];
	case 'O':
		[[fallthrough]];
	case 'U':
		std::cout << "'" << alphabet << "' is a vowel" << std::endl;
		break;
	default:
		std::cout << "'" << alphabet << "' is a Consonant" << std::endl;
	}

	return 0;

}

//int main() {
//	enum class Color { red, green = 20, blue };
//	Color r = Color::green;
//	switch (r)
//	{
//		case Color::red: 
//			std::cout << "red means danger\n";   
//			break;
//		case Color::green: 
//			std::cout << "green means happy time\n"; 
//			break;
//		case Color::blue: 
//			std::cout << "blue means freedom\n";  
//			break;
//	}
//	return 0;
//}

//int main() {
//	std::cout << 1 << std::endl;
//	std::cout << '1' << std::endl;
//	std::cout << static_cast<int>('1') << std::endl;
//#define JAN 12
//	std::cout << JAN << std::endl;
//
//	std::string month;
//	std::cout << "Enter month : ";
//	std::cin >> month;
//	std::cout << "month = " << month;
//	return 0;
//	// }