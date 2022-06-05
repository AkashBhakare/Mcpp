// 74_formatting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <stdexcept>
void english_to_french() {
    try {
        std::locale loc1;                           // copy of the current global locale
        std::cout << "Name : " << loc1.name() << std::endl;
        std::locale loc2{ "" };                     // copy of ‘‘the user’s preferred locale’’
        std::cout << "Name : " << loc2.name() << std::endl;
        std::locale loc3{ "C" };                    // copy of the ‘‘C’’ locale
        std::cout << "Name : " << loc3.name() << std::endl;
        std::locale loc4{ std::locale::classic() }; // copy of the ‘‘C’’ locale
        std::cout << "Name : " << loc4.name() << std::endl;
        //std::locale loc5{ "POSIX"};                // copy of the locale named "POSIX"
        //std::cout << "Name : " << loc5.name() << std::endl;
        std::locale loc6{ "Danish_Denmark.1252" };  // copy of the locale named "Danish_Denmark.1252"
        std::cout << "Name : " << loc6.name() << std::endl;
        std::locale loc7{ "en_US.UTF8" };          // copy of the locale named "en_US.UTF-8"
        std::cout << "Name : " << loc7.name() << std::endl;
        std::locale loc8{ "Hindi_India.1252" };  // copy of the locale named "Danish_Denmark.1252"
        std::cout << "Name : " << loc8.name() << std::endl;

    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}


int main()
{
    english_to_french();
}

