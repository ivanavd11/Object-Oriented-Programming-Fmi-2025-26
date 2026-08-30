#ifndef LAPTOP_H
#define LAPTOP_H

#include "Computer.h"

class Laptop : public Computer {
public:
    Laptop(
        double processorPower,
        const char* videoCardModel,
        int powerSupply,
        int ram
    );

    void printComputerType() const override;

    const char* const* getPeripherals(
        std::size_t& count
    ) const override;
};

#endif
