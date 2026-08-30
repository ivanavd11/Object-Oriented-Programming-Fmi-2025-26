#include "VehicleList.h"

#include <stdexcept>
#include <cstring>

using namespace std;

VehicleList::VehicleList(unsigned capacity)
{
    if (capacity == 0)
    {
        capacity = 1;
    }

    currentCapacity = capacity;
    currentSize = 0;

    vehicles =new Vehicle * [currentCapacity];

    for (unsigned i = 0;i < currentCapacity;i++)
    {
        vehicles[i] = nullptr;
    }
}

void VehicleList::freeMemory()
{
    for (unsigned i = 0;i < currentCapacity;i++)
    {
        delete vehicles[i];
    }

    delete[] vehicles;

    vehicles = nullptr;

    currentSize = 0;
    currentCapacity = 0;
}

void VehicleList::copyFrom(const VehicleList& other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    vehicles =new Vehicle * [currentCapacity];

    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (other.vehicles[i] == nullptr)
        {
            vehicles[i] = nullptr;
        }
        else
        {
            vehicles[i] =new Vehicle(*other.vehicles[i]);
        }
    }
}

void VehicleList::moveFrom(VehicleList&& other)
{
    vehicles = other.vehicles;
    currentSize =other.currentSize;
    currentCapacity = other.currentCapacity;

    other.vehicles = nullptr;
    other.currentSize = 0;
    other.currentCapacity = 0;
}

VehicleList::VehicleList(const VehicleList& other)
{
    copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
    if (this != &other)
    {
        freeMemory();
        copyFrom(other);
    }

    return *this;
}

VehicleList::VehicleList(VehicleList&& other) noexcept
{
    moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
    if (this != &other)
    {
        freeMemory();
        moveFrom(std::move(other));
    }

    return *this;
}

VehicleList::~VehicleList()
{
    freeMemory();
}

void VehicleList::resize(unsigned newCapacity)
{
    Vehicle** newVehicles =new Vehicle * [newCapacity];

    for (unsigned i = 0; i < newCapacity;i++)
    {
        newVehicles[i] = nullptr;
    }

    for (unsigned i = 0;i < currentCapacity;i++)
    {
        newVehicles[i] = vehicles[i];
    }

    delete[] vehicles;

    vehicles = newVehicles;

    currentCapacity =newCapacity;
}

Vehicle* VehicleList::find(const Registration& registration)
{
    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] != nullptr && vehicles[i]->getRegistration()== registration)
        {
            return vehicles[i];
        }
    }

    return nullptr;
}

const Vehicle* VehicleList::find(const Registration& registration) const
{
    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] != nullptr && vehicles[i]->getRegistration()== registration)
        {
            return vehicles[i];
        }
    }

    return nullptr;
}

VehicleList& VehicleList::operator+=(const Vehicle& vehicle)
{
    if (find(vehicle.getRegistration())!= nullptr)
    {
        return *this;
    }

    if (currentSize == currentCapacity)
    {
        resize(currentCapacity * 2);
    }

    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] == nullptr)
        {
            vehicles[i] =new Vehicle(vehicle);
            currentSize++;
            break;
        }
    }

    return *this;
}

VehicleList&VehicleList::operator-=(const Registration& registration)
{
    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] != nullptr && vehicles[i]->getRegistration() == registration)
        {
            delete vehicles[i];
            vehicles[i] = nullptr;
            currentSize--;
            break;
        }
    }

    return *this;
}

Vehicle& VehicleList::operator[](unsigned index)
{
    if (index >= currentCapacity)
    {
        throw out_of_range(
            "Invalid index!");
    }

    if (vehicles[index] == nullptr)
    {
        throw runtime_error(
            "Slot is empty!");
    }

    return *vehicles[index];
}

const Vehicle& VehicleList::operator[](unsigned index) const
{
    if (index >= currentCapacity)
    {
        throw out_of_range(
            "Invalid index!");
    }

    if (vehicles[index] == nullptr)
    {
        throw runtime_error(
            "Slot is empty!");
    }

    return *vehicles[index];
}

bool VehicleList::isFreeSlot(unsigned pos) const
{
    if (pos >= currentCapacity)
    {
        return false;
    }

    return vehicles[pos] == nullptr;
}

bool VehicleList::isEmpty() const
{
    return currentSize == 0;
}

unsigned VehicleList::size() const
{
    return currentSize;
}

unsigned VehicleList::capacity() const
{
    return currentCapacity;
}

VehicleList::operator bool() const
{
    return currentSize > 0;
}

bool VehicleList::matchesAreaCode(const Registration& registration,const char* areaCode) const
{
    if (areaCode == nullptr)
    {
        return false;
    }

    size_t areaLength =strlen(areaCode);

    if (areaLength != 1 && areaLength != 2)
    {
        return false;
    }

    const char* code = registration.getCode();

    for (size_t i = 0; i < areaLength;i++)
    {
        char expected = toupper(static_cast<unsigned char>(areaCode[i]));

        if (code[i] != expected)
        {
            return false;
        }
    }
    return code[areaLength] >= '0' && code[areaLength] <= '9';
}

unsigned VehicleList::operator()(const char* areaCode) const
{
    unsigned result = 0;

    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] != nullptr && matchesAreaCode(vehicles[i]->getRegistration(),areaCode))
        {
            result++;
        }
    }
    return result;
}

int VehicleList::firstOccupiedIndex() const
{
    for (unsigned i = 0;i < currentCapacity;i++)
    {
        if (vehicles[i] != nullptr)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

bool VehicleList::operator<(const VehicleList& other) const
{
    if (currentSize < other.currentSize)
    {
        return true;
    }

    if (currentSize > other.currentSize)
    {
        return false;
    }

    if (currentSize == 0)
    {
        return false;
    }

    int first1 = firstOccupiedIndex();

    int first2 = other.firstOccupiedIndex();

    return vehicles[first1]->getRegistration() < other.vehicles[first2]->getRegistration();
}

bool VehicleList::operator==(const VehicleList& other) const
{
    if (currentSize != other.currentSize)
    {
        return false;
    }

    if (currentSize == 0)
    {
        return true;
    }

    int first1 = firstOccupiedIndex();
    int first2 = other.firstOccupiedIndex();

    return vehicles[first1]->getRegistration() == other.vehicles[first2]->getRegistration();
}

bool VehicleList::operator!=(const VehicleList& other) const
{
    return !(*this == other);
}

bool VehicleList::operator>(const VehicleList& other) const
{
    return other < *this;
}

bool VehicleList::operator<=(const VehicleList& other) const
{
    return !(*this > other);
}

bool VehicleList::operator>=(const VehicleList& other) const
{
    return !(*this < other);
}

ostream& operator<<(ostream& out,const VehicleList& list)
{
    for (unsigned i = 0;i < list.currentCapacity;i++)
    {
        if (list.vehicles[i] == nullptr)
        {
            out << "[*]";
        }
        else
        {
            out << "[" << list.vehicles[i]->getRegistration() << "]";
        }

        if (i + 1 < list.currentCapacity)
        {
            out << " ";
        }
    }

    return out;
}