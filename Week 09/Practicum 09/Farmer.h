#pragma once
#include "Plot.h"

class Farmer {
private:
	char* name;
	size_t nameSize;
	Plot** plots;
	size_t plotSize;

	void free();
	void copyFrom(const Farmer& other);
	void moveFrom(Farmer&& other);

public:
	Farmer(const char* name, size_t size, Plot** newplots, size_t plotssize);

	Farmer(const Farmer& other);
	Farmer& operator=(const Farmer& other);

	Farmer(Farmer&& other) noexcept;
	Farmer& operator=(Farmer&& other) noexcept;

	~Farmer();

	void addPlot(Plot* plot);

	void printField() const;

};
