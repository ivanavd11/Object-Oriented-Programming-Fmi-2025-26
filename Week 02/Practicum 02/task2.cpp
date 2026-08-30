#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class User
{
private:
    char username[31];
    char password[16];

public:
    // Конструктор
    User(const char* user = "", const char* pass = "")
    {
        strcpy(username, user);
        strcpy(password, pass);
    }

    // Setter за username
    void setUsername(const char* newUsername)
    {
        strncpy(username, newUsername, 30);
        username[30] = '\0';
    }

    // Getter за username
    const char* getUsername() const
    {
        return username;
    }

    // Setter за password
    void setPassword(const char* newPassword)
    {
        int length = strlen(newPassword);

        if (length < 8 || length > 15)
        {
            cout << "Invalid password!" << endl;
            return;
        }

        bool hasUpper = false;
        bool hasDigit = false;

        for (int i = 0; i < length; i++)
        {
            if (isupper(newPassword[i]))
            {
                hasUpper = true;
            }

            if (isdigit(newPassword[i]))
            {
                hasDigit = true;
            }
        }

        if (!hasUpper || !hasDigit)
        {
            cout << "Invalid password!" << endl;
            return;
        }

        strcpy(password, newPassword);
    }

    // Проверка на парола
    bool checkPassword(const char* input) const
    {
        return strcmp(password, input) == 0;
    }
};

int main()
{
    User user;

    user.setUsername("Georgi");

    user.setPassword("Password1");

    cout << user.getUsername() << endl;

    cout << user.checkPassword("Password1") << endl;

    cout << user.checkPassword("password1") << endl;

    user.setPassword("abc");

    return 0;
}