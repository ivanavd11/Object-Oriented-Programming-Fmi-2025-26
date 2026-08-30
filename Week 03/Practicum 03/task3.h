#pragma once

class MyStack
{
private:
    int* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);

public:
    MyStack(size_t initialCapacity = 2);
    ~MyStack();

    MyStack(const MyStack& other);

    MyStack& operator=(const MyStack& other);

    void push(int value);
    void pop();

    int top() const;

    bool empty() const;

    size_t getSize() const;
};
