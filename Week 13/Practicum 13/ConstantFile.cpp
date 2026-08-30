#include "ConstantFile.h"
#include <iostream>
#include <stdexcept>

ConstantFile::ConstantFile(const std::string& data)
	: MyFile(data)
{

}

void ConstantFile::setData(const std::string& newData)
{
	throw std::logic_error("Constant file cannot be changed.");
}

void ConstantFile::printDetails() const
{
	std::cout << "Constant file - cannot be changed\n";
}
