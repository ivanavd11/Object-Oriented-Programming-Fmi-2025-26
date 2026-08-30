#pragma once
#include "Landmark.h"
class Dungeon : public Landmark
{
    int depth;
public:
	Dungeon(const std::string& name, int threat, const Coords& coords, int depth);

	int getDepth() const;

	std::string getType() const override;
	void print() const override;

	std::unique_ptr<Landmark> clone() const override;
};

