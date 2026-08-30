#include "StudentList.h"
#include <iostream>

using namespace std;

StudentList::StudentList()
{
    maxCapacity = 10;
    studentsCount = 0;

    studentsNames = new string[maxCapacity];
}

StudentList::StudentList(const StudentList& other)
{
    maxCapacity = other.maxCapacity;
    studentsCount = other.studentsCount;

    studentsNames = new string[maxCapacity];

    for (int i = 0; i < studentsCount; i++)
    {
        studentsNames[i] = other.studentsNames[i];
    }
}

StudentList& StudentList::operator=(const StudentList& other)
{
    if (this != &other)
    {
        delete[] studentsNames;

        maxCapacity = other.maxCapacity;
        studentsCount = other.studentsCount;

        studentsNames = new string[maxCapacity];

        for (int i = 0; i < studentsCount; i++)
        {
            studentsNames[i] = other.studentsNames[i];
        }
    }

    return *this;
}

StudentList::~StudentList()
{
    delete[] studentsNames;
}

void StudentList::print() const
{
    for (int i = 0; i < studentsCount; i++)
    {
        cout << studentsNames[i] << endl;
    }
}

void StudentList::addStudent(const string& name)
{
    if (studentsCount >= maxCapacity)
    {
        cout << "List is full!" << endl;
        return;
    }

    studentsNames[studentsCount] = name;
    studentsCount++;
}

void StudentList::setStudent(int index, const string& name)
{
    if (index < 0 || index >= studentsCount)
    {
        cout << "Invalid index!" << endl;
        return;
    }

    studentsNames[index] = name;
}