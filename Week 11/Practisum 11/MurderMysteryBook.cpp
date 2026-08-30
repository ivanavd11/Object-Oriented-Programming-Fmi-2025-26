#include "MurderMysteryBook.h"

void MurderMysteryBook::free()
{
	delete[] killer;
	killer = 0;
	victimCount = 0;
}
void MurderMysteryBook::copyFrom(const MurderMysteryBook& other)
{
	killer = new char[strlen(other.killer) + 1];
	strcpy(killer, other.killer);
	victimCount = other.victimCount;
}
void MurderMysteryBook::moveFrom(MurderMysteryBook&& other) noexcept
{
	killer = other.killer;
	victimCount = other.victimCount;

	other.killer = nullptr;
	other.victimCount = 0;
}

MurderMysteryBook::MurderMysteryBook(const char* title, const char* author, const char* killer, int victim)
	: Book(title, author), killer(nullptr), victimCount(0)
{
	setKiller(killer);
	setVictimCount(victim);
}

MurderMysteryBook::MurderMysteryBook(const MurderMysteryBook& other)
	: Book(other)
{
	copyFrom(other);
}
MurderMysteryBook& MurderMysteryBook::operator=(const MurderMysteryBook& other)
{
	if (this != &other)
	{
		Book::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

MurderMysteryBook::MurderMysteryBook(MurderMysteryBook&& other) noexcept
	: Book(std::move(other))
{
	moveFrom(std::move(other));
}
MurderMysteryBook& MurderMysteryBook::operator=(MurderMysteryBook&& other) noexcept
{
	if (this != &other)
	{
		Book::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MurderMysteryBook::~MurderMysteryBook()
{
	free();
}

const char* MurderMysteryBook::getKiller() const
{
	return killer;
}
int MurderMysteryBook::getVictimCount() const
{
	return victimCount;
}

void MurderMysteryBook::setKiller(const char* newKiller)
{
	if (newKiller == nullptr)
	{
		return;
	}
	char* copyNewKiller = new char[strlen(newKiller) + 1];
	strcpy(copyNewKiller, newKiller);

	delete[] killer;
	killer = copyNewKiller;
}
void MurderMysteryBook::setVictimCount(int newCount)
{
	if (newCount < 0)
	{
		return;
	}
	victimCount = newCount;
}

std::ostream& operator<<(std::ostream& os, const MurderMysteryBook& book)
{
	os<<static_cast< const Book&>(book)
		<< " - a murder mystery book where the killer was "
		<< book.killer
		<< " who killed "
		<< book.victimCount
		<< " people";

	return os;
}