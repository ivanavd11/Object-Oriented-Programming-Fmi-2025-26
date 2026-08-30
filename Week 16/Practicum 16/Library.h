#pragma once
#include <vector>
#include <memory>
#include "Reader.h"
#include "LibraryItem.h"

class Library
{
	std::string name;

    std::vector<std::unique_ptr<LibraryItem>> items;
    std::vector<std::unique_ptr<Reader>> readers;

    Reader& findReader(std::size_t readerId);
    const Reader& findReader(std::size_t readerId) const;

    LibraryItem& findItem(std::size_t itemId);
    const LibraryItem& findItem(std::size_t itemId) const;

public:

    explicit Library(const std::string& name);

    const std::string& getName() const;
    void setName(const std::string& newName);

    Reader& addReader(const std::string& readerName);

    void addItem(std::unique_ptr<LibraryItem> item);

    void addItemCopy(const LibraryItem& item);

    Reader& getReader(std::size_t readerId);
    const Reader& getReader(std::size_t readerId) const;

    LibraryItem& getItem(std::size_t itemId);
    const LibraryItem& getItem(std::size_t itemId) const;

    void borrowItem(std::size_t readerId,const std::string& title);

    void returnItem(std::size_t readerId,std::size_t itemId);

    std::size_t getItemsCount() const;
    std::size_t getReadersCount() const;

    void printItems() const;
    void printReaders() const;
};
