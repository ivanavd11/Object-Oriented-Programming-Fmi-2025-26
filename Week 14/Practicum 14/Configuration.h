#pragma once
#include "Component.h"
#include <memory>
#include <vector>
class Configuration
{
private:
	std::vector<std::unique_ptr<Component>> components;

	void copyFrom(const Configuration& other);

public:
	Configuration() = default;

	Configuration(const Configuration& other);
	Configuration& operator=(const Configuration& other);

	Configuration(Configuration&& other) noexcept = default;
	Configuration& operator=(Configuration&& other) noexcept = default;

	~Configuration() = default;

	void insert(const std::unique_ptr<Component>& component);
	double price() const;

	size_t size() const;

	const Component& operator[](int index) const;

	friend std::ostream& operator<<(std::ostream& os, const Configuration& config);
};

