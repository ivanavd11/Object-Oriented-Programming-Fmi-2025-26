#include "Book.h"
#include <cstring>
#include <iostream>

void Book::free()
{
	delete[] title;
	delete[] author;

	title = nullptr;
	author = nullptr;
}
void Book::copyFrom(const Book& other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);
}
void Book::moveFrom(Book&& other) noexcept
{
	title = other.title;
	author = other.author;

	other.title = nullptr;
	other.author = nullptr;
}

Book::Book(const char* title, const char* author)
	: title(nullptr), author(nullptr)
{
	setTitle(title);
	setAuthor(author);
}

Book::Book(const Book& other)
{
	copyFrom(other);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}

Book::Book(Book&& other) noexcept
{
	moveFrom(std::move(other));
}
Book& Book::operator=(Book&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return*this;
}

Book::~Book()
{
	free();
}

const char* Book::getTitle() const
{
	return title;
}
const char* Book::getAuthor() const
{
	return author;
}

void Book::setTitle(const char* newTitle)
{
	if (newTitle == nullptr)
	{
		return;
	}

	char* newTitleCopy = new char[strlen(newTitle) + 1];
	strcpy(newTitleCopy, newTitle);

	delete[] title;
	title = newTitleCopy;
}
void Book::setAuthor(const char* newAuthor)
{
	if (newAuthor == nullptr)
	{
		return;
	}
	char* newAuthorCopy = new char[strlen(newAuthor) + 1];
	strcpy(newAuthorCopy, newAuthor);

	delete[] author;
	author = newAuthorCopy;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.title << " by " << book.author;
	return os;
}