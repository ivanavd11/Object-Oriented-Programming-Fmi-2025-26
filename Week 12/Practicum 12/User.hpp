#pragma once

#include <vector>
#include "Document.hpp"


template<typename T>
class User
{
private:
	std::string name;
	int id;
	std::vector<Document< T >> documents;

public:
	User(const std : string & name, int id)
		: name(name), id(id), documents()
	{ }

	const std::string getName() const
	{
		return name;
	}
	int getId() const {
		return id;
	}
	std::size_t getDocumentsCount() const {
		return documents.size();
	}

	void setName(const std::string& name) {
		this.name = name;
	}
	void setId(int newId)
	{
		if (newId <= 0)
		{
			throw std::out_of_range("Id is negative");
		}
		id = newId;
	}

	void addDocument(const Document< T >& doc)
	{
		documents.push_back(doc);
	}

	const Document< T >& getDocument(size_t index)
	{
		if (index < 0 || index>=getDocumentsCount())
		{
			throw std::out_of_range("Index is negative");
		}

		return documents[index];
	}

	void updateDocument(size_t index, const T& newContent)
	{
		if (index < 0 || index >= getDocumentsCount())
		{
			throw std::out_of_range("Index is negative");
		}
		documents[index].updateContent(newContent);
	}
};