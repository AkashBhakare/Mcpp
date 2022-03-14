// 37_Pointer_Introduction.cpp : 

#include <iostream>
void size_of_pointers() {
    char* cptr = nullptr;
    int* iptr = nullptr;
    double* dptr = nullptr;
    /*all pointer varaibles of same size and same type*/
    std::cout << "Size of pointer to Character : " << sizeof(cptr) << " bytes\n";
    std::cout << "Size of pointer to Integer : " << sizeof(iptr) << " bytes\n";
    std::cout << "Size of pointer to Double : " << sizeof(dptr) << " bytes\n";
    return;
}

void access_data_indeirectly() {
    char grade{ 'A' };
    std::cout << "Grade:\tAddress : " 
        << reinterpret_cast<unsigned int>(&grade) <<
        "\tValue : " << grade << "\n";
    char* cptr{ &grade };
    std::cout << "Cptr :" <<
        "\nAddres : " << reinterpret_cast<unsigned int>(&cptr) <<
        "\nAddress stored in cptr : " << reinterpret_cast<unsigned int>(cptr) <<
        "\nValue stored at the address stored in cptr : " << *cptr << "\n";

    
    std::cout << "\n\nGrade:\tAddress : " << std::hex
        << reinterpret_cast<unsigned int>(&grade) 
        << "\tValue : " << grade << "\n";
    
    std::cout << "Cptr :" <<
        "\nAddres : " << std::hex << reinterpret_cast<unsigned int>(&cptr) <<
        "\nAddress stored in cptr : " << reinterpret_cast<unsigned int>(cptr) <<
        "\nValue stored at the address stored in cptr : " << *cptr << "\n";
    return;
}

int main()
{
    size_of_pointers();
    access_data_indeirectly();
}

