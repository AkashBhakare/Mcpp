// 123_dynamic_memory.cpp :

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
struct Product {
	char name[1000];
	float price;
	float weight;

	Product() { //ctor default
		std::cout << "\tCtor invoked\n";
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}

	//parameterized ctor
	Product(const char* _name, float _price, float _weight) { //ctor
		std::cout << "\tCtor invoked\n";
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
		std::cout << "\tDtor invoked\n";
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}
};


void placement_new_primitive_type_case1() {

	//System decides the location where the allocation has to happen on the heap
	{
		int* iptr = nullptr;
		iptr = new int[10]; //allocate memory somewhare on the heap
		std::cout << "Address : " << std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(iptr)
			<< std::dec << std::noshowbase << std::endl;
		delete[] iptr;		//deallocate
		iptr = nullptr;


		iptr = new int[100]; //allocate memory somewhare on the heap
		std::cout << "Address : " << std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(iptr)
			<< std::dec << std::noshowbase << std::endl;
		delete[] iptr; //deallocate
		iptr = nullptr;
	}

	{
		char* cbuff = nullptr;
		cbuff = new char[1000];  //allocate pool somewhere on heap
		std::cout << "Address of cbuff : (dec) " << reinterpret_cast<unsigned long long>(cbuff) << "\t(Hex) "
			<< std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(cbuff)
			<< std::dec << std::noshowbase << std::endl;

		int* iptr = nullptr;

		//Placement new
		iptr = new(cbuff) int[100]; //allocate memory at the address of cbuff
		std::cout << "Address of integer array : (dec) : " << reinterpret_cast<unsigned long long>(iptr) << "\t"
			<< "( Hex) : " << std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(iptr)
			<< std::dec << std::noshowbase << std::endl;
		//delete[] iptr;

		double* dptr = nullptr;
		dptr = new(cbuff + 400) double[10];
		std::cout << "Address of double array  : (dec) : " << reinterpret_cast<unsigned long long>(dptr) << "\t"
			<< "( Hex) : " << std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(dptr)
			<< std::dec << std::noshowbase << std::endl;


		float* fptr = new(cbuff) float[10];
		std::cout << "Address of float array   : (dec) : " << reinterpret_cast<unsigned long long>(iptr) << "\t"
			<< "( Hex) : " << std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(iptr)
			<< std::dec << std::noshowbase << std::endl;


		delete[] cbuff; //destroys the pool of memory
		cbuff = nullptr;
	}

}

void placement_new_primitive_type_case2(char* cptr)
{
	//Allocate memory dynamically on the stack
	//Placement new
	int* iptr = new(cptr) int[100]; //allocate memory at the address of array on the stack of main frame
	std::cout << "Address of integer array : (dec) : " << reinterpret_cast<unsigned long long>(iptr) << "\t"
		<< "( Hex) : " << std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(iptr)
		<< std::dec << std::noshowbase << std::endl;
	//delete[] iptr; //interferes in automatic allocation and deallocation of memory on stack
	iptr = nullptr;

}


void placement_new_class_type(char* cptr_main_buff) {


	//Allocation on some address on heap
	Product* prod_ptr1 = new Product("Marker", 500.5F, 100.0f); //handle allocation
	prod_ptr1->print_product();
	delete prod_ptr1;  //handle deallocation
	prod_ptr1 = nullptr;


	//Allocation on preallocated memory on stack
	prod_ptr1 = new(cptr_main_buff) Product("Pencil", 50.5F, 10.0f);
	prod_ptr1->print_product();
	//delete prod_ptr1;
	prod_ptr1->~Product();  //clean up
	prod_ptr1 = nullptr;
}


int main()
{
	try {
		placement_new_primitive_type_case1();

		char main_buff[1000]{}; //Character allocated on the stack of main frame
		std::cout << "\nSize of Array of main frame : " << sizeof(main_buff) << " bytes" << std::endl;
		std::cout << "\nAddress of main_buff     : (dec) : " << reinterpret_cast<unsigned long long>(main_buff) << "\t( Hex) : "
			<< std::hex << std::showbase
			<< reinterpret_cast<unsigned long long>(main_buff)
			<< std::dec << std::noshowbase << std::endl;

		placement_new_primitive_type_case2(main_buff);
		std::cout << "\nSize of Array of main frame : " << sizeof(main_buff) << " bytes" << std::endl;
	}
	catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
	}

	//char arr[std::numeric_limits<int>::max()]{};

	std::cout << "Entering the code block in main\n";
	{
		Product p{ "Pen",140.5F,50.0f };
	}
	std::cout << "Exiting the code block in main\n";

	{
		char main_buffer[1000]{};
		placement_new_class_type(main_buffer);
	}

}
