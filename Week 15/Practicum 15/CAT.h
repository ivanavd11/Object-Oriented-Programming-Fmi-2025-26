#pragma once

#include "Ticket.h"
#include "Vehicle.h"

#include <cstddef>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class CAT {
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    std::vector<Ticket> tickets;

    void copyFrom(const CAT& other);

public:
    CAT() = default;

    CAT(const CAT& other);

    CAT& operator=(const CAT& other);

    CAT(CAT&& other) noexcept = default;

    CAT& operator=(CAT&& other) noexcept = default;

    ~CAT() = default;

    // Превозни средства
    void addVehicle( std::unique_ptr<Vehicle> vehicle);

    void addVehicle(const Vehicle& vehicle);

    std::unique_ptr<Vehicle>removeVehicle(const std::string& registrationNumber);


    // Глоби
    void addTicket(const Ticket& ticket);

    void payTicket(std::size_t index);

    std::vector<std::reference_wrapper<const Ticket>>
        findTicketsForVehicle(
            const std::string& registrationNumber
        ) const;

    std::size_t vehiclesCount() const;
    std::size_t ticketsCount() const;

    void printVehicles() const;
    void printTickets() const;
};