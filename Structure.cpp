// Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <iomanip>
void structure_introduction();
void aggregate_initialization();
void accessing_struct_members();
void struct_layout();
void alignment();
void alignas_demo();
void compact_struct();
void struct_bit_fields();
void struct_encapsulation();

int main()
{
    //structure_introduction();
    //accessing_struct_members();
    //alignment();
    //struct_layout();
    //alignas_demo();
    //compact_struct();
    //struct_bit_fields();
    //struct_encapsulation();
    return EXIT_SUCCESS;
}

void structure_introduction() {
    /*Structure Declaration : giving the compiler information about the design of
    new userdefied data type*/
    struct Point {
        int x;   //structure element (member)
        int y;   //struct element(member)
    }p1; //structure variable

    std::cout << "Size of Struct Point : " << sizeof(struct Point) << " bytes\n";
    std::cout << "Size of Struct Point : " << sizeof(Point) << " bytes\n";
    std::cout << "Size of Struct Point : " << sizeof(p1) << " bytes\n";

    /*Defining Structure Variable*/
    struct Point p2;
    // uninitialized local variable 'p2' used
   // std::cout << "x : " << p2.x << "\ty : " << p2.y << std::endl;

    //Default initialization of members will be done
    Point p3{};
    std::cout << "x : " << p3.x << "\ty : " << p3.y << std::endl;

    Point p4{ 1 }; // y is implicitly initialized to 0
    std::cout << "x : " << p4.x << "\ty : " << p4.y << std::endl;

    struct Point p5 { 10, 20 };
    std::cout << "x : " << p5.x << "\ty : " << p5.y << std::endl;

    //use of designated initializers requires at least '/std:c++latest
    Point p6{ .x = 5, .y = 6 };
    std::cout << "x : " << p6.x << "\ty : " << p6.y << std::endl;

    //designators must appear in member declaration order of class/struct
    //struct Point p7 { .y = 5, .x = 6 };
    return;

}

void aggregate_initialization() {
    struct Employee
    {
        int id{};
        int age{};
        double wage{};
    };

    Employee faizal = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee raju(3, 45, 62500.0);  // direct initialization using parenthesized list (C++20)
    Employee jay{ 2, 28, 45000.0 };     // list initialization using braced list (preferred)
    Employee aman{ 2, 28 }; // aman.wage will be value-initialized to 0.0

    //Assignment with an initializer list
    aman = { aman.id, 33, 66000.0 }; // Aman had a birthday and got a raise

 //Assignment with designated initailizers C++20
    aman = { .id = aman.id, .age = 3, .wage = 77000.0 }; // aman had a birthday and got a raise

}

void accessing_struct_members() {
    /*Structure Declaration : No memory is allocated when a structure is declared */
    struct Point {
        int x;
        int y;
    };

    /*Defining a structure variable*/
    struct Point p1 { 10, 20 };
    Point p3{ 20, 30 };

    /*access structure member using dot operator along with structure variable
        structure_variable.member;
     */
    std::cout << "x : " << p3.x << "\ty : " << p3.y << std::endl;

    //Accessing using pointer ot structure
    Point* ptr = &p1;
    /*
      The arrow operator (->) is a dereference operator that is used
      exclusively with pointers to objects
      Access structure member using -> operator along with pointer to structure variable
          pointer_to_structure->member;
       */
    std::cout << "x : " << ptr->x << "\ty : " << ptr->y << std::endl;

    //Address of the Structure
    std::cout << "Address of p1 : " << &p1 << std::endl;
    std::cout << "Address of p1 : " << ptr << std::endl;

    //Address of Structure Members using structure variable
    std::cout << "Address of p1.x : " << &(p1.x) << std::endl;

    // dot operator has higher precedence than &
    std::cout << "Address of p1.x : " << &p1.x << std::endl;
    std::cout << "Address of p1.y : " << &p1.y << std::endl;

    std::cout << "Address of ptr->x : " << &(ptr->x) << std::endl;
    // -> operator has higher precedence than &
    std::cout << "Address of ptr->x : " << &ptr->x << std::endl;
    std::cout << "Address of ptr->y : " << &ptr->y << std::endl;


    return;

}

