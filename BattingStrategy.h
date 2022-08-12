#pragma once
#include <iostream>
#include <string>
using namespace std::literals;
namespace mylib {
	//Strategy Interface
	struct BattingStrategy {
		virtual std::string batting_style() = 0;
	};

	// Concrete Strategy
	struct AggressiveBatting : public BattingStrategy {
		std::string batting_style() override {
			return "Batting  Aggressively.. only 4s and 6s\n"s;
		}
	};

	// Concrete Strategy
	struct DefensiveBatting : public BattingStrategy {
		std::string batting_style() override {
			return "Batting  Defensively.. only 1s and 2s\n"s;
		}
	};

	// Concrete Strategy
	struct MixedBatting : public BattingStrategy {
		std::string batting_style() override {
			return "Batting  Defensively & Occasionally Agressively..\n"s;
		}
	};
}
