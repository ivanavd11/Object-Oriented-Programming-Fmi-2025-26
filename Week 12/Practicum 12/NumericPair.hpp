#include <iostream>
#include <concepts>
#include <stdexcept>

#include "DivisionByZeroException.h"

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <Number T>
class NumericPair
{
private:
	T first;
	T second;

public:
    NumericPair(const T& first, const T& second) {
        setFirst(first);
        setSecond(second);
    }

    const T& getFirst() const {
        return first;
    }

    const T& getSecond() const {
        return second;
    }

    void setFirst(const T& newFirst) {
        if (newFirst < T{ 0 }) {
            throw std::invalid_argument(
                "First cannot be negative."
            );
        }

        first = newFirst;
    }
    void setSecond(const T& newSecond) {
        if (newSecond < T{ 0 }) {
            throw std::invalid_argument(
                "Second cannot be negative."
            );
        }

        second = newSecond;
    }

    T divide()
    {
        if (second == T{ 0 })
        {
            throw DivisionByZeroException("Second number is 0");
        }
        return first / second;
    }
};
