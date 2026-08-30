#pragma once
#include "Calculator.h"
#include <string>

class User {
private:
	static int countUsers;

	int id;
	std::string username;
	std::string password;
	Calculator* calc;

public:
	User(const std::string& newUsername, const std::string& newPassword);

	int getId() const;

	std::string getUsername() const;
	std::string getPassword() const;

	void setUsername(const std::string& newUsername);
	void setPassword(const std::string& newPassword);

	Calculator* getCalculator() const;
};
