#include <iostream>
#include <memory>

#include "BookClub.h"

int main() {
    BookClub club("Readers Club");

    club.addBook(
        std::make_unique<Book>(
            "The Hobbit",
            "J. R. R. Tolkien"
        )
    );

    club.addBook(
        std::make_unique<Book>(
            "1984",
            "George Orwell"
        )
    );

    club.addBook(
        std::make_unique<Book>(
            "The Little Prince",
            "Antoine de Saint-Exupery"
        )
    );

    club.addMember(
        std::make_unique<Reader>(
            "Ivan",
            "Ivanov"
        )
    );

    club.addMember(
        std::make_unique<Reader>(
            "Maria",
            "Petrova"
        )
    );

    club.printMembers();

    std::cout << '\n';
    club.printAvailableBooks();

    std::cout << "\nIvan borrows The Hobbit.\n";

    club.borrowBook(
        "The Hobbit",
        "Ivan",
        "Ivanov"
    );

    std::cout << '\n';
    club.printAvailableBooks();

    const auto& members = club.getMembers();
    members[0]->printBorrowedBooks();

    std::cout << "\nIvan returns The Hobbit.\n";

    club.returnBook(
        "The Hobbit",
        "Ivan",
        "Ivanov"
    );

    std::cout << '\n';
    club.printAvailableBooks();
    members[0]->printBorrowedBooks();

    return 0;
}