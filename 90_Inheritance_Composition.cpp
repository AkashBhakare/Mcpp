// 90_Inheritance_Composition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "department.h"
#include "university.h"
#include <string>
#include <utility>
using namespace std::literals;
int main()
{
    {
        mylib::University u1("UOP"s, 1956u, { "Computer","Sarthak",20 });
        std::cout << u1.get_univ_info();
        std::cout << '\n';
        u1.add_departments("Physics"s, "Tejas", 15);
        std::cout << u1.get_univ_info();
    }
    std::cout << "done\n";
    return 0;
}