#pragma once
#include "Cartographer.h"
class Archivist : public Cartographer
{
private:
	std::string institution;
public:
	Archivist(const std::string& name, int yearsExperience, const std::string& institution);
	
	const std::string& getInstitution() const;

	std::string getRole() const override;
	void print() const override;
};

