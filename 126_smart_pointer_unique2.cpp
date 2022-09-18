// 126_smart_pointer_unique2.cpp : 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>


struct SomeClass {
	int _data1;
	int _data2{ 99 };

	SomeClass() = delete;

	SomeClass(int data) : _data1(data) {
		std::cout << "Some object is created\n";
	}

	~SomeClass() {
		std::cout << "Some object is destroyed\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const SomeClass& obj) {
		os << "Operating on Some class Object{" << obj._data1 << ", " << obj._data2 << "}\n";
		return os;
	}

};

void misuse_of_unique_pointer();
void empty_unique_ptr_demo();
void initializing_unique_ptr();
void accessing_resource_using_unique_ptr();
void memory_leak_resetting_raw_pointer();
void avoiding_memory_leak_using_unique_ptr();
void non_copyable_unique_pointer();
void movability_of_unique_pointer();
void releasing_resource();
int main() {
	//empty_unique_ptr_demo();
	//initializing_unique_ptr();
	//accessing_resource_using_unique_ptr();
	//memory_leak_resetting_raw_pointer();
	//avoiding_memory_leak_using_unique_ptr();
	//non_copyable_unique_pointer();
	movability_of_unique_pointer();
	misuse_of_unique_pointer();
	releasing_resource();


	return 0;
}

void empty_unique_ptr_demo() {
	// Empty std::unique_ptr object
	std::unique_ptr<int> uptr{};

	// Check if unique pointer object is empty
	if (!uptr) {
		std::cout << "uptr is empty" << std::endl;
	}

	// Check if unique pointer object is empty
	if (uptr == nullptr) {
		std::cout << "uptr is empty" << std::endl;
	}
}

void initializing_unique_ptr() {
	// can not create std::unique_ptr "object" by initializing through assignment
	//std::unique_ptr<SomeClass> uptr = new SomeClass(56); // Compile Error

	//Create a std::unique_ptr object through raw pointer
	std::unique_ptr<SomeClass> uptr(new SomeClass(23));
	// Check if sPtr is empty or it has an associated raw pointer
	if (uptr != nullptr) {
		std::cout << "uptr is  not empty" << std::endl;
	}

}

/*The object being owned by unique_ptr is handled exactly the same way as one
  would handle an aboject using raw pointer */
void accessing_resource_using_unique_ptr() {
	//Create a std::unique_ptr object through raw pointer
	std::unique_ptr<SomeClass> uptr(new SomeClass(23));

	//Access the entire object through std::unique_ptr
	std::cout << "The object : " << *uptr << std::endl;

	//Access the element through std::unique_ptr
	std::cout << "Accessing field using unique_ptr (->) : " << uptr->_data1 << std::endl;

	//Access the element through std::unique_ptr
	std::cout << "Accessing field using unique_ptr (*). : " << (*uptr)._data1 << std::endl;
}

void memory_leak_resetting_raw_pointer() {
	SomeClass* rptr(new SomeClass(23));
	if (rptr == nullptr)
		std::cout << "raw ptr is  empty" << std::endl;
	else
		std::cout << "raw ptr is not empty" << std::endl;
	std::cout << "Reset the raw ptr" << std::endl;
	// Resetting the raw pointer will not delete the associated object
	//resulting in memory leak
	rptr = nullptr;
	// Check if rptr is empty 
	if (rptr == nullptr)
		std::cout << "raw ptr is  empty" << std::endl;
	else
		std::cout << "raw ptr is not empty" << std::endl;
}

void avoiding_memory_leak_using_unique_ptr() {
	//Create a std::unique_ptr object through raw pointer
	std::unique_ptr<SomeClass> uptr(new SomeClass(23));
	if (uptr == nullptr)
		std::cout << "unique pointer is  empty" << std::endl;
	else
		std::cout << "unique pointer is not  empty" << std::endl;

	std::cout << "Reset the sptr" << std::endl;
	// Resetting the std::unique_ptr will delete the associated
	// raw pointer and make std::unique_ptr object empty
	uptr.reset();

	// Check if sptr is empty or it has an associated raw pointer
	if (uptr == nullptr)
		std::cout << "unique pointer is  empty" << std::endl;
	else
		std::cout << "unique pointer is not  empty" << std::endl;
}


