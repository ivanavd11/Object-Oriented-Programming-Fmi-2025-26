#pragma once
#include "MyFile.h"
#include <memory>
#include <vector>

class FileSystem
{
private:
	std::vector<std::unique_ptr<MyFile>> fileSystem;

public:
	void addFile(const std::unique_ptr<MyFile> file);
	void deleteFile(int index);

	void printFiles() const;

	std::size_t getFilesCount() const;
};



