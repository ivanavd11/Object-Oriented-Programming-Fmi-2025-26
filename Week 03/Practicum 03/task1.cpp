#include <iostream>
#include "task1.h"

using namespace std;

MyPair::MyPair(int first = 0, int second = 0)
{
	setFirst(first);
	setSecond(second);
}

int MyPair::getFirst() const
{
	return first;
}

int MyPair::getSecond() const
{
	return second;
}

void MyPair::setFirst(int a)
{
	this->first = a;
}

void MyPair::setSecond(int b)
{
	this->second = b;
}

void MyPair::swapElements()
{
	int temp = first;
	first = second;
	second = first;
}

void MyPair::printPair() const
{
	cout << "Pair: (" << first << ", " << second << ")\n";
}
int MyPair::maxElement() const
{
	if (first > second)
	{
		return first;
	}
	return second;
}

