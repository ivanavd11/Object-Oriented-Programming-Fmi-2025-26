#include "Component.h"
#include <stdexcept>

Component::Component(const std::string& label)
	:label(label)
{
	if (label.empty())
	{
		throw std::invalid_argument("Eticket is empty");
	}
}

const std::string& Component::getLabel() const
{
	return label;
}

