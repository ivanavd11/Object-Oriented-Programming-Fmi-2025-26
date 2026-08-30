#include "LibraryItemFactory.h"

#include "Album.h"
#include "Book.h"
#include "Movie.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace {
    std::string toLower(std::string value) {
        std::transform(
            value.begin(),
            value.end(),
            value.begin(),
            [](unsigned char symbol) {
                return static_cast<char>(std::tolower(symbol));
            }
        );

        return value;
    }

    int parsePositiveInteger(const std::string& value) {
        std::size_t processedCharacters = 0;
        int result;

        try {
            result = std::stoi(value, &processedCharacters);
        }
        catch (const std::exception&) {
            throw std::invalid_argument(
                "The value must be a valid integer."
            );
        }

        if (processedCharacters != value.size()) {
            throw std::invalid_argument(
                "The value contains invalid characters."
            );
        }

        if (result <= 0) {
            throw std::invalid_argument(
                "The value must be positive."
            );
        }

        return result;
    }

    bool parseBoolean(const std::string& value) {
        const std::string lowerValue = toLower(value);

        if (lowerValue == "true" ||
            lowerValue == "yes" ||
            lowerValue == "1") {
            return true;
        }

        if (lowerValue == "false" ||
            lowerValue == "no" ||
            lowerValue == "0") {
            return false;
        }

        throw std::invalid_argument(
            "Boolean value must be true/false, yes/no or 1/0."
        );
    }
}

std::unique_ptr<LibraryItem> LibraryItemFactory::create(
    const std::string& type,
    const std::string& title,
    const std::string& releaseDate,
    const std::vector<std::string>& arguments,
    const std::vector<Song>& songs
) {
    const std::string normalizedType = toLower(type);

    if (normalizedType == "book") {
        if (arguments.size() != 2) {
            throw std::invalid_argument(
                "Book requires author and ISBN."
            );
        }

        return std::make_unique<Book>(
            title,
            releaseDate,
            arguments[0], // author
            arguments[1]  // ISBN
        );
    }

    if (normalizedType == "movie") {
        if (arguments.size() != 4) {
            throw std::invalid_argument(
                "Movie requires director, duration, colored and silent."
            );
        }

        const int duration = parsePositiveInteger(arguments[1]);
        const bool colored = parseBoolean(arguments[2]);
        const bool silent = parseBoolean(arguments[3]);

        return std::make_unique<Movie>(
            title,
            releaseDate,
            arguments[0], // director
            duration,
            colored,
            silent
        );
    }

    if (normalizedType == "album") {
        if (arguments.size() != 1) {
            throw std::invalid_argument(
                "Album requires an artist."
            );
        }

        return std::make_unique<Album>(
            title,
            releaseDate,
            arguments[0], // artist
            songs
        );
    }

    throw std::invalid_argument(
        "Unknown library item type: " + type
    );
}