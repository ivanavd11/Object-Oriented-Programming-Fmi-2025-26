#pragma once

class MyPair {
private:
	int first;
	int second;

public:
	MyPair(int first = 0, int second = 0);
	int getFirst() const;
	int getSecond() const;
	void setFirst(int a);
	void setSecond(int b);
	void swapElements();
	void printPair() const;
	int maxElement() const;
};