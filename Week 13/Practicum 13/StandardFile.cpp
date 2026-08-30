#include "StandardFile.h"
#include <iostream>

StandardFile::StandardFile()
	:MyFile()
{

}
StandardFile::StandardFile(const std::string& data)
	:MyFile(data)
{

}

void StandardFile::printDetails() const 
{
	std::cout << "Standard file - data can be added and deleted\n";
}
void StandardFile::add(const std::string& toAdd) 
{
	setData(getData() + toAdd);
}
void StandardFile::null() 
{
	setData("");
}