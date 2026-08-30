#pragma once
#include "Component.h"
class CPU : public Component
{
private:
	const unsigned short cores;
	const unsigned short clockSpeed;
public:
	CPU(const std::string& label, unsigned short cores, unsigned short clockSpeed);

	unsigned short getCores() const;
	unsigned short getClockSpeed() const;

	double price() const override;
	void output(std::ostream& os) const override;

	std::unique_ptr<Component>clone() const override;
};

