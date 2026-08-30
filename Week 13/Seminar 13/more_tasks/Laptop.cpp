#include "Laptop.h"

#include <iostream>

Laptop::Laptop(
    double processorPower,
    const char* videoCardModel,
    int powerSupply,
    int ram
)
    : Computer(
        processorPower,
        videoCardModel,
        powerSupply,
        ram
    ) {
}

void Laptop::printComputerType() const {
    std::cout << "Computer type: Laptop\n";
}

const char* const* Laptop::getPeripherals(
    std::size_t& count
) const {
    static const char* peripherals[] = {
        "mouse pad",
        "keyboard",
        "monitor"
    };

    count = 3;
    return peripherals;
}