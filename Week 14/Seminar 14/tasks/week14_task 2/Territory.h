#pragma once
#include "Landmark.h"
#include <vector>

class Territory
{
	std::string name;
	int dangerLevel;

	std::vector<std::unique_ptr<Landmark>> landmarks;

	void copyFrom(const Territory& other);

public:
	explicit Territory(const std::string& name,int dangerLevel = 1);

	Territory(const Territory& other);
	Territory& operator=(const Territory& other);

	Territory(Territory&& other) noexcept = default;
	Territory& operator=(Territory&& other) noexcept = default;

	~Territory() = default;

	const std::string& getName() const;
	int getDangerLevel() const;
	std::size_t landmarksCount() const;

	void addLandmark(std::unique_ptr<Landmark> land);

	std::unique_ptr<Landmark> removeLandmark(const std::string& name);

	void setDangerLevel(int level);

	bool hasLandmark(const std::string& name) const;

	void print() const;
};

