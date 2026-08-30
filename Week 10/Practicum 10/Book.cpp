#include "Book.h"

Book::Book(const string& newTitle, const string& newAuthor) : title(newTitle), author(newAuthor)
{

}

const string& Book::getTitle() const
{
	return title;
}
const string& Book::getAuthor() const
{
	return author;
}

void Book::setTitle(const string& newTitle)
{
	this->title = newTitle;
}
void Book::setAuthor(const string& newAuthor)
{
	this->author = newAuthor;
}