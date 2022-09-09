// 119_AssertDemo.cpp : 
#define NDEBUG 
#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>
#include <stdexcept>

//static_assert(sizeof(long) == 4, "long must be 8 bytes");
static_assert(sizeof(int) == 4, "int must be 4 bytes");

bool is_value_in_range(int lower, int upper, int val) {

    assert(lower <= upper);

    return (val >= lower and val <= upper);
}

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    assert(initialHeight > 0);
    assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.
    double time;
    if (initialHeight == 0.0) { // The object is already on the ground. Or buried.
        time = 0.0;
    }
    else {
        time = std::sqrt((2.0 * initialHeight) / gravity);
    }
    assert(time >= 0); // post condition
    return time;
}

bool is_even(int val) {

    //assert(val != 0);

    if (val == 0) {
        throw  std::invalid_argument("Value to be checked cannot be zero\n");
    }

    return (val % 2 == 0);

}

int main()
{
    constexpr double earth_gravity{ 9.8 };
    constexpr double jupiter_gravity{ 24.79 };
    constexpr double venus_gravity{ 8.87 };
    constexpr double mercury_gravity{ 3.7 };
    double height = 100.0;
    /* std::cout << "on Earth it Took " << calculateTimeUntilObjectHitsGround(height, earth_gravity) << " second(s)\n";
     std::cout << "on Jupiter it Took " << calculateTimeUntilObjectHitsGround(height, jupiter_gravity) << " second(s)\n";
     std::cout << "on Venus it Took " << calculateTimeUntilObjectHitsGround(height, venus_gravity) << " second(s)\n";
    std::cout << "on Mercury it Took " << calculateTimeUntilObjectHitsGround(height, mercury_gravity) << " second(s)\n";*/
    //std::cout << "on Mercury it Took " << calculateTimeUntilObjectHitsGround(-height, mercury_gravity) << " second(s)\n";
    std::cout << " is 10 within the range of 5 to 50 : " << std::boolalpha << is_value_in_range(5, 50, 10) << std::endl;
    std::cout << " is 10 within the range of 50 to 5 : " << std::boolalpha << is_value_in_range(50, 5, 10) << std::endl;
    std::cout << " is 100 within the range of 5 to 500 : " << std::boolalpha << is_value_in_range(100, 5, 500) << std::endl;

    //try {
    //    std::cout << "is 10 even ? " << is_even(10) << std::endl;
    //    std::cout << "is 15 even ? " << is_even(15) << std::endl;
    //    std::cout << "is 0 even ?  " << is_even(0) << std::endl;
    //}
    //catch (const std::invalid_argument& e) {
    //    std::cout << e.what();
    //}
    return 0;
}