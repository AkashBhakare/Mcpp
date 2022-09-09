// 121_dynamic_memory.cpp :
// understand new and delete operator

#include <iostream>
#include <iomanip>
#include <memory>
#include <new>

void  primitive_types_single_variable() {
	/*Allocate memory for single integer variable on the heap*/
	int* iptr = nullptr;

	/*creates a uninitialized variable of type integer on the heap*/
	iptr = new int;
	std::cout << "Address : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(iptr)
		<< std::dec << std::noshowbase
		<< "\tValue : " << *iptr
		<< std::endl;

	/*Store value into the integer created dynamically*/
	*iptr = 99;
	std::cout << "Address : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(iptr)
		<< std::dec << std::noshowbase
		<< "\tValue : " << *iptr
		<< std::endl;

	delete iptr;
	iptr = nullptr;

	/*creates a variable of type integer on the heap  and performs default initialization*/
	iptr = new int{};
	std::cout << "Address : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(iptr)
		<< std::dec << std::noshowbase
		<< "\tValue : " << *iptr
		<< std::endl;

	delete iptr;
	iptr = nullptr;

	/*creates a variable of type integer on the heap and initializes it give value*/
	iptr = new int{ 7 };
	std::cout << "Address : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(iptr)
		<< std::dec << std::noshowbase
		<< "\tValue : " << *iptr
		<< std::endl;

	delete iptr;
	iptr = nullptr;

	/*creates a variable of type double on the heap and initializes it give value*/
	double* dptr = nullptr;
	dptr = new double{ 1233456789.6234238678 };
	std::cout << "Address : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(dptr)
		<< std::dec << std::noshowbase << std::fixed << std::setprecision(10)
		<< "\tValue : " << *dptr
		<< std::endl;

	delete dptr;
	dptr = nullptr;

}


struct Product {
	char name[1000];
	float price;
	float weight;

	Product() { //ctor default
		std::cout << "Product constructor called\n";
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}

	//parameterized ctor
	Product(const char* _name, float _price, float _weight) { //ctor
		std::cout << "Product constructor (Parameterized) called\n";
		strcpy_s(name, _name);
		price = _price;
		weight = _weight;
	}

	void print_product() {
		std::cout << "Name : " << name << "\t"
			<< "Price : " << price << "\t"
			<< "Weight :" << weight << std::endl;
	}

	~Product() { //dtor
		std::cout << "Product destructor called\n";
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}
};


void user_defined_type_allocation() {

	Product* product_ptr = nullptr;

	/*Product class object is created by calling the default constructor*/
	product_ptr = new Product;

	product_ptr->print_product();

	/*Product class object is destroyed after calling destructor*/
	delete product_ptr;
	product_ptr = nullptr;

	/*Product class object is created by calling the parameterized constructor*/
	product_ptr = new Product("Marker Pen", 150.50f, 30.0f);
	product_ptr->print_product();

	/*Product class object is destroyed after calling destructor*/
	delete product_ptr;
	product_ptr = nullptr;
}


void print_array(int* iptr, size_t number_of_elements) {
	for (size_t i{ 0 }; i < number_of_elements; ++i) {
		std::cout << *(iptr + i) << ", ";
	}
	std::cout << std::endl;
}

void store_values(int* iptr, size_t number_of_elements) {
	for (size_t i{ 0 }; i < number_of_elements; ++i) {
		*(iptr + i) = static_cast<int>((i + 1) * 10);
	}
	std::cout << std::endl;
}

void primitive_type_array_allocation() {

	int number_of_elements{};
	std::cout << "How many integers do you want to store ? ";
	std::cin >> number_of_elements;

	int* iptr = nullptr;
	try {
		/*Dynamically allocates memory for array of integers on the heap
		Elements in the array are not initialized
		*/
		iptr = new int[number_of_elements];

		std::cout << "Printing the uninitialized array : \n";
		print_array(iptr, number_of_elements);

		delete[] iptr;
		iptr = nullptr;

		/*
		Dynamically allocates memory for array of integers on the heap
		Elements in the array are  initialized to default value
		*/
		iptr = new int[number_of_elements] {};

		std::cout << "Printing the initialized array : \n";
		print_array(iptr, number_of_elements);

		// delete iptr;  // this will release memory only of the first variable in the array resulting in memory leak
		delete[] iptr;  // will will delete the entire array
		iptr = nullptr;
	}
	catch (std::bad_array_new_length& err) {
		std::cout << err.what() << "\n";
		std::cout << "Number of integers should be positive value\n";
	}
}


void userdefined_type_array_allocation() {

	Product* product_ptr = nullptr;

	size_t number_of_products{};

	std::cout << "How many Products do you want to store ? ";
	std::cin >> number_of_products;

	/*Product class object is created by calling the default constructor*/
	product_ptr = new Product[number_of_products]{ };
	//product_ptr = new Product[number_of_products]{ {"Pen",400.0f,100.0F} }; //works

	for (size_t i{ 0 }; i < number_of_products; ++i) {
		(product_ptr + i)->print_product();
	}

	/*Product class object is destroyed after calling destructor*/
	delete[] product_ptr;
	product_ptr = nullptr;

}


int main()
{
	primitive_types_single_variable();
	user_defined_type_allocation();
	primitive_type_array_allocation();
	userdefined_type_array_allocation();
}