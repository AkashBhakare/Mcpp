#pragma once
#include <memory>
#include <utility>
#include <string>
#include "BattingStrategy.h"

namespace mylib {

	//Context
	class Batsman
	{
	private:
		mylib::BattingStrategy* batting_strategy;
		std::string name;
		size_t batting_position;
	public:
		Batsman(std::string name, size_t batting_position, BattingStrategy* bs);
		virtual void batting() final;
		virtual void change_batting_style(BattingStrategy* style);
	};

}