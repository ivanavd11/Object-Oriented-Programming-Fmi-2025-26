#pragma once
#include <string>
#include "LibraryItem.h"
#include <vector>
#include <memory>

class Reader
{
	std::string name;
	const int id;
	std::vector<LibraryItem*> borrowedItems;

	static int nextId;

	void borrowItem(LibraryItem* item);
	void returnItem(std::size_t itemId);

	friend class Library;
public:
	explicit Reader(const std::string& name);

	const std::string& getName() const;
	std::size_t getId() const;

	void setName(const std::string& newName);

	std::size_t getBorrowedItemsCount() const;

	const std::vector<LibraryItem*>& getBorrowedItems() const;

	bool hasBorrowedItem(std::size_t itemId) const;

	void printInfo() const;

};

