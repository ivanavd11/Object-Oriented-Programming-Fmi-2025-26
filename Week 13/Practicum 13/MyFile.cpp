#include "MyFile.h"

MyFile::MyFile()
	:data() 
{

}
explicit MyFile::MyFile(const std::string& data)
	:data(data)
{

}

const std::string& MyFile::getData() const
{
	return data;
}

void MyFile::setData(const std::string& newData)
{
	data = newData;
}

