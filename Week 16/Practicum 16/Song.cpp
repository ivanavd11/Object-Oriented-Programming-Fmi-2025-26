#include "Song.h"
#include <stdexcept>
#include <iostream>

Song::Song(const std::string& name, int duration)
	:name(name), duration(duration)
{
    if (name.empty()) {
        throw std::invalid_argument("Song name cannot be empty.");
    }

    if (duration <= 0) {
        throw std::invalid_argument("Song duration must be positive.");
    }
}

const std::string& Song::getName() const
{
	return name;
}
int Song::getDuration() const
{
	return duration;
}

void Song::print() const
{
	std::cout << "Song name: " << name
		<< ", duration: " << duration << "seconds\n";
}