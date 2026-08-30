#include "Movie.h"
#include <stdexcept>
#include <iostream>


Movie::Movie(const std::string& title, const std::string& releaseDate, const std::string& director, int duration,
    bool colored, bool silent)
    :LibraryItem(title, releaseDate), director(director), durationMinutes(duration), colored(colored), silent(silent)
{
    if (director.empty()) {
        throw std::invalid_argument("Movie director cannot be empty.");
    }

    if (durationMinutes <= 0) {
        throw std::invalid_argument("Movie duration must be positive.");
    }
}

const std::string& Movie::getDirector() const
{
    return director;
}
int Movie::getDurationMinutes() const
{
    return durationMinutes;
}
bool Movie::isColored() const
{
    return colored;
}
bool Movie::isSilent() const
{
    return silent;
}

std::string Movie::getType() const
{
    return "Movie";
}

void Movie::printInfo() const
{
    printBaseInfo();
    std::cout << ", director: " << director
        << ", duration: " << durationMinutes << " minutes"
        << ", picture: " << (colored ? "colored" : "black and white")
        << ", sound: " << (silent ? "silent movie" : "sound movie") << "\n";
}
std::unique_ptr<LibraryItem> Movie::clone() const 
{
    return std::make_unique<Movie>(*this);
}