#include "ExpeditionLeader.h"
#include <iostream>
#include <stdexcept>

ExpeditionLeader::ExpeditionLeader(const std::string& name, int yearsExperience, int expeditionsLed)
	:Cartographer(name, yearsExperience), expeditionsLed(expeditionsLed)
{
	if (expeditionsLed < 0)
	{
		throw std::invalid_argument("Expeditions count must be positive");
	}
}

int ExpeditionLeader::getExpeditionsLed() const
{
	return expeditionsLed;
}

std::string ExpeditionLeader::getRole() const
{
	return "Expedition Leader";
}
void ExpeditionLeader::print() const
{
	std::cout << "Expedition Leader: " << getName()
		<< ", years of experience: " << getYears()
		<< ", expeditions counter: " << getExpeditionsLed() << "\n";
}