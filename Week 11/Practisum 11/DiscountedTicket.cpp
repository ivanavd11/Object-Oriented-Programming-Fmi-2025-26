#include "DiscountedTicket.h"
#include <iostream>

DiscountedTicket::DiscountedTicket(const string& newName, double cost, int percent)
	: Ticket(newName, cost), discountPercentage(percent)
{
	if (discountPercentage < 0 || discountPercentage>100)
	{
		cout << "Invalid percent";
	}
}

int DiscountedTicket::getPersent() const
{
	return discountPercentage;
}

void DiscountedTicket::setPersent(int newPercent)
{
	if (newPercent < 0 || newPercent>100)
	{
		cout << "Invalid percent\n";
		return;
	}
	discountPercentage = newPercent;
}

double DiscountedTicket::getDiscountedCost() const
{
	return getCost() * (1.0 - discountPercentage / 100.0);
}