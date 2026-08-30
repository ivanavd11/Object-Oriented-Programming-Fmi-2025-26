#include "GroupTicket.h"
#include <iostream>

GroupTicket::GroupTicket(const string& name, double cost, int size, int percent)
	: Ticket(name, cost), groupSize(size), discountRatePercentage(percent)
{
	if (groupSize <= 0 || groupSize > 6)
	{
		cout << "Invalid group size\n";
	}
	if (discountRatePercentage < 0 || discountRatePercentage>10)
	{
		cout << "Invalid percent\n";
	}
}

int GroupTicket::getGroupSize() const
{
	return groupSize;
}
int GroupTicket::GetDiscountRatePercentage() const
{
	return discountRatePercentage;
}

void GroupTicket::setGroupSize(int newSize)
{
	if (newSize <= 0 || newSize > 6)
	{
		cout << "Invalid group size\n";
		return;
	}
	groupSize = newSize;
}
void GroupTicket::setDiscountPercent(int newPercent)
{
	if (newPercent < 0 || newPercent>10)
	{
		cout << "Invalid percent\n";
		return;
	}
	discountRatePercentage = newPercent;
}

double GroupTicket::getGroupCost() const
{
	int percentOfGroup = discountRatePercentage * groupSize;

	return ((getCost()*groupSize)* (1.0 - percentOfGroup / 100.0));
}