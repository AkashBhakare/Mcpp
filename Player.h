#pragma once
#pragma once
#include <string>

class Player
{
private:
	static constexpr size_t max_age{ 70 };
	static constexpr size_t min_age{ 18 };
	static constexpr size_t min_yob{ 1990 };
	static constexpr size_t max_yob{ 2022 };

	std::string name;
	size_t year_of_debut;
	size_t age;
	bool is_name_valid(std::string);
	bool is_age_valid(size_t age);
	bool is_yob_valid(size_t year);
public:
	/* Returns the name of the player*/
	std::string get_name();

	/* Returns the year of debut of the player*/
	size_t get_year_of_debut();

	/* Returns the age of the player*/
	size_t get_age();

	/* Sets the name of the player*/
	void set_name(std::string name);

	/* Sets the Age of the player*/
	void set_age(size_t age);

	/* Sets the Year of Debut of the player*/
	void set_year_of_debut(size_t yob);
};
