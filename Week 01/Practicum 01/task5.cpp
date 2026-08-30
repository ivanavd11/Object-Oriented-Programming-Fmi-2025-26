#include <iostream>

namespace Constants {
    const int MAX_LENGTH = 50;
    const int BOOKS_CAPACITY = 3;
}

enum class Genre {
    Novel,
    Historic,
    Poetry,
    Other
};

using namespace Constants;

struct Book {
    char title[MAX_LENGTH] = "";
    char author[MAX_LENGTH] = "";
    Genre genre = Genre::Other;
    bool available = false;
};

struct Library {
    int countBook = 0;
    Book books[BOOKS_CAPACITY];
};

Genre fromIntToGenre(int num)
{
    switch (num)
    {
    case 0: return Genre::Novel;
    case 1: return Genre::Historic;
    case 2:return Genre::Poetry;
    default: return Genre::Other;
    }
}

const char* genreToString(const Genre& g)
{
    switch (g)
    {
    case Genre::Novel: return "Novel";
    case Genre::Historic: return "Historic";
    case Genre::Poetry: return "Poetry";
    default: return "Other";
    }
}

void printBook(const Book& b)
{
    std::cout << "Book name: " << b.title << ", with author: " << b.author << ", genre: " << genreToString(b.genre)
        << ", available: ";
    if (b.available)
    {
        std::cout << "yes";
    }
    else
    {
        std::cout << "no";
    }
    std::cout << '\n';
}

void printLibrary(const Library&l)
{
    std::cout << "Library:\n";
    for (int i = 0; i < l.countBook; i++)
    {
        std::cout << (i + 1) << ": \n";
        printBook(l.books[i]);
    }
}

void initBook(Book& book)
{
    int genreNum;
    std::cin >> book.title >> book.author >> genreNum >> book.available;
    book.genre = fromIntToGenre(genreNum);
}

void addBook(const Book& book, Library& library)
{
    if (library.countBook == BOOKS_CAPACITY)
    {
        std::cout<< "Max books capacity is reached!";
        return;
    }
    library.books[library.countBook++] = book;
}

const Book& getBookFromTitle(const Library& l, const char* title)
{
    for (int i = 0; i < l.countBook; i++)
    {
        if (strcmp(l.books[i].title, title) == 0) {
            l.books[i].available = false;
            return l.books[i];
        }
    }
}

void returnBookFromTitle(const Library& l, const char* title)
{
    for (int i = 0; i < l.countBook; i++)
    {
        if (strcmp(l.books[i].title, title) == 0) {
            l.books[i].available = true;
        }
    }
}

int main()
{

}