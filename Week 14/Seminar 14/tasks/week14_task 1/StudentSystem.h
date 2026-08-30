#pragma once

#include "AdmissionReport.h"
#include "AdmissionService.h"
#include "Student.h"

#include <string>
#include <vector>

class StudentSystem {
private:
    std::vector<Student> students;
    AdmissionService admissionService;

public:
    explicit StudentSystem(
        const AdmissionService& admissionService
    );

    void addStudent(
        const Student& student
    );

    void removeStudent(
        const std::string& facultyNumber
    );

    Student& operator[](
        const std::string& facultyNumber
        );

    const Student& operator[](
        const std::string& facultyNumber
        ) const;

    const std::vector<Student>&
        getStudents() const;

    AdmissionReport checkAdmission(
        const std::string& facultyNumber
    ) const;
};
