#include "Territory.h"
#include <memory>
#include <stdexcept>
#include <iostream>

void Territory::copyFrom(const Territory& other)
{
	landmarks.reserve(other.landmarks.size());

	for (const auto& land : other.landmarks)
	{
		landmarks.push_back(land->clone());
	}
}

Territory::Territory(const std::string& name, int dangerLevel)
	: name(name), dangerLevel(dangerLevel)
{
	if (name.empty()) {
		throw std::invalid_argument(
			"Territory name cannot be empty."
		);
	}

	if (dangerLevel < 1 ||
		dangerLevel > 10) {
		throw std::invalid_argument(
			"Territory danger level must be "
			"between 1 and 10."
		);
	}
}

Territory::Territory(const Territory& other)
	: name(other.name), dangerLevel(other.dangerLevel)
{
	copyFrom(other);
}
Territory& Territory::operator=(const Territory& other)
{
	if (this != &other)
	{
		Territory copy(other);

		name.swap(copy.name);
		std::swap(dangerLevel, copy.dangerLevel);
		landmarks.swap(copy.landmarks);
	}
	return *this;
}

const std::string& Territory::getName() const
{
	return name;
}

int Territory::getDangerLevel() const
{
	return dangerLevel;
}

std::size_t Territory::landmarksCount() const
{
	return landmarks.size();
}

void Territory::addLandmark(std::unique_ptr<Landmark> land)
{
	if (!land)
	{
		throw std::invalid_argument("Cannot add an empty landmark.");
	}
	
	if (hasLandmark(land->getName()))
	{
		throw std::invalid_argument(
			"Landmark with name "+ land->getName()+ " already exists.");
	}

	landmarks.push_back(std::move(land));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
	for (int i = 0; i < landmarksCount(); i++)
	{
		if (landmarks[i]->getName() == name)
		{
			std::unique_ptr<Landmark> removed = std::move(landmarks[i]);

			landmarks.erase(landmarks.begin() + 1);

			return removed;
		}
	}
	throw std::invalid_argument("Landmark not found: " + name);
}

void Territory::setDangerLevel(int newLevel)
{
	if (newLevel < 1 || newLevel > 10) {
		throw std::invalid_argument("Territory danger level must be between 1 and 10.");
	}

	dangerLevel = newLevel;
}

bool Territory::hasLandmark(const std::string& name) const
{
	for (const auto& landmark : landmarks) {
		if (landmark->getName() == name) {
			return true;
		}
	}

	return false;
}

void Territory::print() const
{
	std::cout
		<< "Territory: " << name
		<< '\n'
		<< "Danger level: "
		<< dangerLevel
		<< '\n'
		<< "Landmarks: "
		<< landmarks.size()
		<< '\n';

	for (const auto& landmark : landmarks) {
		std::cout << "- ";
		landmark->print();
	}
}