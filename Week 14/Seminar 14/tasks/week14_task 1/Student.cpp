#include "Student.h"
#include <stdexcept>

Student::Student(
    const std::string& facultyNumber,
    const std::string& name,
    int accumulatedCredits,
    double averageGrade
)
    : facultyNumber(facultyNumber),
    name(name),
    accumulatedCredits(accumulatedCredits),
    averageGrade(averageGrade) {
    if (facultyNumber.empty()) {
        throw std::invalid_argument(
            "Faculty number cannot be empty."
        );
    }

    if (name.empty()) {
        throw std::invalid_argument(
            "Student name cannot be empty."
        );
    }

    if (accumulatedCredits < 0) {
        throw std::invalid_argument(
            "Accumulated credits cannot be negative."
        );
    }

    if (averageGrade < 2.0 || averageGrade > 6.0) {
        throw std::invalid_argument(
            "Average grade must be between 2.00 and 6.00."
        );
    }
}

const std::string& Student::getFacultyNumber() const {
    return facultyNumber;
}

const std::string& Student::getName() const {
    return name;
}

const std::vector<Course>& Student::getCourses() const {
    return courses;
}

int Student::getAccumulatedCredits() const {
    return accumulatedCredits;
}

double Student::getAverageGrade() const {
    return averageGrade;
}

void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

bool Student::hasPassedCourse(const std::string& courseName) const {
    for (const Course& course : courses) {
        if (course.getName() == courseName &&
            course.isPassed()) {
            return true;
        }
    }

    return false;
}

int Student::countPassedCoursesFromCategory(CourseCategory category) const {
    int count = 0;

    for (const Course& course : courses) {
        if (course.getCategory() == category &&
            course.isPassed()) {
            count++;
        }
    }

    return count;
}

int Student::getPassedElectiveCredits() const {
    int credits = 0;

    for (const Course& course : courses) {
        if (!course.isMandatory() &&
            course.isPassed()) {
            credits += course.getCredits();
        }
    }

    return credits;
}

int Student::countRemainingElectives() const {
    int count = 0;

    for (const Course& course : courses) {
        if (!course.isMandatory() &&
            !course.isPassed()) {
            count++;
        }
    }

    return count;
}