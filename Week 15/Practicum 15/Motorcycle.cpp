#include "Motorcycle.h"
#include <stdexcept>
#include <iostream>

Motorcycle::Motorcycle(
    const std::string& registrationNumber,
    const std::string& ownerName,
    double maximumSpeed)
    :Vehicle(registrationNumber), ownerName(ownerName), maximumSpeed(maximumSpeed)
{
    if (ownerName.empty()) {
        throw std::invalid_argument("Motorcycle owner name cannot be empty.");
    }

    if (maximumSpeed <= 0) {
        throw std::invalid_argument("Maximum speed must be positive.");
    }
}

const std::string& Motorcycle::getOwnerName() const
{
    return ownerName;
}
double Motorcycle::getMaximumSpeed() const
{
    return maximumSpeed;
}

std::string Motorcycle::getType() const
{
    return "Motorcycle";
}
void Motorcycle::print() const
{
    std::cout
        << "Type: " << getType()
        << ", registration number: "
        << getRegistrationNumber()
        << ", owner: " << ownerName
        << ", maximum speed: "<<maximumSpeed
        << " km/h\n";
}

std::unique_ptr<Vehicle>Motorcycle::clone() const
{
    return std::make_unique<Motorcycle>(*this);
}