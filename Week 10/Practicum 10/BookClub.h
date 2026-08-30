#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Reader.h"
using namespace std;

class BookClub {
private:
	string name;
	vector<unique_ptr<Book>> clubBooks;
	vector < unique_ptr<Reader>> members;

	Reader* findMember(const std::string& firstName, const std::string& lastName);

public:
	explicit BookClub(const string& newName);

	void setName(const std::string& newName);

	const std::string& getName() const;
	const std::vector<std::unique_ptr<Book>>& getClubBooks() const;
	const std::vector<std::unique_ptr<Reader>>& getMembers() const;

	void addBook(unique_ptr<Book> book);
	void addMember(unique_ptr<Reader> member);

	std::unique_ptr<Book> removeBook(const std::string& title);
	std::unique_ptr<Reader> removeMember(const std::string& firstName,const std::string& lastName);

	bool borrowBook(const std::string& title, const std::string& firstName, const std::string& lastName);

	bool returnBook(const std::string& title, const std::string& firstName, const std::string& lastName);

	void printAvailableBooks() const;
	void printMembers() const;
};
