#pragma once
#include <string>
namespace mylib {
	class Song
	{
	public:
		Song(std::string&& title, std::string&& singer, float length);
		~Song();
		friend std::ostream& operator << (std::ostream& out, const Song&);
		std::string get_title()const;

	private:
		std::string title;
		std::string singer;
		float length;

	};

	std::ostream& operator << (std::ostream& out, const Song&);
}