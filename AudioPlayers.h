#pragma once

namespace audio_player {

	class Radio
	{
	public:
		void play(void);
		void stop(void);
		void changeVolume(void);
		void turnof(void);
	};

	class Tape
	{
	public:
		void play(void);
		void stop(void);
		void changeVolume(void);
		void turnof(void);
	};

	class TwoInOne :public Radio, public Tape {
	public:
		/*Overrides the inherited method turnof from Tape & Radio*/
		void turnof(void);
	};

}

