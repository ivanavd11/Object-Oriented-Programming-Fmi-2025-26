#include "Computer.h"

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>

Computer::Computer(
    double processorPower,
    const char* videoCardModel,
    int powerSupply,
    int ram
)
    : processorPower(0),
    videoCardModel(nullptr),
    powerSupply(0),
    ram(0) {

    setProcessorPower(processorPower);
    setVideoCardModel(videoCardModel);
    setPowerSupply(powerSupply);
    setRam(ram);
}

Computer::Computer(const Computer& other)
    : processorPower(0),
    videoCardModel(nullptr),
    powerSupply(0),
    ram(0) {
    copyFrom(other);
}

Computer& Computer::operator=(
    const Computer& other
    ) {
    if (this != &other) {
        char* newModel =
            new char[std::strlen(other.videoCardModel) + 1];

        std::strcpy(
            newModel,
            other.videoCardModel
        );

        delete[] videoCardModel;

        videoCardModel = newModel;
        processorPower = other.processorPower;
        powerSupply = other.powerSupply;
        ram = other.ram;
    }

    return *this;
}

Computer::Computer(Computer&& other) noexcept
    : processorPower(0),
    videoCardModel(nullptr),
    powerSupply(0),
    ram(0) {
    moveFrom(std::move(other));
}

Computer& Computer::operator=(
    Computer&& other
    ) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Computer::~Computer() {
    free();
}

void Computer::free() {
    delete[] videoCardModel;
    videoCardModel = nullptr;
}

void Computer::copyFrom(const Computer& other) {
    processorPower = other.processorPower;
    powerSupply = other.powerSupply;
    ram = other.ram;

    videoCardModel =
        new char[std::strlen(other.videoCardModel) + 1];

    std::strcpy(
        videoCardModel,
        other.videoCardModel
    );
}

void Computer::moveFrom(Computer&& other) noexcept {
    processorPower = other.processorPower;
    videoCardModel = other.videoCardModel;
    powerSupply = other.powerSupply;
    ram = other.ram;

    other.processorPower = 0;
    other.videoCardModel = nullptr;
    other.powerSupply = 0;
    other.ram = 0;
}

double Computer::getProcessorPower() const {
    return processorPower;
}

const char* Computer::getVideoCardModel() const {
    return videoCardModel;
}

int Computer::getPowerSupply() const {
    return powerSupply;
}

int Computer::getRam() const {
    return ram;
}

void Computer::setProcessorPower(double newPower) {
    if (newPower <= 0) {
        throw std::invalid_argument(
            "Processor power must be positive."
        );
    }

    processorPower = newPower;
}

void Computer::setVideoCardModel(
    const char* newModel
) {
    if (newModel == nullptr ||
        std::strlen(newModel) == 0) {
        throw std::invalid_argument(
            "Video card model cannot be empty."
        );
    }

    char* newModelCopy =
        new char[std::strlen(newModel) + 1];

    std::strcpy(newModelCopy, newModel);

    delete[] videoCardModel;
    videoCardModel = newModelCopy;
}

void Computer::setPowerSupply(
    int newPowerSupply
) {
    if (newPowerSupply <= 0) {
        throw std::invalid_argument(
            "Power supply must be positive."
        );
    }

    powerSupply = newPowerSupply;
}

void Computer::setRam(int newRam) {
    if (newRam <= 0) {
        throw std::invalid_argument(
            "RAM must be positive."
        );
    }

    ram = newRam;
}

void Computer::printComponents() const {
    std::cout << "Processor power: "
        << processorPower
        << " GHz\n";

    std::cout << "Video card: "
        << videoCardModel
        << '\n';

    std::cout << "Power supply: "
        << powerSupply
        << " W\n";

    std::cout << "RAM: "
        << ram
        << " GB\n";
}

void Computer::printPeripherals() const {
    std::size_t count = 0;

    const char* const* peripherals =
        getPeripherals(count);

    std::cout << "Peripherals: ";

    for (std::size_t i = 0; i < count; ++i) {
        std::cout << peripherals[i];

        if (i + 1 < count) {
            std::cout << ", ";
        }
    }

    std::cout << '\n';
}