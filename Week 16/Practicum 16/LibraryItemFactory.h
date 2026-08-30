#pragma once

#include "LibraryItem.h"
#include "Song.h"

#include <memory>
#include <string>
#include <vector>

class LibraryItemFactory {
public:
    static std::unique_ptr<LibraryItem> create(
        const std::string& type,
        const std::string& title,
        const std::string& releaseDate,
        const std::vector<std::string>& arguments,
        const std::vector<Song>& songs = {}
    );
};