#include "Configuration.h"
#include <stdexcept>
#include <iostream>

void Configuration::copyFrom(const Configuration& other)
{
	components.reserve(other.components.size());

	for (const auto& component : other.components)
	{
		components.push_back(component->clone());
	}
}

Configuration::Configuration(const Configuration& other)
{
	copyFrom(other);
}
Configuration& Configuration::operator=(const Configuration& other)
{
	if (this != &other)
	{
		Configuration copy(other);
		components.swap(copy.components);
	}
	return *this;
}

void Configuration::insert(const std::unique_ptr<Component>& component)
{
	if (!component) {
		throw std::invalid_argument("Cannot insert an empty component.");
	}
	components.push_back(component->clone());
}
double Configuration::price() const
{
	double result = 0;
	for (const auto& component : components)
	{
		result += component->price();
	}
	return result;
}

size_t Configuration::size() const
{
	return components.size();
}

const Component& Configuration::operator[](int index) const
{
	if (index < 0 || index >= size())
	{
		throw std::invalid_argument("Index must be valid number between 0 and count of components");
	}

	return *components[index];
}

std::ostream& operator<<(std::ostream& os, const Configuration& config)
{
	os << "-----Configuration-----\n";
	for (const auto& component : config.components)
	{
		component->output(os);
	}

	os << "total price: " << config.price() << "euro\n";
}
