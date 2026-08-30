#include "CPU.h"
#include <stdexcept>
#include <iostream>

CPU::CPU(const std::string& label, unsigned short cores, unsigned short clockSpeed)
	:Component(label), cores(cores), clockSpeed(clockSpeed)
{
	if (cores < 1 || cores >8)
	{
		throw std::invalid_argument("Cores must be between 1 and 8.");
	}
}

unsigned short CPU::getCores() const
{
	return cores;
}
unsigned short CPU::getClockSpeed() const
{
	return clockSpeed;
}

constexpr double PRISE_FOR_CPU = 19.99;

double CPU::price() const
{
	return cores * PRISE_FOR_CPU;
}
void CPU::output(std::ostream& os) const
{
	os << "CPU label: " << this->getLabel()
		<< " with cores: " << this->getCores()
		<< " and clockSpeed: " << this->getClockSpeed() << "MHz"
		<< ", price: " << price() << " Euro\n";
}

std::unique_ptr<Component>CPU::clone() const
{
	return std::make_unique<CPU>(*this);
}
