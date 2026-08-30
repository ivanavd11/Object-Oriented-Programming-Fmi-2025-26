#include "Car.h"
#include <stdexcept>
#include <iostream>

Car::Car(
    const std::string& registrationNumber,
    const std::string& ownerName,
    const std::string& brand,
    const std::string& model,
    int productionYear
)
    : Vehicle(registrationNumber), ownerName(ownerName), brand(brand), model(model), productionYear(productionYear)
{
    if (ownerName.empty()) {
        throw std::invalid_argument("Car owner name cannot be empty.");
    }

    if (brand.empty()) {
        throw std::invalid_argument("Car brand cannot be empty.");
    }

    if (model.empty()) {
        throw std::invalid_argument("Car model cannot be empty.");
    }

    if (productionYear <= 0) {
        throw std::invalid_argument("Production year must be positive.");
    }
}

const std::string& Car::getOwnerName() const
{
    return ownerName;
}
const std::string& Car::getBrand() const
{
    return brand;
}
const std::string& Car::getModel() const
{
    return model;
}
int Car::getProductionYear() const
{
    return productionYear;
}

std::string Car::getType() const
{
    return "Car";
}
void Car::print() const
{
    std::cout
        << "Type: " << getType()
        << ", registration number: "
        << getRegistrationNumber()
        << ", owner: " << ownerName
        << ", brand: " << brand
        << ", model: " << model
        << ", production year: "
        << productionYear
        << '\n';
}

std::unique_ptr<Vehicle>Car::clone() const
{
    return std::make_unique<Car>(*this);
}
