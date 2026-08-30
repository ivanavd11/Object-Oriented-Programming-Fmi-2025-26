#include "UserAccount.h"

int UserAccount::accountsCount = 0;

UserAccount::UserAccount(const std::string& username, int id)
{
    this->username = username;
    this->id = id;

    accountsCount++;
}

std::string UserAccount::getUsername() const
{
    return username;
}

int UserAccount::getId() const
{
    return id;
}

int UserAccount::getAccountsCount()
{
    return accountsCount;
}