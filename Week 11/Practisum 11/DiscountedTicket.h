#pragma once
#include "Ticket.h"

class DiscountedTicket:public Ticket
{
private:
	int discountPercentage;

public:
	DiscountedTicket(const string& newName, double cost, int percent);

	int getPersent() const;

	void setPersent(int newPercent);

	double getDiscountedCost() const;

};
