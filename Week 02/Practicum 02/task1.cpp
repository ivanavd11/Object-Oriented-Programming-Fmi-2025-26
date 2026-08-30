#include <iostream>
#include <cstring>
using namespace std;

class BankAccount
{
private:
    char owner[51];
    double balance;

public:
    // Конструктор
    BankAccount(const char* name = "", double money = 0)
    {
        strcpy(owner, name);
        balance = money;
    }

    // Deposit
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }

        balance += amount;
    }

    // Withdraw
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance!" << endl;
            return;
        }

        balance -= amount;
    }

    // Getter
    double getBalance() const
    {
        return balance;
    }

    // Setter
    void setOwner(const char* name)
    {
        strncpy(owner, name, 50);
        owner[50] = '\0';
    }

    // По желание
    void print() const
    {
        cout << "Owner: " << owner << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account("Ivan", 1000);

    account.deposit(500);
    account.withdraw(300);

    account.print();

    account.withdraw(1500);

    account.deposit(-10);

    account.setOwner("Georgi");

    account.print();

    return 0;
}