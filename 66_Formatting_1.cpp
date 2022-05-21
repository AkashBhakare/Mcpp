// 66_Formatting_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Explore the formatting flags defined in IOS class

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>

void boolalphademo() {

    bool flag{ true };
    std::cout << "Flag : " << flag << std::endl;
    flag = false;
    std::cout << "Flag : " << flag << std::endl;

    std::cout.setf(std::ios::boolalpha);

    std::cout << "Flag : " << flag << std::endl;
    flag = true;
    std::cout << "Flag : " << flag << std::endl;
    int age{ 17 };
    std::cout << "Is he/she eligible to vote ? " << (age >= 18) << std::endl;

    std::cout.unsetf(std::ios::boolalpha);

    std::cout << "Is he/she eligible to vote ? " << (age >= 18) << std::endl;

}

void base_demo() {
    int i = 100;

    //base
    std::cout << "Value of i is (dec) : " << i << std::endl;

    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::cout << "Value of i is (hex) : " << i << std::endl;

    std::cout.setf(std::ios::oct, std::ios::basefield);

    std::cout << "Value of i is (oct) : " << i << std::endl;

    std::cout.setf(std::ios::dec, std::ios::basefield);

    std::cout << "Value of i is (dec) : " << i << std::endl;

    //showbase

    std::cout << "Showbase " << std::endl;

    std::cout.setf(std::ios::showbase);

    std::cout.setf(std::ios::dec, std::ios::basefield);

    std::cout << "Value of i is (dec) : " << i << std::endl;

    std::cout.setf(std::ios::oct, std::ios::basefield);

    std::cout << "Value of i is (oct) : " << i << std::endl;

    std::cout.setf(std::ios::hex, std::ios::basefield);

    std::cout << "Value of i is (hex) : " << i << std::endl;

    // uppercase
    i = 2000;
    std::cout << "Uppercase " << std::endl;
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout.setf(std::ios::showbase);
    std::cout << "Value of i is (hex) : " << i << std::endl;
    std::cout.setf(std::ios::uppercase);
    std::cout << "Value of i is (hex) : " << i << std::endl;
    std::cout.setf(std::ios::dec, std::ios::basefield);
}


void left_right_justification_demo() {
    //justification
    int i{ 1234 };
    std::cout << i << std::endl;
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << i << std::endl;
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << i << std::endl;

    std::cout << std::cout.width() << std::endl; //returns the current width

    std::cout.width(10);   //set the width
    std::cout << std::cout.width() << std::endl;

    std::cout.width(10);
    std::cout << i << "*" << std::endl;
    std::cout << std::endl;

    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout.width(10);
    std::cout << i << std::endl;
    std::cout << std::endl;

    std::cout.width(10);
    std::cout << "hello" << std::endl;
    std::cout << std::endl;

    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.width(10);
    std::cout << "hello" << "*";
    std::cout << std::endl;

    std::cout.width(10);
    std::cout << "HI" << "POS" << "*" << std::endl;

    std::cout.setf(std::ios::right, std::ios::adjustfield);
}


void cin_width_demo() {

    /*std::string data;
    size_t width{ 1 };
     std::cout << "Please enter a String :";

   do {
       std::cin.width(width++);
       std::cin >> data;
       std::cout << data << std::endl;
    }while(!std::cin.eof());*/

    /*std::string input{ "IamveryhappytodayIwillgivemybesttoday" };
    std::istringstream mystream{ input };

    while (!mystream.eof()) {
        mystream.width(width++);
        mystream >> data;
        std::cout << data << std::endl;

    }*/

    //102345 : 10 : dept code  234 : empid   5: grade
   /* int employee_code;
    std::cout << "Please enter the employee code : ";
    std::cin >> employee_code;
    std::cout << "Employee_code : " << employee_code << '\n';*/

    std::cout << "Please enter the employee code : ";
    std::string emp_code;
    std::cin >> emp_code;

    std::istringstream my_cin{ emp_code };
    std::string dept_code;
    my_cin.width(2);
    my_cin >> dept_code;
    std::string emp_id;
    my_cin.width(3);
    my_cin >> emp_id;
    std::string grade;
    my_cin.width(1);
    my_cin >> grade;
    std::cout << "Employee_Id : " << emp_id << '\n';
    std::cout << "Employee_grade : " << grade << '\n';
    std::cout << "Employee_department_code : " << dept_code << '\n';
}

void filldemo() {
    int i = 99;
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout.fill('*');
    std::cout.width(5);
    std::cout << i << std::endl;
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.fill('#');
    std::cout.width(5);
    std::cout << i << std::endl;
    std::cout.width(5);
    std::cout << i << std::endl;

    i = -14;
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout.fill('0');
    std::cout.width(6);
    std::cout << i << std::endl;
}

