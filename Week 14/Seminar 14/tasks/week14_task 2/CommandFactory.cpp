#include "CommandFactory.h"

#include "AddLandmarkCommand.h"
#include "LandmarkFactory.h"
#include "RemoveLandmarkCommand.h"
#include "SetDangerLevelCommand.h"

#include <algorithm>
#include <cctype>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
    std::string toLower(
        std::string text
    ) {
        std::transform(
            text.begin(),
            text.end(),
            text.begin(),
            [](unsigned char symbol) {
                return static_cast<char>(
                    std::tolower(symbol)
                    );
            }
        );

        return text;
    }

    std::vector<std::string> split(
        const std::string& text,
        char delimiter
    ) {
        std::vector<std::string> parts;
        std::string currentPart;

        for (char symbol : text) {
            if (symbol == delimiter) {
                parts.push_back(currentPart);
                currentPart.clear();
            }
            else {
                currentPart += symbol;
            }
        }

        parts.push_back(currentPart);

        return parts;
    }

    int parseInteger(
        const std::string& text,
        const std::string& fieldName
    ) {
        if (text.empty()) {
            throw std::invalid_argument(
                fieldName + " cannot be empty."
            );
        }

        try {
            std::size_t processedCharacters = 0;

            int value = std::stoi(
                text,
                &processedCharacters
            );

            if (processedCharacters != text.size()) {
                throw std::invalid_argument(
                    "Invalid integer."
                );
            }

            return value;
        }
        catch (const std::exception&) {
            throw std::invalid_argument(
                fieldName
                + " must be a valid integer."
            );
        }
    }

    double parseDouble(
        const std::string& text,
        const std::string& fieldName
    ) {
        if (text.empty()) {
            throw std::invalid_argument(
                fieldName + " cannot be empty."
            );
        }

        try {
            std::size_t processedCharacters = 0;

            double value = std::stod(
                text,
                &processedCharacters
            );

            if (processedCharacters != text.size()) {
                throw std::invalid_argument(
                    "Invalid number."
                );
            }

            return value;
        }
        catch (const std::exception&) {
            throw std::invalid_argument(
                fieldName
                + " must be a valid number."
            );
        }
    }

    std::unique_ptr<Command>
        createAddCommand(
            const std::string& args,
            Territory& target
        ) {
        std::vector<std::string> parts =
            split(args, '|');

        if (parts.size() != 6) {
            throw std::invalid_argument(
                "Invalid add command arguments. "
                "Expected: "
                "type|name|x|y|threat|extra"
            );
        }

        const std::string& landmarkType =
            parts[0];

        const std::string& landmarkName =
            parts[1];

        double x = parseDouble(
            parts[2],
            "Landmark x coordinate"
        );

        double y = parseDouble(
            parts[3],
            "Landmark y coordinate"
        );

        int threat = parseInteger(
            parts[4],
            "Landmark threat"
        );

        const std::string& extra =
            parts[5];

        std::unique_ptr<Landmark> landmark =
            LandmarkFactory::create(
                landmarkType,
                landmarkName,
                Coords{ x, y },
                threat,
                extra
            );

        return std::make_unique<
            AddLandmarkCommand
        >(
            target,
            std::move(landmark)
        );
    }
}

std::unique_ptr<Command>
CommandFactory::create(
    const std::string& type,
    const std::string& args,
    Territory& target
) {
    std::string normalizedType =
        toLower(type);

    if (normalizedType == "add") {
        return createAddCommand(
            args,
            target
        );
    }

    if (normalizedType == "remove") {
        if (args.empty()) {
            throw std::invalid_argument(
                "Remove command requires "
                "a landmark name."
            );
        }

        return std::make_unique<
            RemoveLandmarkCommand
        >(
            target,
            args
        );
    }

    if (normalizedType == "danger") {
        int newLevel = parseInteger(
            args,
            "Danger level"
        );

        return std::make_unique<
            SetDangerLevelCommand
        >(
            target,
            newLevel
        );
    }

    throw std::invalid_argument(
        "Unknown command type: " + type
    );
}