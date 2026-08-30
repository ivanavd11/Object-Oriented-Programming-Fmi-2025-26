#pragma once
#include "MyFile.h"
#include "Addable.h"

class PermanentFile : public MyFile, public Addable
{
public:
	explicit PermanentFile(const std::string& data);

	void setData(const std::string& newData) override;

	void printDetails() const override;
	void add(const std::string& toAdd) override;
};

