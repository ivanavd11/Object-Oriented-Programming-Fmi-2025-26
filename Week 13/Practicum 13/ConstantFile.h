#pragma once
#include "MyFile.h"
class ConstantFile : public MyFile
{
public:
	explicit ConstantFile(const std::string& data);

	void setData(const std::string& newData) override;

	void printDetails() const override;
};