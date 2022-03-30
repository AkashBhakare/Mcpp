// 44_Lvalue_Rvalue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
int gbl_var = 100;
void difficulty_with_pointers();
void good_old_references();
void very_basic_definition();
void bit_more_detailed_definition();
int& foo(void);
int foobar(void);
void passing_argument();

void increment_by(int, int, int incre_by); //by value
void increment_by(int*, int*, int incre_by); //by reference using pointer
void decrement_by(int&, int&, int decre_by); //by referecen using reference
void print(const int&, const int&);
void major_diff__pointer_reference();
void scenario_where_ref_are_recommended();

struct Student {
    int roll;
    float per;
    char name[50];
    char address[200];
    unsigned long long tel;
};

void print_student_details(Student);
void show_student_details(const Student&);

int main()
{
    //  difficulty_with_pointers();
    //  good_old_references();
    //  passing_argument();
    //  major_diff__pointer_reference();
    //  scenario_where_ref_are_recommended();
    //  very_basic_definition();
    bit_more_detailed_definition();
    return 0;
}

void difficulty_with_pointers() {

    int ivar = 10;
    std::cout << "Address of Variable ivar :" << &ivar << std::endl;
    std::cout << "Access the value using variable name :" << ivar << std::endl;
    /*Pointer arithmetics are confusing and source of errors*/
    int* iptr = &ivar;
    std::cout << "Address of Variable ivar using pointer :" << iptr << std::endl;
    std::cout << "Access the value using pointer :" << *iptr << std::endl;
    *iptr = 45;
    std::cout << "Access the value using pointer :" << *iptr << std::endl;
    //*iptr++; //incremented the pointer
    (*iptr)++; //increments the value pointed by pointer
    std::cout << "Access the value using pointer :" << *iptr << std::endl;
    ++* iptr;  //increments the value pointed by pointer
    std::cout << "Access the value using pointer :" << *iptr << std::endl;
    --* iptr;  //increments the value pointed by pointer
    std::cout << "Access the value using pointer :" << *iptr << std::endl;
}

void good_old_references() {
    int ivar = 10;
    std::cout << "Address of Variable ivar :" << &ivar << std::endl;
    std::cout << "Access the value using variable name :" << ivar << std::endl;
    // defining a reference
    int& iref1 = ivar;
    std::cout << "Address of Variable iref1 :" << &iref1 << std::endl;
    //References are like pointers that are by default dereferenced
    // iref is internally interpreted as (*iref)
    std::cout << "Access the value using variable name :" << iref1 << std::endl;
    iref1 = 99;
    int x = iref1;
    std::cout << "Value of ivar  :" << ivar << std::endl;
    std::cout << "value of iref1 :" << iref1 << std::endl;
    // addtional reference to ivar
    int& iref2 = ivar;
    std::cout << "Address of Variable iref2 :" << &iref2 << std::endl;
    std::cout << "value of iref2 :" << iref2 << std::endl;

    iref2 = 77;
    std::cout << "Value of ivar  :" << ivar << std::endl;
    std::cout << "value of iref1 :" << iref1 << std::endl;
    std::cout << "value of iref2 :" << iref2 << std::endl;

    iref1++;
    std::cout << "Value of ivar  :" << ivar << std::endl;
    std::cout << "value of iref1 :" << iref1 << std::endl;
    std::cout << "value of iref2 :" << iref2 << std::endl;
    --iref1;
    std::cout << "Value of ivar  :" << ivar << std::endl;
    std::cout << "value of iref1 :" << iref1 << std::endl;
    std::cout << "value of iref2 :" << iref2 << std::endl;
}

void passing_argument() {
    int i1num = 10;
    int i2num = 20;
    increment_by(i1num, i2num, 5); //call by value
    std::cout << "i1num :" << i1num << "\ti2num :" << i2num << std::endl;
    increment_by(&i1num, &i2num, 5); //call by reference using pointer
    std::cout << "i1num :" << i1num << "\ti2num :" << i2num << std::endl;
    decrement_by(i1num, i2num, 3);  //call by reference using references
    std::cout << "i1num :" << i1num << "\ti2num :" << i2num << std::endl;
    print(i1num, i2num);
    std::cout << "i1num :" << i1num << "\ti2num :" << i2num << std::endl;
}

void increment_by(int i1num, int i2num, int incre_by) {
    i1num += incre_by;
    i2num += incre_by;
    return;
}

void increment_by(int* iptr1, int* iptr2, int incre_by) {
    *iptr1 = *iptr1 + incre_by;
    *iptr2 = *iptr1 + incre_by;
    return;
}

