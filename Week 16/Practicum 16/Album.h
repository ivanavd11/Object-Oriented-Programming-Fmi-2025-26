#pragma once
#include "LibraryItem.h"
#include "Song.h"
#include <vector>

class Album :public LibraryItem
{
	std::string artist;
	std::vector<Song> songs;
public:
    Album(const std::string& title,const std::string& releaseDate,const std::string& artist,const std::vector<Song>& songs);

    const std::string& getArtist() const;
    const std::vector<Song>& getSongs() const;
    std::size_t getSongCount() const;

    int getTotalDuration() const;

    void addSong(const Song& song);

    std::string getType() const override;

    void printInfo() const override;
    std::unique_ptr<LibraryItem> clone() const override;
};

