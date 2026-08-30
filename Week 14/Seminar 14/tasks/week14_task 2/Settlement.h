#pragma once
#include "Landmark.h"
class Settlement : public Landmark
{
	int population;
public:
	Settlement(const std::string& name, int threat, const Coords& coords, int population);

	int getPopulation() const;

	std::string getType() const override;
	void print() const override;

	std::unique_ptr<Landmark> clone() const override;
};

