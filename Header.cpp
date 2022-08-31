#include <string>
#include <stdexcept>
#include "Header.h"

void A::foo()
{
    throw std::range_error("Error from A_foo\n");
    std::string str(__func__);
    str.append(" Error occurred\n");
    throw std::invalid_argument(str.c_str());
}

void B::baz()
{
    std::string str(__func__);
    str.append(" Error fromB class)\n");
    throw std::invalid_argument(str.c_str());
}