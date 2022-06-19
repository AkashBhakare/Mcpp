// 78_Inheritance.cpp : 
// Concept of Direct and Indirect base class
// Multilevel Inheritance

#include <iostream>

class Vehicle {
private:
    float price;
    int year_of_manufacture;
};

/*
* For Car class Vehicle is direct base class or Parent Class
*/
class Car : public Vehicle {
private:
    int chasis_number;
    int engine_number;
};

/*
* For RacingCar; Car is Direct base class whereas Vehicle is indirect Base class
*/
class RacingCar : public {
    int max_intro_booster;

};


int main()
{
    std::cout << "Size of Vehicle   : " << sizeof(Vehicle) << " bytes \n";
    std::cout << "Size of Car       : " << sizeof(Car) << " bytes \n";
    std::cout << "Size of RacingCar : " << sizeof(RacingCar) << " bytes \n";
    Vehicle veh;
    Car car;
    RacingCar racingcar;
    std::cout << "Size of Vehicle   : " << sizeof(veh) << " bytes \n";
    std::cout << "Size of Car       : " << sizeof(car) << " bytes \n";
    std::cout << "Size of RacingCar : " << sizeof(racingcar) << " bytes \n";
    return 0;
}