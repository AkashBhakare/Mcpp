// 92_finalclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

class Weekdays final {

};

/* cannot derive from 'final' base 'Weekdays' in derived type 'MyWeekdays'
class MyWeekdays : public Weekdays{

};
*/

class Sample {
public:
    virtual void dotask() final {
        std::cout << "Sample::dotask\n";
    }
};

class MySample : public Sample {
public:
    virtual void action() {

    }

    ///*Virtual function 'virtual void MySample::dotask()' overriding final function */
    //virtual void dotask() override {
    //    std::cout << "MySample::dotask\n";
    //}
};

int main(void) {
    MySample mys;
    Sample s;
    Sample* ptr = &mys;
    ptr->dotask();
    return 0;
}