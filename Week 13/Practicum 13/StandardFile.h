#pragma once
#include "MyFile.h"
#include "Nullable.h"
#include "Addable.h"

class StandardFile: public MyFile, public Nullable, public Addable
{
public:
	StandardFile();
	explicit StandardFile(const std::string& data);

	void printDetails() const override;
	void add(const std::string& toAdd) override;
	void null() override;
};

