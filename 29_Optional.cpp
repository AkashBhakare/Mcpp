// 29_Optional.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <optional>
#include<complex>
using namespace std::literals;

void optional_creation() {
    std::optional<int> o1;
    std::optional<int> o2 (std::nullopt);
    std::optional o3{ 42 };
    std::optional<std::string> o4{ "hello" };
    std::optional o5{ "hello" };
    std::optional o6{ std::complex{3.0,4.0} };
    std::optional<std::complex<double>> o7{ std::in_place, 3.0, 4.0 };
    std::optional o8{ "hello" };
    std::optional<std::string> o9{ o8 };
    auto o10 = std::make_optional(3.0);
    auto o11 = std::make_optional("hello");
    auto o12 = std::make_optional<std::complex<double>>(3.0, 4.0);
}
int main()
{
    optional_creation();
}