void decrement_by(int& iref1, int& iref2, int decre_by)
{
    iref1 = iref1 - decre_by;
    iref2 = iref2 - decre_by;
}

void print(const int& iref1, const int& iref2)
{
    std::cout << iref1 << "\t" << iref2 << "\n";
    /*  iref1++;
      --ref2;*/
}

void very_basic_definition() {
    /*
    * An lvalue is an expression e that may appear on the left
      or on the right hand side of an assignment, whereas an rvalue
      is an expression that can only appear on the right hand side
      of an assignment.
    */
    int a = 42;
    int b = 43;
    // 42 = a;  //illegal; Rvlaue is non-assignable

    // a and b are both l-values: because they have storage location
    a = b; // ok
    b = a; // ok
    a = a * b; // ok

    // a * b is an rvalue:
    int c = a * b; // ok, rvalue on right hand side of assignment
   // a * b = 42; // error, rvalue on left hand side of assignment

    //non-assignable lvalue
    const int d = 10; // d has an storage location therefore its lvalue
   // d = 66; // expression on left must be assignable lvalue

    int* iptr = nullptr;
    // *iptr = 77; //undefined behavious.. but *iptr is lvalue

    char str[10] = "Impetus"; //rvalue with address
    printf("Address of str = %p\n", str);
    printf("Character = %c\n", str[1]);    // *(str+1)
    printf("Character = %c\n", *(str + 1));
    printf("Address of \'Impetus\'= %p \n", "Impetus");
    printf("Character = %c\n", "Impetus"[1]);
    str[1] = 'Q';
    //"Impetus"[1] = 'Q'; // R-Value is non-assignable
    std::string m = std::move("I l u");
    return;
}

void major_diff__pointer_reference() {
    int* iptr; //pointer may not be inititalized
    //references must be initialized
    //int& iref;

    int ivar1 = 99;
    int ivar2 = 22;
    /*Pointers can hold address of diffrent variables at different times*/
    iptr = &ivar1;
    std::cout << "*ptr : " << *iptr << std::endl;
    iptr = &ivar2;
    std::cout << "*ptr : " << *iptr << std::endl;
    /*References refer to the same variable throughouts its life time*/
    int& iref = ivar1;
    std::cout << "iref : " << iref << std::endl;
    // &iref = ivar2;
    iref = ivar2; // *iref1 = ivar2
    std::cout << "iref  : " << iref << std::endl;
    std::cout << "ivar1 : " << ivar1 << std::endl;


}
void scenario_where_ref_are_recommended()
{
    Student s{ 12,77.88f,
        "Sairam",
        "Nanded city, near Gurudwara, lane no5, block no 14",
        88899664433ull };
    std::cout << "Address of variable s :" << &s << std::endl;
    print_student_details(s);
    show_student_details(s);
}

void print_student_details(Student temp) {
    std::cout << "Address of variable temp :" << &temp << std::endl;
    std::cout << "Name : " << temp.name << "\n" <<
        "Roll No:" << temp.roll << "\n" <<
        "Percentage :" << temp.per << "\n" <<
        "address :" << temp.address << "\n";
    return;

}

/*since the reference is declared const it will not be allowed to
change the data that is refers to*/
void show_student_details(const Student& ref) {
    std::cout << "Address of variable ref :" << &ref << std::endl;
    std::cout << "Name : " << ref.name << "\n" <<
        "Roll No:" << ref.roll << "\n" <<
        "Percentage :" << ref.per << "\n" <<
        "address :" << ref.address << "\n";
    return;

}

void bit_more_detailed_definition() {
    /*
    *  An lvalue is an expression that refers to a memory location
       and allows us to take the address of that memory location via
       the & operator.
       An rvalue is an expression that is not an lvalue.
    */

    // lvalues:

    int i = 42;
    i = 43; // ok, i is an lvalue
    int* p = &i; // ok, i is an lvalue
    int& foo();
    foo() = 42; // ok, foo() is an lvalue
    int* p1 = &foo(); // ok, foo() is an lvalue

    // rvalues:

    int foobar();
    int j = 0;
    j = foobar(); // ok, foobar() is an rvalue
    //foobar() = 42;  // error; foobar() is an rvalue
    //int* p2 = &foobar(); // error, cannot take the address of an rvalue
    j = 42; // ok, 42 is an rvalue
}

int& foo(void) {
    gbl_var = 99;
    return gbl_var;
}

int foobar(void) {
    return 10;
}