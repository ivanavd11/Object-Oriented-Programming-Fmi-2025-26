#pragma once
#include <string>
class Song
{
	std::string name;
	int duration;
public:
	Song(const std::string& name, int duration);

	const std::string& getName() const;
	int getDuration() const;

	void print() const;
};

