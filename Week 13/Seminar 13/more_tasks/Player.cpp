#include "Player.h"

#include <iostream>
#include <stdexcept>

Player::Player(int id)
    : id(id),
    points(0),
    stars(Stars::One) {

    if (id < 0) {
        throw std::invalid_argument(
            "Player ID cannot be negative."
        );
    }
}

int Player::getId() const {
    return id;
}

std::uint64_t Player::getPoints() const {
    return points;
}

Stars Player::getStars() const {
    return stars;
}

void Player::completeMission(
    std::uint64_t earnedPoints
) {
    points += earnedPoints;
}

bool Player::exchangePointsForStar(
    std::uint64_t requiredPoints
) {
    if (stars == Stars::Five) {
        return false;
    }

    if (points < requiredPoints) {
        return false;
    }

    points -= requiredPoints;

    stars = static_cast<Stars>(
        static_cast<int>(stars) + 1
        );

    return true;
}

bool Player::levelUp() {
    switch (stars) {
    case Stars::One:
        return exchangePointsForStar(256);

    case Stars::Two:
        return exchangePointsForStar(512);

    case Stars::Three:
        return exchangePointsForStar(1024);

    case Stars::Four:
        return exchangePointsForStar(2048);

    case Stars::Five:
        return false;
    }

    return false;
}

void Player::printInfo() const {
    std::cout << "Player ID: " << id << '\n';
    std::cout << "Points: " << points << '\n';

    std::cout << "Stars: "
        << static_cast<int>(stars)
        << '\n';
}