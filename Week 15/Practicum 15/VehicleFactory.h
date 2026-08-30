#pragma once

#include "Vehicle.h"

#include <memory>
#include <string>
#include <vector>

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> create(
        const std::string& type,
        const std::string& registrationNumber,
        const std::vector<std::string>& arguments
    );
};