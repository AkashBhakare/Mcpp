#include "playlist.h"
#include <iostream>
#include <algorithm>
#include <vector>
mylib::PlayList::PlayList(std::string&& name, std::string&& genre)
{
    this->list_name = std::move(name);
    this->genre = std::move(genre);
}
mylib::PlayList::~PlayList()
{
    std::cout << "PlayList Name : " << list_name << " destroyed\n";
}
std::string mylib::PlayList::get_genre() const
{
    return this->genre;
}

size_t mylib::PlayList::get_song_count()
{
    remove_deleted_songs();
    return songs.size();
}

void mylib::PlayList::print_playlist() const
{
    std::cout << "PlayList Name : " << list_name << "\tGenre : " << genre << '\n';
    // std::vector<std::weak_ptr<Song>>::iterator iter_to_delete{};
    for (auto song : songs)
    {
        if (not song.expired()) {
            std::cout << *song.lock() << '\n';

        }
    }

    std::cout << '\n';
}

void mylib::PlayList::add_song(std::shared_ptr<Song>& song)
{
    songs.push_back(song);
}

void mylib::PlayList::remove_song(const std::string& title)
{
    songs.erase(std::remove_if(songs.begin(), songs.end(), [title](auto song) {return song.lock()->get_title() == title; }));
}

void mylib::PlayList::remove_deleted_songs()
{
    for (std::vector<std::weak_ptr<Song>>::iterator it = songs.begin(); it != songs.end(); ) {
        if (it->expired()) {
            it = songs.erase(it);
        }
        else {
            ++it;
        }
    }
}