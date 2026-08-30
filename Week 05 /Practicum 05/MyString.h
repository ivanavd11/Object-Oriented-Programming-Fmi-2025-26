#pragma once

class MyString {
private:
	char* data;
	size_t length;
	size_t capacity;

	void free();
	void copyFrom(const MyString& other);
	void resize(size_t newCapacity);

public:
	MyString(const char* name="");
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	size_t getLength() const;
	void clear();
	void setAt(size_t index, char ch);
	int find(char ch) const;

	void toUpper();
	void toLower();
	void erase(size_t index);
	void insert(size_t index, char ch);
	void append(char* str);
	void print() const;
};
