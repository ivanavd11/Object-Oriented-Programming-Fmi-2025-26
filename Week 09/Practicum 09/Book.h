#pragma once

#include "Genre.h"

class Book {
private:
	char* title;
	size_t titleSize;
	char* author;
	size_t authorSize;
	Genre genre;

	void free();
	void copyFrom(const Book& other);
	void moveFrom(Book&& other);

public:
	Book();
	Book(const char* title, size_t titleSize, const char* author, size_t authorSize, const Genre genre);

	Book(const Book& other);
	Book& operator=(const Book& other);

	Book(Book&& other) noexcept;
	Book& operator=(Book&& other) noexcept;

	~Book();

	const char* getTitle() const;
	size_t getTitleSize() const;
	const char* getAuthor() const;
	size_t getAuthorSize() const;
	Genre getGenre() const;

	void setTitle(const char* newTitle, size_t newSizeTitle);
	void setAuthor(const char* newAuthor, size_t newSizeAuthor);
	void setGenre(const Genre newGenre);

};
