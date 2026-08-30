#include "CAT.h"
#include <stdexcept>
#include <iostream>

void CAT::copyFrom(const CAT& other)
{
	vehicles.reserve(other.vehicles.size());

	for (const auto& vehicle : other.vehicles)
	{
		vehicles.push_back(vehicle->clone());
	}
}

CAT::CAT(const CAT& other): tickets(other.tickets) 
{
	copyFrom(other);
}

CAT& CAT::operator=(const CAT& other) {
	if (this != &other)
	{
		CAT copy(other);
		tickets.swap(copy.tickets);
		vehicles.swap(copy.vehicles);
	}
	return *this;
}

void CAT::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    if (!vehicle) {
        throw std::invalid_argument("Cannot add an empty vehicle.");
    }

    if (findVehicle(vehicle->getRegistrationNumber())) {
        throw std::invalid_argument(
            "Vehicle with registration number "
            + vehicle->getRegistrationNumber()
            + " already exists.");
    }

    vehicles.push_back(std::move(vehicle));
}

void CAT::addVehicle(const Vehicle& vehicle) {
    if (findVehicle(vehicle.getRegistrationNumber())) {
        throw std::invalid_argument(
            "Vehicle with registration number "
            + vehicle.getRegistrationNumber()
            + " already exists."
        );
    }

    vehicles.push_back(vehicle.clone());
}

std::unique_ptr<Vehicle> CAT::removeVehicle(const std::string& registrationNumber) {
    for (std::size_t i = 0;
        i < vehicles.size();
        i++) {
        if (vehicles[i]->getRegistrationNumber()== registrationNumber) {
            std::unique_ptr<Vehicle> removed =std::move(vehicles[i]);

            vehicles.erase(vehicles.begin() + i);

            return removed;
        }
    }

    return nullptr;
}

void CAT::addTicket(const Ticket& ticket)
{
    if (!findVehicle(ticket.getVehicleRegistrationNumber())) {
        throw std::invalid_argument(
            "Cannot add ticket because vehicle "
            + ticket.getVehicleRegistrationNumber()
            + " is not registered."
        );
    }

    tickets.push_back(ticket);
}

void CAT::payTicket(std::size_t index) {
    if (index >= tickets.size()) {
        throw std::out_of_range("Invalid ticket index.");
    }

    tickets[index].pay();
}

std::size_t CAT::vehiclesCount() const {
    return vehicles.size();
}

std::size_t CAT::ticketsCount() const {
    return tickets.size();
}

void CAT::printVehicles() const {
    if (vehicles.empty()) {
        std::cout
            << "There are no registered vehicles.\n";
        return;
    }

    std::cout << "Registered vehicles:\n";

    for (const auto& vehicle : vehicles) {
        vehicle->print();
    }
}

void CAT::printTickets() const {
    if (tickets.empty()) {
        std::cout
            << "There are no registered tickets.\n";
        return;
    }

    std::cout << "Registered tickets:\n";

    for (std::size_t i = 0;
        i < tickets.size();
        i++) {
        std::cout
            << "Ticket index " << i << ": ";

        tickets[i].print();
    }
}