#pragma once

void conversion_userdefined_to_primitive();
void sqr(int);
void conversion_constructor();

class A {
private:
    int data = 88;
public:
    A() = default;
    /*Converting constructor*/
    A(int i) :data(i) {}
    int get()const { return data; }
};


class B {
private:
    int data = 88;
public:
    B() = default;
    /*Not a converting constructor*/
    explicit B(int i) :data(i) {}
    int get()const { return data; }
};
void bar(B obj)
{}

void foo(const A& a) {

}

/*Copy initialization*/
void baz(A a) {

}