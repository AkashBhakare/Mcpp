// 8. Operators_Bitwise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdint>
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



/* Turn off a bit

	n = 100		=>	01100100
	bitmask ?		11111011
				   -----------
				    01100000

    bitpos = 3
	bitmask = 2 ^ (bitpos -1 )
			  2 ^ 2 => 4
	bistmak	  00000100
	~bitmask  11111011
 
*/

void bit_and_turn_off() {
	int i1n{ 100 };
	int ibitpos{ 3 };
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	int mask{ static_cast<int>(powf(2, (static_cast<float>(ibitpos - 1)))) };
	mask = ~mask;
	int iresult = i1n & mask;

	std::cout << "Integer iresult : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;

}

/*  Check if the bit is on or off

    i= 100;						01100100
	bitpos = 3;					00000100
	mask = 2 ^ (bitpos-1)      __________
		   2 ^ 2 = > 4          00000100     ans = i & mask
	mask = 00000100

	if ans != 0		then the bit is on otherwise the bit is off
	if nas == mask  then the bit is on otherwise the bit is off

	i = 100						01100100     i
	bitpos = 5					00010000     mask
	mask = 2 ^ (bitpos-1)      __________
	mask = 2 ^ 4 => 16          00000000    ans = i & mask
		   00010000

*/


void bit_and_check_status() {
	int i1n{  };
	int ibitpos ;

	std::cout << "Please enter a integer : ";
	std::cin >> i1n;
	std::cout << "Which bit position do you want to check ? ";
	std::cin >> ibitpos;

	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;

	int iresult = i1n & static_cast<int>(pow(2, (ibitpos - 1)));

	if (iresult == 0) {
		std::cout << "\tBit position " << ibitpos << " is Off" 	<< std::endl;
	}
	else
	{
		std::cout << "\tBit position " << ibitpos << " is ON" << std::endl;
	}

}


/*	Turn a bit on
	i = 100;					01100100	i
	bitpos = 4					00001000	mask
								_________				
	mask = 2 ^(bitpos-1)		01101100    i = i | mask
		 = 2 ^ 3 =>
		8 = 00001000

*/

void bit_or_turn_on() {
	int i1n{ 100 };
	int ibitpos{ 5 };

	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	int mask = static_cast<int>(pow(2, (ibitpos - 1)));
	i1n = i1n | mask;

	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;
}

/* Check bit status

	i = 100;				01100100	i
	bitpos = 5				11101111	mask
						   __________
	mask = 2 ^ (bitpos-1)   11101111    result = i | mask
		 = 2 ^ 4 => 16
	16	 = 00010000
	~16  = 11101111

	if mask==result then the bit is off otherwise the bit is on

	i = 100;				01100100	i
	bitpos = 6				11011111	mask
	mask = 2 ^ (bitpos-1)   ----------
	mask = 2 ^ 5 => 32      11111111    result = i | mask
	 32 = 00100000
	~32 = 11011111
*/
void bit_or_check() {
	int i1n{ 100 };
	int ibitpos{ 5 };
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	int mask = static_cast<int>(pow(2, (ibitpos - 1)));
	mask = ~mask;
	int iresult = i1n | mask;
	
	std::cout << "Integer iresult : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;

	(mask == iresult) ? (std::cout << "Bit is Off\n") : (std::cout << "Bit is on\n");
	return;
}


/* Toggle bit on or off
	i = 100;				01100100	i
	bitpos = 3				00000100	mask
							_________
	mask = 2^(bitpos-1)		01100000	i = i ^ mask 
		 = 2^2 => 4
		 = 00000100

	bitpoas = 4				01100100	i
	mask = 8 => 00001000	00001000	mask
							_________
							01101100	i = i ^ mask

*/

void bit_xor_demo() {
	int i1n{ 100 };
	int ibitpos{ 5 };
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	int mask = static_cast<int>(pow(2, (ibitpos - 1)));
	mask = ~mask;
	int iresult = i1n | mask;

	std::cout << "Integer iresult : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;
}


void textual_alternative() {
	int i1n{ 0b01100100 };
	int imask{ 0b00000101 };

	// & => bitand
	std::cout << "Bitwise and : " << (i1n bitand imask ) << "\n";

	// | => bitor
	std::cout << "Bitwise or : " << (i1n bitor imask) << "\n";

	// ^  => xor
	std::cout << "Bitwise xor : " << (i1n xor imask) << "\n";

	// ~  => compl
	std::cout << "Bitwise compliment : " << (compl i1n ) << "\n";
}

