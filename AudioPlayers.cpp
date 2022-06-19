#include "AudioPlayers.h"
#include <iostream>

void audio_player::Radio::play()
{
	std::cout << "Playing the Radio\n";
}

void audio_player::Radio::stop()
{
	std::cout << "Stopped playing Radio\n";
}

void audio_player::Radio::changeVolume()
{
	std::cout << "Changed the Radio Volume\n";
}

void audio_player::Radio::turnof()
{
	std::cout << "Turned the Radio power off\n";
}


void audio_player::Tape::play()
{
	std::cout << "Playing the Tape\n";
}

void audio_player::Tape::stop()
{
	std::cout << "Stopped playing Tape\n";
}


void audio_player::Tape::changeVolume()
{
	std::cout << "Changed the Tape Volume\n";
}

void audio_player::Tape::turnof()
{
	std::cout << "Turned the Tape Power off\n";
}

void audio_player::TwoInOne::turnof()
{
	std::cout << "Turning off the TWO_IN_ONE\n";
	Radio::turnof(); //invoking the overridden/suppressed/hidden method of Radio
	Tape::turnof();  //invoking the overridden/suppressed/hidden method of Tape

}
