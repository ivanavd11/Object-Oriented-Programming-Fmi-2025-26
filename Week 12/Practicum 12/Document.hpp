#pragma once
#include <string>
#include <stdexcept>

template<typename T>
class Document
{
private:
	std::string title;
	T content;
	bool locked;
public:
    Document(const std::string& title, const T& content)
        : title(title), content(content), locked(false) {
    }

    const std::string& getTitle() const {
        return title;
    }

    const T& getContent() const {
        return content;
    }

    bool isLocked() const {
        return locked;
    }

    void setTitle(const std::string& newTitle) {
        if (locked) {
            throw std::runtime_error("Cannot change the title of a locked document.");
        }

        title = newTitle;
    }

    void lock() {
        if (locked) {
            throw std::logic_error("Document is already locked.");
        }

        locked = true;
    }

    void unlock() {
        if (!locked) {
            throw std::logic_error("Document is already unlocked.");
        }

        locked = false;
    }

    void updateContent(const T& value) {
        if (locked) {
            throw std::runtime_error("Cannot update a locked document.");
        }

        content = value;
    }
};

