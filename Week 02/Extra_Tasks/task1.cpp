#include <iostream>
#include <cstring>

using namespace std;

class Teacher
{
private:
    char name[51];
    int age;
    int experience;

public:
    // Default конструктор
    Teacher()
    {
        strcpy(name, "Unknown");
        age = 18;
        experience = 0;
    }

    // Конструктор с параметри
    Teacher(const char* newName, int newAge, int newExperience)
    {
        setName(newName);
        setAge(newAge);
        setExperience(newExperience);
    }

    // Getter-и
    const char* getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    int getExperience() const
    {
        return experience;
    }

    // Setter-и
    void setName(const char* newName)
    {
        if (strlen(newName) > 50)
        {
            cout << "Name is too long!" << endl;
            return;
        }

        strcpy(name, newName);
    }

    void setAge(int newAge)
    {
        if (newAge <= 0)
        {
            cout << "Invalid age!" << endl;
            return;
        }

        age = newAge;
    }

    void setExperience(int newExperience)
    {
        if (newExperience < 0)
        {
            cout << "Invalid experience!" << endl;
            return;
        }

        if (newExperience > age)
        {
            cout << "Experience cannot be greater than age!" << endl;
            return;
        }

        experience = newExperience;
    }
};

int main()
{
    Teacher t1("Ivan Petrov", 45, 20);

    cout << t1.getName() << endl;
    cout << t1.getAge() << endl;
    cout << t1.getExperience() << endl;

    t1.setAge(-5);            // Грешка
    t1.setExperience(60);     // Грешка
    t1.setName("Georgi");

    cout << t1.getName() << endl;

    return 0;
}