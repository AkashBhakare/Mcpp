// 14. Selection_Dual_alternative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// 13. Selection_single_alternative.cpp : 

/*
Accept product rate and quantity purchased and calculate the gross and net bill amount
Gross bill amount = quantity purchased X product rate
Net Bill amount = Gross bill amount - discount
Discount is 5 % of Gross bill amount if the quantity purchased is more than 100 units
If the quantity purchased is less than or equal to 100 units then the discount 
is 2 % of Gross bill amount
*/
#include <iostream>
#include <iomanip>
int main()
{
    constexpr float max_discount_rate{ 0.05f };
    constexpr float min_discount_rate{ 0.02f };
    constexpr unsigned maximum_qty_for_minimum_discount{ 100u };

    float product_rate{};
    std::cout << "Please enter the Product Rate(Rs) : ";
    std::cin >> product_rate;

    unsigned int quantity_purchased{};
    std::cout << "How many units of this product have you purshased ? ";
    std::cin >> quantity_purchased;

    float gross_bill_amt = product_rate * quantity_purchased;
    float discount_amt{ 0 };

    if (quantity_purchased <= maximum_qty_for_minimum_discount) {
        discount_amt = gross_bill_amt * min_discount_rate;
    }
    else {
        discount_amt = gross_bill_amt * max_discount_rate;
    }

    float net_bill_amt = gross_bill_amt - discount_amt;

    std::cout << std::setprecision(2) << std::showpoint << std::fixed;
    std::cout << "The Gross bill amount is Rs " << gross_bill_amt << "\n";
    std::cout << "The Net bill amount is Rs " << net_bill_amt << "\n";
}
