#include <iostream>
#include "Reader.h"
#include <cstring>

using namespace std;

void Reader::free()
{
	delete[] name;
	name = nullptr;
	nameSize = 0;

	for (int i = 0; i < booksSize; i++)
	{
		delete[] books[i];

	}
	delete[] books;
	books = nullptr;
	booksSize = 0;

	delete[] sizes;
	sizes = nullptr;
}
void Reader::copyFrom(const Reader& other)
{
	nameSize = other.nameSize;
	name = new char[nameSize + 1];
	strcpy(name, other.name);

	booksSize = other.booksSize;
	books = new Book * [booksSize];
	sizes = new size_t[booksSize];
	for (int i = 0; i < booksSize; i++)
	{
		sizes[i] = other.sizes[i];
		if (sizes[i] == 0)
		{
			books[i] = nullptr;
			continue;
		}
		books[i] = new Book[sizes[i]];
		for (int j = 0; j < sizes[i]; j++)
		{
			books[i][j] = other.books[i][j];
		}
	}
}
void Reader::moveFrom(Reader&& other)
{
	name = other.name;
	nameSize = other.nameSize;

	books = other.books;
	booksSize = other.booksSize;

	sizes = other.sizes;

	other.name = nullptr;
	other.nameSize = 0;
	other.books = nullptr;
	other.booksSize = 0;
	other.sizes = nullptr;
}

Reader::Reader(const char* name, size_t nameSize)
{
	if (name == nullptr || strlen(name) != nameSize)
	{
		cout << "Invalid input\n";
		return;
	}
	this->nameSize = nameSize;
	this->name = new char[nameSize + 1];
	strcpy(this->name, name);

	booksSize = 5;
	books = new Book * [booksSize];
	sizes = new size_t[booksSize];

	for (int i = 0; i < booksSize; i++)
	{
		books[i] = nullptr;
		sizes[i] = 0;
	}
}

size_t Reader::genreToIndex(Genre genre) const
{
	switch (genre)
	{
	case Genre::ROMANCE: return 0;
		break;
	case Genre::HORROR: return 1;
		break;
	case Genre::MYSTERY: return 2;
		break;
	case Genre::SCIENCE_FICTION: return 3;
		break;
	case Genre::FANTASY: return 4;
		break;
	default: return -1;
		break;
	}
}

Reader::Reader(const Reader& other)
{
	copyFrom(other);
}
Reader& Reader::operator=(const Reader& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Reader::Reader(Reader&& other) noexcept
{
	moveFrom(std::move(other));
}
Reader& Reader::operator=(Reader&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Reader::~Reader()
{
	free();
}

void Reader::addBook(Book book)
{
	size_t index = genreToIndex(book.getGenre());

	size_t oldSize = sizes[index];

	Book* newData = new Book[oldSize + 1];

	for (int i = 0; i < oldSize; i++)
	{
		newData[i] = books[index][i];
	}

	newData[oldSize] = book;
	delete[] books[index];
	books[index] = newData;
	sizes[index]++;
}

Book* Reader::getBooksByGenre(Genre genre)
{
	size_t index = genreToIndex(genre);

	if (sizes[index] == 0)
	{
		return nullptr;
	}
	return books[index];
}

const Book* Reader::getBooksByGenre(Genre genre) const
{
	size_t index = genreToIndex(genre);

	if (sizes[index] == 0)
	{
		return nullptr;
	}
	return books[index];
}

size_t Reader::getBooksCountByGenre(Genre genre) const
{
	return sizes[genreToIndex(genre)];
}
