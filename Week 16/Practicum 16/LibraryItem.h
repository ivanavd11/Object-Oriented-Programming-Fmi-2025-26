#pragma once
#include <string>
#include <memory>
class LibraryItem
{
	std::string title;
	std::string releaseDate;
	const std::size_t id;
	bool borrowed;

	static std::size_t nextId;

protected:
    LibraryItem(const LibraryItem& other);
    void printBaseInfo() const;

public:
    LibraryItem(
        const std::string& title,
        const std::string& releaseDate
    );

    LibraryItem& operator=(
        const LibraryItem& other
        ) = delete;

    const std::string& getTitle() const;

    const std::string& getReleaseDate() const;

    std::size_t getId() const;

    bool isBorrowed() const;

    void markAsBorrowed();
    void markAsReturned();

    virtual std::string getType() const = 0;

	virtual void printInfo() const = 0;
	virtual std::unique_ptr<LibraryItem> clone() const = 0;
	virtual ~LibraryItem() = default;
};

