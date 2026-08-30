#include "Library.h"
#include "LibraryExceptions.h"

#include <iostream>
#include <stdexcept>
#include <utility>

Library::Library(const std::string& name)
    : name(name) {
    if (name.empty()) {
        throw std::invalid_argument(
            "Library name cannot be empty."
        );
    }
}

const std::string& Library::getName() const {
    return name;
}

void Library::setName(const std::string& newName) {
    if (newName.empty()) {
        throw std::invalid_argument(
            "Library name cannot be empty."
        );
    }

    name = newName;
}

Reader& Library::addReader(const std::string& readerName) {
    auto reader = std::make_unique<Reader>(readerName);

    Reader& result = *reader;

    readers.push_back(std::move(reader));

    return result;
}

void Library::addItem(
    std::unique_ptr<LibraryItem> item
) {
    if (item == nullptr) {
        throw std::invalid_argument(
            "Cannot add a null library item."
        );
    }

    items.push_back(std::move(item));
}

void Library::addItemCopy(const LibraryItem& item) {
    items.push_back(item.clone());
}

Reader& Library::findReader(std::size_t readerId) {
    for (const std::unique_ptr<Reader>& reader : readers) {
        if (reader->getId() == readerId) {
            return *reader;
        }
    }

    throw ReaderNotFoundException(
        "Reader with ID " +
        std::to_string(readerId) +
        " was not found."
    );
}

const Reader& Library::findReader(
    std::size_t readerId
) const {
    for (const std::unique_ptr<Reader>& reader : readers) {
        if (reader->getId() == readerId) {
            return *reader;
        }
    }

    throw ReaderNotFoundException(
        "Reader with ID " +
        std::to_string(readerId) +
        " was not found."
    );
}

LibraryItem& Library::findItem(std::size_t itemId) {
    for (const std::unique_ptr<LibraryItem>& item : items) {
        if (item->getId() == itemId) {
            return *item;
        }
    }

    throw ItemNotFoundException(
        "Library item with ID " +
        std::to_string(itemId) +
        " was not found."
    );
}

const LibraryItem& Library::findItem(
    std::size_t itemId
) const {
    for (const std::unique_ptr<LibraryItem>& item : items) {
        if (item->getId() == itemId) {
            return *item;
        }
    }

    throw ItemNotFoundException(
        "Library item with ID " +
        std::to_string(itemId) +
        " was not found."
    );
}

Reader& Library::getReader(std::size_t readerId) {
    return findReader(readerId);
}

const Reader& Library::getReader(
    std::size_t readerId
) const {
    return findReader(readerId);
}

LibraryItem& Library::getItem(std::size_t itemId) {
    return findItem(itemId);
}

const LibraryItem& Library::getItem(
    std::size_t itemId
) const {
    return findItem(itemId);
}

void Library::borrowItem(
    std::size_t readerId,
    const std::string& title
) {
    Reader& reader = findReader(readerId);

    LibraryItem* availableItem = nullptr;

    for (const std::unique_ptr<LibraryItem>& item : items) {
        if (item->getTitle() == title &&
            !item->isBorrowed()) {
            availableItem = item.get();
            break;
        }
    }

    if (availableItem == nullptr) {
        throw ItemUnavailableException(
            "No available item with title \"" +
            title +
            "\"."
        );
    }

    availableItem->markAsBorrowed();

    try {
        reader.borrowItem(availableItem);
    }
    catch (...) {
        // Връщаме старото състояние, ако добавянето
        // при читателя е неуспешно.
        availableItem->markAsReturned();
        throw;
    }
}

void Library::returnItem(
    std::size_t readerId,
    std::size_t itemId
) {
    Reader& reader = findReader(readerId);

    if (!reader.hasBorrowedItem(itemId)) {
        throw ItemNotFoundException(
            "Reader with ID " +
            std::to_string(readerId) +
            " has not borrowed item with ID " +
            std::to_string(itemId) +
            "."
        );
    }

    LibraryItem& item = findItem(itemId);

    item.markAsReturned();
    reader.returnItem(itemId);
}

std::size_t Library::getItemsCount() const {
    return items.size();
}

std::size_t Library::getReadersCount() const {
    return readers.size();
}

void Library::printItems() const {
    std::cout << "Library: " << name << '\n';
    std::cout << "Items count: " << items.size() << '\n';

    if (items.empty()) {
        std::cout << "The library has no items.\n";
        return;
    }

    for (const std::unique_ptr<LibraryItem>& item : items) {
        std::cout << "--------------------\n";
        item->printInfo();
    }
}

void Library::printReaders() const {
    std::cout << "Readers count: "
        << readers.size()
        << '\n';

    if (readers.empty()) {
        std::cout << "The library has no readers.\n";
        return;
    }

    for (const std::unique_ptr<Reader>& reader : readers) {
        std::cout << "--------------------\n";
        reader->printInfo();
    }
}