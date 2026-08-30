#pragma once

#include "Landmark.h"

#include <memory>
#include <string>

class LandmarkFactory 
{
public:
    static std::unique_ptr<Landmark> create(
        const std::string& type,
        const std::string& name,
        Coords coords,
        int threat,
        const std::string& extra = ""
    );
};