// 24_Auto_any.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
#include <thread>
#include <chrono>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <climits>
#include <cinttypes>
#include <intsafe.h>
#include <array>
#include <any>

void type_name_demo() {
    //Type of literal  (constant)
    std::cout << "Type of 3.14 :" << typeid(3.14).name() << std::endl;
    std::cout << "Type of 3.14F :" << typeid(3.14f).name() << std::endl;

    //Type of the Variable
    int i = 12;
    std::cout << "Type of i :" << typeid(i).name() << std::endl;

    //Type of Experssion
    std::cout << "Type of expression :" << typeid(i * 3.14).name() << std::endl;
}

void initialization_necessary() {
    /*int age;
    std::cout << "Age is " << age << "\n";*/
    auto weight{ 77.5f };
    std::cout << "Type of weight :" << typeid(weight).name() << std::endl;
    std::cout << "Weight : " << weight << "\n";
}

//Using auto ensures that you always use the correct type and that implicit conversion will not occur

void  no_implicit_conversion() {
    long long int tel{9988776655LL};
    int length = sizeof(tel);            //implict conversion from  size_t to int
    std::cout << "Size of tel : " << length << " bytes\n";

    std::vector<std::string> friends{ "Aryan","Rushi","Appu","Dhanashree" };
    int number_of_friends = friends.size(); //implicit conversion from size_t to int
    std::cout << "Number of friends : " << number_of_friends << '\n';
    auto friend_count = friends.size();
    std::cout << "Number of friends : " << number_of_friends << '\n';

    double root1 = sqrt(345);  //possoble loss of precision; long double converted to double (narrowing)
    std::cout << "Square root1 : " << root1 << '\n';

    auto root2 = sqrtl(345);    //No possibility of loss of precision
    std::cout << "Square root2 : " << root2 << "\t Type or root2 : " << typeid(root2).name() << '\n';
}

void less_typing() {
    std::vector <int> even_nos{ 2,4,6,8,10,12 };

    for (size_t i{ 0 }; i < even_nos.size(); ++i) {

    }
    std::cout << "Using iterators : too much code \n";
    for (std::vector<int>::iterator iter = even_nos.begin(); iter != even_nos.end(); ++iter) {
        std::cout << (*iter) << ',';
    }
    std::cout << '\n';

    std::cout << "Using auto : less typing \n";
    for (auto iter = even_nos.begin(); iter != even_nos.end(); ++iter) {
        std::cout << (*iter) << ',';
    }
    std::cout << '\n';
}

//The auto specifier is only a placeholder for the type, not for the const/ volatile and references specifiers
void where_we_cannot_use_auto() {
    //The auto specifier is only a placeholder for the type
    auto var1{ "str" };
    std::cout << "Type of var1 : " << typeid(var1).name() << '\n';

    using namespace std::string_literals;
    auto var2{ "str"s };
    std::cout << "Type of var2 : " << typeid(var2).name() << '\n';

    std::string name{ "Aparajita" };
    std::string& alias1{ name };

    std::cout << "Name : " << name << "\tAlias1 : " << alias1 << '\n';
    name = "appu";
    std::cout << "Name : " << name << "\tAlias1 : " << alias1 << '\n';
    
    std::string surname{ "Patil" };
    auto alias2{ surname };
    std::cout << "Surname Name : " << surname << "\tAlias2 : " << alias2 << '\n';
    surname = "Pandit";
    std::cout << "Surname Name : " << surname << "\tAlias2 : " << alias2 << '\n';
}

//It is not possible to use auto for multi-word types: likv
void multi_word_type() {
    auto ivar = int(40);
    std::cout << "ivar : " << ivar << "\ttype : " << typeid(ivar).name() << '\n';

    /*auto llvar = long long{ 40 };
    std::cout << "llvar : " << llvar << "\ttype : " << typeid(llvar).name() << '\n';
    
    auto ldvar = long double{ 40 };
    std::cout << "ldvar : " << ldvar << "\ttype : " << typeid(ldvar).name() << '\n';*/

    using llong  = long long;
    using ldouble = long double;

    auto llvar = llong{ 40 };
    std::cout << "llvar : " << llvar << "\ttype : " << typeid(llvar).name() << '\n';
    
    auto ldvar = long double{ 40 };
    std::cout << "ldvar : " << ldvar << "\ttype : " << typeid(ldvar).name() << '\n';

}

int main()
{
    //type_name_demo();
    //initialization_necessary();
    //no_implicit_conversion();
    //less_typing();
    //where_we_cannot_use_auto();
    multi_word_type();
}

