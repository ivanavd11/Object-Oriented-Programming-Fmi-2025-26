#pragma once
#include "Apartment.h"
#include <string>
#include <memory>
using namespace std;

class Tennant {
private:
	string firstName;
	string lastName;
	shared_ptr<Apartment> residence;

public:
	Tennant(const string& newFirst, const string& newSecond,
		shared_ptr<Apartment> newResidence);

	~Tennant();

	Tennant(const Tennant&) = delete;
	Tennant& operator=(const Tennant&) = delete;

	const string& getFirstName() const;
	const string& getLastName() const;
	const shared_ptr<Apartment>& getResidence() const;

	void setFirstName(const std::string& newFirstName);
	void setLastName(const std::string& newLastName);
	void setResidence(std::shared_ptr<Apartment> newResidence);

	void changeResidence(std::shared_ptr<Apartment> newResidence);

	void printInformation() const;
};
