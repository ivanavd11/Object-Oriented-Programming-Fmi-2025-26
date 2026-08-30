#pragma once
#include <string>

enum class CourseCategory
{
    Programming,
    Mathematics,
    AppliedMathematics,
    Other
};

const char* categoryToString
(
	CourseCategory category
);

class Course
{
private:
	std::string name;
	double credits;
	CourseCategory category;
	bool mandatory;
	bool passed;

public:
    Course(const std::string& name,int credits,CourseCategory category,bool mandatory,bool passed);

    const std::string& getName() const;
    int getCredits() const;
    CourseCategory getCategory() const;

    bool isMandatory() const;
    bool isPassed() const;
};

