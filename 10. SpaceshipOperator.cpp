// 10. SpaceshipOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <compare>
#include <functional>
#include <typeinfo>

void print(std::strong_ordering value)
{
    if (value == 0)
        std::cout << "equal";
    else if (value < 0)
        std::cout << "less";
    else
        std::cout << "greater";
    std::cout << "\n";
}

void show(std::strong_ordering value)
{
    //The type std::strong_ordering has four valid values, implemented as const static data members of its type:
    if (value == std::strong_ordering::equal)
        std::cout << "equal";
    else if (value == std::strong_ordering::less)
        std::cout << "less";
    else if (value == std::strong_ordering::greater)
        std::cout << "greater";
    std::cout << "\n";
}

void basic_idea() {
    int a{ 100 };
    int b{ 200 };
    std::cout << std::boolalpha << std::showpos;
    std::cout << a << " >  " << b << " : " << (a > b) << "\n";
    std::cout << a << " <  " << b << " : " << (a < b) << "\n";
    std::cout << a << " == " << b << " : " << (a == b) << "\n";

    std::string s1{ "aaaaa" };
    std::string s2{ "xxx" };
    std::cout << s1 << " == " << s2 << " : " << (s1 == s2) << "\n";
    std::cout << s1 << " > " << s2 << " : " << (s1 > s2) << "\n";
    std::cout << s1 << " <  " << s2 << " : " << (s1 < s2) << "\n";
    //For standard strings this function performs character - by - character lexicographical comparison.
    s1 = "aaaaa";
    s2 = "xxx";
    std::cout << s1 << " compare " << s2 << " : " << s1.compare(s2) << "\n";
    s1 = "xxxx";
    s2 = "xxbbbbbbb";
    std::cout << s1 << " compare " << s2 << " : " << s1.compare(s2) << "\n";
    s1 = "xxxx";
    s2 = "xxxx";
    auto result = s1.compare(s2);
    std::cout << s1 << " compare " << s2 << " : " << result << "\n";
    std::cout << "Data Type of result : " << typeid(result).name() << "\n";

    //using spaceship operator
    s1 = "xxxx";
    s2 = "xxxx";
    auto result1{ (s1 <=> s2) };
    std::cout << "Data Type of result1 : " << typeid(result1).name() << "\n";
    std::cout << s1 << " <=> " << s2 << " : "; print(result1);
   
    s1 = "aaaa";
    s2 = "xxxx";
    std::cout << s1 << " <=> " << s2 << " : "; print((s1 <=> s2));

    s1 = "xxxx";
    s2 = "bbbb";
    std::cout << s1 << " <=> " << s2 << " : "; show((s1 <=> s2));

    a = 100 ;
    b = 200;
    std::cout << a << " <=>  " << b << " : "; print((a <=> b));
    //Function object for performing comparisons.
    std::cout << a << " <=>  " << b << " : "; show(std::compare_three_way{}(a, b));

    a = 100;
    b = 100;
    std::cout << a << " <=>  " << b << " : "; print((a <=> b));
    std::cout << a << " <=>  " << b << " : "; show(std::compare_three_way{}(a, b));

    a = 200;
    b = 100;
    std::cout << a << " <=>  " << b << " : "; print((a <=> b));
    std::cout << a << " <=>  " << b << " : "; show( std::compare_three_way{}(a, b));

    a = 700;
    b = 1000;
    std::cout << a << " <=>  " << b << " : "; print((a <=> b));
    std::cout << a << " <=>  " << b << " : "; show(std::compare_three_way{}(a, b));
}


void user_defined_types_comparision() {
    //struct Point {
    //    int x;
    //    int y;
    //};

    //Point p1{ 10,20 };
    //Point p2{ 10,20 };
    //auto result = (p1 == p2);
    //std::cout << "p1 < p2 : " << (p1 < p2);
    //std::cout << "p1 <=> p2 : "; show(p1 <=> p2);

    /*
    You can define the three-way comparison operator or request it from the compiler with =default. 
    In both cases you get all six comparison operators: ==, !=, <, <=, >, and >=.
    */
    struct CenterPoint {
        int x;
        int y;
        auto operator<=>(const CenterPoint&) const = default;
    };
    CenterPoint cp1{ 10,20 };
    CenterPoint cp2{ 10,20 };
    CenterPoint cp3{ 100,200 };
    std::cout << std::boolalpha;
    std::cout << "cp1 <=> cp2 : "; show((cp1 <=> cp2));
    std::cout << "cp1 == cp2 : " << (cp1 == cp2) << "\n";

    std::cout << "cp1 <=> cp3 : "; show((cp1 <=> cp3));
    std::cout << "cp1 < cp3 : " << (cp1 < cp3) << "\n";

    std::cout << "cp3 <=> cp1 : "; show((cp3 <=> cp1));
    std::cout << "cp3 > cp1 : " << (cp3 > cp1) << "\n";
}


int main()
{
  //  basic_idea();
    user_defined_types_comparision();
}
