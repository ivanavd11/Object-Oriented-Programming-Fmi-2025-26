#include "Book.h"
#include <stdexcept>
#include <iostream>

Book::Book(const std::string& title, const std::string& releaseDate, const std::string& author, const std::string& ISBN)
	:LibraryItem(title, releaseDate), author(author), ISBN(ISBN)
{
	if (author.empty()) {
		throw std::invalid_argument("Book author cannot be empty.");
	}

	if (ISBN.empty()) {
		throw std::invalid_argument("Book ISBN cannot be empty.");
	}
}

const std::string& Book::getAuthor() const
{
	return author;
}

const std::string& Book::getISBN() const
{
	return ISBN;
}

std::string Book::getType() const
{
	return "Book";
}

void Book::printInfo() const
{
	printBaseInfo();
	std::cout << ", author: " << author
		<< ", ISBN: " << ISBN << "\n";
}

std::unique_ptr<LibraryItem> Book::clone() const
{
	return std::make_unique<Book>(*this);
}
