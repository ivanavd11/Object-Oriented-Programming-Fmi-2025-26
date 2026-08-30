#include "User.h"

int User::countUsers = 0;

User::User(const std::string& newUsername, const std::string& newPassword)
{
    id = ++countUsers;

    this->username = newUsername;
    this->password = newPassword;

    calc = Calculator::getInstance();
}

int User::getId() const
{
    return id;
}

std::string User::getUsername() const
{
    return username;
}
std::string User::getPassword() const
{
    return password;
}

void User::setUsername(const std::string& newUsername)
{
    this->username = newUsername;
}
void User::setPassword(const std::string& newPassword)
{
    this->password = newPassword;
}

Calculator* User::getCalculator() const
{
    return calc;
}