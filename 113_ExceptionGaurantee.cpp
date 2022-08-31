// 113_ExceptionGaurantee.cpp : 
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

//bool copy_basic(char src[], char dest[]) {
//
//}

/*Provides only basic Gaurantee*/
bool copy_basic(char* src_ptr, char* dest_ptr) {
	size_t i{};
	while (*(src_ptr + i) != '\0') {
		*(dest_ptr + i) = *(src_ptr + i);
		++i;
	}
	*(dest_ptr + i) = '\0';
	return true;
}

void copy_strong(std::string src, std::array<char, 20>& dest) {
	std::array<char, 20> temp;
	//std::cout << "Max size : " << temp.max_size();
	auto ptr = src.begin();
	size_t i{};
	while (ptr != src.end()) {
		if (i >= temp.max_size() - 1) {
			throw std::out_of_range("Source too large");
		}
		temp[i++] = *ptr;

		ptr++;
	}
	temp[i] = '\0';
	dest = std::move(temp);

}

int main()
{
	//    {
	//        char src[50];
	//        char dest[20];
	//        std::cout << "Please enter the string : ";
	//        std::cin.getline(src, sizeof(src));
	//        std::cout << "Source String (before Copying) :" << src << std::endl;
	//        copy_basic(src, dest);
	//        std::cout << "Source String (after Copying)  :" << src << std::endl;
	//        std::cout << "Destination String (after Copying) :" << dest << std::endl;
	//    }
		 //Strong
	{
		std::string src_string;
		std::array<char, 20> dest{ 'a','b','c' };
		std::cout << "Please enter the string : ";
		std::getline(std::cin, src_string);
		std::cout << "Source String (before Copying) :" << src_string << std::endl;
		std::cout << "Destination String (before Copying) :";
		for (size_t i = 0; i < dest.size(); i++) {
			std::cout << dest[i];
		}
		std::cout << "\n";
		try {
			copy_strong(src_string, dest);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Source String (after Copying)  :" << src_string;//std::endl;
		std::cout << "Destination String (after Copying) :";
		for (size_t i = 0; dest[i] != '\0'; i++) {
			std::cout << dest[i];
		}
		std::cout << "\n";
	}
}
