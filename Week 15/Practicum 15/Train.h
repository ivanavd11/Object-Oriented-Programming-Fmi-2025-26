#pragma once
#include "Vehicle.h"
class Train : public Vehicle
{
    int requiredDrivers;
    int wagonCount;
    int seatingPlaces;
    int standingPlaces;
public:
    Train(
        const std::string& registrationNumber,
        int requiredDrivers,
        int wagonCount,
        int seatingPlaces,
        int standingPlaces
    );

    int getRequiredDrivers() const;
    int getWagonCount() const;
    int getSeatingPlaces() const;
    int getStandingPlaces() const;

    int getTotalCapacity() const;

    std::string getType() const override;
    void print() const override;

    std::unique_ptr<Vehicle> clone() const override;
};

