// 86_Inheritance_up_down_casting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <typeinfo>
#include "Person.h"
#include "Doctor.h"
#include "Lawyer.h"

void check_person_class() {
	//Case1
	try
	{
		mylib::Person aperson("Tejas");
		std::cout << "Name : " << aperson.get_name() << "\n";
		aperson.set_name("Teja");
		std::cout << "Name : " << aperson.get_name() << "\n";
		aperson.set_name("");
	}
	catch (std::invalid_argument& err) {
		std::cerr << err.what();
	}
}

void check_doctor_class() {
	try {
		mylib::Doctor adoctor("Aparajita", "NeuroSergeon");
		std::cout << "Name : " << adoctor.get_name() << "\n";
		std::cout << "Specialization : " << adoctor.get_specialization() << "\n";
		std::cout << "Operating : " << adoctor.operate();
	}
	catch (std::invalid_argument& err) {
		std::cerr << err.what();
	}
}


void test_overriding() {
	mylib::Person aperson("Sarthak");
	std::cout << "Name : " << aperson.get_name() << "\n";	//static_binding
	mylib::Person& p_ref{ aperson };
	std::cout << "Name : " << p_ref.get_name() << "\n";		//static_binding

	mylib::Doctor adoctor{ "Pratiksha","Heart Sergeon" };
	std::cout << "Name : " << adoctor.get_name() << "\n";	//static_binding
	std::cout << "Specialization : " << adoctor.get_specialization() << "\n";//static_binding
	std::cout << "Operating : " << adoctor.operate();		//static_binding

	mylib::Doctor& d_ref = adoctor;
	std::cout << "Name : " << d_ref.get_name() << "\n"; //static_binding
	mylib::Doctor* d_ptr = &adoctor;
	std::cout << "Name : " << d_ptr->get_name() << "\n"; //static_binding

	/*reference of supertype can point ot object of its own type or subtype*/
	mylib::Person& p_ref1 = adoctor;
	std::cout << "Name : " << p_ref1.get_name() << "\n";		//dynamic_binding:late binding

	mylib::Person* p_ptr = &adoctor;
	std::cout << "Name : " << p_ptr->get_name() << "\n";		//dynamic_binding

	/*Even though a superclass reference or pointer knows that it is actually a subclass,
	you cannot access subclass methods or members that are not defined in the superclass*/
	/*std::cout << "Specialization : " << p_ref.get_specialization() << "\n";
	std::cout << "Operating : " << p_ref.operate();
	std::cout << "Specialization : " << p_ptr->get_specialization() << "\n";
	std::cout << "Operating : " << p_ptr->operate();*/
	return;

}


void welcome_person(mylib::Person& ref_per) {
	std::cout << "Good Evening " << ref_per.get_name() << "\n";
	return;
}

void greet_person(mylib::Person& ref_per) {
	std::cout << "Good Night " << ref_per.get_name() << "\n";
	return;
}

void say_hello(mylib::Person* ptr) {
	std::cout << "hi! " << ptr->get_name() << "\n";
	return;
}


void use_of_overriding() {
	mylib::Person person("Rishi");
	welcome_person(person);

	mylib::Doctor doc("Akash", "Eye Sergeon");
	welcome_person(doc);

	mylib::Lawyer adv("Tejas", "Criminal");
	welcome_person(adv);

	//slicing : static binding
	std::cout << "\nUsing vector of Person Object\n";
	std::vector<mylib::Person> persons{ person,doc,adv };

	std::for_each(persons.begin(), persons.end(), greet_person);
	std::for_each(persons.begin(), persons.end(),
		[](mylib::Person& ref) {std::cout << "Hello " << ref.get_name() << "\n"; });

	// dynamic binding since the object address are deposited in vecor as Person *
	std::cout << "Using vector of Person pointers\n";
	std::vector<mylib::Person*> person_ptr{ &person,&doc,&adv };
	std::for_each(person_ptr.begin(), person_ptr.end(), say_hello);
	std::for_each(person_ptr.begin(), person_ptr.end(),
		[](mylib::Person* ptr) {std::cout << "Hello " << ptr->get_name() << "\n"; });

}

