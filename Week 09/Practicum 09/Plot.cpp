#include "Plot.h"
#include <iostream>

using namespace std;
int Plot::nextId = 1;

Plot::Plot()
{
	id = nextId++;
	setHeight(50);
	setWidth(50);
	cropType = Crop::NOTHING;
}
Plot::Plot(double newWidth, double newHeight, const Crop& crop)
{
	setWidth(newWidth);
	setHeight(newHeight);
	id = nextId++;
	cropType = crop;
}

int Plot::getId()
{
	return id;
}
double Plot::getWidth() const
{
	return width;
}
double Plot::getHeight() const
{
	return height;
}
Crop Plot::getCropType() const
{
	return cropType;
}

void Plot::setWidth(double newWidth)
{
	if (newWidth <= 0)
	{
		cout << "Invalid input\n";
		this->width = 50;
	}
	width = newWidth;
}
void Plot::setHeight(double newHeight)
{
	if (newHeight <= 0)
	{
		cout << "Invalid input\n";
		this->height = 50;
	}
	height = newHeight;
}
void Plot::sow(Crop cropType)
{
	if (cropType == Crop::NOTHING)
	{
		cout<< "Cannot sow NOTHING!" << endl;
		return;
	}
	this->cropType = cropType;
}
void Plot::reap()
{
	if (cropType == Crop::NOTHING)
	{
		cout << "Cannot reap NOTHING!" << endl;
		return;
	}
	cropType = Crop::NOTHING;
}