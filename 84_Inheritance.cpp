// 84_Inheritance.cpp :
//Multiple Inheritance : Ambiguties

#include <iostream>
#include "AudioPlayers.h"
int main()
{
    audio_player::Radio aRadio{};
    aRadio.play();
    aRadio.stop();
    aRadio.turnof();

    std::cout << std::endl;
    audio_player::Tape aTape{};
    aTape.play();
    aTape.stop();
    aTape.turnof();

    audio_player::TwoInOne two_in_one{};

    //"audio_player::TwoInOne::play" is ambiguous
   // two_in_one.play();

    //"audio_player::TwoInOne::raiseVolume" is ambiguous
    //two_in_one.changeVolume();
    std::cout << "\nUsing Two in One \n";
    two_in_one.Radio::play();
    two_in_one.Radio::changeVolume();
    two_in_one.Tape::play();
    two_in_one.Tape::changeVolume();

    /*
    * ambiguous access of 'stop'
    * could be the 'stop' in base 'Radio'
    * or could be the 'stop' in base 'Tape'
    */
    // two_in_one.stop();

     /*No Ambiguity since the class TwoInOne overrides the inherited method turnof() from Tape & Radio*/
    two_in_one.turnof();
}

