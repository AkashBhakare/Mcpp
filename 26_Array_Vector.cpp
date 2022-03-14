// 26_Array_Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <array>

void print(auto val) {
    std::cout << val << ", ";
}

void array_initialization() {
    //case1: /*For Fundamental types the value might be undefined */
    {
        std::array<int, 4> my_array; //OOPS: elements of x have undefined value
        for (int element : my_array) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;


    }

    //case 2
    /*You can providen an empty initializer list insted. in That case,
    all values are guaranteed to be value initialized, which has the effect that elements
    of fundamental types are zero initialized:*/
    {
        std::array<int, 4> my_array = {}; //ok: all elements of x have value 0 (int)
        for (int element : my_array) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    /*case3: you can an initializer list to initialize an array when it got created.
    they elements in initializer list must have the same type, or there must be a
    type conversion to the element type of the array defined*/
    {
        std::array<int, 4> my_array = { 42,377,611,21 };
        for (int element : my_array) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    /*Case4: If an initializer list does not have enough elements,
    the elements in the array are initialized via the default constructor of the element type.
    int this case, it is guaranteed that that for fundamental data types the elements are zero initialized */
    {
        std::array<int, 4> my_array = { 42 };
        for (int element : my_array) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    }

    /*Case5: If the number of elements in the initializer lists is higher than the size of the array,
    the expression is ill - formed:*/
    {
        //std::array<int, 5> c3 = { 1,2,3,4,5,6 }; //ERROR:Too many values
    }


    // case 6:
    //C++17 onward : support type deduction
    {
        std::array<int, 4> marks{ }; //before c++17
        std::array precentages{ 67.8,77.9,88.6,55.7 }; //since C++17
        for (auto element : precentages) {
            std::cout << element << ' ';
        }
        std::cout << std::endl;

        //std::array weights{ 45.6,66.7,70,56.7 }; //Error:all Elements Have to be of same type
        //std::array<int, 4> weights{ 45.6,66.7,70,56.7f };
    }

    {
        std::cout << std::boolalpha;
        std::cout << "double to int ? " << std::is_convertible_v<double, int> << '\n';
        std::cout << "int to int ? " << std::is_convertible_v<int, double> << '\n';
        std::cout << "int to int ? " << std::is_convertible_v<int, std::string> << '\n';

    }
}


void array_iteration() {
    /*Case: 1
    Likely signed/usigned mismatch in this code! Due to a curious decision,
    the size() function ands array index parameter to operator[] use a type called size_type*/
    {
        std::array myArray{ 7,3,1,9,5 };

        //Iterate through the array ans print the v alue the element
        for (int i{ 0 }; i << myArray.size(); ++i) {//Warning
            std::cout << myArray[i] << ' ';
        }
        std::cout << '\n';
    }
    /*Case 2:
    std::array<int, 5>::size_type is the retirn type of size()*/
    {
        std::array myArray{ 7,3,1,9,5 };
        for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i) {
            std::cout << myArray[i] << ' ';
        }
        std::cout << '\n';

        //std::array weights{ 45.6,66.7,70,56.7 };
    }
}
    


void  array_operations_access() {
    //Accessing element
    std::array marks{ 66,77,88,99 };

    //using index of operator []
    std::cout << "1st subject : " << marks[0] << '\n';
    std::cout << "4st subject : " << marks[3] << '\n';

    //using method at()
    std::cout << "1st subject : " << marks.at(0) << '\n';
    std::cout << "4st subject : " << marks.at(3) << '\n';

    //incorrect subscript result in undefined behaviour but no error
    std::cout << "last subject : " << marks[4] << '\n';
    std::cout << "first subject : " << marks[-1] << '\n';

    //any attempt subscript result in undefined behaviour but no error
    //std::cout << "4st subject : " << marks.at[4] << '\n';
    //std::cout << "1st subject : " << marks.at[-1] << '\n';

}
void array_fill() {
    std::array marks{ 66,77,88,99 };
    for (auto mark : marks) {
        std::cout << mark << ' ';
    }
    std::cout << std::endl;

    marks.fill(80);
    for (auto mark : marks) {
        std::cout << mark << ' ';
    }
    std::cout << std::endl;
}

void array_swap() {
    std::array luckynos{ 3,13,31,39 };
    std::array unluckynos{ 10,20,30,40 };
    std::cout << "Lucky Numbers : \n";
    for (auto number : luckynos) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    std::cout << "Unlucky Numbers : \n";
    for (auto number : unluckynos) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;

    std::cout << "After swapping\n";

    luckynos.swap(unluckynos);
    /*Swap the contain*/
    std::cout << "Lucky Numbers : \n";
    for (auto number : luckynos) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
    std::cout << "Unlucky Numbers : \n";
    for (auto number : unluckynos) {
        std::cout << number << ' ';
    }
    std::cout << std::endl;
}

void print_array(int* ptr, size_t size) {
    for (size_t idx{}; idx < size; ++idx) {
        std::cout << ptr[idx] << '\n';
    }
    std::cout << std::endl;
}

void array_access_data() {
    int a[]{ 12,45,67,89 };
    print_array(a, std::size(a));

    std::array even_nos{ 2,4,6,8,10 };
    //print_array(even_nos, even_nos.size());
    print_array(even_nos.data() , even_nos.size());
}

void creat_array() {
    //C-style array
    char vowels[]{ 'a','e','i','o','u' };//charater array

    auto my_vowels = std::to_array(vowels);
    for (char vowel : my_vowels) {
        std::cout << vowel << ", ";
    }
    std::cout << '\n';

    double values[]{ 34.0,56.7,44.5 };

    auto my_values = std::to_array(values);
    for (auto value : values) {
        std::cout << value << ", ";
    }
    std::cout << '\n';

    char v[] = "AEIOU"; //C-string : character array terminated with '\0'
    auto my_array = std::to_array(v);
    for (auto value : my_array) {
        std::cout << value << ", ";
    }
    std::cout << '\n';

    int numbers[]{ 10,20,30,40,50,60,70,80,90,100 };
    auto my_numbers = std::to_array(numbers)[5];
    std::cout << my_numbers;
   /* for (auto value : my_numbers) {
        std::cout << value << ", ";
    }*/
}

int main()
{
    //array_initialization();
    //array_iteration();
    //array_operations_access();
    //array_fill();
    //array_swap();
    //print_array();
    //array_access_data();
    creat_array();
}
