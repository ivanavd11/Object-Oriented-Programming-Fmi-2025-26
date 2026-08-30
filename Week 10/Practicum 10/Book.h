#pragma once
#include <string>

using namespace std;

class Book {
private:
	string title;
	string author;

public:
	Book(const string& newTitle, const string& newAuthor);

	const string& getTitle() const;
	const string& getAuthor() const;

	void setTitle(const string& newTitle);
	void setAuthor(const string& newAuthor);
};
