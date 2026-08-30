#include "Map.h"

#include <iostream>
#include <stdexcept>
#include <utility>

Map::Map(
    const std::string& title,
    std::shared_ptr<Territory> territory
)
    : title(title),
    territory(std::move(territory)) {
    if (title.empty()) {
        throw std::invalid_argument(
            "Map title cannot be empty."
        );
    }

    if (!this->territory) {
        throw std::invalid_argument(
            "Map territory cannot be empty."
        );
    }
}

Map::Map(
    const std::string& title,
    Territory territory
)
    : title(title),
    territory(
        std::make_shared<Territory>(
            std::move(territory)
        )
    ) {
    if (title.empty()) {
        throw std::invalid_argument(
            "Map title cannot be empty."
        );
    }
}

Map::Map(const Map& other)
    : title(other.title),
    territory(other.territory),
    cartographers(other.cartographers) {
    // history умишлено остава празна.
}

Map& Map::operator=(const Map& other) {
    if (this != &other) {
        Map copy(other);

        title.swap(copy.title);
        territory.swap(copy.territory);

        cartographers.swap(
            copy.cartographers
        );

        // При копиране новата карта започва
        // с празна история.
        history.clear();
    }

    return *this;
}

const std::string& Map::getTitle() const {
    return title;
}

void Map::setTitle(
    const std::string& newTitle
) {
    if (newTitle.empty()) {
        throw std::invalid_argument(
            "Map title cannot be empty."
        );
    }

    title = newTitle;
}

Territory& Map::getTerritory() {
    return *territory;
}

const Territory&
Map::getTerritory() const {
    return *territory;
}

bool Map::isLinked() const {
    return territory.use_count() > 1;
}

long Map::useCount() const {
    return territory.use_count();
}

void Map::unlink() {
    if (!isLinked()) {
        return;
    }

    territory =
        std::make_shared<Territory>(
            *territory
        );

    history.clear();
}

void Map::addCartographer(
    std::shared_ptr<Cartographer>
    cartographer
) {
    if (!cartographer) {
        throw std::invalid_argument(
            "Cannot add an empty cartographer."
        );
    }

    cartographers.push_back(
        std::move(cartographer)
    );
}

void Map::execute(
    std::unique_ptr<Command> command
) {
    if (!command) {
        throw std::invalid_argument(
            "Cannot execute an empty command."
        );
    }

    command->execute();

    history.push_back(
        std::move(command)
    );
}

void Map::undo() {
    if (history.empty()) {
        throw std::logic_error(
            "There are no commands to undo."
        );
    }

    history.back()->undo();

    history.pop_back();
}

void Map::printHistory() const {
    if (history.empty()) {
        std::cout
            << "History is empty.\n";

        return;
    }

    std::cout
        << "History for map \""
        << title
        << "\":\n";

    for (std::size_t i = 0;
        i < history.size();
        i++) {
        std::cout
            << i + 1
            << ". "
            << history[i]->description()
            << '\n';
    }
}

void Map::print() const {
    std::cout
        << "================================\n"
        << "Map: " << title << '\n'
        << "Territory use_count: "
        << territory.use_count()
        << '\n'
        << "Linked: "
        << std::boolalpha
        << isLinked()
        << '\n';

    territory->print();

    std::cout
        << "Cartographers: "
        << cartographers.size()
        << '\n';

    for (const auto& cartographer
        : cartographers) {
        std::cout << "- ";
        cartographer->print();
    }

    std::cout
        << "================================\n";
}