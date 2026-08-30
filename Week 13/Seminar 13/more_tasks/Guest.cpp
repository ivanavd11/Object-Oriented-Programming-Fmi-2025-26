#include "Guest.h"

#include <iostream>

Guest::Guest(
    int id,
    unsigned int remainingPlayTime
)
    : Player(id),
    remainingPlayTime(remainingPlayTime) {
}

void Guest::setRemainingPlayTime(
    unsigned int newTime
) {
    remainingPlayTime = newTime;
}

unsigned int Guest::getRemainingPlayTime() const {
    return remainingPlayTime;
}

bool Guest::levelUp() {
    // Гостът никога не може да получи нова звезда.
    return false;
}

void Guest::printInfo() const {
    Player::printInfo();

    std::cout << "Remaining play time: "
        << remainingPlayTime
        << " minutes\n";

    std::cout << "Account type: Guest\n";
}