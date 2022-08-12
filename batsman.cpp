#include <iostream>
#include <memory>
#include <utility>
#include "batsman.h"


mylib::Batsman::Batsman(std::string name, size_t batting_position, BattingStrategy* bs)
{
	this->name = name;
	this->batting_position = batting_position;
	this->batting_strategy = bs;
}

void mylib::Batsman::batting()
{
	std::cout << name << " " << batting_strategy->batting_style();
}

void mylib::Batsman::change_batting_style(BattingStrategy* style)
{
	this->batting_strategy = style;
}