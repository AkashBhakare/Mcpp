#pragma once
#include <string>
#include <vector>
#include <memory>
#include "song.h"
namespace mylib {
	class PlayList
	{
	public:
		PlayList(std::string&& name, std::string&& genre);
		~PlayList();
		std::string get_genre()const;
		size_t get_song_count();
		void print_playlist()const;
		void add_song(std::shared_ptr<Song>&);
		void remove_song(const std::string& title);

	private:
		std::string list_name;
		std::string genre;
		std::vector<std::weak_ptr<Song>> songs;
		void remove_deleted_songs();
	};
}
