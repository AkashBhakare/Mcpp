// 69_Formatting.cpp :
// How to resue formats

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

void resuable_format_1() {

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);

    std::ios::fmtflags small_real_fmt_cout{ std::cout.flags() };

    float pi = 22.0f / 7.0f;
    std::cout << "PI : " << pi << std::endl;

    double avogadro_constant{ 6.022E+23 };
    std::cout << "avogadro_constant : " << avogadro_constant << std::endl;

    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    std::cout.setf(std::ios::uppercase);

    std::ios::fmtflags big_real_fmt_cout{ std::cout.flags() };

    std::cout << "avogadro_constant : " << avogadro_constant << std::endl;

    std::cout.flags(small_real_fmt_cout);
    std::cout << "PI : " << pi << std::endl;

    std::cout.flags(big_real_fmt_cout);
    std::cout << "avogadro_constant : " << avogadro_constant << std::endl;

    std::ostringstream ostr;

    ostr.flags(big_real_fmt_cout);
    ostr << "avogadro_constant : " << avogadro_constant << std::endl;
    ostr << "PI : " << pi << std::endl;
    std::cerr << "the final output from ostr in scientific format :\n";
    std::cerr << ostr.str();
    ostr.str("");

    ostr.flags(small_real_fmt_cout);
    ostr << "avogadro_constant : " << avogadro_constant << std::endl;
    ostr << "PI : " << pi << std::endl;
    std::cerr << "the final output from ostr in fixed is :\n";
    std::cerr << ostr.str();
    ostr.str("");


}


void resuable_format_2() {

    double avogadro_constant{ 6.022E+23 };

    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    std::cout.setf(std::ios::uppercase);

    std::cout << "avogadro_constant : " << avogadro_constant << std::endl;

    std::ostringstream ostr;
    /*current format of cout(ostream) is applied or copied in ostr (ostringstream)*/
    ostr.copyfmt(std::cout);
    ostr << "avogadro_constant : " << avogadro_constant << std::endl;
    std::cerr << "the final output from ostr using cout format :\n";
    std::cerr << ostr.str();
    ostr.str("");

    std::ofstream out_file1{ "d:\\sartak.txt" };
    out_file1 << "avogadro_constant : " << avogadro_constant << std::endl;
    out_file1.close();

    std::ofstream out_file2{ "d:\\aakash.txt" };
    out_file2.copyfmt(std::cout);
    out_file2 << "avogadro_constant : " << avogadro_constant << std::endl;
    out_file2.close();



}

int main()
{
    /*get copy of the Initial/default state of cout stream format flags*/
    std::ios::fmtflags intital_format_cout{ std::cout.flags() };
    // resuable_format_1();
    resuable_format_2();

    /*reset the cout stream flags to defalut state */
    std::cout.flags(intital_format_cout);

}