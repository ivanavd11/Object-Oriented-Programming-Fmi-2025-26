#include "LandmarkFactory.h"

#include "LandmarkFactory.h"

#include "Dungeon.h"
#include "NaturalFeature.h"
#include "Ruin.h"
#include "Settlement.h"

#include <algorithm>
#include <cctype>
#include <memory>
#include <stdexcept>
#include <string>

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

            if (processedCharacters
                != text.size()) {
                throw std::invalid_argument(
                    fieldName
                    + " must be a valid integer."
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

    FeatureKind parseFeatureKind(
        const std::string& text
    ) {
        std::string normalized = toLower(text);

        if (normalized == "volcano") {
            return FeatureKind::Volcano;
        }

        if (normalized == "forest") {
            return FeatureKind::Forest;
        }

        if (normalized == "lake") {
            return FeatureKind::Lake;
        }

        if (normalized == "bog") {
            return FeatureKind::Bog;
        }

        if (normalized == "mountain") {
            return FeatureKind::Mountain;
        }

        if (normalized == "desert") {
            return FeatureKind::Desert;
        }

        throw std::invalid_argument(
            "Unknown natural feature kind: "
            + text
        );
    }
}

std::unique_ptr<Landmark>
LandmarkFactory::create(
    const std::string& type,
    const std::string& name,
    Coords coords,
    int threat,
    const std::string& extra
) {
    std::string normalizedType =
        toLower(type);

    if (normalizedType == "settlement") {
        int population = parseInteger(
            extra,
            "Settlement population"
        );

        return std::make_unique<Settlement>(
            name,
            coords,
            threat,
            population
        );
    }

    if (normalizedType == "dungeon") {
        int depth = parseInteger(
            extra,
            "Dungeon depth"
        );

        return std::make_unique<Dungeon>(
            name,
            coords,
            threat,
            depth
        );
    }

    if (normalizedType == "ruin") {
        if (extra.empty()) {
            throw std::invalid_argument(
                "Ruin civilization cannot be empty."
            );
        }

        return std::make_unique<Ruin>(
            name,
            coords,
            threat,
            extra
        );
    }

    if (normalizedType == "natural") {
        FeatureKind kind =
            parseFeatureKind(extra);

        return std::make_unique<NaturalFeature>(
            name,
            coords,
            threat,
            kind
        );
    }

    throw std::invalid_argument(
        "Unknown landmark type: " + type
    );
}
