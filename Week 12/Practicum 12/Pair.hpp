#include <iostream>

template <typename T, typename U>
class Pair
{
private:
	T first;
	U second;

public:
	Pair(const T& first, const U& second);

	const T& getFirst() const;
	const U& getSecond() const;

	void setFirst(const T& newFirst);
	void setSecond(const U& newSecond);

};

template <typename T, typename U>
Pair<T, U>::Pair(const T& first, const U& second)
	: first(first), second(second)
{

}

template <typename T, typename U>
const T& Pair<T, U>::getFirst() const
{
	return first;
}

template <typename T, typename U>
const U& Pair<T, U>::getSecond() const
{
	return second;
}

template <typename T, typename U>
void Pair<T, U>::setFirst(const T& newFirst)
{
	first = newFirst;
}

template <typename T, typename U>
void Pair<T, U>::setSecond(const U& newSecond)
{
	second = newSecond;
}