#pragma once
#include "LibraryItem.h"

class Movie :public LibraryItem
{
    std::string director;
    int durationMinutes;
    bool colored;
    bool silent;
public:
    Movie(const std::string& title, const std::string& releaseDate, const std::string& director, int duration,
        bool colored, bool silent);

    const std::string& getDirector() const;
    int getDurationMinutes() const;
    bool isColored() const;
    bool isSilent() const;

    std::string getType() const override;

    void printInfo() const override;
    std::unique_ptr<LibraryItem> clone() const override;
};

