#include "Memory.h"
#include <stdexcept>
#include <iostream>

Memory::Memory(const std::string& label, unsigned short capacity)
	:Component(label), capacity(capacity)
{
	if (capacity < 0 || capacity>10000)
	{
		throw std::invalid_argument("Capacity must be between 1 and 10000 GB");
	}
}

unsigned short Memory::getCapacity() const
{
	return capacity;
}

constexpr double PRICE_FOR_MEMORY = 49.99;
double Memory::price() const
{
	return capacity * PRICE_FOR_MEMORY;
}
void Memory::output(std::ostream& os) const
{
	os << "Memory label: " << this->getLabel()
		<< " with capacity: " << this->getCapacity() << " GB"
		<< " and price: " << price() << " Evro\n";
}

std::unique_ptr<Component>Memory::clone() const
{
	return std::make_unique<Memory>(*this);
}