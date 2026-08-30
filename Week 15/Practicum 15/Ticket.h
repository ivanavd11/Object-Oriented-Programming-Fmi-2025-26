#pragma once
#include <string>
class Ticket
{
    std::string vehicleRegistrationNumber;
    double amount;
    std::string issueDate;
    bool paid;
public:
    Ticket(
        const std::string&
        vehicleRegistrationNumber,
        double amount,
        const std::string& issueDate
    );

    const std::string&
        getVehicleRegistrationNumber() const;

    double getAmount() const;

    const std::string&
        getIssueDate() const;

    bool isPaid() const;

    void pay();

    void print() const;
};

