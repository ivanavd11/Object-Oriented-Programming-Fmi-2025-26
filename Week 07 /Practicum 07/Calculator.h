#pragma once

class Calculator {
private:
	Calculator();
	static Calculator* instance;

public:
	Calculator(const Calculator& other) = delete;
	Calculator& operator=(const Calculator& other) = delete;

	static Calculator* getInstance();

	double sum(double first, double second);
	double substeact(double first, double second);
	double multiply(double first, double second);
	double divide(double first, double second);
};
