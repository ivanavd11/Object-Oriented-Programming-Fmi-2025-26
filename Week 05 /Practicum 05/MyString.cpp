#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

void MyString::free()
{
	delete[] data;
	data = nullptr;
	length = 0;
	capacity = 8;
}
void MyString::copyFrom(const MyString& other)
{
	data = new char[other.capacity];
	strcpy(data, other.data);
	length = other.length;
	capacity = other.capacity;
}
void MyString::resize(size_t newCapacity)
{
	char* newData = new char[newCapacity];
	strcpy(newData, data);
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

MyString::MyString(const char* name)
{
	length = strlen(name);
	capacity = length + 1;
	data = new char[capacity];
	strcpy(data, name);
}
MyString::MyString(const MyString& other)
{
	copyFrom(other);
}
MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}
MyString::~MyString()
{
	free();
}

size_t MyString::getLength() const
{
	return length;
}
void MyString::clear()
{
	length = 0;
	data[0] = '\0';
}
void MyString::setAt(size_t index, char ch)
{
	if (index >= length)
	{
		cout << "Invalid index!" << endl;
		return;
	}

	data[index] = ch;
}
int MyString::find(char ch) const
{
	for (size_t i = 0; i < length; i++)
	{
		if (data[i] == ch)
		{
			return i;
		}
	}

	return -1;
}

void MyString::toUpper()
{
	for (size_t i = 0; i < length; i++)
	{
		data[i] = toupper(data[i]);
	}
}
void MyString::toLower()
{
	for (size_t i = 0; i < length; i++)
	{
		data[i] = tolower(data[i]);
	}
}
void MyString::erase(size_t index)
{
	if (index >= length)
	{
		cout << "Invalid index!" << endl;
		return;
	}

	for (size_t i = index; i < length - 1; i++)
	{
		data[i] = data[i + 1];
	}

	length--;
	data[length] = '\0';
}
void MyString::insert(size_t index, char ch)
{
	if (index > length)
	{
		cout << "Invalid index!" << endl;
		return;
	}

	if (length + 1 >= capacity)
	{
		resize(capacity * 2);
	}

	for (size_t i = length; i > index; i--)
	{
		data[i] = data[i - 1];
	}

	data[index] = ch;

	length++;

	data[length] = '\0';
}
void MyString::append(char* str)
{
	size_t len = strlen(str);

	while (length + len + 1 > capacity)
	{
		resize(capacity * 2);
	}

	strcat(data, str);

	length += len;
}
void MyString::print() const
{
	cout << data << endl;
}