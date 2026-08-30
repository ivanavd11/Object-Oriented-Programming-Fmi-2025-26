#pragma once
#include <iostream>

class Point {
private:
	int x;
	int y;

public:
	Point();
	Point(int x, int y);

	int getX() const;
	int getY() const;

	void setX(int newX);
	void setY(int newY);

	static double getDistance(const Point& a, const Point& b);
};
