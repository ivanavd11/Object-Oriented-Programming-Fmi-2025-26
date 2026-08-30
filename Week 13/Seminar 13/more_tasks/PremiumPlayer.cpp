#include "PremiumPlayer.h"

#include <iostream>
#include <stdexcept>

PremiumPlayer::PremiumPlayer(
    int id,
    const std::string& password,
    const std::string& name
)
    : LoggedPlayer(id, password),
    name(name) {

    if (name.empty()) {
        throw std::invalid_argument(
            "Premium player name cannot be empty."
        );
    }
}

void PremiumPlayer::setName(
    const std::string& newName
) {
    if (newName.empty()) {
        throw std::invalid_argument(
            "Premium player name cannot be empty."
        );
    }

    name = newName;
}

const std::string& PremiumPlayer::getName() const {
    return name;
}

bool PremiumPlayer::levelUp() {
    return exchangePointsForStar(256);
}

void PremiumPlayer::sendMessage(
    const std::string& message
) const {
    std::cout << '[' << name << "]: "
        << message << '\n';
}

void PremiumPlayer::printInfo() const {
    Player::printInfo();

    std::cout << "Name: " << name << '\n';
    std::cout << "Account type: Premium player\n";
}