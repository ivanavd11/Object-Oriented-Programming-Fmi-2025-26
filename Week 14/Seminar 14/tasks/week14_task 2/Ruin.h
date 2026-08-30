#pragma once
#include "Landmark.h"
class Ruin : public Landmark
{
    std::string civilization;
public:
	Ruin(const std::string& name, int threat, const Coords& coords, const std::string& civilization);

	const std::string& getCivilization() const;

	std::string getType() const override;
	void print() const override;

	std::unique_ptr<Landmark> clone() const override;
};

