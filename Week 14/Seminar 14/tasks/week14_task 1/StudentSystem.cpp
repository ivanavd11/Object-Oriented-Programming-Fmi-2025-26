#include "StudentSystem.h"

#include "Exceptions.h"

#include <cstddef>

StudentSystem::StudentSystem(
    const AdmissionService& admissionService
)
    : admissionService(admissionService) {
}

void StudentSystem::addStudent(
    const Student& student
) {
    for (const Student& currentStudent
        : students) {
        if (currentStudent.getFacultyNumber()
            == student.getFacultyNumber()) {
            throw DuplicateStudentException(
                student.getFacultyNumber()
            );
        }
    }

    students.push_back(student);
}

void StudentSystem::removeStudent(
    const std::string& facultyNumber
) {
    for (std::size_t i = 0;
        i < students.size();
        i++) {
        if (students[i].getFacultyNumber()
            == facultyNumber) {
            students.erase(
                students.begin() + i
            );

            return;
        }
    }

    throw StudentNotFoundException(
        facultyNumber
    );
}

Student& StudentSystem::operator[](
    const std::string& facultyNumber
    ) {
    for (Student& student : students) {
        if (student.getFacultyNumber()
            == facultyNumber) {
            return student;
        }
    }

    throw StudentNotFoundException(
        facultyNumber
    );
}

const Student& StudentSystem::operator[](
    const std::string& facultyNumber
    ) const {
    for (const Student& student : students) {
        if (student.getFacultyNumber()
            == facultyNumber) {
            return student;
        }
    }

    throw StudentNotFoundException(
        facultyNumber
    );
}

const std::vector<Student>&
StudentSystem::getStudents() const {
    return students;
}

AdmissionReport StudentSystem::checkAdmission(
    const std::string& facultyNumber
) const {
    const Student& student =
        (*this)[facultyNumber];

    return admissionService.checkAdmission(
        student
    );
}