#pragma once
#include <iostream>

class Book {
private:
	char* title;
	char* author;

	void free();
	void copyFrom(const Book& other);
	void moveFrom(Book&& other) noexcept;

public:
	Book(const char* title, const char* author);

	Book(const Book& other);
	Book& operator=(const Book& other);

	Book(Book&& other) noexcept;
	Book& operator=(Book&& other) noexcept;

	virtual ~Book();

	const char* getTitle() const;
	const char* getAuthor() const;

	void setTitle(const char* newTitle);
	void setAuthor(const char* newAuthor);

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
