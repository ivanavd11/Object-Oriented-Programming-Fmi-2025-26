#pragma once
#include "Course.h"
#include <vector>

class Student
{
private:
    std::string facultyNumber;
    std::string name;
    std::vector<Course> courses;

    int accumulatedCredits;
    double averageGrade;
public:
    Student(const std::string& facultyNumber,const std::string& name,int accumulatedCredits,double averageGrade);

    const std::string& getFacultyNumber() const;
    const std::string& getName() const;
    const std::vector<Course>& getCourses() const;

    int getAccumulatedCredits() const;
    double getAverageGrade() const;

    void addCourse(const Course& course);

    bool hasPassedCourse(const std::string& courseName) const;

    int countPassedCoursesFromCategory(CourseCategory category) const;

    int getPassedElectiveCredits() const;

    int countRemainingElectives() const;
};

