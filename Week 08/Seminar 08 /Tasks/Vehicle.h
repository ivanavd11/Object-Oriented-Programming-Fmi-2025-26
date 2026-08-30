#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

#include "Registration.h"

class Vehicle
{
private:
    Registration registration;
    std::string description;

    unsigned year;
    unsigned horsePower;

public:
    // Няма default constructor

    Vehicle(
        const Registration& registration,
        const std::string& description,
        unsigned year,
        unsigned horsePower
    );

    const Registration& getRegistration() const;

    const std::string& getDescription() const;

    unsigned getYear() const;
    unsigned getHorsePower() const;

    bool operator==(const Vehicle& other) const;
    bool operator!=(const Vehicle& other) const;

    bool operator<(const Vehicle& other) const;
    bool operator<=(const Vehicle& other) const;

    bool operator>(const Vehicle& other) const;
    bool operator>=(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& out,const Vehicle& vehicle);
};

#endif