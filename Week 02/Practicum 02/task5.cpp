#include <iostream>

using namespace std;

class ExamResult
{
private:
    int score;
    mutable int timesChecked;
    mutable int lastReturnedGrade;

public:
    // Конструктор
    ExamResult(int s = 0)
    {
        score = s;
        timesChecked = 0;
        lastReturnedGrade = 0;
    }

    // Setter
    void setScore(int newScore)
    {
        if (newScore < 0 || newScore > 100)
        {
            cout << "Invalid score!" << endl;
            return;
        }

        score = newScore;
    }

    // Връща оценката
    int getGrade() const
    {
        int grade;

        if (score <= 49)
        {
            grade = 2;
        }
        else if (score <= 59)
        {
            grade = 3;
        }
        else if (score <= 69)
        {
            grade = 4;
        }
        else if (score <= 84)
        {
            grade = 5;
        }
        else
        {
            grade = 6;
        }

        timesChecked++;
        lastReturnedGrade = grade;

        return grade;
    }

    // Getter
    int getTimesChecked() const
    {
        return timesChecked;
    }

    // Getter
    int getLastReturnedGrade() const
    {
        return lastReturnedGrade;
    }
};

int main()
{
    ExamResult student;

    student.setScore(78);

    cout << student.getGrade() << endl;
    cout << student.getGrade() << endl;

    cout << student.getTimesChecked() << endl;
    cout << student.getLastReturnedGrade() << endl;

    return 0;
}