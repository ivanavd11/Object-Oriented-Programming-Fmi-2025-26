#ifndef COMPUTER_H
#define COMPUTER_H

#include <cstddef>

class Computer {
private:
    double processorPower;
    char* videoCardModel;
    int powerSupply;
    int ram;

    void free();
    void copyFrom(const Computer& other);
    void moveFrom(Computer&& other) noexcept;

protected:
    Computer(
        double processorPower,
        const char* videoCardModel,
        int powerSupply,
        int ram
    );

public:
    Computer(const Computer& other);
    Computer& operator=(const Computer& other);

    Computer(Computer&& other) noexcept;
    Computer& operator=(Computer&& other) noexcept;

    virtual ~Computer();

    double getProcessorPower() const;
    const char* getVideoCardModel() const;
    int getPowerSupply() const;
    int getRam() const;

    void setProcessorPower(double newPower);
    void setVideoCardModel(const char* newModel);
    void setPowerSupply(int newPowerSupply);
    void setRam(int newRam);

    virtual void printComputerType() const = 0;

    virtual const char* const* getPeripherals(
        std::size_t& count
    ) const = 0;

    void printComponents() const;
    void printPeripherals() const;
};

#endif