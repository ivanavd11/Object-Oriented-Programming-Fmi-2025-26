#pragma once
#include <string>
#include <memory>
struct Coords
{
	double x, y;
};
class Landmark
{
	std::string name;
	int threat;
	Coords coords;
protected: 
	void printBaseInfo() const;
public:
	Landmark(const std::string& name, int threat, const Coords& coords);

	const std::string& getName() const;
	int getThreat() const;
	Coords getCoords() const;

	virtual std::string getType() const = 0;
	virtual void print() const = 0;

	virtual std::unique_ptr<Landmark> clone() const = 0;

	virtual ~Landmark() = default;
};

