#include "GamingConsole.h"

#include <iostream>

GamingConsole::GamingConsole(
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

void GamingConsole::printComputerType() const {
    std::cout << "Computer type: Gaming console\n";
}

const char* const* GamingConsole::getPeripherals(
    std::size_t& count
) const {
    static const char* peripherals[] = {
        "joystick",
        "monitor"
    };

    count = 2;
    return peripherals;
}