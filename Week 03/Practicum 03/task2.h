#pragma once

class DynamicArray {
private:
	int* data;
	size_t size;
	size_t capacity;

	void resize(size_t newCapacity);

public:
	DynamicArray(size_t newCapacity = 2);

	DynamicArray(const DynamicArray& other);

	DynamicArray& operator=(const DynamicArray& other);

	~DynamicArray();

	void push_back(int value);
	void pop_back();
	void set(int index, int value);

	int get(int index) const;
	int getSize() const;
	int getCapacity() const;
};
