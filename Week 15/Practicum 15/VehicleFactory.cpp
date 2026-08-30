#include "VehicleFactory.h"

#include "Car.h"
#include "Motorcycle.h"
#include "Train.h"

#include <algorithm>
#include <cctype>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace {
    std::string toLower(
        std::string text
    ) {
        std::transform(
            text.begin(),
            text.end(),
            text.begin(),
            [](unsigned char symbol) {
                return static_cast<char>(
                    std::tolower(symbol)
                    );
            }
        );

        return text;
    }

    int parseInteger(
        const std::string& text,
        const std::string& fieldName
    ) {
        if (text.empty()) {
            throw std::invalid_argument(
                fieldName + " cannot be empty."
            );
        }

        try {
            std::size_t processedCharacters = 0;

            int value = std::stoi(
                text,
                &processedCharacters
            );

            if (processedCharacters != text.size()) {
                throw std::invalid_argument(
                    "Invalid integer."
                );
            }

            return value;
        }
        catch (const std::exception&) {
            throw std::invalid_argument(
                fieldName
                + " must be a valid integer."
            );
        }
    }

    double parseDouble(
        const std::string& text,
        const std::string& fieldName
    ) {
        if (text.empty()) {
            throw std::invalid_argument(
                fieldName + " cannot be empty."
            );
        }

        try {
            std::size_t processedCharacters = 0;

            double value = std::stod(
                text,
                &processedCharacters
            );

            if (processedCharacters != text.size()) {
                throw std::invalid_argument(
                    "Invalid number."
                );
            }

            return value;
        }
        catch (const std::exception&) {
            throw std::invalid_argument(
                fieldName
                + " must be a valid number."
            );
        }
    }

    std::unique_ptr<Vehicle> createCar(
        const std::string& registrationNumber,
        const std::vector<std::string>& arguments
    ) {
        if (arguments.size() != 4) {
            throw std::invalid_argument(
                "Car requires exactly 4 arguments: "
                "owner, brand, model, production year."
            );
        }

        const std::string& ownerName =
            arguments[0];

        const std::string& brand =
            arguments[1];

        const std::string& model =
            arguments[2];

        int productionYear = parseInteger(
            arguments[3],
            "Car production year"
        );

        return std::make_unique<Car>(
            registrationNumber,
            ownerName,
            brand,
            model,
            productionYear
        );
    }

    std::unique_ptr<Vehicle>
        createMotorcycle(
            const std::string& registrationNumber,
            const std::vector<std::string>& arguments
        ) {
        if (arguments.size() != 2) {
            throw std::invalid_argument(
                "Motorcycle requires exactly "
                "2 arguments: owner and maximum speed."
            );
        }

        const std::string& ownerName =
            arguments[0];

        double maximumSpeed = parseDouble(
            arguments[1],
            "Motorcycle maximum speed"
        );

        return std::make_unique<Motorcycle>(
            registrationNumber,
            ownerName,
            maximumSpeed
        );
    }

    std::unique_ptr<Vehicle> createTrain(
        const std::string& registrationNumber,
        const std::vector<std::string>& arguments
    ) {
        if (arguments.size() != 4) {
            throw std::invalid_argument(
                "Train requires exactly 4 arguments: "
                "drivers, wagons, seating places "
                "and standing places."
            );
        }

        int requiredDrivers = parseInteger(
            arguments[0],
            "Required drivers"
        );

        int wagonCount = parseInteger(
            arguments[1],
            "Wagon count"
        );

        int seatingPlaces = parseInteger(
            arguments[2],
            "Seating places"
        );

        int standingPlaces = parseInteger(
            arguments[3],
            "Standing places"
        );

        return std::make_unique<Train>(
            registrationNumber,
            requiredDrivers,
            wagonCount,
            seatingPlaces,
            standingPlaces
        );
    }
}

std::unique_ptr<Vehicle>
VehicleFactory::create(
    const std::string& type,
    const std::string& registrationNumber,
    const std::vector<std::string>& arguments
) {
    std::string normalizedType =
        toLower(type);

    if (normalizedType == "car") {
        return createCar(
            registrationNumber,
            arguments
        );
    }

    if (normalizedType == "motorcycle") {
        return createMotorcycle(
            registrationNumber,
            arguments
        );
    }

    if (normalizedType == "train") {
        return createTrain(
            registrationNumber,
            arguments
        );
    }

    throw std::invalid_argument(
        "Unknown vehicle type: " + type
    );
}
