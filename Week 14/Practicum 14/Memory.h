#pragma once
#include "Component.h"

class Memory: public Component
{
private:
	const unsigned short capacity;
public:
	Memory(const std::string& label, unsigned short capacity);

	unsigned short getCapacity() const;

	double price() const override;
	void output(std::ostream& os) const override;

	std::unique_ptr<Component>clone() const override;
};

