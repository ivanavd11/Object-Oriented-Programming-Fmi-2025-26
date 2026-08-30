#pragma once

class Temperature {
private:
	int temperature;
	char system;

	int toCelsius() const;
	int toFahrenheit() const;

public:
	Temperature(int newTemp = 0, char newSystem = 'c');

	int getTemperature() const;
	char getSystem() const;

	void setTemperature(int newTemp);
	void setSystem(char newSystem);

	bool operator==(const Temperature& other) const;
	bool operator<(const Temperature& other) const;

	bool operator!=(const Temperature& other) const;
	bool operator<=(const Temperature& other) const;
	bool operator>(const Temperature& other) const;
	bool operator>=(const Temperature& other) const;

	Temperature operator+(const Temperature& other) const;
	Temperature operator-(const Temperature& other) const;

	Temperature& operator+=(const Temperature& other);
	Temperature& operator-=(const Temperature& other);
};
