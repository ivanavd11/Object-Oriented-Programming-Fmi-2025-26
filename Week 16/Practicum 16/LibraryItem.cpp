#include "LibraryItem.h"
#include <stdexcept>
#include <iostream>

std::size_t LibraryItem::nextId = 1;

void LibraryItem::printBaseInfo() const
{
	std::cout << "Type: " << getType()
		<< ", title: " << title
		<< ", release data: " << releaseDate
		<< ", ID: " << id;
	if (borrowed)
	{
		std::cout << ", borrowed: yes";
	}
	std::cout << ", borrowed: no";
}

LibraryItem::LibraryItem(const LibraryItem& other)
	: title(other.title), releaseDate(other.releaseDate),
	id(nextId++), borrowed(false)
{

}

LibraryItem::LibraryItem(const std::string& title, const std::string& releaseDate)
	: title(title), releaseDate(releaseDate), id(nextId++), borrowed(false)
{
	if (title.empty()) {
		throw std::invalid_argument("Library item title cannot be empty.");
	}

	if (releaseDate.empty()) {
		throw std::invalid_argument("Release date cannot be empty.");
	}
}

const std::string&LibraryItem::getTitle() const {
	return title;
}

const std::string&LibraryItem::getReleaseDate() const {
	return releaseDate;
}

std::size_t LibraryItem::getId() const {
	return id;
}

bool LibraryItem::isBorrowed() const {
	return borrowed;
}

void LibraryItem::markAsBorrowed() {
	if (borrowed) {
		throw std::logic_error("Library item is already borrowed.");
	}

	borrowed = true;
}

void LibraryItem::markAsReturned() {
	if (!borrowed) {
		throw std::logic_error("Library item is not currently borrowed.");
	}

	borrowed = false;
}