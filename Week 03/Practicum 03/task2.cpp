#include <iostream>
#include "task2.h"

void DynamicArray::resize(size_t newCapacity)
{
	if (newCapacity < size)
	{
		std::cout << "New capacity is too small!" << std::endl;
		return;
	}

	int* newData = new int[newCapacity];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;

	data = newData;
	capacity = newCapacity;
	delete[] newData;
}

DynamicArray::DynamicArray(size_t newCapacity = 2)
{
	if (newCapacity == 0)
	{
		newCapacity = 1;
	}

	capacity = newCapacity;
	size = 0;
	data = new int[capacity];
}

DynamicArray::~DynamicArray()
{
	delete[] data;
	size = 0;
	capacity = 0;
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new int[capacity];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
	if (this != &other)
	{
		delete[] data;

		size = other.size;
		capacity = other.capacity;

		data = new int[capacity];

		for (size_t i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}

	return *this;
}

void DynamicArray::push_back(int value)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size] = value;
	size++;
}

void DynamicArray::pop_back()
{
	if (size == 0)
	{
		std::cout << "Array is empty!" << std::endl;
		return;
	}

	size--;
}

void DynamicArray::set(int index, int value)
{
	if (index >= size)
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	data[index] = value;
}

int DynamicArray::get(int index) const
{
	if (index >= size)
	{
		std::cout << "Invalid index!" << std::endl;
		return 0;
	}
	return data[index];
}

int DynamicArray::getSize() const
{
	return size;

}
int DynamicArray::getCapacity() const
{
	return capacity;
}