void problem_of_not_having_virtual_destructor() {
	//Person class created dynamically
	{
		mylib::Person* person_ptr = new mylib::Person("Vedant");
		std::cout << person_ptr->get_name() << "\n";
		delete person_ptr;
	}

	//Doctor created dynamically
	{
		mylib::Doctor* doc_ptr = new mylib::Doctor("Appu", "Orthopedic");
		std::cout << doc_ptr->get_name() << "\n";
		std::cout << doc_ptr->get_specialization() << "\n";
		delete doc_ptr;
	}

	//Doctor created dynamically refered by supercalss Person pointer
	{
		mylib::Person* per_ptr = new mylib::Doctor("Aman", "Medicine");
		std::cout << per_ptr->get_name() << "\n";
		//	std::cout << per_ptr->get_specialization() << "\n";
			/*destructor of Person will be binded statically to delete unless declared as virtual is Person class*/
		delete per_ptr;
	}
	return;
}

using namespace std::string_literals;
void upcasting_demo() {
	mylib::Doctor adoc("Akash"s, "Othopedic"s);
	mylib::Doctor d_ref = adoc;
	std::cout << "Name : " << d_ref.get_name() << '\n';
	std::cout << "Operate : " << d_ref.operate() << '\n';
	std::cout << "Specialization : " << d_ref.get_specialization() << '\n';

	mylib::Person& p_ref1 = d_ref; //upcasting
	mylib::Person& p_ref2 = adoc;  //upcasting

	std::cout << "Name : " << p_ref1.get_name() << '\n';
	/*Cannot invoke sub class specific method using reference of super class
	even if it is reference to object of subclass*/
	/*std::cout << "Operate : " << p_ref1.operate() << '\n';
	std::cout << "Specialization : " << p_ref2.get_specialization() << '\n';*/

	mylib::Person* p_ptr = &adoc; //upcasting
	std::cout << "Name : " << p_ptr->get_name() << '\n';
	/*Cannot invoke sub class specific method using pointer to super class
	even if it is pointer points to object of subclass*/
	/*std::cout << "Operate : " << p_ptr->operate() << '\n';
	std::cout << "Specialization : " << p_ptr->get_specialization() << '\n';*/


}


void downcasting_demo() {
	mylib::Doctor adoc("Akash"s, "Othopedic"s);
	mylib::Person& p_ref = adoc;  //upcasting
	mylib::Person* p_ptr = &adoc; //upcasting
	std::cout << "Name using reference: " << p_ref.get_name() << '\n';
	std::cout << "Name using pointer  : " << p_ref.get_name() << '\n';
	//unsafe downcasting
	std::cout << "Operate : " << ((mylib::Doctor&)p_ref).operate() << '\n';
	std::cout << "Operate : " << ((mylib::Doctor*)p_ptr)->operate() << '\n';

	mylib::Lawyer adv("Tejas", "Criminal");
	p_ptr = &adv;
	std::cout << "Operate unsafe : " << ((mylib::Doctor*)p_ptr)->operate() << '\n';
	//p_ptr = &adoc;
	//Safe downcasting uing pointer
	if (mylib::Doctor* dptr = dynamic_cast<mylib::Doctor*>(p_ptr); dptr != nullptr) {
		std::cout << "After confirmation Safe\n";
		std::cout << "Operate : " << dptr->operate() << '\n'; //downcasting
	}
	else {
		std::cerr << "Supre Class Person's pointer not pointing to object of Doctor class\n";
	}

	mylib::Person& p_ref1 = adv;  //upcasting
	std::cout << "Lawyer unsafe down casting casting: " << ((mylib::Lawyer&)p_ref1).get_practice() << '\n';
	try {
		std::cout << "Lawyer safe downcasting : " << dynamic_cast<mylib::Lawyer&>(p_ref1).get_practice() << '\n';
	}
	catch (std::bad_cast& err) {
		std::cerr << "Error! :" << err.what() << '\n';
	}

}

int main()
{
	//check_person_class();
	//check_doctor_class();
	//test_overriding();
	//use_of_overriding();
	//problem_of_not_having_virtual_destructor();
	//upcasting_demo();
	downcasting_demo();
}