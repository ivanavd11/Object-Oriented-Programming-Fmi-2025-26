#include "Reader.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>

int Reader::nextId = 1;

Reader::Reader(const std::string& name)
    : name(name), id(nextId++) {
    if (name.empty()) {
        throw std::invalid_argument("Reader name cannot be empty.");
    }
}

const std::string& Reader::getName() const {
    return name;
}

std::size_t Reader::getId() const {
    return id;
}

void Reader::setName(const std::string& newName) {
    if (newName.empty()) {
        throw std::invalid_argument("Reader name cannot be empty.");
    }

    name = newName;
}

std::size_t Reader::getBorrowedItemsCount() const {
    return borrowedItems.size();
}

const std::vector<LibraryItem*>& Reader::getBorrowedItems() const {
    return borrowedItems;
}

bool Reader::hasBorrowedItem(std::size_t itemId) const {
    for (const LibraryItem* item : borrowedItems) {
        if (item != nullptr && item->getId() == itemId) {
            return true;
        }
    }

    return false;
}

void Reader::borrowItem(LibraryItem* item) {
    if (item == nullptr) {
        throw std::invalid_argument("Cannot borrow a null library item.");
    }

    if (hasBorrowedItem(item->getId())) {
        throw std::logic_error("The reader has already borrowed this item.");
    }

    borrowedItems.push_back(item);
}

void Reader::returnItem(std::size_t itemId) {
    auto iterator = std::find_if(
        borrowedItems.begin(),
        borrowedItems.end(),
        [itemId](const LibraryItem* item) {
            return item != nullptr &&
                item->getId() == itemId;
        }
    );

    if (iterator == borrowedItems.end()) {
        throw std::invalid_argument("The reader has not borrowed this item.");
    }

    borrowedItems.erase(iterator);
}

void Reader::printInfo() const {
    std::cout << "Reader ID: " << id << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Borrowed items: "
        << borrowedItems.size() << '\n';

    if (borrowedItems.empty()) {
        std::cout << "No borrowed items.\n";
        return;
    }

    for (const LibraryItem* item : borrowedItems) {
        if (item != nullptr) {
            std::cout << "--------------------\n";
            item->printInfo();
        }
    }
}