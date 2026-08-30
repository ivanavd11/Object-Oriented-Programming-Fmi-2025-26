#pragma once
#include <string>
#include <memory>

class Component
{
private:
	const std::string label;

public:
	explicit Component(const std::string& label);
	const std::string& getLabel() const;

	virtual double price() const = 0;
	virtual void output(std::ostream& os) const = 0;

	virtual std::unique_ptr<Component>clone() const = 0;
	virtual ~Component() = default;
};

