#include "LibraryExceptions.h"

ReaderNotFoundException::ReaderNotFoundException()
    : std::runtime_error("Reader was not found.") {
}

ReaderNotFoundException::ReaderNotFoundException(
    const std::string& message
)
    : std::runtime_error(message) {
}

ItemNotFoundException::ItemNotFoundException()
    : std::runtime_error("Library item was not found.") {
}

ItemNotFoundException::ItemNotFoundException(
    const std::string& message
)
    : std::runtime_error(message) {
}

ItemUnavailableException::ItemUnavailableException()
    : std::runtime_error(
        "No available item with the requested title."
    ) {
}

ItemUnavailableException::ItemUnavailableException(
    const std::string& message
)
    : std::runtime_error(message) {
}