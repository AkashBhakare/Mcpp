#pragma once
namespace my_lib {
	class Operation
	{
		int data_member = 0;
	public:
		static long long int add(int, int);
		static long long int add(int, int, int);
		static long double   add(float, float);

		/*cannot overload static and non-static member functions with the same parameter types*/
	//	static long long int multiply(int, int);
		long long int multiply(int, int);

		void dotask()const;
		void dotask();
	};
}

