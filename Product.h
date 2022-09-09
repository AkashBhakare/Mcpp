#pragma once
namespace mylib {
	struct Product {
		char name[1000];
		float price;
		float weight;

		Product();

		//parameterized ctor
		Product(const char* _name, float _price, float _weight);

		void print_product();

		~Product();
	};


}