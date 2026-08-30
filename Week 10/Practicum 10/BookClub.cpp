#include <iostream>
#include "BookClub.h"

BookClub::BookClub(const string& newName) : name(newName), clubBooks(), members()
{

}

void BookClub::setName(const std::string& newName)
{
	name = newName;
}

const std::string& BookClub::getName() const
{
	return name;
}
const std::vector<std::unique_ptr<Book>>& BookClub::getClubBooks() const
{
	return clubBooks;
}
const std::vector<std::unique_ptr<Reader>>& BookClub::getMembers() const
{
	return members;
}

void BookClub::addBook(unique_ptr<Book> book)
{
	if (book)
	{
		clubBooks.push_back(std::move(book));
	}
}

void BookClub::addMember(unique_ptr<Reader> member)
{
	if (member)
	{
		members.push_back(std::move(member));
	}
}

std::unique_ptr<Book> BookClub::removeBook(const std::string& title)
{
	for (auto it = clubBooks.begin(); it != clubBooks.end(); ++it)
	{
		if ((*it)->getTitle() == title)
		{
			unique_ptr<Book> removedBook = std::move(*it);

			clubBooks.erase(it);
			return removedBook;
		}
	}
	return nullptr;
}
std::unique_ptr<Reader> BookClub::removeMember(const std::string& firstName, const std::string& lastName)
{
	for (auto it = members.begin(); it != members.end(); ++it)
	{
		if ((*it)->getFirstName() == firstName
			&& (*it)->getLastName() == lastName)
		{
			unique_ptr<Reader> removedMember = std::move(*it);

			members.erase(it);
			return removedMember;
		}
	}
	return nullptr;
}

Reader* BookClub::findMember(const std::string& firstName, const std::string& lastName)
{
	for (const auto& member : members)
	{
		if (member->getFirstName() == firstName
			&& member->getLastName() == lastName)
		{
			return member.get();
		}
	}
	return nullptr;
}

bool BookClub::borrowBook(const std::string& title, const std::string& firstName, const std::string& lastName)
{
	Reader* member = findMember(firstName, lastName);

	if (member == nullptr)
	{
		std::cout << "Member not found.\n";
		return false;
	}

	std::unique_ptr<Book> book = removeBook(title);

	if (!book) 
	{
		std::cout << "Book is not available.\n";
		return false;
	}

	member->addBook(std::move(book));
	return true;
}

bool BookClub::returnBook(const std::string& title, const std::string& firstName, const std::string& lastName)
{
	Reader* member = findMember(firstName, lastName);

	if (member == nullptr)
	{
		std::cout << "Member not found.\n";
		return false;
	}

	unique_ptr<Book>book = member->removeBook(title);

	if (!book)
	{
		std::cout << "The reader has not borrowed this book.\n";
		return false;
	}

	addBook(std::move(book));
	return true;
}

void BookClub::printAvailableBooks() const
{
	std::cout << "Available books in " << name << ":\n";

	if (clubBooks.empty()) 
	{
		std::cout << "  No available books.\n";
		return;
	}

	for (const auto& book : clubBooks) 
	{
		std::cout << "  " << book->getTitle()
			<< " by " << book->getAuthor() << '\n';
	}
}
void BookClub::printMembers() const
{
	std::cout << "Members in " << name << ":\n";

	if (members.empty())
	{
		std::cout << "No members\n";
		return;
	}

	for (const auto& member : members)
	{
		std::cout << " " << member->getFirstName() << " "
			<< member->getLastName() << '\n';
	}
}

