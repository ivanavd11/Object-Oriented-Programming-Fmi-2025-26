#pragma once

#ifndef VEHICLE_LIST_H
#define VEHICLE_LIST_H

#include "Vehicle.h"

class VehicleList
{
private:
    Vehicle** vehicles;

    unsigned currentSize;
    unsigned currentCapacity;

    void freeMemory();
    void copyFrom(const VehicleList& other);
    void moveFrom(VehicleList&& other);

    void resize(unsigned newCapacity);

    int firstOccupiedIndex() const;

    bool matchesAreaCode(const Registration& registration,const char* areaCode) const;

public:
    VehicleList(unsigned capacity);

    VehicleList(const VehicleList& other);

    VehicleList& operator=(const VehicleList& other);

    VehicleList(VehicleList&& other) noexcept;

    VehicleList& operator=(VehicleList&& other) noexcept;

    ~VehicleList();

    VehicleList& operator+=(const Vehicle& vehicle);

    VehicleList& operator-=(const Registration& registration);

    Vehicle& operator[](unsigned index);

    const Vehicle& operator[](unsigned index) const;

    explicit operator bool() const;

    unsigned operator()(const char* areaCode) const;

    bool isFreeSlot(unsigned pos) const;

    bool isEmpty() const;

    unsigned capacity() const;

    unsigned size() const;

    Vehicle* find(const Registration& registration);

    const Vehicle* find(const Registration& registration) const;

    bool operator==(const VehicleList& other) const;
    bool operator!=(const VehicleList& other) const;

    bool operator<(const VehicleList& other) const;
    bool operator<=(const VehicleList& other) const;

    bool operator>(const VehicleList& other) const;
    bool operator>=(const VehicleList& other) const;

    friend std::ostream& operator<<(std::ostream& out,const VehicleList& list);
};

#endif
