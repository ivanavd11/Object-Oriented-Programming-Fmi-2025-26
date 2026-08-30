#pragma once

#include "Book.h"

class Library
{
private:
	char* libraryName = nullptr;
	char* address = nullptr;
	Book** books;
	size_t booksSize;

	void free();
	void copyFrom(const Library& other);
	void moveFrom(Library&& other) noexcept;
public:
	Library(const char* name, const char* address);

	Library(const Library& other);
	Library& operator=(const Library& other);

	Library(Library&& other) noexcept;
	Library& operator=(Library&& other) noexcept;

	~Library();

	void addBook(Book* book);

	void printCollection() const;
};
