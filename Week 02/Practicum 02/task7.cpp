#include <iostream>
#include <cstring>

using namespace std;

class Message
{
private:
    char* text;

public:
    // Default конструктор
    Message()
    {
        text = new char[strlen("no_text") + 1];
        strcpy(text, "no_text");
    }

    // Конструктор с параметри
    Message(const char* message)
    {
        text = new char[strlen(message) + 1];
        strcpy(text, message);
    }

    // Деструктор
    ~Message()
    {
        delete[] text;
    }

    // Извеждане
    void print() const
    {
        cout << text << endl;
    }
};

int main()
{
    Message m1;
    Message m2("Hello World!");

    m1.print();
    m2.print();

    return 0;
}