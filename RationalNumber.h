#pragma once
/* Concept of Rational number
https://www.mathsisfun.com/algebra/rational-numbers-operations.html
*/
#include <string>
namespace mylib {

	class RationalNumber
	{
		friend RationalNumber operator-(const RationalNumber&, const RationalNumber&);
		friend std::istream& operator >> (std::istream&, mylib::RationalNumber&);
		friend std::ostream& operator <<(std::ostream&, const RationalNumber&);
	private:
		int numerator = 1;
		int demoninator = 1;
	public:
		RationalNumber() = default;
		RationalNumber(int numerator);
		RationalNumber(int numerator, int denominator);
		RationalNumber(const RationalNumber&);
		RationalNumber(RationalNumber&&);
		const RationalNumber& operator=(const RationalNumber&);
		std::string get_string_representation() const;

		RationalNumber operator+(const RationalNumber&) const;
	};


	RationalNumber operator-(const RationalNumber&, const RationalNumber&);

	/*Inserter */
	std::ostream& operator <<(std::ostream&, const mylib::RationalNumber&);

	/*Extractor */
	std::istream& operator >> (std::istream&, mylib::RationalNumber&);
}
