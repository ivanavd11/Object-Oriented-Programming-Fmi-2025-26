#pragma once
#include "Book.h"

class Reader {
private:
	char* name;
	size_t nameSize;

	Book** books;
	size_t booksSize;

	size_t* sizes;

	void free();
	void copyFrom(const Reader& other);
	void moveFrom(Reader&& other);

	size_t genreToIndex(Genre genre) const;

public:
	Reader(const char* name, size_t nameSize);

	Reader(const Reader& other);
	Reader& operator=(const Reader& other);

	Reader(Reader&& other) noexcept;
	Reader& operator=(Reader&& other) noexcept;

	~Reader();

	void addBook(Book book);

	Book* getBooksByGenre(Genre genre);
	const Book* getBooksByGenre(Genre genre) const;

	size_t getBooksCountByGenre(Genre genre) const;
};
