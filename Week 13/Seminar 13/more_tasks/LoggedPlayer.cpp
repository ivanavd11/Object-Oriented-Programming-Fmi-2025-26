#include "LoggedPlayer.h"

#include <iostream>
#include <stdexcept>

LoggedPlayer::LoggedPlayer(
    int id,
    const std::string& password
)
    : Player(id), password(password) {

    validatePassword(password);
}

void LoggedPlayer::validatePassword(
    const std::string& password
) {
    if (password.empty()) {
        throw std::invalid_argument(
            "Password cannot be empty."
        );
    }

    if (password.length() > 8) {
        throw std::invalid_argument(
            "Password cannot contain more than 8 characters."
        );
    }
}

void LoggedPlayer::setPassword(
    const std::string& newPassword
) {
    validatePassword(newPassword);
    password = newPassword;
}

bool LoggedPlayer::login(
    int enteredId,
    const std::string& enteredPassword
) const {
    return enteredId == getId() &&
        enteredPassword == password;
}

bool LoggedPlayer::levelUp() {
    return Player::levelUp();
}

void LoggedPlayer::printInfo() const {
    Player::printInfo();
    std::cout << "Account type: Logged player\n";
}