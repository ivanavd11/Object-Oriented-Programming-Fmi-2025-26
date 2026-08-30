#ifndef PC_H
#define PC_H

#include "Computer.h"

class PC : public Computer {
public:
    PC(
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
