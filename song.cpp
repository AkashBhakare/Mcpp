#include <iostream>
#include "song.h"

mylib::Song::Song(std::string&& title, std::string&& singer, float length)
{
	this->title = std::move(title);
	this->singer = std::move(singer);
	this->length = length;
}

mylib::Song::~Song()
{
	std::cout << "Deleting song  \n";
}

std::string mylib::Song::get_title() const
{
	return this->title;
}

std::ostream& mylib::operator<<(std::ostream& out, const Song& song)
{
	out << "Title : " << song.title << "\nSinger : " << song.singer << "\nSong Length : " << song.length << " min\n";
	return out;
}