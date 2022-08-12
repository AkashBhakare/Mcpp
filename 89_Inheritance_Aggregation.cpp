// 89_Inheritance_Aggregation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Aggregation : 
// The componants can outlive the aggregate
// Weak association
// No exclusive ownership : The componant can be a part of multiple aggregate
// Aggregate is not responsible for construction and destruction of componanats

#include <iostream>
#include "song.h"
#include "playlist.h"
#include <memory>
#include <stdexcept>
using namespace std::literals;

int main()
{
	auto s1 = std::make_shared<mylib::Song>("My Love"s, "Sonu Nigum"s, 5.3f);
	std::cout << s1 << '\n';
	auto s2 = std::make_shared<mylib::Song>("Kora Kakaj"s, "Kishore Kumar"s, 4.4f);
	std::cout << s2 << '\n';
	auto s3 = std::make_shared<mylib::Song>("Milae sur"s, "Lata Di"s, 5.4f);
	auto s4 = std::make_shared<mylib::Song>("Danger", "Unknown", 5.5f);

	std::cout << "Playlist\n";
	try {
		mylib::PlayList list1("Travel_list"s, "Romantic");
		list1.add_song(s1);
		list1.add_song(s2);


		std::cout << "Number of songs in list1 : " << list1.get_song_count() << '\n';
		list1.print_playlist();

		list1.remove_song("Kora Kakaj"s);
		std::cout << "After Removing:\n";
		std::cout << "Number of songs in list1 : " << list1.get_song_count() << '\n';
		list1.print_playlist();

		mylib::PlayList list2("Another_list"s, "Romantic");
		list2.add_song(s1);
		list2.add_song(s3);
		list2.add_song(s4);

		std::cout << "Number of songs in list2 : " << list2.get_song_count() << '\n';
		list2.print_playlist();
		////	delete song_ptr;
		s4.reset();
		std::cout << "After deleting the componant\n";
		std::cout << "Number of songs in list2 : " << list2.get_song_count() << '\n';
		list2.print_playlist();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "Here!";
	//std::cout << "Componants outlive the aggregate\n";
	//std::cout << *s1 <<'\n';
	//std::cout << *s2 <<'\n';
	//std::cout << *s3 <<'\n';
	return 0;
}