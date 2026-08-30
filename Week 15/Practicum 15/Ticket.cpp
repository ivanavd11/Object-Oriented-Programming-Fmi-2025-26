#include "Ticket.h"
#include <stdexcept>
#include <iostream>

Ticket::Ticket(
    const std::string&
    vehicleRegistrationNumber,
    double amount,
    const std::string& issueDate
) :vehicleRegistrationNumber(vehicleRegistrationNumber), amount(amount), issueDate(issueDate), paid(false)
{
    if (vehicleRegistrationNumber.empty()) {
        throw std::invalid_argument("Ticket vehicle registration number cannot be empty.");
    }

    if (amount <= 0) {
        throw std::invalid_argument("Ticket amount must be positive.");
    }

    if (issueDate.empty()) {
        throw std::invalid_argument("Ticket issue date cannot be empty.");
    }
}

const std::string& Ticket::getVehicleRegistrationNumber() const
{
    return vehicleRegistrationNumber;
}

double Ticket::getAmount() const
{
    return amount;
}

const std::string& Ticket::getIssueDate() const
{
    return issueDate;
}

bool Ticket::isPaid() const
{
    return paid;
}

void Ticket::pay()
{
    if (paid)
    {
        throw std::logic_error("Ticket has already been paid.");
    }

    paid = true;
}

void Ticket::print() const
{
    std::cout
        << "Vehicle registration number: "
        << vehicleRegistrationNumber
        << ", amount: "
        << amount
        << " BGN"
        << ", issue date: "
        << issueDate
        << ", status: "
        << (paid ? "paid" : "unpaid")
        << '\n';
}
