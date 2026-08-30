#pragma once
#include <vector>
#include <stdexcept>

template<typename T>
class Box
{
protected:
	std::vector<T> items;
public:
	Box() = default;

	virtual void addItem(const T& item)
	{
		items.push_back(item);
	}
	void removeItem(int index)
	{
		if (index = > items.size())
		{
			throw std::invalid_argument("Index is negative");
		}
	}
	items.erase(items.begin() + index);

	const std::vector<T>& getItems() const 
	{
		return items;
	}

	std::size_t getSize() const 
	{
		return items.size();
	}

	bool isEmpty() const 
	{
		return items.empty();
	}

	virtual ~Box() = default;
};


template<typename T>
class SortingBox :public Box
{

public:
	SortingBox() = default;
	void addItem(const T& item) override
	{
		this->items.push_back(item);
		sort(items.begin(), items.end());
	}
};