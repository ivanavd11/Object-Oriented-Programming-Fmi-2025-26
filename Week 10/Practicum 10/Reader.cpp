#include "Reader.h"
#include <iostream>

Reader::Reader(const string& newfirst, const string& newlast) :firstName(newfirst), lastName(newlast), borrowedBooks()
{

}

const string& Reader::getFirstName() const
{
	return firstName;
}
const string& Reader::getLastName() const
{
	return lastName;
}
const vector<unique_ptr<Book>>& Reader::getBorrowedBooks() const
{
	return borrowedBooks;
}

void Reader::setFirstName(const string& newFirst)
{
	firstName = newFirst;
}
void Reader::setLastName(const string& newLast)
{
	lastName = newLast;
}

void Reader::addBook(unique_ptr<Book>book)
{
	if (book)
	{
		borrowedBooks.push_back(std::move(book));
	}
}

unique_ptr<Book> Reader::removeBook(const string& title)
{
	for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it)
	{
		if ((*it)->getTitle() == title)
		{
			unique_ptr<Book> removedBook = std::move(*it);

			borrowedBooks.erase(it);
			return removedBook;
		}
	}
	return nullptr;
}

void Reader::printBorrowedBooks() const
{
	std::cout << "Books borrowed by " << firstName << ' ' << lastName << ":\n";

	if (borrowedBooks.empty()) 
	{
		std::cout << "  No borrowed books.\n";
		return;
	}

	for (const auto& book : borrowedBooks) 
	{
		std::cout << "  " << book->getTitle()
			      << " by " << book->getAuthor() << '\n';
	}
}