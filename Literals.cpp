// Literals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void integer_numerals() {
	int age = 21;
	int score = -10;

	signed int range = -99;
	range = +99;

	short int roll = 10;
	roll = -99;

	signed short int div = 10;
	div = -10;

	unsigned short int age1 = 55;
	age1 = -55; //will never store negative value

	unsigned int age2 = 55u;
	//age2 = -55u; //Error
	age2 = 99U;

	long int tel = 27640406L;
	unsigned long int telephone = 27640406UL;

	long long int mobile = 9970600774LL;
	mobile = -9970600774LL;

	unsigned long long int credit_card = 1234567898765432LLU;
	//credit_card = -1234567898765432LLU;

	std::cout << "Size of 1   : " << sizeof(1) << " bytes\n";
	std::cout << "Size of 1LL : " << sizeof(1LL) << " bytes\n";
	/*
	In most cases, it is not necessary to declare the type of
	literals explicitly since the implicit conversion between
	built-in numeric types usually sets the values at the
	programmer’s expectation.
*/
}

void char_literal() {
	char grade = 'A';
	/*Automatic conversion*/
	grade = 70;
	grade = 500; //illegal

	signed char ch1   = 65;
	ch1 = 'A';
	unsigned char ch2 = 236;
	ch2 = 'α';
	ch2 = 'ß';

	char8_t ch8   = u8'm';

	char16_t ch16 = u'm';

	char32_t ch32 = U'm';

	wchar_t chw   = L'm';

}
	
void floating_point_literal() {
	float f = 4.5F;
	f = 7.8f;

	double d = 4.5;
	d = 7.8;

	long double ld = 4.5L;
	ld = 7.8L;

	std::cout << "Size of float literal			: " << sizeof(4.5F) << " bytes\n";
	std::cout << "Size of double literal		: " << sizeof(4.5) << " bytes\n";
	std::cout << "Size of long double literal	: " << sizeof(4.5L) << " bytes\n";

}

int main()
{
	//integer_numerals();
	//char_literal();
	floating_point_literal();
}