void alignment() {
    /*
    An object doesn’t just need enough storage to hold its representation.
    In addition, on some machine architectures, the bytes used to hold it
    must have proper alignment for the hardware to access it efficiently
    (or in extreme cases to access it at all)
    The alignof() operator returns the alignment of its argument expression
    */
    char c_var1 = 'A';
    std::cout << "Size of c_var1 : " << sizeof(c_var1) << " bytes\n";
    std::cout << "Address of c_var1 : "
        << std::showbase << std::hex
        << reinterpret_cast<unsigned long long>(&c_var1) << "\t"
        << std::dec << reinterpret_cast<unsigned long long>(&c_var1)
        << std::endl;
    char c_var2 = 'A';
    std::cout << "Address of c_var2 : "
        << std::showbase << std::hex
        << reinterpret_cast<unsigned long long>(&c_var2) << "\t"
        << std::dec << reinterpret_cast<unsigned long long>(&c_var2)
        << std::endl;

    std::cout << "Alignment of char variable   : " << alignof(char) << std::endl;
    std::cout << "Alignment of int variable    : " << alignof(int) << std::endl;
    std::cout << "Alignment of double variable : " << alignof(double) << std::endl;
    //constant not allowed
    //std::cout << "Alignment of double variable : " << alignof(4.5) << std::endl;
    return;

}


void struct_layout() {
    // An object of a struct holds its members in the order they are declared
    struct Readout {
        char hour; // [0:23]
        int  value;
        char seq; // sequence mark ['a':'z']
    };

    std::cout << "Size of struct Readout : " << sizeof(Readout) << " bytes\n";
    //Members are allocated in memory in declaration order, 
    struct Writeout {
        int  value;
        char hour;
        char seq;
    };
    std::cout << "Size of struct Writeout : " << sizeof(Writeout) << " bytes\n";

    struct ReadIn {
        char hour;      // 7 slack bytes
        double value;   // 0 slack bytes
        char seq;       // 7 slack bytes
    };
    std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";

    /*
    You can minimize wasted space by simply ordering members by size
    (largest member first).
    */
    struct WriteIn {
        double value;   // 0 slack bytes
        char hour;      // 0 slack bytes
        char seq;       // 6 slack bytes
    };
    std::cout << "Size of struct WriteIn : " << sizeof(WriteIn) << " bytes\n";

    //so the address of hour must be less than the address of value.


    /*
    * the size of an object of a struct is not necessarily the sum of the sizes of
    its members. This is because many machines require objects of certain types
    to be allocated on architecture dependent boundaries or handle such objects
    much more efficiently if they are.
    For example, integers are often allocated on word boundaries. On such machines,
    objects are said to have to be properly aligned. This leads to ‘‘holes’’ (slack bytes)
    in the structures.

    */
}

void  alignas_demo() {

    struct alignas(16) ReadIn {
        char hour;     // 15 slack bytes
        double value;  // 0 slack byte
        char seq;      // 7 slack bytes
    };
    std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";

    struct alignas(double) WriteIn {
        char hour;     // 7 slack bytes
        double value;  // 0 slack byte
        char seq;      // 7 slack bytes
    };
    std::cout << "Size of struct ReadIn : " << sizeof(WriteIn) << " bytes\n";


    struct alignas(double) WriteOut {
        double value;  // 0 slack byte
        char hour;     // 0 slack bytes
        char seq;      // 6 slack bytes
    };
    std::cout << "Size of struct WriteOut : " << sizeof(WriteOut) << " bytes\n";
}

#pragma ms_struct off

void compact_struct() {
    struct ReadIn {
        char cdata1; // 3
        int  idata;  // 0
        char cdata2; // 3
    };
    std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";

    /*
    //Works under linux __attribute__((__packed__))
    struct WriteOut {
         char cdata1;
         int  idata;
         char cdata2;
     }__attribute__((__packed__));
     std::cout << "Size of struct WriteOut : " << sizeof(WriteOut) << " bytes\n";*/

}

