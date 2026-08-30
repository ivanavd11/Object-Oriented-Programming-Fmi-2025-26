#pragma once
#include <string>

class MyFile
{
private:
	std::string data;

protected:
	MyFile();
	explicit MyFile(const std::string& data);

public:
	const std::string& getData() const;

	virtual void setData(const std::string& newData);

	virtual void printDetails() const = 0;

	virtual ~MyFile() = default;
};

