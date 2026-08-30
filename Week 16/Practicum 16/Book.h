#pragma once
#include "LibraryItem.h"

class Book :public LibraryItem
{
	std::string author;
	std::string ISBN;

public:
	Book(const std::string& title,const std::string& releaseDate, const std::string& author, const std::string& ISBN);

	const std::string& getAuthor() const;

	const std::string& getISBN() const;

	std::string getType() const override;

	void printInfo() const override;
	std::unique_ptr<LibraryItem> clone() const override;
};

