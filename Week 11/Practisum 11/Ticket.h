#pragma once
#include <string>

using namespace std;

class Ticket {
private:
	string filmName;
	double cost;

public:
	Ticket(const string& name, double cost);

	const string& getName() const;
	double getCost() const;

	void setName(const string& newName);
	void setCost(double newCost);
};
