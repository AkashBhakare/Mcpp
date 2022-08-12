// 91_Inheritance_Strategy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Strategy design pattern
#include <iostream>
#include "batsman.h"
#include "BattingStrategy.h"
#include <utility>
#include <memory>
int main()
{
    mylib::Batsman viru("Virendra", 1, new mylib::AggressiveBatting());
    viru.batting();
    mylib::Batsman rahul("Rahul", 1, new mylib::DefensiveBatting());
    rahul.batting();
    viru.change_batting_style(new mylib::DefensiveBatting());
    viru.batting();
    viru.change_batting_style(new mylib::MixedBatting());
    viru.batting();
}