void struct_bit_fields() {
    struct HotelGuestProfile {
        int8_t isVeg;
        int8_t isAlcoholic;
        int8_t isSmoker;
        int8_t isFrequentFlyer;
        int8_t isIndianCitizen;
        int8_t isAdult;
        int8_t isEmployed;
        int8_t isMarried;
    };
    std::cout << "Size of struct HotelGuestProfile : " << sizeof(HotelGuestProfile) << " bytes\n";
    struct GuestProfileFlags {
        int8_t isVeg : 1;
        int8_t isAlcoholic : 1;
        int8_t isSmoker : 1;
        int8_t isFrequentFlyer : 1;
        int8_t isIndianCitizen : 1;
        int8_t isAdult : 1;
        int8_t isEmployed : 1;
        int8_t isMarried : 1;
    };
    std::cout << "Size of struct GuestProfileFlags : " << sizeof(GuestProfileFlags) << " bytes\n";
    GuestProfileFlags gp{};


    auto profile = std::bitset<8>(reinterpret_cast<char*>(&gp));
    std::cout << "Is alcoholic : " << std::boolalpha << profile.test(2)
        << std::endl;
    profile.set(2, true);
    std::cout << "Is alcoholic : " << std::boolalpha << profile.test(2)
        << std::endl;


    struct StudentProfile {
        int grade : 3;
        int rollNo : 5;
    };
    std::cout << "Size of struct StudentProfile : " << sizeof(StudentProfile) << " bytes\n";
    StudentProfile sp1{ 3, 29 };
    std::cout << "Grade :" << sp1.grade << "\tRoll No." << sp1.rollNo << std::endl;

    int* ptr = reinterpret_cast<int*>(&sp1);
    std::cout << "235 : " << std::bitset<8>(*ptr) << std::endl;
    std::cout << "Grade   :" << ((*ptr << 29) >> 29) << std::endl;
    std::cout << "Roll no :" << (*ptr >> 3) << std::endl;


    auto sprofile = std::bitset<8>(*(reinterpret_cast<char*>(&sp1)));

    std::cout << "Grade   :" << ((sprofile << 5) >> 5).to_ullong() << std::endl;
    std::cout << "Roll no :" << (sprofile >> 3).to_ullong() << std::endl;

    std::cout << "************";
}

void struct_encapsulation() {
    struct Student {
        std::string name;
        int roll;
        float percentage;
    };

    Student s1{ "Raja",12,78.9F };
    std::cout << "Name       : " << s1.name << std::endl;
    std::cout << "Roll no    : " << s1.roll << std::endl;
    std::cout << "Percentage : " << s1.percentage << std::endl;

    s1.roll = -89;
    s1.percentage = 788.9F;
    std::cout << "Name       : " << s1.name << std::endl;
    std::cout << "Roll no    : " << s1.roll << std::endl;
    std::cout << "Percentage : " << s1.percentage << std::endl;

    struct StudentDetails {
    private:
        std::string _name;
        int _roll;
        float _per;
    public:
        StudentDetails(std::string name, int roll, float per) {
            _name = name;
            _roll = roll;
            _per = per;
        }

        std::string getName() {
            return _name;
        }

        int getRoll() {
            return _roll;
        }

        float getPercentage() {
            return _per;

        }

        void setName(std::string name) {
            _name = name;
        }

        void setRoll(int roll) {
            if (roll > 0 && roll < 30) {
                _roll = roll;
            }
            else {
                std::cerr << "Incorrect Roll number supplied!\n";
            }
        }

        void setPercentage(float per) {
            if (per >= 0 && per <= 100) {
                _per = per;
            }

        }

    };

    StudentDetails sd1{ "Rani",12,78.9F };
    std::cout << "Name       : " << sd1.getName() << std::endl;
    std::cout << "Roll no    : " << sd1.getRoll() << std::endl;
    std::cout << "Percentage : " << sd1.getPercentage() << std::endl;

    sd1.setName("Rameshwari");
    sd1.setRoll(13);
    sd1.setPercentage(189.6F);
    std::cout << "Name       : " << sd1.getName() << std::endl;
    std::cout << "Roll no    : " << sd1.getRoll() << std::endl;
    std::cout << "Percentage : " << sd1.getPercentage() << std::endl;

}