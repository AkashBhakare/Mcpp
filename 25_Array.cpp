// 25_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iterator>
#include<valarray>
#include<cmath>


/* Data_tyoe <array_name>[<size>]*/

void defining_array() {
    /*Group of 5 variable of type integer*/
    int marks[5];
    std::cout << "Intitial contents of the array : \n";
    for (int index{ 0 }; index < 5; ++index) {
        std::cout << "marks : " << marks[index]  <<  "\n";
    }

    // Assigning values to array
    marks[0] = 92;
    marks[1] = 77;
    marks[2] = 73;
    marks[3] = 67;
    marks[4] = 53;

    std::cout << "Contents of the  array after assignment : \n";
    for (int element : marks) {
        std::cout << "Marks : " << element << "\n";
    }
}

void array_size() {
    char grades[5];  // syntatically correct but not appropriate

    constexpr int number_of_subjects{ 5 };
    char grade[number_of_subjects];
    std::cout << "Size of charater array : " << sizeof(grade) << "bytes\n";

    double distances[10];
    std::cout << "Size of double array : " << sizeof(distances) << "bytes\n";
    std::cout << "Number of element int the array : " << sizeof(distances) / sizeof(distances[0]) << "bytes\n";

    size_t number_of_distances = sizeof(distances) / sizeof(distances[0]);
    for (size_t index{ 0 }; index < number_of_distances; ++index) {
        std::cout << "distance : " << distances[index] << "\n";
    }
}

void array_initialization() {
    /*We cannot define array without specifying size
    *char vowels[];
    */

    char vowels[5]{ 'a','e','i','o','u' };
    std::cout << "The characters in the array are as follows : \n";
    for (char vowel : vowels) {
        std::cout << "\t" << vowel << "\n";
    }

    /*Number of initializers determine the size of the arrays*/
    char consonants[]{ 'q','w','r','t','y','p' };
    std::cout << "The consonants in the array are as follows : \n";
    for (char consonant : consonants) {
        std::cout << "\t" << consonant << "\n";
    }

    int marks[]{ 34,45,44,47,50 };
    std::cout << "The Marks are as the follows : \n";
    for (int mark : marks) {
        std::cout << "\t" << mark << "\n";
    }
    //total size of array must not exceed 0x7fffffff bytes
    // double big_array[1000000000ll]{};
    std::cout << 0x7fffffff;
}

/*We can overcome the limitiation of need to specify the array size at compile time by 
memory for array at runtime on heap*/
void heap_based_array() {
    int number_students{};
//  int marks[number_students]
    std::cout << "How many stuedents marks do you want to store ?";
    std::cin >> number_students;

    int* marks = new int[number_students];

    std::cout << "please the enter the marks of " << number_students << "students\n";
    for (int idx{ 0 }; idx < number_students; ++idx) {
        std::cout << "Student number : " << (idx + 1) << ": ";
        std::cin >> marks[idx];
    }
    
    std::cout << "Students marks are follows\n";
    for (int idx{ 0 }; idx < number_students; ++idx) {
        std::cout << "Student number : " << (idx + 1) << "Marks : " << marks[idx] << "\n";
    }

    delete[] marks; //Compulsory

}

//void  passing_array(int score[6])
//void  passing_array(int score[])
void  passing_array(int* score) {
    std::cout << "The contents of teh array area as follows : \n";
    std::cout << "The size of the array is : " << sizeof(score) << " bytes\n";
    size_t size = sizeof(score) / sizeof(score[0]);
    std::cout << "The number of elements in the arrays is : " << size << '\n';
    for (size_t counter{ 0 }; counter < size; ++counter) {
        std::cout << score[counter] << '\n'  ;
    }
}

void passing_array_correctly(int score[], size_t number_of_elements) {
    std::cout << "The content of the array is : \n";
    for (size_t counter{ 0 }; counter < number_of_elements; ++counter) {
        std::cout << score[counter] << '\n';
    }
    
}

void     std_size_demo() {
    int a[] = { -5, 10, 15 };
    std::cout << "Number of elements in the arays is : " << std::size(a) << '\n';

    std::cout << "Traversing array i ascending order using std::size() \n";
    //since c++17: std::size() return the size of the given container or array
    size_t size = std::size(a);
    for (size_t index{ 0 }; index < size; ++index) {
        std::cout << "element : " << a[index] << "\n";
    }

    /*std::cout << "Traversing array in descending order using std::size() \n";
    for (auto index = (std::size(a) - 1); index >= 0; --index) {
        std::cout << "element : " << a[index] << "\n";
    }*/


    std::cout << "Traversing array in descending order using std::size() \n";
    //since c++20 the signed size (ssize) can avail
    auto idx = std::ssize(a);
    for (--idx; idx != - 1; --idx) {
        std::cout << a[idx] << (idx ? ", " : "\n");
    }
    std::cout << "index = " << idx << '\n';

}

void  working_with_arrays() {
    int a[]{ 10,20,30 };
    int b[]{ 3,4,5 };
    //std::cout << "Addition of arrays a+b: " << a + b << '\n';
    //std::cout << "Addition of arrays a*b: " << a * b << '\n';
    // a = a + 5;
    int c[3];
    for (size_t idx{ 0 }; idx < std::size(a); ++idx) {
        c[idx] = a[idx] + b[idx];
    }


    std::cout << "The result ofter addition of array : \n";
    for (int element : c) {
        std::cout << element << ',';

    }
    std::cout << '\n';

    float degrees[]{ 180,115,90 };
    std::cout << "Sine of the values are :\n";
    for (float deg : degrees) {
        std::cout << "Since of " << deg << "degree : " << std::sin(deg * (std::numbers::pi / 180)) << '\n';
    }
    std::cout << '\n';

}

void valarray_demo() {
    std::valarray < float > v = { 1,2,3 };
    std::valarray < float > w = { 7,8,9 };
    auto s = v * w;
    std::cout << "Result of multiplying two valarray : \n";
    for (float element : s) {
        std::cout << element << ' ';

    }
    std::cout << '\n';
    std::valarray < float > addition1 = v + w; //okay
    auto addition2 = v + w;                     //recommended
    std::cout << "Result of addition two valarray : \n";
    for (float element : addition2) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    auto x = v + 5;
    std::cout << "Result of addition of 5 to valarray : \n";
    for (float element : x) {
        std::cout << element << ',';
    }
    std::cout << '\n';
}


int main()
{
    /*defining_array();
    array_size();
    array_initialization();
    heap_based_array();*/
    //std_size_demo();
    //int score[]{ 67,89,65,87,78 };
    //passing_array(score);
    //passing_array_correctly(score, (sizeof(score) / (sizeof(score[0)));
    //passing_array_correctly(score, std::size(score));
    //working_with_arrays();
    
    
    valarray_demo();

}
