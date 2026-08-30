#pragma once
#include "Cartographer.h"
class FieldSurveyor : public Cartographer
{
	std::string region;
public:
	FieldSurveyor(const std::string& name, int yearsExperience, const std::string& region);

	const std::string& getRegion() const;

	std::string getRole() const override;
	void print() const override;
};

