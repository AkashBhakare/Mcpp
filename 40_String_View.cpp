// 40_String_View.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <String_view>
#include <algorithm>
#include <xutility>
#include <cassert>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <vector>

void* operator new(std::size_t count) {
    std::cout << "  " << count << "bytes" << std::endl;
    return malloc(count);
}


void string_basic() {
    {
        char text[15]{ "I love c++" }; //Stack
        //std::string_str;
        //std::cout << "Size of str : " << sizeof(str) << std::endl;
        //std::cin >> str;
        std::string str1{ text };
        std::string str2{ str1 };
        std::cout << "Text : " << text << std::endl;
        std::cout << "str1 : " << str1 << std::endl;
        std::cout << "str2 : " << str2 << std::endl;
    }
    {
        char text[15]{ "I Love C++" }//Stack
        /*Unlike std::string, Which keeps its own copy of the strinf,
        std::string_view provides a voew of a string that is defined elsewhwre.*/
        std::string_view sv1{ "I am facinated with C++" };
        /*The string "I am facinated with c++" is stored in the binary and is not allocated at run-time*/
        std::string_view sv2{ sv1 };
        std::string_view sv3{ text };
        std::cout << "sv1 : " << sv1 << std::endl;
        std::cout << "sv2 : " << sv2 << std::endl;

    }
    {
        /*Because Std::string_view doesn't create a copy of the string ,
        if we change the viewed string, the changes are reflected in the string_view*/
        char arr[]{ "Gold" };
        std::string_view str{ arr };

        std::cout << str << '\n'; //Gold

        //change 'd' to 'f' in arr
        arr[3] = 'f';

        std::cout << str << '\n'; //Golf
    }
}

void remove_demo() {

    std::string_view str{ "C++ Language" };

    std::cout << str << '\n';

    //Ignore the first charater.
    str.remove_prefix(1);

    std::cout << str << '\n';

    //Ignore the last 2 charater.
    str.remove_suffix(2);

    std::cout << str << '\n';
    return;
}


void string_view_without_ntbs() {
    //No-null-terminator
    char vowels[]{ 'á', 'e', 'i', 'o','u' };

    //vowel isn't null=terminated. We need to pass the length manually.
    //Because vowels is an arrays, We can use std::size to get its length.
    std::string_view str{ vowels, std::size(vowels) };

    std::cout << str << '\n'; //Thois is safe. std::cout knows how to print std::string_view.

}


/*
* Ownership issues
Being only a view, a std::string_view's lifetime is indepedent of that of the string it is viewing.
If the viewed string goes out of scope, std::string_view has nothing to observe and accessing it
causes undefined behavior. The string that a std::string_view is viewing has to have been created
somewhere else.
It might be a string literal that lives as long as the program does or it was created by a std::string,
in which case the string lives until the std::string decided to destroy it or the std::string dies.
std::string_view can't create any string on its own, because it's just a view.
*/
std::string_view askForName()
{
    std::cout << "What's your name?\n";

    //Use a std::string, because std::cin needs to modify it.
    std::string str{};
    std::cin >> str;

    // We're switching to std::string_view for demonstrative purpose only.
    // If you already have a std::string, there's no reasopn to switch to
    // a std::string_view.
    std::_string_view view{ str };

    std::cout << "Hello " << view << '\n';

    return view;
} //str dies, and so does the string that str created.

/*
* Modifying a std::string can cause its internal string to die and be replaced with a new one
 in a different place. The std::string_view will still look at where the old string was, but it's not there anymore.
*/

void string_view_ownership_issue() {
    std::string_view view{ askForName() };

    // view is observing a string that already died.
    std::cout << "Your name is " << view << '\n'; //Undefined Behavior
}




int main()
{
    string_basic();
    //remove_demo();
    //string_view_without_ntbs();
    //string_view_ownership_issue();
    // string_view_conversion();
    // small_string_optimization();
    // string_view_demo();
    // check_performance();

    return EXIT_SUCCESS;
}
