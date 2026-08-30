#pragma once
#include <cstdint>
enum class Stars
{
	One = 1,
	Two,
	Three,
	Four,
	Five
};
class Player
{
private:
	int id;
	std::uint64_t points;
	Stars stars;

protected:
	bool exchangePointsForStar(std::uint64_t requiredPoints);
public:
	explicit Player(int id);

	int getId() const;
	std::uint64_t getPoints() const;
	Stars getStars() const;

	void completeMission(std::uint64_t earnedPoints);

	virtual bool levelUp();

	virtual void printInfo() const;

	virtual ~Player() = default;
};

