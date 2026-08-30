#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
	std::string ownerName;
	std::string brand;
	std::string model;
	int productionYear;
public:
    Car(
        const std::string& registrationNumber,
        const std::string& ownerName,
        const std::string& brand,
        const std::string& model,
        int productionYear
    );

    const std::string& getOwnerName() const;
    const std::string& getBrand() const;
    const std::string& getModel() const;
    int getProductionYear() const;

    std::string getType() const override;
    void print() const override;

    std::unique_ptr<Vehicle>clone() const override;
};

