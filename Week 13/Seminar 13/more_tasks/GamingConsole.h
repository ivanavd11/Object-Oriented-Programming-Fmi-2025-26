#ifndef GAMING_CONSOLE_H
#define GAMING_CONSOLE_H

#include "Computer.h"

class GamingConsole : public Computer {
public:
    GamingConsole(
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
