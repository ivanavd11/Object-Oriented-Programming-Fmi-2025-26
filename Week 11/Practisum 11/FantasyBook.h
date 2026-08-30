#pragma once
#include "Book.h"
#include <iostream>

class FantasyBook :public Book
{
private:
	char* wiseOldMenthor;

	void free();
	void copyFrom(const FantasyBook& other);
	void moveFrom(FantasyBook&& other) noexcept;

public:
	FantasyBook(const char* title, const char* author, const char* menthor);

	FantasyBook(const FantasyBook& other);
	FantasyBook& operator=(const FantasyBook& other);

	FantasyBook(FantasyBook&& other) noexcept;
	FantasyBook& operator=(FantasyBook&& other) noexcept;

	~FantasyBook();

	const char* getMenthor() const;
	void setMenthor(const char* menthor);

	friend std::ostream& operator<<(std::ostream& os, const FantasyBook& book);
};
