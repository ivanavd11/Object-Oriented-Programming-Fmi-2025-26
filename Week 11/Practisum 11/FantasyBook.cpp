#include "FantasyBook.h"

void FantasyBook::free()
{
	delete[] wiseOldMenthor;
	wiseOldMenthor = nullptr;
}
void FantasyBook::copyFrom(const FantasyBook& other)
{
	wiseOldMenthor = new char[strlen(other.wiseOldMenthor) + 1];
	strcpy(wiseOldMenthor, other.wiseOldMenthor);
}
void FantasyBook::moveFrom(FantasyBook&& other) noexcept
{
	wiseOldMenthor = other.wiseOldMenthor;
	other.wiseOldMenthor = nullptr;
}

FantasyBook::FantasyBook(const char* title, const char* author, const char* menthor)
	:Book(title, author)
{
	setMenthor(menthor);
}

FantasyBook::FantasyBook(const FantasyBook& other)
	: Book(other)
{
	copyFrom(other);
}
FantasyBook& FantasyBook::operator=(const FantasyBook& other)
{
	if (this != &other)
	{
		Book::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

FantasyBook::FantasyBook(FantasyBook&& other) noexcept
	: Book(std::move(other))
{
	moveFrom(std::move(other));
}
FantasyBook& FantasyBook::operator=(FantasyBook&& other) noexcept
{
	if (this != &other)
	{
		Book::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

FantasyBook::~FantasyBook()
{
	free();
}

const char* FantasyBook::getMenthor() const
{
	return wiseOldMenthor;
}
void FantasyBook::setMenthor(const char* menthor)
{
	if (menthor == nullptr)
	{
		return;
	}
	char* newMentor = new char[strlen(menthor) + 1];
	strcpy(newMentor, menthor);

	delete[] wiseOldMenthor;
	wiseOldMenthor = newMentor;
}

std::ostream& operator<<(std::ostream& os, const FantasyBook& book)
{
	os<< static_cast<const Book&>(book)
		<< " - a fantasy book where the Wise Old Menthor is "
		<< book.wiseOldMenthor;

	return os;
}