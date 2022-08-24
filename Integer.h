#pragma once
namespace mylib {
	class Integer
	{
		friend Integer operator--(Integer&);
	private:
		int data = 0;
	public:
		Integer() = default;
		Integer(int);
		Integer(const Integer&); //Copy constructor
		Integer(Integer&&);		 //move constructor
		int get_value(void)const;
		int get_max_value() const;
		int get_min_value() const;
		void set_value(long long int);

		/* Prefix ++ as member function of class */
		Integer operator++();

		/* Postfix ++ as member frunction of the class */
		Integer operator++(int);

		/* Overload operator = function as member function*/
		Integer operator=(const Integer&);
	};

	/* Prefix -- as non-member function of class */
	Integer operator--(Integer&);
}