void storing_colors() {
	//Yellow : FF FF 00 FF
   // Greeen : 8a d3 5d FF
   //unsigned int of 8 bits
	uint8_t red{ 0x8a };    // 255
	uint8_t green{ 0xd3 };    // 255
	uint8_t blue{ 0x5d };    // 0
	uint8_t alpha{ 0xFF };    // 255

	std::cout << "Red   :" << std::setw(8) << red
		<< " Binary : " << std::bitset<8>(red) << std::endl;
	std::cout << "Red   :" << std::setw(8) << static_cast<int>(red)
		<< " Binary : " << std::bitset<8>(red) << std::endl;
	std::cout << "Green :" << std::setw(8) << static_cast<int>(green)
		<< " Binary : " << std::bitset<8>(green) << std::endl;
	std::cout << "Blue  :" << std::setw(8) << static_cast<int>(blue)
		<< " Binary : " << std::bitset<8>(blue) << std::endl;
	std::cout << "Alpha :" << std::setw(8) << static_cast<int>(alpha)
		<< " Binary : " << std::bitset<8>(alpha) << std::endl;

	uint32_t color{ 0b11111111'11111111'00000000'11111111 };
	std::cout << "Color :" << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;
	std::cout << std::endl;
	color = 0;

	//inserting RED
	color = red; //255
	std::cout << "Color :" << std::setw(10) << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;

	//inserting Green
	color = (color << 8) bitor green;
	std::cout << "Color :" << std::setw(10) << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;

	//inserting Blue
	color = (color << 8) bitor blue;
	std::cout << "Color :" << std::setw(10) << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;

	//inserting Alpha
	color = (color << 8) bitor alpha;
	std::cout << "Color :" << std::setw(10) << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;

	std::cout << "Color :" << std::setw(10) << color
		<< " Binary :" << std::bitset<32>(color) << std::endl;

	std::cout << std::endl << "Extracting Colors " << std::endl;

	uint32_t r = (color >> 24U);
	std::cout << "Red   :" << std::setw(8) << r
		<< " Binary :" << std::bitset<8>(r) << std::endl;

	uint32_t g = ((color << 8) >> 24);
	std::cout << "Green :" << std::setw(8) << g
		<< " Binary :" << std::bitset<8>(g) << std::endl;

	uint32_t b = ((color << 16) >> 24);
	std::cout << "Blue  :" << std::setw(8) << b
		<< " Binary :" << std::bitset<8>(b) << std::endl;

	uint32_t a = ((color << 24) >> 24);
	std::cout << "Alpha :" << std::setw(8) << a
		<< " Binary :" << std::bitset<8>(a) << std::endl;

}

void storing_date() {
	uint16_t date = (512 * (2021 - 1980) + 32 * 12 + 18);
	//Date:          21394 Binary : 0101001110010010
	std::cout << "Date :" << std::setw(16) << date
		<< " Binary :" << std::bitset<16>(date) << std::endl;

	uint16_t day = (date << 11u);
	day = (day >> 11u);
	std::cout << "Day :" << std::setw(16) << day
		<< "\tBinary :" << std::bitset<16>(day) << std::endl;

	uint16_t month = (date << 7u);
	month = month >> 12u;
	std::cout << "Month :" << std::setw(16) << month
		<< "\tBinary :" << std::bitset<16>(month) << std::endl;

	uint16_t year = (date >> 9u);
	std::cout << "Year :" << std::setw(16) << (year + 1980)
		<< "\tBinary :" << std::bitset<16>(year) << std::endl;

}

void storing_font() {
	
	//Font
	uint16_t font{ 0b00000110'0'1'0'01100 };
	std::cout << "Font :" << std::setw(8) << font
		<< " Binary :" << std::bitset<16>(font) << std::endl;

	uint32_t font_size_mask{ 0b0000000000011111 };
	uint32_t font_size = font & font_size_mask;
	std::cout << "Font Size :" << std::setw(8) << font_size
		<< " Binary :" << std::bitset<8>(font_size) << std::endl;

	uint32_t style_mask{ 8 };
	uint32_t font_style = font >> style_mask;
	std::cout << "Font Size :" << std::setw(8) << font_size
		<< " Binary :" << std::bitset<8>(font_style) << std::endl;
}

int main()
{
	// bitset_demo();
	//one_compliment_demo();
	//right_shift_demo();
	//left_shift_demo();
	//bit_and_turn_off();
	//bit_and_check_status();
	//bit_or_turn_on();
	//bit_or_check();
	//bit_xor_demo();
	//textual_alternative();
	storing_date();
	storing_colors();
	storing_font();
}
