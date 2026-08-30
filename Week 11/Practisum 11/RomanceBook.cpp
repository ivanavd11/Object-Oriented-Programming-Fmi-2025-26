#include "RomanceBook.h"

void RomanceBook::free()
{
	delete[] loveInterestOne;
	delete[] loveInterestTwo;

	loveInterestOne = nullptr;
	loveInterestTwo = nullptr;
}
void RomanceBook::copyFrom(const RomanceBook& other)
{
	loveInterestOne = new char[strlen(other.loveInterestOne) + 1];
	strcpy(loveInterestOne, other.loveInterestOne);

	loveInterestTwo = new char[strlen(other.loveInterestTwo) + 1];
	strcpy(loveInterestTwo, other.loveInterestTwo);
}
void RomanceBook::moveFrom(RomanceBook&& other) noexcept
{
	loveInterestOne = other.loveInterestOne;
	loveInterestTwo = other.loveInterestTwo;
	
	other.loveInterestOne = nullptr;
	other.loveInterestTwo = nullptr;
}

RomanceBook::RomanceBook(const char* title, const char* author, const char* one, const char* two)
	:Book(title, author)
{
	setOne(one);
	setTwo(two);
}

RomanceBook::RomanceBook(const RomanceBook& other)
	:Book(other)
{
	copyFrom(other);
}
RomanceBook& RomanceBook::operator=(const RomanceBook& other)
{
	if (this != &other)
	{
		Book::operator=(other);
		free();
		copyFrom(other);
	}
}

RomanceBook::RomanceBook(RomanceBook&& other) noexcept
	: Book(std::move(other))
{
	moveFrom(std::move(other));
}
RomanceBook& RomanceBook::operator=(RomanceBook&& other) noexcept
{
	if (this != &other)
	{
		Book::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
}

RomanceBook::~RomanceBook()
{
	free();
}

const char* RomanceBook::getOne() const
{
	return loveInterestOne;
}
const char* RomanceBook::getTwo() const
{
	return loveInterestTwo;
}

void RomanceBook::setOne(const char* newOne)
{
	if (newOne == nullptr)
	{
		return;
	}
	char* newLover = new char[strlen(newOne) + 1];
	strcpy(newLover, newOne);

	delete[] loveInterestOne;
	loveInterestOne = newLover;
}
void RomanceBook::setTwo(const char* newTwo)
{
	if (newTwo == nullptr)
	{
		return;
	}
	char* newLover = new char[strlen(newTwo) + 1];
	strcpy(newLover, newTwo);

	delete[] loveInterestTwo;
	loveInterestTwo = newLover;
}

std::ostream& operator<<(std::ostream& os, const RomanceBook& book)
{
	os << static_cast<const Book&>(book)
		<< " - a romance book where "
		<< book.loveInterestOne << " and " << book.loveInterestTwo
		<< " fall in love.";
	return os;
}