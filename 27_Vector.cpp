// 27_Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int>& v) {
    for (auto element : v) {
        std::cout << element << ", ";
    }
    std::cout << "\n";
}

void print_meta_data(std::vector<double>& v) {
    std::cout << "Size of Marks : " << v.size() << '\n';
    std::cout << "Capacity of Marks : " << v.capacity() << '\n';

}

void  vector_basics() {
    std::vector<int> marks;
    std::cout << "Size of Marks : " << marks.size() << '\n';
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    std::cout << "Size of Marks : " << marks.size() << '\n';
    print(marks);
    std::cout << "Capacity of Marks : " << marks.capacity() << '\n';
    marks.push_back(40);
    marks.push_back(50);
    marks.push_back(60);
    marks.push_back(70);
    std::cout << "Size of Marks : " << marks.size() << '\n';
    std::cout << "Capacity of Marks : " << marks.capacity() << '\n';

    //Extra memory can be returned to the system via a call to shrink_to_fit()
    marks.shrink_to_fit();
}

void vector_memory() {
    std::vector<double> v1;
    std::cout << "Size of v1 : " << v1.size() << '\n';
    std::cout << "Capacity of v1 : " << v1.capacity() << '\n';

    std::cout << "After reserving the memory\n";
    v1.reserve(10); //memory allocated to hold 10 double values
    std::cout << "Size of v1 : " << v1.size() << '\n';
    std::cout << "Capacity of v1 : " << v1.capacity() << '\n';

    std::cout << "After Storing 10 values\n";
    for (int i{ 1 }; i <= 10; ++i) {
        v1.push_back(std::sqrt(i * 10));
    }
    std::cout << "Size of v1 : " << v1.size() << '\n';
    std::cout << "Capacity of v1 : " << v1.capacity() << '\n';

    std::cout << "After resizing vector\n";
    v1.resize(6);
    std::cout << "Size of v1 : " << v1.size() << '\n';
    std::cout << "Capacity of v1 : " << v1.capacity() << '\n';
    
    std::cout << "After shrinking vector\n";
    v1.shrink_to_fit();
    std::cout << "Size of v1 : " << v1.size() << '\n';
    std::cout << "Capacity of v1 : " << v1.capacity() << '\n';

}

int main()
{
    //vector_basics();
    vector_memory();
}

