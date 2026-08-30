#pragma once

#include "Book.h"

class RomanceBook :public Book
{
private:
	char* loveInterestOne = nullptr;
	char* loveInterestTwo = nullptr;

	void free();
	void copyFrom(const RomanceBook& other);
	void moveFrom(RomanceBook&& other) noexcept;
public:
	RomanceBook(const char* title, const char* author, const char* one, const char* two);

	RomanceBook(const RomanceBook& other);
	RomanceBook& operator=(const RomanceBook& other);

	RomanceBook(RomanceBook&& other) noexcept;
	RomanceBook& operator=(RomanceBook&& other) noexcept;

	~RomanceBook();

	const char* getOne() const;
	const char* getTwo() const;

	void setOne(const char* newOne);
	void setTwo(const char* newTwo);

	friend std::ostream& operator<<(std::ostream& os, const RomanceBook& book);
};