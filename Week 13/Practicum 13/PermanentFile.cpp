#include "PermanentFile.h"
#include <iostream>
#include <stdexcept>

PermanentFile::PermanentFile(const std::string& data)
	: MyFile(data)
{
	if (data.empty())
	{
		throw std::invalid_argument("Data is empty");
	}
}

void PermanentFile::setData(const std::string& newData)
{
	if (newData.empty()) {
		throw std::invalid_argument("Permanent file data cannot be empty.");
	}

	MyFile::setData(newData);
}

void PermanentFile::printDetails() const
{
	std::cout << "Permanent file - data cannot be deleted\n";
}
void PermanentFile::add(const std::string& toAdd)
{
	setData(toAdd + getData());
}
