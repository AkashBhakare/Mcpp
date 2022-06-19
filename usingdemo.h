#pragma once


class Base
{
private:
	int b_pri_mem;
protected:
	int b_pro_mem;
public:
	int b_pub_mem;
};


class Derived1 : public Base {
private:
	int d1_pri_mem;
protected:
	int d1_pro_mem;
public:
	int d1_pub_mem;
	void check_member_access();
};


class Derived2 : public Base {
private:
	int d2_pri_mem;
protected:
	int d2_pro_mem;
public:
	//using Base::b_pri_mem;
	using Base::b_pro_mem;
	int d2_pub_mem;
	void check_member_access();
};


class Derived3 : private Base {
private:
	int d3_pri_mem;
	/*inherited public and portected members become private members of the
	Derived class since access specifer for inheritance is private*/
protected:
	int d3_pro_mem;
public:
	int d3_pub_mem;
	void check_member_access();
};

class Derived4 : private Base {
private:
	int d4_pri_mem;
protected:
	int d4_pro_mem;
public:
	//using Base::b_pri_mem;
	/*inherited public and protected members are brought in the public scope of derived class*/
	using Base::b_pro_mem;
	using Base::b_pub_mem;

	int d4_pub_mem;
	void check_member_access();
};
