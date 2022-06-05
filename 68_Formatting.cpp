// 68_Formatting.cpp : 
/*
 * Check Flag Status of a particular flag
 */

#include <cstdlib>
#include <iostream>
#include <bitset>
#include <cinttypes>

using namespace std;

void check_hex_status() {
    if (std::cout.flags() & ios::hex) {
        std::cout << "hex is on";
    }
    else {
        std::cout << "hex is off";
    }
    std::cout << std::endl;
}

void check_skipws_status() {
    if (std::cout.flags() & ios::skipws) {
        std::cout << "skipws is on";
    }
    else {
        std::cout << "skipws is off";
    }
    std::cout << std::endl;
}

bool check_flag_status(ios::fmtflags flag_to_check) {
    return (std::cout.flags() bitand flag_to_check);
}

void print_all_flags()
{
    ios::fmtflags flag_state{ cout.flags() };
    int value;
    for (int i = 16; i >= 0; --i) {
        if (flag_state & (1 << i)) {
            std::cout << "1";
        }
        else {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
    std::cout << "Alternate way to get all flags : \n";
    std::bitset<16> fmtflag_init{ static_cast<uint16_t>(std::cout.flags()) };
    std::cout << fmtflag_init << std::endl;
    return;
}
/*
* Order of flafs in fmtflags
*   13       12      11    10     9      8        7     6       5         4         3          2        1         0
 [fixed][scientific][hex] [oct] [dec][internal][right][left][showpos][showpoint][showbase][uppercase][unitbuf][skipws]
   8192   4096       2048 1024   512   256       128    64      32       16         8         4         2         1

*/

int main(int argc, char** argv) {
    int f = 0x0080;
    std::cout << f << std::endl;
    std::cout << "Value of dec flag : " << ios::dec << std::endl;
    std::cout << "Value of oct flag : " << ios::oct << std::endl;
    std::cout << "Value of hex flag : " << ios::hex << std::endl;
    /*
    ios::fmtflags ios::flags() const:
    the current set of flags controlling the format state of the stream for which the member
    function is called is returned.
    */
    ios::fmtflags my_initial_setting = std::cout.flags();

    std::cout << "flags : " << std::cout.flags() << std::endl;
    std::bitset<16> fmtflag_init{ static_cast<uint16_t>(std::cout.flags()) };

    std::cout << "Initial state of cout flags : " << fmtflag_init << std::endl;

    //check the flag status of ios::hex
    check_hex_status();
    std::cout.setf(ios::hex, ios::basefield);
    //check the flag status of ios::hex
    check_hex_status();
    //check the flag status of ios::skipws
    check_skipws_status();
    fmtflag_init = { static_cast<uint16_t>(std::cout.flags()) };
    std::cout << "Later state of cout flags   : " << fmtflag_init << std::endl;

    std::cout << "is scientific flag on : " << std::boolalpha << check_flag_status(ios::scientific) << std::endl;
    std::cout << "is dec flag on        : " << std::boolalpha << check_flag_status(ios::dec) << std::endl;
    std::cout << "is skipws flag on     : " << std::boolalpha << check_flag_status(ios::skipws) << std::endl;
    std::cout << "is hex flag on        : " << std::boolalpha << check_flag_status(ios::hex) << std::endl;
    /*
        fmtflags flags(fmtflags f);
        allows you to set all format flags associated with a stream.
    */
    std::cout.flags(my_initial_setting);

    fmtflag_init = static_cast<uint16_t>(std::cout.flags());
    std::cout << "After resetting state of cout flags : " << fmtflag_init << std::endl;
    std::cout << "All flags :";
    print_all_flags();
    return 0;
}