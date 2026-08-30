#include "PC.h"

#include <iostream>

PC::PC(
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

void PC::printComputerType() const {
    std::cout << "Computer type: PC\n";
}

const char* const* PC::getPeripherals(
    std::size_t& count
) const {
    static const char* peripherals[] = {
        "mouse",
        "keyboard",
        "microphone",
        "headphones"
    };

    count = 4;
    return peripherals;
}