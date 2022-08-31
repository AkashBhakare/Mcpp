// 118_ExceptionGaurantee.cpp :
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>


/*Provides only basic Gaurantee*/
bool copy_basic(const char* src_ptr, char* dest_ptr, size_t dest_size) {
	size_t i{};
	try {
		while (*(src_ptr + i) != '\0') {
			*(dest_ptr + i) = *(src_ptr + i);
			if (i == (dest_size - 1)) {
				//break;
				throw std::out_of_range("Destination array is full!\n");
			}
			++i;
		}
	}
	catch (std::out_of_range err) {
		std::cout << err.what() << std::endl;
	}
	*(dest_ptr + i) = '\0';
	return true;
}

void copy_strong(const std::string& src_ref, std::array<char, 20>& dest) {
	std::array<char, 20> temp{};
	//std::cout << "Max size : " << temp.max_size();
	auto ptr = src_ref.begin();
	size_t i{};
	while (ptr != src_ref.end()) {
		if (i >= temp.size()) {
			throw std::out_of_range("Source too large! Cpying operation hs failed\n");
		}
		temp[i++] = *ptr;
		ptr++;
	}
	dest = std::move(temp);
}


void basic_guarantee()
{
	char src[50]{ "Mysource" };
	char dest[20]{ "Mydestination" };
	std::cout << "Source String (Original)  :" << src << std::endl;
	std::cout << "Destination String (Original) :" << dest << std::endl;
	std::cout << "Please enter the string : ";
	std::cin.getline(src, sizeof(src));
	copy_basic(src, dest, sizeof(dest));
	std::cout << "Source String (after Copying)  :" << src << std::endl;
	std::cout << "Destination String (after Copying) :" << dest << std::endl;
}

void strong_guarantee()
{
	std::string src_string;
	std::array<char, 20> dest{ 'a','b','c' };
	std::cout << "Please enter the string : ";
	std::getline(std::cin, src_string);
	std::cout << "Source String (before Copying) :" << src_string << std::endl;
	std::cout << "Destination String (before Copying) :";
	/*functional style*/
	for (char ch : dest) {
		std::cout << ch;
	}
	std::cout << std::endl;
	/* Iterative style
	for (size_t i = 0; i < dest.size(); i++) {
		std::cout << dest[i];
	}*/
	std::cout << "\n";
	try {
		copy_strong(src_string, dest);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Destination String (after Copying) :";
	for (char ch : dest) {
		std::cout << ch;
	}
	std::cout << "\n";
}


int main()
{
	basic_guarantee();
	strong_guarantee();

}