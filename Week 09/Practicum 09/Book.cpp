#include "Book.h"
#include <iostream>
#include <cstring>
using namespace std;

void Book::free()
{
	delete[] title;
	title = nullptr;
	titleSize = 0;

	delete[] author;
	author = nullptr;
	authorSize = 0;
}
void Book::copyFrom(const Book& other)
{
	titleSize = other.titleSize;
	title = new char[titleSize + 1];
	strcpy(title, other.title);

	authorSize = other.authorSize;
	author = new char[authorSize + 1];
	strcpy(author, other.author);

	genre = other.genre;

}
void Book::moveFrom(Book&& other)
{
	title = other.title;
	titleSize = other.titleSize;
	author = other.author;
	authorSize = other.authorSize;
	genre = other.genre;

	other.title = nullptr;
	other.titleSize = 0;
	other.author = nullptr;
	other.authorSize = 0;
}

Book::Book()
{
	titleSize = strlen("Default title");
	title = new char[titleSize + 1];
	strcpy(title, "Default title");

	authorSize = strlen("Default Author");
	author = new char[authorSize + 1];
	strcpy(author, "Default Author");

	genre = Genre::FANTASY;
}

Book::Book(const char* title, size_t titleSize, const char* author, size_t authorSize, const Genre genre)
{
	if (title == nullptr || author == nullptr ||
		strlen(title) != titleSize || strlen(author) != authorSize)
	{
		cout << "Invalid input\n";
		return;
	}

	this->titleSize = titleSize;
	this->title = new char[this->titleSize + 1];
	strcpy(this->title, title);

	this->authorSize = authorSize;
	this->author = new char[this->authorSize + 1];
	strcpy(this->author, author);

	setGenre(genre);
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
	return *this;
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
	return *this;
}

Book::~Book()
{
	free();
}

const char* Book::getTitle() const
{
	return title;
}
size_t Book::getTitleSize() const
{
	return titleSize;
}
const char* Book::getAuthor() const
{
	return author;
}
size_t Book::getAuthorSize() const
{
	return authorSize;
}
Genre Book::getGenre() const
{
	return genre;
}

void Book::setTitle(const char* newTitle, size_t newSizeTitle)
{
	if (newTitle == nullptr || strlen(newTitle) == 0
		|| strlen(newTitle) != newSizeTitle || newSizeTitle <= 0)
	{
		cout << "Invalid input\n";
		return;
	}

	char* newData = new char[newSizeTitle + 1];
	strcpy(newData, newTitle);

	delete[] title;
	title = newData;
	titleSize = newSizeTitle;

}
void Book::setAuthor(const char* newAuthor, size_t newSizeAuthor)
{
	if (newAuthor == nullptr || strlen(newAuthor) == 0
		|| strlen(newAuthor) != newSizeAuthor || newSizeAuthor <= 0)
	{
		cout << "Invalid input\n";
		return;
	}

	char* newData = new char[newSizeAuthor + 1];
	strcpy(newData, newAuthor);
	
	delete[] author;
	author = newData;
	authorSize = newSizeAuthor;
}
void Book::setGenre(const Genre newGenre)
{
	genre = newGenre;
}