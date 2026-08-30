#pragma once
#include "Vehicle.h"

class Motorcycle :public Vehicle
{
	std::string ownerName;
	double maximumSpeed;

public:
    Motorcycle(
        const std::string& registrationNumber,
        const std::string& ownerName,
        double maximumSpeed);

    const std::string& getOwnerName() const;
    double getMaximumSpeed() const;

    std::string getType() const override;
    void print() const override;

    std::unique_ptr<Vehicle>clone() const override;
};

