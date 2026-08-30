#pragma once
#include <stdexcept>
#include <string>

class DivisionByZeroException :public std::runtime_error
{
public:
	DivisionByZeroException() :std::runtime_error("Division by zero") {};

	DivisionByZeroException(const std::string& message) :std::runtime_error(message) {};
};