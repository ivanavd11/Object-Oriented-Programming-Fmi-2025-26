#include "Vehicle.h"

#include <stdexcept>

using namespace std;

Vehicle::Vehicle(
    const Registration& registration,
    const string& description,
    unsigned year,
    unsigned horsePower)
    : registration(registration),
    description(description),
    year(year),
    horsePower(horsePower)
{
    if (description.empty())
    {
        throw invalid_argument(
            "Description cannot be empty!"
        );
    }

    if (year == 0)
    {
        throw invalid_argument(
            "Invalid year!"
        );
    }

    if (horsePower == 0)
    {
        throw invalid_argument(
            "Invalid horse power!"
        );
    }
}

const Registration& Vehicle::getRegistration() const
{
    return registration;
}

const string& Vehicle::getDescription() const
{
    return description;
}

unsigned Vehicle::getYear() const
{
    return year;
}

unsigned Vehicle::getHorsePower() const
{
    return horsePower;
}

bool Vehicle::operator==(const Vehicle& other) const
{
    return year == other.year &&
        horsePower == other.horsePower;
}

bool Vehicle::operator!=(const Vehicle& other) const
{
    return !(*this == other);
}

bool Vehicle::operator<(const Vehicle& other) const
{
    if (year < other.year)
    {
        return true;
    }

    if (year > other.year)
    {
        return false;
    }

    return horsePower < other.horsePower;
}

bool Vehicle::operator>(const Vehicle& other) const
{
    return other < *this;
}

bool Vehicle::operator<=(const Vehicle& other) const
{
    return !(*this > other);
}

bool Vehicle::operator>=(const Vehicle& other) const
{
    return !(*this < other);
}

ostream& operator<<(ostream& out,const Vehicle& vehicle)
{
    out << "["
        << vehicle.registration
        << "] "
        << vehicle.description
        << ", Year: "
        << vehicle.year
        << ", HP: "
        << vehicle.horsePower;

    return out;
}