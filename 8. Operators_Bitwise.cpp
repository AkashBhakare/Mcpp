// 8. Operators_Bitwise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <limits>

void bitset_demo() {
	unsigned int i1n{ 50 };
	std::cout << "i1n dec : " << i1n << "\n";
	std::bitset<8> bset1{ i1n };
	std::cout << "Binary  : " << bset1 << "\n";

	std::bitset<16> bset2{ i1n };
	std::cout << "Binary  : " << bset2 << "\n";

	i1n = 456784923u;
	std::cout << "i1n dec : " << i1n << "\n";
	std::bitset<32> bset3{ i1n };
	std::cout << "Binary  : " << bset3 << "\n";

	std::string str1{ "11000101101" };
	std::bitset<12> bset4{ str1 };
	std::cout << "Binary  : " << bset4 << "\tDecimal : " << bset4.to_ulong() << "\n";
	bset4.flip(); //Works like  one's compliment
	std::cout << "Binary  : " << bset4 << "\tDecimal : " << bset4.to_ulong() << "\n";

	bset4.set(2, 1); //bitwise or
	std::cout << "Binary  : " << bset4 << "\tDecimal : " << bset4.to_ulong() << "\n";
	bset4.set(4, 0); //bitwise and
	std::cout << "Binary  : " << bset4 << "\tDecimal : " << bset4.to_ulong() << "\n";

	std::cout << "Count of '1' : " << bset4.count() << "\n";

	/*Can represent the binary */
	std::bitset<8> bset5(-55);
	std::cout << "Binary of -55 : " << bset5 << "\n";
	bset5.reset(3);
	std::cout << "Set 4th bit off: " << bset5 << "\n";
	bset5.reset();
	std::cout << "Set all bit off: " << bset5 << "\n";

}


/*One's Compliment */
void one_compliment_demo()
{
	/*
	   "char" is by default "signed char"
	   char			: -128 to +127
	   unsigned char: 0 - 255
	*/

	unsigned char cdata1 = 'A';

	std::cout << "character 1 : " << cdata1 <<
		"\tCharacter Code  : " << static_cast<int>(cdata1) <<
		"\t(Binary) " << std::bitset<8>(cdata1) << std::endl;

	unsigned char cdata2 = ~cdata1;

	std::cout << "character 2 : " << cdata2 <<
		"\tCharacter Code  : " << static_cast<int>(cdata2) <<
		"\t(Binary) " << std::bitset<8>(cdata2) << std::endl;

	unsigned int idata1 = 1005U;
	std::cout << "Integer data1 : " << idata1 << std::endl <<
		"\t(Binary) " << std::bitset<16>(idata1) << std::endl;

	unsigned int idata2 = ~idata1;

	std::cout << "Integer data2 : " << idata2 << std::endl <<
		"\t(Binary) " << std::bitset<16>(idata2) << std::endl;

	int idata3 = -1005;
	std::cout << "Integer data3 : " << idata3 << std::endl <<
		"\t(Binary) " << std::bitset<16>(idata3) << std::endl;

	int idata4 = ~idata3;

	std::cout << "Integer data4 : " << idata4 << std::endl <<
		"\t(Binary) " << std::bitset<16>(idata4) << std::endl;

}

/*Right Shift*/
void right_shift_demo()
{
	int i1n = 100;
	int ibitpos = 3;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<8>(i1n) << std::endl;
	int iresult = i1n >> ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<8>(iresult) << std::endl;

	i1n = INT_MAX;//INT_MAX;
	ibitpos = 5;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;
	/*When the number is +ve the blank spaces introduced on right are padded with zero*/
	iresult = i1n >> ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<32>(iresult) << std::endl;

	i1n = INT_MIN;//INT_MAX;
	ibitpos = 5;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;
	/*When the number is -ve the blank spaces introduced on right are padded with One*/
	iresult = i1n >> ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<32>(iresult) << std::endl;
}


void left_shift_demo() {
	int i1n{ 100 };
	int ibitpos{ 1 };

	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;
	/*blank spaces introduced to the right side always padded with zero*/
	int iresult = i1n << ibitpos;

	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;

	i1n = -7;
	ibitpos = 5;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;
	iresult = i1n << ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<32>(iresult) << std::endl;

}

int main()
{
	// bitset_demo();
	//one_compliment_demo();
	//right_shift_demo();
	//left_shift_demo();
}
