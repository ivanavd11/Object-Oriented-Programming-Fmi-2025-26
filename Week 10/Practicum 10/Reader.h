#pragma once
#include <string>
#include "Book.h"
#include <memory>
#include <vector>

using namespace std;

class Reader {
private:
	string firstName;
	string lastName;
	vector<unique_ptr<Book>> borrowedBooks;

public:
	Reader(const string& newfirst, const string& newlast);

	const string& getFirstName() const;
	const string& getLastName() const;
	const vector<unique_ptr<Book>>& getBorrowedBooks() const;

	void setFirstName(const string& newFirst);
	void setLastName(const string& newLast);

	void addBook(unique_ptr<Book>book);
	
	unique_ptr<Book> removeBook(const string& title);

	void printBorrowedBooks() const;

};
