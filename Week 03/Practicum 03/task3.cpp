#include "task3.h"
#include <iostream>

using namespace std;

MyStack::MyStack(size_t initialCapacity)
{
    if (initialCapacity == 0)
    {
        initialCapacity = 1;
    }

    capacity = initialCapacity;
    size = 0;

    data = new int[capacity];
}

MyStack::~MyStack()
{
    delete[] data;
}

void MyStack::resize(size_t newCapacity)
{
    if (newCapacity < size)
    {
        cout << "Invalid capacity!" << endl;
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
}

MyStack::MyStack(const MyStack& other)
{
    size = other.size;
    capacity = other.capacity;

    data = new int[capacity];

    for (size_t i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

MyStack& MyStack::operator=(const MyStack& other)
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

void MyStack::push(int value)
{
    if (size == capacity)
    {
        resize(capacity * 2);
    }

    data[size] = value;
    size++;
}

void MyStack::pop()
{
    if (empty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    size--;
}

int MyStack::top() const
{
    if (empty())
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }

    return data[size - 1];
}

bool MyStack::empty() const
{
    return size == 0;
}

size_t MyStack::getSize() const
{
    return size;
}