#include "Dungeon.h"
#include <stdexcept>
#include <iostream>
#include <memory>

Dungeon::Dungeon(const std::string& name, int threat, const Coords& coords, int depth)
	:Landmark(name, threat, coords), depth(depth)
{
	if (depth <= 0)
	{
		throw std::invalid_argument("Depth must be positive");
	}
}

int Dungeon::getDepth() const
{
	return depth;
}

std::string Dungeon::getType() const
{
	return "Dungeon";
}
void Dungeon::print() const
{
	printBaseInfo();
	std::cout << ", depth: " << depth << "\n";
}

std::unique_ptr<Landmark> Dungeon::clone() const
{
	return std::make_unique<Dungeon>(*this);
}