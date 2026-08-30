#include <iostream>
#include <cstring>

using namespace std;

class Secret
{
private:
    char* task;
    char* password;
    int loginFails;

    bool checkPassword(const char* pwd)
    {
        if (pwd != nullptr && strcmp(password, pwd) == 0)
        {
            return true;
        }

        loginFails++;
        return false;
    }

public:
    // Default constructor
    Secret()
    {
        task = new char[strlen("no_task") + 1];
        strcpy(task, "no_task");

        password = new char[strlen("12345678") + 1];
        strcpy(password, "12345678");

        loginFails = 0;
    }

    // Constructor with parameters
    Secret(const char* newTask, const char* newPassword)
    {
        if (newTask == nullptr)
        {
            newTask = "no_task";
        }

        if (newPassword == nullptr || strlen(newPassword) == 0)
        {
            newPassword = "12345678";
        }

        task = new char[strlen(newTask) + 1];
        strcpy(task, newTask);

        password = new char[strlen(newPassword) + 1];
        strcpy(password, newPassword);

        loginFails = 0;
    }

    // Copy constructor
    Secret(const Secret& other)
    {
        task = new char[strlen(other.task) + 1];
        strcpy(task, other.task);

        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);

        loginFails = other.loginFails;
    }

    // Operator =
    Secret& operator=(const Secret& other)
    {
        if (this != &other)
        {
            delete[] task;
            delete[] password;

            task = new char[strlen(other.task) + 1];
            strcpy(task, other.task);

            password = new char[strlen(other.password) + 1];
            strcpy(password, other.password);

            loginFails = other.loginFails;
        }

        return *this;
    }

    // Destructor
    ~Secret()
    {
        delete[] task;
        delete[] password;
    }

    // Връща задачата само при правилна парола
    const char* getTask(const char* pwd)
    {
        if (checkPassword(pwd))
        {
            return task;
        }

        cout << "Wrong password!" << endl;
        return nullptr;
    }

    // Смяна на парола
    void setPassword(const char* newPassword,
        const char* oldPassword)
    {
        if (!checkPassword(oldPassword))
        {
            cout << "Wrong old password!" << endl;
            return;
        }

        if (newPassword == nullptr || strlen(newPassword) == 0)
        {
            cout << "Invalid new password!" << endl;
            return;
        }

        delete[] password;

        password = new char[strlen(newPassword) + 1];
        strcpy(password, newPassword);
    }

    // Смяна на условието
    void setTask(const char* newTask,
        const char* passwd)
    {
        if (!checkPassword(passwd))
        {
            cout << "Wrong password!" << endl;
            return;
        }

        if (newTask == nullptr || strlen(newTask) == 0)
        {
            cout << "Invalid task!" << endl;
            return;
        }

        delete[] task;

        task = new char[strlen(newTask) + 1];
        strcpy(task, newTask);
    }

    int getLoginFails() const
    {
        return loginFails;
    }
};