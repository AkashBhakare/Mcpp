// 98_Polymorphism_Incer_Decre.cpp : Overload unary ++ & unary -- operator 
//

#include <iostream>
#include "Integer.h"

void  overloading_prefix_incre_decre(void);
void  overloading_postfix_incre_decre(void);

int main()
{
    overloading_prefix_incre_decre();
    overloading_postfix_incre_decre();
    return 0;
}

void overloading_prefix_incre_decre() {
    mylib::Integer iobj1;
    std::cout << "iobj1.data = " << iobj1.get_value() << '\n';
    iobj1.set_value(1234567890LL);
    std::cout << "iobj1.data = " << iobj1.get_value() << '\n';
    std::cout << "Max : " << iobj1.get_max_value() << '\n';
    std::cout << "Min : " << iobj1.get_min_value() << '\n';

    mylib::Integer iobj2 = ++iobj1;  /* iobj1.operator++() */
    std::cout << "iobj1.data  = " << iobj1.get_value() << '\n';
    std::cout << "iobj2.data  = " << iobj2.get_value() << '\n';

    iobj2 = ++iobj1;
    std::cout << "iobj1.data  = " << iobj1.get_value() << '\n';
    std::cout << "iobj2.data  = " << iobj2.get_value() << '\n';
    --iobj1;              /*  operator--(iobj1)  */
    iobj2 = --iobj1;      /*  operator--(iobj1)  */
                          /*  iobj2.operator=(iobj1)  */
    std::cout << "iobj1.data  = " << iobj1.get_value() << '\n';
    std::cout << "iobj2.data  = " << iobj2.get_value() << '\n';
}

void overloading_postfix_incre_decre() {
    mylib::Integer iobj1(10);
    std::cout << "iobj1.data = " << iobj1.get_value() << '\n';
    iobj1++;    /*  iobj1.operator++(int) */
    std::cout << "iobj1.data = " << iobj1.get_value() << '\n';

    mylib::Integer iobj2 = iobj1++;
    std::cout << "iobj1.data = " << iobj1.get_value() << '\n';
    std::cout << "iobj2.data = " << iobj2.get_value() << '\n';

}
