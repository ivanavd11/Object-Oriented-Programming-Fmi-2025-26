#pragma once

#include <memory>
#include <string>

class Vehicle {
private:
    std::string registrationNumber;

public:
    explicit Vehicle(const std::string& registrationNumber);

    const std::string&getRegistrationNumber() const;

    virtual std::string getType() const = 0;
    virtual void print() const = 0;

    virtual std::unique_ptr<Vehicle>clone() const = 0;

    virtual ~Vehicle() = default;
};