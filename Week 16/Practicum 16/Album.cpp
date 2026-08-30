#include "Album.h"
#include <stdexcept>
#include <iostream>

Album::Album(const std::string& title, const std::string& releaseDate,
	const std::string& artist, const std::vector<Song>& songs)
	:LibraryItem(title, releaseDate), artist(artist), songs(songs)
{
    if (artist.empty()) 
	{
		throw std::invalid_argument("Album artist cannot be empty.");
    }
}

const std::string& Album::getArtist() const
{
	return artist;
}
const std::vector<Song>& Album::getSongs() const
{
	return songs;
}
std::size_t Album::getSongCount() const
{
	return songs.size();
}

int Album::getTotalDuration() const
{
	int totalDuration = 0;
	for (const auto& song : songs)
	{
		totalDuration += song.getDuration();
	}

	return totalDuration;
}

void Album::addSong(const Song& song)
{
	songs.push_back(song);
}

std::string Album::getType() const
{
	return "Album";
}

void Album::printInfo() const
{
	printBaseInfo();
	std::cout << ", artist name: " << artist
		<< "total duration: " << getTotalDuration() << " seconds\n";
	for (int i = 0; i < getSongCount(); i++)
	{
		std::cout << i + 1 << ". ";
		songs[i].print();
	}
}
std::unique_ptr<LibraryItem> Album::clone() const
{
	return std::make_unique<Album>(*this);
}
