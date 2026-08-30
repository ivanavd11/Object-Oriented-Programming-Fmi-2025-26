#pragma once

#include <string>

class UserAccount
{
private:
    std::string username;
    int id;

    static int accountsCount;

public:
    // Default конструктор
    UserAccount() = default;

    // Конструктор с параметри
    UserAccount(const std::string& username, int id);

    // Деструктор
    ~UserAccount() = default;

    // Забраняваме копиране
    UserAccount(const UserAccount&) = delete;

    // Забраняваме operator=
    UserAccount& operator=(const UserAccount&) = delete;

    std::string getUsername() const;
    int getId() const;

    static int getAccountsCount();
};
