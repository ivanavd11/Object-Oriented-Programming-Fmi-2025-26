#pragma once
#include "Crop.h"


class Plot {
private:
	int id;
	static int nextId;

	double width;
	double height;
	Crop cropType;

public:
	Plot();
	Plot(double newWidth, double newHeight, const Crop& crop);

	int getId();
	double getWidth() const;
	double getHeight() const;
	Crop getCropType() const;

	void setWidth(double newWidth);
	void setHeight(double newHeight);

	void sow(Crop cropType);
	void reap();
};
