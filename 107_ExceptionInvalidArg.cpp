// 107_ExceptionInvalidArg.cpp : 
/*
 * invalid_argument exception thrown if
 * parameters to constructor are invalid
 *
 * Exception can be thrown while creating objects
 * Destructor is called only for objects
 * created successfully
 */
#include <cstdlib>
#include <iostream>
#include <stdexcept>

 /*
  * invalid_argument exception
  */

class MyTime {
private:
    int hr;
    int min;
    int sec;
public:

    MyTime(int h, int m, int s) noexcept(false) {
        if (h >= 24 || h < 0) {
            throw std::invalid_argument("Incorrect Hour value");
        }
        if (m < 0 || m >= 60) {
            throw std::invalid_argument("Incorrect minutes");
        }
        if (s < 0 || s >= 60) {
            throw std::invalid_argument("Incorrect seconds");
        }

        hr = h;
        min = m;
        sec = s;
    }

    ~MyTime() {
        hr = 0;
        min = 0;
        sec = 0;
        std::cout << "MyTime object destroyed!" << std::endl;
    }

    void showTime() {
        std::cout << std::endl << "Time is " << hr << ":"
            << min << ":" << sec << std::endl;
    }
};

int main() {
    int hr;
    int min;
    int sec;
    do {
        try {
            std::cout << "Enter hour : ";
            std::cin >> hr;
            std::cout << "Enter Minutes : ";
            std::cin >> min;
            std::cout << "Enter Sec : ";
            std::cin >> sec;
            MyTime t1(hr, min, sec);
            t1.showTime();
            //  MyTime t2(24, 7, 23);
            // t2.showTime();
            break;

        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    } while (true);
    std::cout << "Continue with rest of the code!\n";
    return 0;
}

