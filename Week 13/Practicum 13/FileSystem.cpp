#include "FileSystem.h"
#include <stdexcept>
#include <iostream>

void FileSystem::addFile(const std::unique_ptr<MyFile> file)
{
    if (!file) {
        throw std::invalid_argument("Cannot add an empty file pointer.");
    }

    fileSystem.push_back(std::move(file));
}
void FileSystem::deleteFile(int index)
{
    if (index < 0 || index >= getFilesCount())
    {
        throw std::invalid_argument("Index is invalid\n");
    }
    fileSystem.erase(fileSystem.begin() + index);
}

void FileSystem::printFiles() const
{
    if (fileSystem.empty())
    {
        std::cout << "The file system is empty.\n";
        return;
    }

    for (int i = 0; i < getFilesCount(); i++)
    {
        std::cout << "File " << i << "\n";
        std::cout << " data: " << fileSystem[i]->getData() << "\n";
        std::cout << " type: ";
        fileSystem[i]->printDetails();
        std::cout << "\n\n";
    }
}

std::size_t FileSystem::getFilesCount() const
{
    return fileSystem.size();
}