void internal_justification() {
    int i{ -55 };
    std::cout.width(6);
    std::cout.setf(std::ios::internal, std::ios::adjustfield);
    std::cout << i << std::endl;

    std::cout.fill('#');
    std::cout.width(6);
    std::cout << i << std::endl;
}


void showpos_demo() {
    int i{ -55 };
    std::cout.fill('*');
    std::cout.width(6);
    std::cout.setf(std::ios::internal, std::ios::adjustfield);
    std::cout << i << std::endl;

    i = +55;
    std::cout.width(6);
    std::cout.setf(std::ios::internal, std::ios::adjustfield);
    std::cout << i << std::endl;


    i = +55;
    std::cout.width(6);
    std::cout.setf(std::ios::internal, std::ios::adjustfield);
    std::cout.setf(std::ios::showpos);
    std::cout << i << std::endl;

    i = +55;
    std::cout.width(6);
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout.setf(std::ios::showpos);
    std::cout << i << std::endl;

    i = -55;
    std::cout.width(6);
    std::cout.setf(std::ios::internal, std::ios::adjustfield);
    std::cout.setf(std::ios::showpos);
    std::cout << i << std::endl;
}

void floating_point_precision() {
    std::cout.flush();
    float f1{ 36 };
    std::cout << "Real number 36    : " << f1 << std::endl;
    float f2{ 36.0 };
    std::cout << "Real number 36.0  : " << f1 << std::endl;
    float f3{ 36.0f };
    std::cout << "Real number 36.0f : " << f3 << std::endl;

    std::cout.setf(std::ios::showpoint);

    std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
    std::cout << "Real number 36    : " << f1 << std::endl;
    std::cout << "Real number 36.0  : " << f2 << std::endl;
    std::cout << "Real number 36.0f : " << f3 << std::endl;

    std::cout.precision(4);
    std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
    std::cout << "Real number 36    : " << f1 << std::endl;
    std::cout << "Real number 36.0  : " << f2 << std::endl;
    std::cout << "Real number 36.0f : " << f3 << std::endl;

    std::cout.precision(10);
    std::cout << "\nCurrent Precision : " << std::cout.precision() << std::endl;
    std::cout << "Real number 36    : " << f1 << std::endl;
    std::cout << "Real number 36.0  : " << f2 << std::endl;
    std::cout << "Real number 36.0f : " << f3 << std::endl;
    f3 = 1234.987f;
    std::cout << "Real number 1234.987f : " << f3 << std::endl;
    std::cout.precision(6);  //revert to default

}


void floating_point_formatting() {

    std::cout.unsetf(std::ios::showpoint);

    std::cout.precision(6);

    float f1{ 36 };
    std::cout << "Real number 36    : " << f1 << std::endl;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);

    std::cout << "Real number 36    : " << f1 << std::endl;

    std::cout.precision(4);

    std::cout << "Real number 36    : " << f1 << std::endl;

    f1 = 30000000;

    std::cout << "Real number 30000000    : " << f1 << std::endl;

    std::cout.precision(2);
    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << "Real number 30000000    : " << f1 << std::endl;

    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << "Real number 30000000    : " << f1 << std::endl;
}


void read_failure() {
    int roll_no{};
    std::cin.unsetf(std::ios::skipws);
    std::cout << "Enter an ingeter :";
    std::cin >> roll_no; /* 34  or 'A' */
    if (std::cin.fail()) {
        std::cerr << "Last read operations has failed!\n";
    }
    else {
        std::cout << "Last read operations has succeeded!\n";
        std::cout << "Roll number : " << roll_no << std::endl;
    }


}

/*by default : skipws skips only whitespace characters (space, tab, enter)*/
void skipws_demo() {
    int roll_no{};
    std::string name{};
    {
        std::cin.unsetf(std::ios::skipws);
        std::cout << "Please enter your Roll number followed by name : ";
        std::cin >> roll_no >> name;
        std::cout << "Roll Number : " << roll_no << "\tName :" << name << std::endl;
    }

    if (std::cin.fail()) {
        std::cerr << "Last read operations has failed!\n";
        std::cerr << "Taking corrective action\n";
        /*reset  all the stream flgs*/
        std::cin.clear();
        /*clears i.e. flushes the stream*/
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    {
        std::cin.setf(std::ios::skipws); //default behavoiur
        std::cout << "Please enter your Roll number followed by name : ";
        std::cin >> roll_no >> name;
        std::cout << "Roll Number : " << roll_no << "\tName :" << name << std::endl;
    }

}

int main()
{
    // boolalphademo();
    // base_demo();
    //  left_right_justification_demo();
    //  cin_width_demo();
    //  filldemo();
    //  internal_justification();
    //  showpos_demo();
    //  floating_point_precision();
    //  floating_point_formatting();
    // read_failure();
    skipws_demo();
}