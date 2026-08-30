#pragma once

#include <stdexcept>
#include <string>

class ReaderNotFoundException : public std::runtime_error {
public:
    ReaderNotFoundException();

    explicit ReaderNotFoundException(
        const std::string& message
    );
};

class ItemNotFoundException : public std::runtime_error {
public:
    ItemNotFoundException();

    explicit ItemNotFoundException(
        const std::string& message
    );
};

class ItemUnavailableException : public std::runtime_error {
public:
    ItemUnavailableException();

    explicit ItemUnavailableException(
        const std::string& message
    );
};
