#pragma once

#include "Cartographer.h"
#include "Command.h"
#include "Territory.h"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class Map {
private:
    std::string title;

    std::shared_ptr<Territory> territory;

    std::vector<
        std::shared_ptr<Cartographer>
    > cartographers;

    std::vector<
        std::unique_ptr<Command>
    > history;

public:
    Map(
        const std::string& title,
        std::shared_ptr<Territory> territory
    );

    Map(
        const std::string& title,
        Territory territory
    );

    Map(const Map& other);

    Map& operator=(const Map& other);

    Map(Map&& other) noexcept = default;

    Map& operator=(
        Map&& other
        ) noexcept = default;

    ~Map() = default;

    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);

    Territory& getTerritory();
    const Territory& getTerritory() const;

    bool isLinked() const;
    long useCount() const;

    void unlink();

    void addCartographer(
        std::shared_ptr<Cartographer>
        cartographer
    );

    void execute(
        std::unique_ptr<Command> command
    );

    void undo();

    void printHistory() const;
    void print() const;
};