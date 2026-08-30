#pragma once

class City {
private:
	char* name;
	long population;

	void free();
	void copyFrom(const City& other);

public:
	City();
	City(const char* name, long newPopulation);
	City(const City& other);
	City& operator=(const City& other);
	~City();

	void setName(const char* name);
	void setPopulation(long population);

	const char* getName() const;
	long getPopulation() const;
};
