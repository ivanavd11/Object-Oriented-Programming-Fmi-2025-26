#pragma once
#include "Book.h"

class MurderMysteryBook :public Book
{
private:
	char* killer;
	int victimCount;

	void free();
	void copyFrom(const MurderMysteryBook& other);
	void moveFrom(MurderMysteryBook&& other) noexcept;

public:
	MurderMysteryBook(const char* title, const char* author, const char* killer, int victim);

	MurderMysteryBook(const MurderMysteryBook& other);
	MurderMysteryBook& operator=(const MurderMysteryBook& other);

	MurderMysteryBook(MurderMysteryBook&& other) noexcept;
	MurderMysteryBook& operator=(MurderMysteryBook&& other) noexcept;

	~MurderMysteryBook();

	const char* getKiller() const;
	int getVictimCount() const;

	void setKiller(const char* newKiller);
	void setVictimCount(int newCount);

	friend std::ostream& operator<<(std::ostream& os, const MurderMysteryBook& book);

};