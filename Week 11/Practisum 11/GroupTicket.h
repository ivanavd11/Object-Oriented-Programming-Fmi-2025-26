#pragma once
#include "Ticket.h"


class GroupTicket:public Ticket
{
private:
	int groupSize;
	int discountRatePercentage;
public:
	GroupTicket(const string& name, double cost, int size, int percent);

	int getGroupSize() const;
	int GetDiscountRatePercentage() const;

	void setGroupSize(int newSize);
	void setDiscountPercent(int newPercent);

	double getGroupCost() const;

};
