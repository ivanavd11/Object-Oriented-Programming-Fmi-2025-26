#include "Train.h"
#include <stdexcept>
#include <iostream>

Train::Train(
    const std::string& registrationNumber,
    int requiredDrivers,
    int wagonCount,
    int seatingPlaces,
    int standingPlaces
)
    :Vehicle(registrationNumber), requiredDrivers(requiredDrivers),wagonCount(wagonCount),
    seatingPlaces(seatingPlaces), standingPlaces(standingPlaces) 
{
    if (requiredDrivers <= 0) {
        throw std::invalid_argument("Train must require at least one driver.");
    }

    if (wagonCount <= 0) {
        throw std::invalid_argument("Train must have at least one wagon.");
    }

    if (seatingPlaces < 0) {
        throw std::invalid_argument("Seating places cannot be negative." );
    }

    if (standingPlaces < 0) {
        throw std::invalid_argument("Standing places cannot be negative.");
    }
}

int Train::getRequiredDrivers() const {
    return requiredDrivers;
}

int Train::getWagonCount() const {
    return wagonCount;
}

int Train::getSeatingPlaces() const {
    return seatingPlaces;
}

int Train::getStandingPlaces() const {
    return standingPlaces;
}

int Train::getTotalCapacity() const {
    return seatingPlaces + standingPlaces;
}

std::string Train::getType() const {
    return "Train";
}

void Train::print() const {
    std::cout
        << "Type: " << getType()
        << ", registration number: "
        << getRegistrationNumber()
        << ", required drivers: "
        << requiredDrivers
        << ", wagons: " << wagonCount
        << ", seating places: "
        << seatingPlaces
        << ", standing places: "
        << standingPlaces
        << ", total capacity: "
        << getTotalCapacity()
        << '\n';
}

std::unique_ptr<Vehicle>
Train::clone() const {
    return std::make_unique<Train>(*this);
}