//    As std::unique_ptr<> is not copyable, only movable. 
//    Hence we can not create copy of a std::unique_ptr object either through 
//    copy constructor or assignment operator.
void non_copyable_unique_pointer() {
	//Create a std::unique_ptr object through raw pointer
	std::unique_ptr<SomeClass> uptr1(new SomeClass(23));

	//Create a std::unique_ptr object through raw pointer
	std::unique_ptr<SomeClass> uptr2(new SomeClass(55));
	if (uptr2 != nullptr) {
		std::cout << "second unique_pointer is not empty" << std::endl;
	}

	// std::unique_ptr object is Not copyable
	// uptr1 = uptr2; //compile error

	// std::unique_ptr object is Not copyable
	// std::unique_ptr<SomeClass> uptr3{ uptr1 };

	/*
		unique_ptr has the copy constructor and assignment operator function
		explicitly deleted
	*/
}

/*Unique pointers are movable*/
void movability_of_unique_pointer() {

	//understanding transfer of ownership in string class
	{
		std::string s1{ "My string" };
		std::cout << "String1 : " << s1 << std::endl;
		std::string s2 = s1; //Copyable
		std::cout << "String1 : " << s1 << std::endl;
		std::cout << "String2 : " << s2 << std::endl;
		std::string s3{ s1 }; //Copyable
		std::cout << "String1 : " << s1 << std::endl;
		std::cout << "String3 : " << s3 << std::endl;

		std::string s4{ std::move(s1) }; //Movable
		//Never access the object whose content has been moved (Transfered)
		std::cout << "String1 (UB) : " << s1 << std::endl;
		std::cout << "String4      : " << s4 << std::endl;

	}
	{
		std::unique_ptr<SomeClass> uptr1{ new SomeClass(20) };
		// Transfer the ownership
		std::unique_ptr<SomeClass> uptr2{ std::move(uptr1) };

		if (uptr1 == nullptr)
			std::cout << "uptr1 is empty after moving" << std::endl;
		else
			std::cout << "uptr1 is not empty after moving" << std::endl;

		// ownership of sptr2 is transfered to sptr4
		if (uptr2 == nullptr)
			std::cout << "uptr2 is empty after moving" << std::endl;
		else
			std::cout << "uptr2 is not empty after moving" << std::endl;

		std::cout << uptr2->_data1 << std::endl; //Ok
		//Never access the object whose content has been moved (Transfered)
		//std::cout << uptr1->_data1 << std::endl; //UB
		//sptr4 goes out of scope and deletes the associated raw pointer
	}
}

void releasing_resource() {
	// Create a std::unique_ptr object through raw pointer
	//std::unique_ptr<SomeClass> sptr5(new SomeClass(55));
	//if (sptr5 != nullptr) {
	//	std::cout << "sptr5 is not empty" << std::endl;
	//}
	//// Release the ownership of object from raw pointer; resource is not destroyed
	//SomeClass* raw_ptr = sptr5.release();

	//if (sptr5 == nullptr) {
	//	std::cout << "sptr5 is empty" << std::endl;
	//}
	//std::cout << raw_ptr->_data1 << std::endl;

	//delete raw_ptr;

	//
}


void misuse_of_unique_pointer() {
	/*
	legal syntactically, the end result will be that
	both res1 and res2 will try to delete the Resource,
	which will lead to undefined behavior.
	*/
	SomeClass* res{ new SomeClass(99) };
	std::unique_ptr<SomeClass> res1{ res };
	std::unique_ptr<SomeClass> res2{ res };
}